/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: merelmourik <merelmourik@student.42.fr>      +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/09/17 10:36:03 by merelmourik   #+#    #+#                 */
/*   Updated: 2020/09/29 10:38:37 by merelmourik   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <errno.h>
#include <sys/stat.h>
#include <fcntl.h>

int strcmp_expected;
int strcmp_actual;

# define FT_STRCMP_EXPECT(s1, s2) do { \
	strcmp_expected = strcmp(s1, s2); \
	strcmp_actual = ft_strcmp(s1, s2); \
	if ((strcmp_expected < 0 && strcmp_actual < 0) || \
	    (strcmp_expected > 0 && strcmp_actual > 0) || \
	    (strcmp_expected == 0 && strcmp_actual == 0)) \
		printf("OK\n"); \
	else \
		printf("KO: [COMPARE]: ft_strcmp.s: expected: %d got: %d with: "#s1", "#s2"\n", \
			   strcmp_expected, strcmp_actual); \
} while (0);

int	ft_strcmp(const char *s1, const char *s2)
{
	size_t			count;
	unsigned char	*str1;
	unsigned char	*str2;
	str1 = (unsigned char*)s1;
	str2 = (unsigned char*)s2;
	count = 0;
	while (str1[count] != '\0' || str2[count] != '\0')
	{
		if (str1[count] != str2[count])
			return (str1[count] - str2[count]);
		count++;
	}
	return (0);
}

int main(void)
{
	extern size_t ft_strlen(const char *str);
	char *str_slen = "Length should be 19";
	printf("ft_strlen should be 19: %lu \n", ft_strlen(str_slen));
	printf("ft_strlen should be 0: %lu \n", ft_strlen(""));
	extern char *ft_strcpy(char *dst, const char *src);
	char *src = "I'm the source! I'm the source! I'm the source! I'm the source! I'm the source! I'm the source! I'm the source! I'm the source! I'm the source! I'm the source! I'm the source! I'm the source! I'm the source! I'm the source! I'm the source! I'm the source! I'm the source! I'm the source! I'm the source! I'm the source! I'm the source! I'm the source! I'm the source! I'm the source! I'm the source! I'm the source! I'm the source! I'm the source! I'm the source! I'm the source!";
	char *dst = malloc(480);
	ft_strcpy(dst, src);
	printf("ft_strcpy: %s\n", dst);
	char src1[0] = "";
	char dst1[4] = "hoi";
	char src2[0] = "";
	char dst2[4] = "hoi";
	strcpy(dst2, src2);
	ft_strcpy(dst1, src1);
	printf("origineel: %s	 mijne: %s\n", dst2, dst1);
	FT_STRCMP_EXPECT("", "");
	FT_STRCMP_EXPECT("bon", "");
	FT_STRCMP_EXPECT("bonjour", "");
	FT_STRCMP_EXPECT("asdklfjasdfj////asdf'''asdf3##", "");
	FT_STRCMP_EXPECT("the\0hidden", "");
	FT_STRCMP_EXPECT("Lorem ipsum dolor sit amet, consectetur adipiscing\
elit. Sed in malesuada purus. Etiam a scelerisque massa. Ut non euismod elit. Aliquam\
bibendum dolor mi, id fringilla tellus pulvinar eu. Fusce vel fermentum sem. Cras\
volutpat, eros eget rhoncus rhoncus, diam augue egestas dolor, vitae rutrum nisi\
felis sed purus. Mauris magna ex, mollis non suscipit eu, lacinia ac turpis. Phasellus\
ac tortor et lectus fermentum lobortis eu at mauris. Vestibulum sit amet posuere\
tortor, sit amet consequat amet.", "");
	FT_STRCMP_EXPECT("", "");
	FT_STRCMP_EXPECT("bon", "bon");
	FT_STRCMP_EXPECT("bonjour", "bonjour");
	FT_STRCMP_EXPECT("asdklfjasdfj////asdf'''asdf3##", "asdklfjasdfj////asdf'''asdf3##");
	FT_STRCMP_EXPECT("the\0hidden", "the\0hidden");
	FT_STRCMP_EXPECT("Lorem ipsum dolor sit amet, consectetur adipiscing\
elit. Sed in malesuada purus. Etiam a scelerisque massa. Ut non euismod elit. Aliquam\
bibendum dolor mi, id fringilla tellus pulvinar eu. Fusce vel fermentum sem. Cras\
volutpat, eros eget rhoncus rhoncus, diam augue egestas dolor, vitae rutrum nisi\
felis sed purus. Mauris magna ex, mollis non suscipit eu, lacinia ac turpis. Phasellus\
ac tortor et lectus fermentum lobortis eu at mauris. Vestibulum sit amet posuere\
tortor, sit amet consequat amet.",
"Lorem ipsum dolor sit amet, consectetur adipiscing\
elit. Sed in malesuada purus. Etiam a scelerisque massa. Ut non euismod elit. Aliquam\
bibendum dolor mi, id fringilla tellus pulvinar eu. Fusce vel fermentum sem. Cras\
volutpat, eros eget rhoncus rhoncus, diam augue egestas dolor, vitae rutrum nisi\
felis sed purus. Mauris magna ex, mollis non suscipit eu, lacinia ac turpis. Phasellus\
ac tortor et lectus fermentum lobortis eu at mauris. Vestibulum sit amet posuere\
tortor, sit amet consequat amet.");
	FT_STRCMP_EXPECT("", "asdf");
	FT_STRCMP_EXPECT("bon", "bo");
	FT_STRCMP_EXPECT("bonjour", "onjour");
	FT_STRCMP_EXPECT("asdklfjasdfj////asdf'''asdf3##", "asdklfjasdfj////asdf'''asdf3##");
	FT_STRCMP_EXPECT("the\0hidden", "thehidden");
	FT_STRCMP_EXPECT("Lorem ipsum dolor st amet, consectetur adipiscing", "Lodsfsdfasdf");
	FT_STRCMP_EXPECT("\x01", "\x01");
	FT_STRCMP_EXPECT("\x02", "\x01");
	FT_STRCMP_EXPECT("\x01", "\x02");
	FT_STRCMP_EXPECT("\xff", "\xff");
	FT_STRCMP_EXPECT("\xfe", "\xff");
	FT_STRCMP_EXPECT("\xff", "\xfe");
	FT_STRCMP_EXPECT("\x01\x01", "\x01");
	FT_STRCMP_EXPECT("\x01\x02", "\x01");
	FT_STRCMP_EXPECT("\x02\x01", "\x02");
	FT_STRCMP_EXPECT("\xff\xff", "\xff");
	FT_STRCMP_EXPECT("\xff\xfe", "\xff");
	FT_STRCMP_EXPECT("\xfe\xff", "\xfe");
	FT_STRCMP_EXPECT("\x01", "\x01\x01");
	FT_STRCMP_EXPECT("\x01", "\x01\x02");
	FT_STRCMP_EXPECT("\x02", "\x02\x01");
	FT_STRCMP_EXPECT("\xff", "\xff\xff");
	FT_STRCMP_EXPECT("\xff", "\xff\xfe");
	FT_STRCMP_EXPECT("\xfe", "\xfe\xff");
	char *s_src = "\xfe";
	char *s_dst = "\xff";
	int diff_s = strcmp(s_src, s_dst);
	int diff = ft_strcmp(s_src, s_dst);
	printf("ft_strcmp: me: %i sys: %i\n", diff, diff_s);
	printf("ft_strcmp: me: %i sys: %i\n", ft_strcmp("\xfe", "\xff"), strcmp("\xfe", "\xff"));
	s_src = "";
	s_dst = "asdf";
	diff_s = strcmp(s_dst, s_src);
	diff = ft_strcmp(s_dst, s_src);
	printf("ft_strcmp: me: %i sys: %i\n", diff, diff_s);
	s_src = "asdf";
	s_dst = "";
	diff_s = strcmp(s_dst, s_src);
	diff = ft_strcmp(s_dst, s_src);
	printf("ft_strcmp: me: %i sys: %i\n", diff, diff_s);
	s_src = "bonjour";
	s_dst = "onjour";
	diff_s = strcmp(s_dst, s_src);
	diff = ft_strcmp(s_dst, s_src);
	printf("ft_strcmp: me: %i sys: %i\n", diff, diff_s);
	s_src = "the\0hidden";
	s_dst = "thehidden";
	diff_s = strcmp(s_dst, s_src);
	diff = ft_strcmp(s_dst, s_src);
	printf("ft_strcmp: me: %i sys: %i\n", diff, diff_s);
	s_src = "\x01";
	s_dst = "\x02";
	diff_s = strcmp(s_dst, s_src);
	diff = ft_strcmp(s_dst, s_src);
	printf("ft_strcmp: me: %i sys: %i\n", diff, diff_s);
	s_src = "aaa";
	s_dst = "aaz";
	diff_s = strcmp(s_dst, s_src);
	diff = ft_strcmp(s_dst, s_src);
	printf("ft_strcmp: me: %i sys: %i\n", diff, diff_s);
	extern ssize_t ft_write(int fd, const void *buf, size_t count);
	int fd;
	fd = open("test.txt", O_CREAT | O_RDWR);
	printf("ft_write should be 6: %zi\n", ft_write(fd, "Test.\n", 6));
	printf("ft_write should be -1: %zi\n", ft_write(66, "Test.\n", 6));
	extern ssize_t ft_read(int fd, void *buf, size_t count);
	char buf[10];
	printf("mijne: %zi\n", ft_read(0, buf, 10));
	//printf("origineel: %i\n", read(0, buf, 10));
	printf("mijne: %s\n", strerror(errno));
	printf("origineel: %s\n", strerror(errno));
	errno = 0;
	printf("mijne: (error): %zi\n", ft_read(10, buf, 10));
	//printf("origineel (error): %i\n", read(10, buf, 10));
	printf("mijne: %s\n", strerror(errno));
	printf("origineel: %s\n", strerror(errno));
	errno = 0;
	extern char *ft_strdup(const char *s1);
	char *str;
	str = ft_strdup("Test.\n Test.\n Test.\n Test.\n Test.\n Test.\n Test.\n Test.\n Test.\n Test.\n Test.\n Test.\n Test.\n Test.\n");
	printf("ft_strdup: %s\n", str);
	str = ft_strdup("");
	char *str1 = strdup("");
	printf("mijne: [%s], 	origineel: [%s]\n", str1, str);
	//printf("ft_strdup: %s mem: %p \n", str, &(str[0]));
	return (0);
}
