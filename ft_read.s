; ssize_t read(int fildes, void *buf, size_t nbyte);

section .text
	extern ___error				; external ___error will be called, imported like this
	global _ft_read

_ft_read:
	mov rax, 0x2000003
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