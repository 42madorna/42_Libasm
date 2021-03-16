; char *strdup(const char *s1); -> rdi = const char *s1

section .text
	global _ft_strdup
	extern _ft_strlen		; ft_strlen will be called. Imported like this
	extern _ft_strcpy		; ft_strcpy will be called. Imported like this
	extern _malloc			; malloc will be called. Imported like this

_ft_strdup:
	call _ft_strlen			; rax = ft_strlen(rdi)
	add rax, 1				; add 1 more space so '\0' can be placed
	push rdi				; move rdi to the end of the stack
	mov rdi, rax			; rdi = rax (strlen + 1)
	call _malloc			; rax = malloc(rax)
	pop rcx					; take rdi, and save it into rcx
	mov rdi, rax			; rdi = malloc(rax)
	mov rsi, rcx			; rsi (second param for ft_strcpy) = rcx
	call _ft_strcpy			; ft_strcpy(rdi, rsi)

exit:
	ret						; return (rax)