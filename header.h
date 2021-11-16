/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   header.h                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: merelmourik <merelmourik@student.codam.      +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/11/16 15:10:18 by merelmourik   #+#    #+#                 */
/*   Updated: 2021/11/16 15:12:01 by merelmourik   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <fcntl.h>
#include <unistd.h>

#define BOLDBLUE  "\033[1m\033[34m"
#define RESET 	  "\033[0m"

char 	*ft_strdup(const char *s1);
char 	*ft_strcpy(char *dst, const char *src);
int		ft_strcmp(const char *s1, const char *s2);
size_t 	ft_strlen(const char *str);
ssize_t ft_write(int fd, const void *buf, size_t count);
ssize_t ft_read(int fd, void *buf, size_t count);