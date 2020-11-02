; **************************************************************************** ;
;                                                                              ;
;                                                         ::::::::             ;
;    ft_read.s                                          :+:    :+:             ;
;                                                      +:+                     ;
;    By: merelmourik <merelmourik@student.codam.      +#+                      ;
;                                                    +#+                       ;
;    Created: 2020/09/21 11:14:53 by merelmourik   #+#    #+#                  ;
;    Updated: 2020/09/22 16:31:28 by merelmourik   ########   odam.nl          ;
;                                                                              ;
; **************************************************************************** ;

; ssize_t ft_read(int fildes, void *buf, size_t nbyte)

global _ft_read
extern ___error

_ft_read:
    mov rax, 0x2000003		; syscall 0x2000003 is to read
    syscall					; syscall to activate read
    jc .error           	; if it carries an error, go to error
    ret						; return

.error:
	push rax				; push rax to the stack to save the value
	call ___error			; calling error, which will save the return in rax
	mov rdi, rax			; putting rax in the first paramater
	pop rax					; putting the original value of rax back
	mov [rdi], rax			; setting errno
	mov rax, -1				; set the return value to -1
	ret						; return 
