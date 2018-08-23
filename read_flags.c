/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_flags.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtsai <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/18 15:53:24 by jtsai             #+#    #+#             */
/*   Updated: 2018/08/23 14:53:57 by jtsai            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	type(int k)
{
	return (k == 's' || k == 'S' || k == 'p' || k == 'd' || k == 'D' || \
			k == 'i' || k == 'o' || k == 'O' || k == 'u' || k == 'U' || \
			k == 'x' || k == 'X' || k == 'c' || k == 'C' || k == '%' || \
			k < 32);
}

void	init_flags(t_var *data)
{
	int	j;

	j = 31;
	while (++j < 50)
		data->flag[j] = 0;
	data->flag['_'] = 0;
	data->flag['h'] = 0;
	data->flag['H'] = 0;
	data->flag['l'] = 0;
	data->flag['L'] = 0;
	data->flag['j'] = 0;
	data->flag['z'] = 0;
}

int	read_flags(t_var *data, char *s, int i)
{
	init_flags(data);
	if (type(s[i]))
		return (i);
	while (!type(s[i]) && s[i])
	{
		if ('1' <= s[i] && s[i] <= '9')
			data->flag['_'] = re_atoi(s + i, &i);
		else if (s[i] == '.' && '1' <= s[i + 1] && s[i + 1] <= '9')
		{
			data->flag['.'] = 1;
			data->flag['/'] = re_atoi(s + (++i), &i);
		}
		else if (s[i] == 'h' && s[i + 1] == 'h')
		{
			data->flag['H'] += 1;
			i += 2;
		}
		else if (s[i] < 127)
			data->flag[(t_max)s[i++]] += 1;
		else
			i++;
	}
	return (i);
}
