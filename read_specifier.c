/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_specifier.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtsai <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/23 08:05:49 by jtsai             #+#    #+#             */
/*   Updated: 2018/08/23 16:45:35 by jtsai            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	type_di(t_var *data, char type);
void	type_oux(t_var *data, char type, t_max base);

int		read_specifier(t_var *data, char type, int i)
{
	if (type == 's')
		deal_str(data, va_arg(data->args, char *));
	else if (type == 'c' || type == '%')
		deal_char(data, (type - '%') ? (char)va_arg(data->args, int) : '%');
	else if (type == 'd' || type == 'i' || type == 'D')
		type_di(data, type);
	else if (type == 'u' || type == 'U')
		type_oux(data, type, 10);
	else if (type == 'o' || type == 'O')
		type_oux(data, type, 8);
	else if (type == 'x' || type == 'X' || type == 'p')
		type_oux(data, type, 16);
	else if (type == 'C')
		save_wide_char(data, va_arg(data->args, wchar_t));
	else if (type == 'S')
		save_wide_string(data, va_arg(data->args, wchar_t *));
	else if (type < 32)
		i--;
	return (i);
}

void	type_di(t_var *data, char type)
{
	if (type == 'D' || data->flag['l'] || data->flag['j'] ||
			data->flag['t'] || data->flag['z'])
		deal_int(data, va_arg(data->args, t_long));
	else if (data->flag['h'])
		deal_int(data, (short)va_arg(data->args, int));
	else if (data->flag['H'])
		deal_int(data, (char)va_arg(data->args, int));
	else
		deal_int(data, va_arg(data->args, int));
}

void	type_oux(t_var *data, char type, t_max base)
{
	if (type == 'p')
		data->flag['#'] = 1;
	if (type == 'U' || type == 'O' || type == 'p' || data->flag['l'] || data->flag['j'])
		deal_int_base(data, va_arg(data->args, t_max), base, type);
	else if (data->flag['t'] || data->flag['z'])
		deal_int_base(data, va_arg(data->args, t_long), base, type);
	else if (data->flag['h'])
		deal_int_base(data, (unsigned short)va_arg(data->args, int), base, type);
	else if (data->flag['H'])
		deal_int_base(data, (unsigned char)va_arg(data->args, int), base, type);
	else
		deal_int_base(data, va_arg(data->args, unsigned int), base, type);
}