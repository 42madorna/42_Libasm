; char *strcpy(char *dst, const char *src) -> rdi = char *dst, rsi = const char *src

section .text
	global _ft_strcpy

_ft_strcpy:
	mov rax, rdi			; rax = rdi
	mov rcx, 0				; rcx = 0

cpy:
	cmp BYTE[rsi + rcx], 0	; if (rsi[rcx] == '\0')
	je exit					; 	return (rax)
	mov dl, BYTE[rsi + rcx]	; dl = rsi[rcx]					
	mov BYTE[rax, rcx], dl	; rax[rcx] = dl -> data access reg Low (8bit, 1 char, 1 BYTE)
	inc rcx					; ++rcx
	jmp cpy					; cpy(), to do it in a loop

exit:
	mov BYTE[rax + rcx], 0	; rax[rcx] = '\0' -> NULL terminate dst
	ret						; return (rax)
