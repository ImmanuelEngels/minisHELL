/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imengels <imengels@student.42vienna.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 16:38:57 by imengels          #+#    #+#             */
/*   Updated: 2025/05/07 16:38:59 by imengels         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include "./bonus/libft_list.h"
# include "./gnl/get_next_line.h"
# include "./limit/libft_limit.h"
# include <stdbool.h>
# include <stddef.h>
# include <stdlib.h>
# include <unistd.h>

typedef bool			t_table[256];
typedef unsigned int	t_utable[256];

/*		FT_IS			*/
int						ft_isalpha(int c);
int						ft_isdigit(int c);
int						ft_isalnum(int c);
int						ft_isascii(int c);
int						ft_isprint(int c);
int						ft_isspace(int n);
/*______________________________________*/

/*		FT_MEM			*/
void					*ft_memset(void *s, int c, size_t n);
void					*ft_memcpy(void *dest, const void *src, size_t n);
void					*ft_memmove(void *dest, const void *src, size_t n);
void					*ft_memchr(const void *s, int c, size_t n);
int						ft_memcmp(const void *s1, const void *s2, size_t n);
void					ft_bzero(void *s, size_t n);
void					*ft_calloc(size_t nmemb, size_t size);
/*______________________________________*/

/*		FT_STR_MLC		*/
char					*ft_strdup(const char *s);
char					*ft_insertsubstr(char *src, char *insert, size_t i_len, size_t pos);
char					*ft_delsubstr(char *src, char *del, size_t d_len, size_t pos);
char					*ft_substr(char const *s, unsigned int start,
							size_t len);
char					*ft_strjoin(char const *s1, char const *s2);
char					*ft_strtrim(char const *s1, char const *set);
char					*ft_strmapi(char const *s, char (*f)(unsigned int,
								char));
char					**ft_split(char const *s, char c);
/*______________________________________*/

/*		FT_STR_UTIL		*/
size_t					ft_strlen(const char *s);
size_t					ft_strlcpy(char *dst, const char *src, size_t size);
size_t					ft_strlcat(char *dst, const char *src, size_t size);
char					*ft_strchr(const char *s, int c);
char					*ft_strrchr(const char *s, int c);
char					*ft_strnstr(const char *big, const char *little,
							size_t len);
void					ft_striteri(char *s, void (*f)(unsigned int, char *));
int						ft_strncmp(const char *s1, const char *s2, size_t n);
/*______________________________________*/

/*		FT_TO			*/
int						ft_toupper(int c);
int						ft_tolower(int c);
/*______________________________________*/

/*		FT_CONVERT		*/
int						ft_atoi(const char *nptr);
char					*ft_itoa(int n);
/*______________________________________*/

/*		FT_PUT_FD		*/
void					ft_putchar_fd(char c, int fd);
void					ft_putstr_fd(char *s, int fd);
void					ft_putendl_fd(char *s, int fd);
void					ft_putnbr_fd(int n, int fd);
/*______________________________________*/

/*		ft_table.c		*/
bool					ft_is_table(int c, t_table table);
void					ft_set_table(const char *set, t_table *table);
unsigned int			ft_get_utable(int c, t_utable table);
void					ft_set_utable(const char *set, t_utable *table);
void					ft_add_utable(const char *set, t_utable *table);
/*______________________________________*/

/*		ft_free_null.c		*/
void					*ft_close(int *fd);
void					*ft_free2(void **ptr1, void **ptr3);
void					*ft_free(void **ptr1);
void					*ft_free_arr(char **arr);
void					*ft_free_intarr(int **arr);
/*______________________________________*/

/*		ft_arr.c		*/
void					ft_putarr_fd(char **arr, int fd);
size_t					ft_arrlen(char **arr);
char					**ft_append_arr(char **arr, char *str);
char					**ft_arrdup(char **arr);
void					ft_arrcpy(char **dest, char **src);

/*______________________________________*/

/*		ft_str_checks.c		*/
size_t					ft_str_contains(char *str, char *set);
bool					ft_str_is_of(char *str, char *set);
bool					ft_str_contains_exact(char *str, char *set);
/*______________________________________*/

/*		ft_arr_checks.c		*/
size_t					ft_arr_contains(char **arr, char *set);
bool					ft_arr_is_of(char **arr, char *set);
bool					ft_arr_contains_exact(char **arr, char *set);
void					ft_arr_get_pos(int *x, int *y, char **arr, char f);
/*______________________________________*/

/*		ft_str_f.c		*/
char					*ft_str_find_f(char *str, bool (*f)(int c));
size_t					ft_str_count_f(char *str, bool (*f)(int c));
void					ft_str_convert_f(char *str, int (*f)(int c));
bool					ft_str_any_f(char *str, bool (*f)(int c));
bool					ft_str_is_f(char *str, bool (*f)(int c));
/*______________________________________*/

/*		ft_arr_f.c		*/
char					*ft_arr_find_f(char **arr, bool (*f)(int c));
size_t					ft_arr_count_f(char **arr, bool (*f)(int c));
void					ft_arr_convert_f(char **arr, int (*f)(int c));
bool					ft_arr_any_f(char **arr, bool (*f)(int c));
bool					ft_arr_is_f(char **arr, bool (*f)(int c));
/*______________________________________*/

#endif
