#ifndef LIBFT_H_
# define LIBFT_H_
#include <stdlib.h>

typedef unsigned long size_t;

void ft_bzero(void *s, size_t n);
char *ft_strchr(const char *str, int ch);
char *ft_strrchr(const char *str, int ch);
int ft_strncmp(char *str1, char *str2);
char *ft_srtdup(char *dest, const char *src);
int ft_isalpha(int ch);
int ft_isascii(int ch);
int ft_isdigit(int ch);
int ft_tolower(int ch);
int ft_toupper(int ch);

int ft_abs(int num);
div_t ft_div(int numerator, int denominator);
void *ft_memset(void *buf, int ch, size_t count);
void *ft_memcpy(void *dest, const void *source, size_t count);
int ft_memcmp(void *buf1, const void *buf2, size_t count);
char *ft_strnstr(const char *s, const char *find, size_t slen);
char *ft_strjoin(const char *s1, const char *s2);
char *ft_strtrim(const char *s);
void ft_striter(char *s, void (*f)(char *));
char *ft_strstr(const char *s, const char *find);
char **ft_strsplit(const char *s,char c);

int ft_strlen(const char *str);


#endif