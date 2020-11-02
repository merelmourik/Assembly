; **************************************************************************** ;
;                                                                              ;
;                                                         ::::::::             ;
;    ft_strcpy.s                                        :+:    :+:             ;
;                                                      +:+                     ;
;    By: merelmourik <merelmourik@student.codam.      +#+                      ;
;                                                    +#+                       ;
;    Created: 2020/09/19 10:37:58 by merelmourik   #+#    #+#                  ;
;    Updated: 2020/09/29 10:33:02 by merelmourik   ########   odam.nl          ;
;                                                                              ;
; **************************************************************************** ;

; char *ft_strcpy(char *dst, const char *src)

global _ft_strcpy

_ft_strcpy:
	mov rax, 0			; set the index to 0
	cmp rsi, 0			; check if the source is not empty
	je .error			; if it is, jump to error
	cmp rdi, 0			; check if the destination is malloced correctly
	je .error			; if it isn't, jump to error
	jmp .loop 			; jump to the loop
	
.loop:
	mov r8b, [rsi + rax]	; move source index in the a register
	mov [rdi + rax], r8b 	; put the register in de destination index
	cmp r8b, 0				; check if the index is at the end of the line
	je .ret					; if it is, go to return
	inc rax					; otherwise increment the index
	jmp .loop				; start the loop over again

.error:
	mov rax, 0				; set return to zero
	ret						; return

.ret:
	mov rax, rdi			; put the destination in the return
	ret						; return