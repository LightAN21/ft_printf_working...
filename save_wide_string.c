/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save_wide_string.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtsai <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/23 16:30:50 by jtsai             #+#    #+#             */
/*   Updated: 2018/08/23 17:13:42 by jtsai            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	save_wide_char(t_var *data, wchar_t wc)
{
	if (wc <= 0x7F)
		data->p[data->k++] = wc;
	else if (wc <= 0x7FF)
	{
		data->p[data->k++] = ((wc >> 6) + 0xC0);
		data->p[data->k++] = ((wc & 0x3F) + 0x80);
	}
	else if (wc <= 0xFFFF)
	{
		data->p[data->k++] = ((wc >> 12) + 0xE0);
		data->p[data->k++] = (((wc >> 6) & 0x3F) + 0x80);
		data->p[data->k++] = ((wc & 0x3F) + 0x80);
	}
	else if (wc <= 0x10FFFF)
	{
		data->p[data->k++] = ((wc >> 18) + 0xF0);
		data->p[data->k++] = (((wc >> 12) & 0x3F) + 0x80);
		data->p[data->k++] = (((wc >> 6) & 0x3F) + 0x80);
		data->p[data->k++] = ((wc & 0x3F) + 0x80);
	}
}

void	save_wide_string(t_var *data, wchar_t *ws)
{
	t_max	i;

	if (ws)
	{
		i = 0;
		while (ws[i] != 0)
			save_wide_char(data, ws[i++]);
	}
}
