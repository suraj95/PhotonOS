; Boot file
 ;
 ; Copyright (c) 2015 Feraru Mihail (mihailferaru2000@gmail.com).
 ; This program is free software; you can redistribute it and/or modify it
 ; under the terms of the GNU General Public License as published by the Free
 ; Software Foundation; either version 2 of the License, or (at your option)
 ; any later version.
 ;
 ; Here starts kernel boot :D

; multiboot header
MBALIGN     equ  1<<0               
MEMINFO     equ  1<<1           
FLAGS       equ  MBALIGN | MEMINFO   
MAGIC       equ  0x1BADB002          
CHECKSUM    equ -(MAGIC + FLAGS)        
 
section .multiboot
align 4
	dd MAGIC
	dd FLAGS
	dd CHECKSUM

; reserve space for kernel stack
section .bootstrap_stack
align 4
stack_bottom:
times 16384 db 0
global stack_top
stack_top:
 
; start of kernel :D
section .text
global _start
_start:
	mov esp, stack_top ; set stack
	push esp ; push stack pointer
 	push ebx ; push multiboot structure
 	cli
	extern kmain
	call kmain ; let's GO!!!
	cli ; if kmain ends, disable interrupts and go to infinite loop
.hang:
	hlt ; if I am here, something went wrong :P
	jmp .hang