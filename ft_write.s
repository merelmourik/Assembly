; **************************************************************************** ;
;                                                                              ;
;                                                         ::::::::             ;
;    ft_write.s                                         :+:    :+:             ;
;                                                      +:+                     ;
;    By: merelmourik <merelmourik@student.codam.      +#+                      ;
;                                                    +#+                       ;
;    Created: 2020/09/21 11:44:07 by merelmourik   #+#    #+#                  ;
;    Updated: 2020/09/28 10:14:21 by merelmourik   ########   odam.nl          ;
;                                                                              ;
; **************************************************************************** ;

; ssize_t ft_write(int fildes, const void *buf, size_t nbyte)

global _ft_write
extern ___error

_ft_write:
	mov	rax, 0x2000004			; syscall 0x2000004 is to read
	syscall						; syscall to activate read
	jc .error					; if it carries an error, go to error
	ret							; return
	
.error:	
	push rax				; push rax to the stack to save the value
	call ___error			; calling error, which will save the return in rax
	mov rdi, rax			; putting rax in the first paramater
	pop rax					; putting the original value of rax back
	mov [rdi], rax			; setting errno
	mov rax, -1				; set the return value to -1
	ret						; return 
