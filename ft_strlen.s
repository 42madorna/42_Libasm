; size_t ft_strlen(const char *s)

segment .text
	global _ft_strlen

_ft_strlen
	mov rax, 0	; rax = 0 (int i = 0)
	jmp count	; count()

count
	cmp BYTE[rdi + rax], 0	; if (s + rax == 0)
	je ret					; 	return (rax)
	inc rax					; else ++rax
	jmp count				; do it in a loop
