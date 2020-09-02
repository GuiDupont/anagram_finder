/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_config.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdupont <gdupont@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/02 22:19:25 by user42            #+#    #+#             */
/*   Updated: 2020/05/07 13:52:37 by gdupont          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

static	void	set_left_align(char const *str, t_conf *conf)
{
	if (conf->symb == 's' && (!conf->dot || conf->precis < 0))
		conf->precis = ft_strlen(conf->str);
	if (conf->width < 0 && (conf->symb == 's' || conf->symb == 'c'))
	{
		conf->width = abs_l(conf->width);
		conf->l_align = 1;
	}
	if (conf->symb != 'p' && conf->symb != 's' && conf->symb != 'c' &&
		conf->symb != '%' && conf->width < 0)
	{
		conf->width = abs_l(conf->width);
		conf->l_align = 1;
	}
	if (find_flag(str, '-') || conf->l_align)
		conf->l_align = 1;
	else if (check_zero(str))
		conf->zero = 1;
	if (conf->symb != 'c' && conf->symb != 's' && conf->symb != '%' &&
	conf->dot == 1)
		conf->zero = 0;
}

static	void	set_str_c(char const *str, va_list *arg, t_conf *conf)
{
	conf->symb = get_symb(str);
	if (conf->symb == 's')
		conf->str = va_arg(*arg, char *);
	if (conf->symb == 'c')
		conf->c = va_arg(*arg, int);
	if (conf->symb == 'p')
		conf->str = ft_ul_to_p((unsigned long)va_arg(*arg, void *));
	if (conf->symb == 'd' || conf->symb == 'i')
		conf->str = ft_itoa(va_arg(*arg, int));
	if (conf->symb == 'x' || conf->symb == 'X')
		conf->str = ft_u_to_x(va_arg(*arg, unsigned int), conf->symb);
	if (conf->symb == 'u')
		conf->str = ft_itoa_u(va_arg(*arg, unsigned int));
	if (conf->str == NULL)
		conf->str = "(null)";
	if (conf->symb != 'c' && conf->symb != 's' && conf->symb != '%'
			&& conf->str[0] == '-')
	{
		conf->neg = 1;
		delete_1st_char(conf->str);
	}
}

static	void	set_width_prec(char const *str, va_list *arg, t_conf *conf)
{
	int		dot_pos;

	set_width(str, conf);
	if ((dot_pos = find_flag(str, '.')))
	{
		if (str[dot_pos - 1] == '*')
			conf->width = va_arg(*arg, int);
		if (str[dot_pos + 1] == '*')
			conf->precis = va_arg(*arg, int);
		else
			conf->precis = ft_atoi(&str[dot_pos + 1]);
		conf->dot = 1;
	}
	else if (ft_find_char(str, '*'))
		conf->width = va_arg(*arg, int);
	if (conf->precis < 0)
	{
		conf->precis = 0;
		conf->dot = 0;
	}
}

static	t_conf	*set_up_conf(char const *str, va_list *arg)
{
	t_conf	*conf;

	if (!(conf = malloc(sizeof(t_conf))))
		return (NULL);
	initialize_conf(conf);
	set_width_prec(str, arg, conf);
	set_str_c(str, arg, conf);
	set_left_align(str, conf);
	return (conf);
}

int				valid_conf(char const *str, va_list *arg, int *pft)
{
	t_conf	*conf;

	conf = set_up_conf(str, arg);
	ft_print_conf(conf, pft);
	free(conf);
	return (is_conf_valid(str) + 1);
}
