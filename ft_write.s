; ssize_t write(int fildes, const void *buf, size_t nbyte); -> rdi = int fildes, rsi = void *buf, rdx = size_t nbyte

section .text
	extern ___error				; external ___error will be called, imported like this
	global _ft_write

_ft_write:
	mov rax, 0x2000004			; save write (0x2000004) into rax
	syscall						; syscall rax (write) and save its return into rax
	jc err						; jump if carry (if there was an error calling write)

exit:
	ret							; return (rax)

err:
	mov r15, rax				; move rax into r15
	call ___error				; call ___error to get error what happened in write
	mov [rax], r15				; save the error
	mov rax, -1					; rax = -1
	ret							; return (rax)
