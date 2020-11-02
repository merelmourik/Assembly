; **************************************************************************** ;
;                                                                              ;
;                                                         ::::::::             ;
;    ft_strdup.s                                        :+:    :+:             ;
;                                                      +:+                     ;
;    By: merelmourik <merelmourik@student.codam.      +#+                      ;
;                                                    +#+                       ;
;    Created: 2020/09/18 09:52:31 by merelmourik   #+#    #+#                  ;
;    Updated: 2020/09/22 16:42:35 by merelmourik   ########   odam.nl          ;
;                                                                              ;
; **************************************************************************** ;

; char *ft_strdup(const char *str1)

global _ft_strdup
extern _ft_strcpy	
extern _ft_strlen	
extern _malloc	

_ft_strdup:
	mov rax, 0					; set rax to 0
	cmp rdi, 0					; check if the input is not empty
	je .error					; if it is, go to error
	call _ft_strlen				; call str_len with rdi (first paramater)
	push rdi					; push rdi to the stack to save it
	inc rax						; increment rax for the \0, or eax?
	mov rdi, rax				; make rax the first paramater for malloc
	call _malloc 				; call malloc
	pop rsi						; put the source from the stack in the second paramater
	cmp rax, 0					; check if didn't fail
	je .error					; if it did, go to error
	mov rdi, rax				; put the malloced memory in the first paramater
	call _ft_strcpy				; call ft_strcpy with the correct paramaters
	ret							; return

.error:
	mov rax, 0					; set return to zero
	ret							; return
