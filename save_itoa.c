/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save_itoa.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtsai <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/17 08:20:42 by jtsai             #+#    #+#             */
/*   Updated: 2018/08/23 15:29:45 by jtsai            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	save_itoa(t_var *data, int k, t_long num)
{
	t_long	len;
	t_long	tmp;

	tmp = num;
	len = 1;
	while (tmp /= 10)
		++len;
	data->k += len;
	if (num >= 0)
		tmp++;
	else
		tmp--;
	while (--len > 0)
	{
		data->p[k + len] = '0' + tmp * (num % 10);
		num /= 10;
	}
	if (data->flag['_'] && !data->flag['/'] && num == 0)
		data->p[k] = ' ';
	else
		data->p[k] = '0' + num * tmp;
}

void	save_itoa_u(t_var *data, int k, t_max num)
{
	t_max	len;
	t_max	tmp;

	tmp = num;
	len = 1;
	while (tmp /= 10)
		++len;
	data->k += len + (num == 0);
	if (num == 0)
		data->p[k] = '0';
	while (len != 0)
	{
		data->p[k + (--len)] = '0' + (num % 10);
		num /= 10;
	}
}
