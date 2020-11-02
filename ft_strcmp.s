; **************************************************************************** ;
;                                                                              ;
;                                                         ::::::::             ;
;    ft_strcmp.s                                        :+:    :+:             ;
;                                                      +:+                     ;
;    By: merelmourik <merelmourik@student.codam.      +#+                      ;
;                                                    +#+                       ;
;    Created: 2020/09/17 12:53:12 by merelmourik   #+#    #+#                  ;
;    Updated: 2020/09/28 09:48:25 by merelmourik   ########   odam.nl          ;
;                                                                              ;
; **************************************************************************** ;

; int	ft_strcmp(const char *str1, const char *str2)

global _ft_strcmp

_ft_strcmp:
	mov rax, 0 	; start with counter/index at 0
	jmp .loop 	; going to the loop function

.increment:
	inc rax		; incrementing rax by one
	
.loop:
	mov r8b, [rdi + rax]	; incrementing the index of the first paramater
	mov r9b, [rsi + rax]	; incrementing the index of the second paramater
	cmp r8b, 0				; check is the first paramater is null
	je .return				; if it is, jump to return
	cmp r9b, 0				; check if the second paramater is null 
	je .return				; if it is, jump to is_zero
	cmp r8b, r9b 			; comparing if the index holds the same value
	jne .return				; not equal, jump to not_equal code
	jmp .increment			; if it is equal, jump to increment

.return:
	sub r8b, r9b		; substracting the index
	movsx rax, r8b		; setting the return to the correct value
	ret					; return the code
