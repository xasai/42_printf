#ifndef FT_PRINTF_H
# define FT_PRINTF_H
#include <stdio.h>
#include <unistd.h> 
#include <stdarg.h>
#include <stdlib.h>
#include "libft.h"
# ifndef TRUE
#  define TRUE 1
#  define FALSE 0
# endif
# define ARR_BASE "0123456789abcdef0123456789ABCDEF"
typedef long long int ll;
typedef unsigned long long int ull;
typedef struct	s_pft
{
	int			ladjust;
	int			f_prec;
	int			capital;
	int			zero;
	int			space;
	int			plus;
	int			sharp;
	int			prec;
	int			width;
	char		prefix[2];
	int			base;
}				t_pft;

int				ft_printf(const char *format, ...);
int				start_pf(const char *format, va_list *argp);
//int				check_null_str(char *s, t_pft *set, int *ret);
void			putchar_c(char c, int *ret);
void			putnum_base(ll i, t_pft *set, int *ret);
void			u_putnum_base(ull i, t_pft *set, int *ret);
void			print_width(t_pft *set, int *ret);
void			do_print(const char **format, va_list *argp, t_pft *set, int *ret);
void			putf_i(int i, t_pft *set, int *ret);
void			putf_u(ull i, t_pft *set, int *ret);
void			putf_s(char *s, t_pft *set, int *ret);
void			putf_c(char c, t_pft *set, int *ret);
void			putf_p(void *p, t_pft *set, int *ret);
void			putf_x(t_pft *set, int *ret);
void			get_flags(const char **format, va_list *argp, t_pft *set);
void			get_set(const char **format, va_list *argp, t_pft *set);
void			bonus(const char **format, va_list *argp, t_pft *set, int *ret);

#endif
