; size_t ft_strlen(const char *s)

section .text
	global _ft_strlen

_ft_strlen:
	mov eax, 0	; rax = 0 (int i = 0)
;	jmp count	; count() NOT NECESSARY because ASM auto jmp to next section

count:
	cmp BYTE[rdi + rax], 0	; if (s + rax == 0)
	je exit					; 	return (rax) ; je,jz == equal -> (cmp 0 == 0)
	inc rax					; else ++rax
	jmp count				; do it in a loop

exit:
	ret						; return (rax)