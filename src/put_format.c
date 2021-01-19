#include "ft_printf.h"

void		putf_i(int i, t_pft *set, int *ret)
{
	int wid;

	wid = ft_intwid(i, set->base);
	if (i < 0)
		putchar_c('-', ret);
	if (set->f_prec == TRUE && set->prec_width > wid
			&& i < 0)
		set->prec_width += 1;
	if (set->f_prec == TRUE && set->prec_width > wid &&
			(set->zero += TRUE) && (set->width = set->prec_width - wid))
		print_width(set,ret);
	else if (set->width > 0 && set->f_ladjust == FALSE &&
								(set->width -= wid))
		print_width(set, ret);
	putnum_base((long)i, set, ret);
}

void		putf_u(unsigned int i, t_pft *set, int *ret)
{

	int wid;

	wid = ft_intwid((long)i, set->base);
	if (set->width > 0 && set->f_ladjust == FALSE &&
								(set->width -= wid))
		print_width(set, ret);
	u_putnum_base(i, set, ret);
}

void		putf_s(char *s, t_pft *set, int *ret)
{
	int len;
	int chknull;

	if ((chknull = check_null_str(s, set, ret)) == 1)
		return ;
	else if (chknull < 0)
		s = "(null)";
	len = ft_strlen(s);	
	set->zero = FALSE;
	if (set->f_prec && set->prec_width < len)
		len = set->prec_width;
	if (set->f_ladjust == FALSE && set->width > len
			&& (set->width -= len))
		print_width(set, ret);
	write(1, s, len);
	*ret += len;
	if (set->f_ladjust && set->width > len
			&& (set->width -= len))
		print_width(set, ret);
}

void		putf_c(char c, t_pft *set, int *ret)
{
	set->zero = FALSE;
	if (set->width > 0 &&
			set->f_ladjust == FALSE && set->width--)
		print_width(set, ret);
	putchar_c(c, ret);
	set->width--;
	if (set->f_ladjust)
		print_width(set, ret);
}
