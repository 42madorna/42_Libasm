; ssize_t read(int fildes, void *buf, size_t nbyte);

section .text
	extern ___error				; external ___error will be called, imported like this
	global _ft_read

_ft_read:
	mov rax, 0x2000003			; save read (0x2000003) into rax
	syscall						; syscall rax (read) and save its return into rax
	jc err						; jump if carry (if there was an error calling read)

exit:
	ret							; return (rax)

err:
	mov r15, rax				; move rax into r15
	call ___error				; call ___error to get error what happened in read
	mov [rax], r15				; save the error
	mov rax, -1					; rax = -1
	ret							; return (rax)