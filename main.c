/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: merelmourik <merelmourik@student.42.fr>      +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/09/17 10:36:03 by merelmourik   #+#    #+#                 */
/*   Updated: 2021/11/16 15:14:23 by merelmourik   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int main(void)
{
	printf(BOLDBLUE "Testing strlen\n" RESET);
	char *str_slen = "Length should be 19";
	printf("Original: %lu \n", strlen(str_slen));
	printf("Mine: %lu \n", ft_strlen(str_slen));
	printf("Original: %lu \n", strlen(""));
	printf("Mine: %lu \n", ft_strlen(""));

	printf(BOLDBLUE"\nTesting strcpy:\n" RESET);
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

	printf(BOLDBLUE"\nTesting strcmp:\n" RESET);
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

	printf(BOLDBLUE"\nTesting write:\n" RESET);
	int fd;
	fd = open("test.txt", O_CREAT | O_RDWR);
	printf("Mine: %zi\nOriginal: %zi\n", ft_write(fd, "Test.\n", 6), write(fd, "Test.\n", 6));
	printf("Mine: %zi\nOriginal: %zi\n", ft_write(66, "Test.\n", 6), write(66, "Test.\n", 6));

	printf(BOLDBLUE"\nTesting read:" RESET);
	char buf[100];
	printf("Please enter a string, press 'enter' and write the same string again (max 100 characters)\n");
	printf("Mine: %zi\n", ft_read(0, buf, 10));
	printf("Original: %zi\n", read(0, buf, 10));
	printf("Mine: %s\n", strerror(errno));
	printf("Original: %s\n", strerror(errno));
	errno = 0;
	printf("Mine: (error): %zi\n", ft_read(10, buf, 10));
	printf("Original (error): %zi\n", read(10, buf, 10));
	printf("Mine: %s\n", strerror(errno));
	printf("Original: %s\n\n", strerror(errno));
	errno = 0;

	printf(BOLDBLUE"Testing strdup:\n" RESET);
	char *str;
	str = ft_strdup("Test.\n Test.\n Test.");
	printf("Mine: %s\n", str);
	str = strdup("Test.\n Test.\n Test.");
	printf("Original: %s\n", str);
	str = ft_strdup("");
	char *str1 = strdup("");
	printf("Mine: [%s]\nOriginal: [%s]\n", str, str1);
	printf("Mine: %s memmory: %p \n", str, &(str[0]));
	printf("Original: %s memmory: %p \n", str1, &(str1[0]));
	return (0);
}
