; size_t ft_strlen(const char *s)

%ifdef __LINUX__
    %define M_FT_STRLEN ft_strlen
%else
    %define M_FT_STRLEN _ft_strlen
%endif

global M_FT_STRLEN

section .text

M_FT_STRLEN:
	mov eax, 0	; rax = 0 (int i = 0)
	jmp count	; count()

count:
	cmp byte [rdi + rax], 0	; if (s + rax == 0)
	jne ret					; 	return (rax)
	inc rax					; else ++rax
	jmp count				; do it in a loop
