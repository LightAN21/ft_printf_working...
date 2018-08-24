/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deal_int.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtsai <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/17 10:53:18 by jtsai             #+#    #+#             */
/*   Updated: 2018/08/24 09:43:48 by jtsai            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		max(int a, int b)
{
	if (a < b)
		return (b);
	return (a);
}

void	deal_zero_base(t_var *data, t_max base)
{
	t_max	len;

	len = 1;
	if (data->flag['_'] && (!(data->flag['-']) && (!(data->flag['0']) ||
				(data->flag['0'] && data->flag['.']))))
		save_char(data, data->flag['_'] - max(data->flag['/'], len), 1, ' ');
	if (base == 10 && data->flag['+'])
		data->p[data->k++] = '+';
	if (data->flag['.'] && data->flag['/'] > len)
		save_char(data, data->flag['/'] - len, 0, '0');
	else if (data->flag['0'] && !data->flag['-'] && !data->flag['.'])
		save_char(data, data->flag['_'] - len, 1, '0');
	if (!data->flag['.'] || (data->flag['.'] && data->flag['/']))
		data->p[data->k++] = '0';
	else if (data->flag['_'])
		data->p[data->k++] = ' ';
	else if (base == 8 && data->flag['#'])
		data->p[data->k++] = '0';
	if (data->flag['-'])
		save_char(data, data->flag['_'] - max(data->flag['/'], len), 1, ' ');
}

void	deal_int(t_var *data, t_long num)
{
	t_long	len;
	t_long	i;

	if (num == 0)
		return (deal_zero_base(data, 10));
	i = num;
	len = 1;
	while (i /= 10)
		++len;
	if (num < 0 && !data->flag['+'] && !data->flag[' '])
		data->flag['_']--;
	if (data->flag['_'] && (!(data->flag['-']) && (!(data->flag['0']) ||
				(data->flag['0'] && data->flag['.']))))
		save_char(data, data->flag['_'] - max(data->flag['/'], len), 1, ' ');
	if (data->flag['+'] || num < 0)
		data->p[data->k++] = (num >= 0) ? '+' : '-';
	else if (data->flag[' '])
		data->p[data->k++] = ' ';
	if (data->flag['.'] && data->flag['/'] - len)
		save_char(data, data->flag['/'] - len, 0, '0');
	else if (data->flag['0'] && !data->flag['-'] && !data->flag['.'])
		save_char(data, data->flag['_'] - len, 1, '0');
	save_itoa(data, data->k, num);
	if (data->flag['-'])
		save_char(data, data->flag['_'] - max(data->flag['/'], len), 1, ' ');
}

void	deal_int_base(t_var *data, t_max num, t_max base, char c)
{
	t_max	len;
	t_max	i;

	if (num == 0)
		return (deal_zero_base(data, base));
	i = num;
	len = 1;
	while (i /= base)
		++len;
	if (data->flag['#'] && base != 10)
		len += (base == 16) ? 2 : 1;
	if (data->flag['_'] && !(data->flag['-'] && !(data->flag['0'] ||
				(data->flag['0'] && data->flag['.']))))
		save_char(data, data->flag['_'] - max(data->flag['/'], len), 1, ' ');
	if (data->flag['#'] && (base == 8 || base == 16))
		data->p[data->k++] = '0';
	if (data->flag['#'] && base == 16)
		data->p[data->k++] = (c == 'x') ? 'x' : 'X';
	if (data->flag['.'] && data->flag['/'] > len)
		save_char(data, data->flag['/'] - len, 0, '0');
	else if (data->flag['0'] && !data->flag['-'] && !data->flag['.'])
		save_char(data, data->flag['_'] - len, 1, '0');
	save_itoa_base(data, num, base, c);
	if (data->flag['-'])
		save_char(data, data->flag['_'] - max(data->flag['/'], len), 1, ' ');
}
