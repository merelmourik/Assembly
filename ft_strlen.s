; **************************************************************************** ;
;                                                                              ;
;                                                         ::::::::             ;
;    ft_strlen.s                                        :+:    :+:             ;
;                                                      +:+                     ;
;    By: merelmourik <merelmourik@student.codam.      +#+                      ;
;                                                    +#+                       ;
;    Created: 2020/09/17 10:34:04 by merelmourik   #+#    #+#                  ;
;    Updated: 2020/09/22 16:16:32 by merelmourik   ########   odam.nl          ;
;                                                                              ;
; **************************************************************************** ;

; size_t	ft_strlen(const char *s)

global _ft_strlen

_ft_strlen:
	mov rax, 0 		; start with counter/index at zero
	jmp .loop 		; going to the loop function

.increment:
	inc rax			; incrementing rax by one

.loop:
	mov r8b, [rdi + rax]	; incrementing the index of the string
	cmp r8b, 0				; checking if the index is null terminated 
	jne .increment			; if not at the end, jump to increment 
	ret 					; the return value is in rax so the correct value is returned