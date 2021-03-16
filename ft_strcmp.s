; int strcmp(const char *s1, const char *s2); -> rdi = const char *s1, rsi = const char *s2

section .text
	global _ft_strcmp

_ft_strcmp:
	mov rcx, 0				; rcx = 0

comp:
	mov al, BYTE[rdi + rcx]	; al = rdi[rcx]
	mov bl, BYTE[rsi + rcx]	; bl = rsi[rcx]
	cmp al, 0				; if (al == 0)
	je exit					; 	exit()
	cmp bl, 0				; if (bl == 0)
	je exit					; 	exit()
	cmp al, bl				; if (al != bl)
	jne exit				; 	exit()
	inc rcx					; ++rcx
	jmp comp				; comp(), do it in a loop

exit:
	movzx rax, al			; rax = al [movzx -> move zero extend (adds zeroes)]
	movzx rbx, bl			; rbx = bl
	sub rax, rbx			; rax = rax - rbx
	ret						; return (rax)