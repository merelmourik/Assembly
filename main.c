/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: merelmourik <merelmourik@student.42.fr>      +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/09/17 10:36:03 by merelmourik   #+#    #+#                 */
/*   Updated: 2021/11/16 11:06:30 by merelmourik   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <errno.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/uio.h>
#include <unistd.h>

extern char *ft_strdup(const char *s1);
extern size_t ft_strlen(const char *str);
extern int	ft_strcmp(const char *s1, const char *s2);
extern char *ft_strcpy(char *dst, const char *src);
extern ssize_t ft_write(int fd, const void *buf, size_t count);
extern ssize_t ft_read(int fd, void *buf, size_t count);

int main(void)
{
	printf("Testing ft_strlen\n");
	char *str_slen = "Length should be 19";
	printf("Original: %lu \n", strlen(str_slen));
	printf("Mine: %lu \n", ft_strlen(str_slen));
	printf("Original: %lu \n", strlen(""));
	printf("Mine: %lu \n", ft_strlen(""));
	
	printf("\nTesting strcpy:\n");
	char *src = "I'm the source! I'm the source! I'm the source! I'm the source! I'm the source! I'm the source! I'm the source! I'm the source! I'm the source! I'm the source! I'm the source! I'm the source! I'm the source! I'm the source! I'm the source! I'm the source! I'm the source! I'm the source! I'm the source! I'm the source! I'm the source! I'm the source! I'm the source! I'm the source! I'm the source! I'm the source! I'm the source! I'm the source! I'm the source! I'm the source!";
	char dst[500];
	printf("Mine: %s\nOriginal: %s\n", ft_strcpy(dst, src), strcpy(dst, src));
	char src1[4] = "Hii";
	char dst1[4] = "Bye";
	printf("Original: %s\n", strcpy(dst1, src1));
	printf("Mine: %s\n", ft_strcpy(dst1, src1));
	char dst2[5] = "daar";
    char src2[1] = "";
	printf("Original: [%s]\n", strcpy(dst2, src2));
    printf("Mine: [%s]\n", ft_strcpy(dst2, src2));

	printf("\nTesting strcmp:\n");
	char *src3 = "\xfe";
	char *dst3 = "\xff";
	int diff_s = strcmp(src3, dst3);
	int diff = ft_strcmp(src3, dst3);
	printf("Mine: %i\nOriginal: %i\n", diff, diff_s);
	printf("Mine: %i\nOriginal: %i\n", ft_strcmp("\xfe", "\xff"), strcmp("\xfe", "\xff"));
	src3 = "";
	dst3 = "asdf";
	diff_s = strcmp(dst3, src3);
	diff = ft_strcmp(dst3, src3);
	printf("Mine: %i\nOriginal: %i\n", diff, diff_s);
	src3 = "asdf";
	dst3 = "";
	diff_s = strcmp(dst3, src3);
	diff = ft_strcmp(dst3, src3);
	printf("Mine: %i\nOriginal: %i\n", diff, diff_s);
	src3 = "bonjour";
	dst3 = "onjour";
	diff_s = strcmp(dst3, src3);
	diff = ft_strcmp(dst3, src3);
	printf("Mine: %i\nOriginal: %i\n", diff, diff_s);
	src3 = "the\0hidden";
	dst3 = "the\0hidden";
	diff_s = strcmp(dst3, src3);
	diff = ft_strcmp(dst3, src3);
	printf("Mine: %i\nOriginal: %i\n", diff, diff_s);
	src3 = "\x01";
	dst3 = "\x02";
	diff_s = strcmp(dst3, src3);
	diff = ft_strcmp(dst3, src3);
	printf("Mine: %i\nOriginal: %i\n", diff, diff_s);
	src3 = "aaa";
	dst3 = "aaz";
	diff_s = strcmp(dst3, src3);
	diff = ft_strcmp(dst3, src3);
	printf("Mine: %i\nOriginal: %i\n", diff, diff_s);

	printf("\nTesting write:\n");
	int fd;
	fd = open("test.txt", O_CREAT | O_RDWR);
	printf("ft_write should be 6: %zi\n", ft_write(fd, "Test.\n", 6));
	printf("ft_write should be -1: %zi\n", ft_write(66, "Test.\n", 6));
	
	printf("\nTesting read:\n");
	char buf[10];
	printf("Mine: %zi\n", ft_read(0, buf, 10));
	printf("Original: %zi\n", read(0, buf, 10));
	printf("Mine: %s\n", strerror(errno));
	printf("Original: %s\n", strerror(errno));
	errno = 0;
	printf("Mine: (error): %zi\n", ft_read(10, buf, 10));
	printf("Original (error): %zi\n", read(10, buf, 10));
	printf("Mine: %s\n", strerror(errno));
	printf("Original: %s\n", strerror(errno));
	errno = 0;

	printf("Testing strdup:\n");
	char *str;
	str = ft_strdup("Test.\n Test.\n Test.\n Test.\n Test.\n Test.\n Test.\n Test.\n Test.\n Test.\n Test.\n Test.\n Test.\n Test.\n");
	printf("Mine: %s\n", str);
	str = ft_strdup("");
	char *str1 = strdup("");
	printf("Mine: [%s], 	original: [%s]\n", str1, str);
	printf("Mine: %s memmory: %p \n", str, &(str[0]));
	printf("Original: %s memmory: %p \n", str1, &(str1[0]));
	return (0);
}
