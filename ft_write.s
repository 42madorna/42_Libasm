; ssize_t write(int fildes, const void *buf, size_t nbyte); -> rdi = int fildes, rsi = void *buf, rdx = size_t nbyte

section .text
	extern ___error				; external ___error will be called, imported like this
	global _ft_write

_ft_write:
	mov rax, 0x2000004
	syscall
	jc err

exit:
	;call ___error
	ret						; return (rax)

err:
	mov r15, rax
	call ___error
	mov [rax], r15
	mov rax, -1
	ret
