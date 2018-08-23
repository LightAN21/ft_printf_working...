/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtsai <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/14 14:30:23 by jtsai             #+#    #+#             */
/*   Updated: 2018/08/23 16:48:12 by jtsai            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <unistd.h>
#include <stdio.h>
#include <locale.h>

void	ft_putwchar(char c)
{
	write(1, &c, 1);
}

void	ft_putwc(wchar_t wc)
{
	if (wc <= 0x7F)
		ft_putwchar(wc);
	else if (wc <= 0x7FF)
	{
		ft_putwchar((wc >> 6) + 0xC0);
		ft_putwchar((wc & 0x3F) + 0x80);
	}
	else if (wc <= 0xFFFF)
	{
		ft_putwchar((wc >> 12) + 0xE0);
		ft_putwchar(((wc >> 6) & 0x3F) + 0x80);
		ft_putwchar((wc & 0x3F) + 0x80);
	}
	else if (wc <= 0x10FFFF)
	{
		ft_putwchar((wc >> 18) + 0xF0);
		ft_putwchar(((wc >> 12) & 0x3F) + 0x80);
		ft_putwchar(((wc >> 6) & 0x3F) + 0x80);
		ft_putwchar((wc & 0x3F) + 0x80);
	}
}

int	main(int ac, char **av)
{
	int		i;
	int		d;
	char	s[100000];

	ac += 0;
	av[0][0] += 0;
	//--------------------Settings--------------------------------
	d = 54321;
/*
	i = -1;
	while (++i < 12345)
		s[i] = '0' + i % 10;
	s[i] = '\0';
*/
	//--------------------Testcase---------------------------------

	ft_printf("%d\n", -42);
	printf("%d\n", -42);
//	printf("%zd\n", (size_t)-0);




/*
	d = -42;

	printf("%5hhd\n", 300);
	ft_putwc(L'我');
	printf("\n");
	printf("%d\n", L'我');
*/


/*
	wchar_t	*w;
	w = L"你是豬嗎";

	char	*k;

	k = (char *)w;
	i = -1;
	while (++i < 4)
		printf("%d\n", w[i]);
	printf("----------------------\n");
	printf("%s\n", k);
	printf("\n-----------\n");
	printf("%ls\n", L"我是豬嗎");
	printf("-----------\n");

	k = setlocale(LC_ALL, "");

	printf("k: %s\n", k);
	printf("===========\n");
	write(1, w, 32);
	printf("------------\n");
	printf("%ls\n", L"我是豬嗎");
	printf("%lc\n", 20320);
*/



// ----------
	/*
	char *x;

	x = va_arg(variable, wchar_t)

		write(1, x, 3);
*/


/*
	char *str;
	str = "你是豬12345";

	i = -1;
	while (++i < 14)
		printf("%d\n", str[i]);
*/

//	ft_printf("%x\n", d);

/*	
	printf("%#x\n", 0);
	printf("%#.0x\n", 0);
	printf("%.0x\n", 0);

	printf("%#o\n", 0);
	printf("%#.0o\n", 0);
	printf("%.0o\n", 0);
*/

/*
	printf("%x\n", (int)d);
	printf("%x\n", (int)(~0) + d + 1);
	printf("%x\n", (unsigned int)d);

	printf("%lx\n", (long int)d);
	printf("%lx\n", (long int)(~0) + d + 1);
	printf("%lx\n", (unsigned long int)d);

	d = 4294967295;
	printf("%x\n", d);
	printf("%x\n", (int)d);
	printf("%x\n", (int)(~0) + d + 1);
	printf("%x\n", (unsigned int)d);
*/

/*
	printf("%hhlhd\n", 18446744073709551615);
	printf("%ld\n", 18446744073709551615);
	printf("%hd\n", 18446744073709551615);
	printf("%lhhhd\n", 9223372036854775807);
	printf("%lhlhuhd\n", 18446744073709551615);
*/








		d = 54321;
	/*
	   ft_printf("ft_printf:\n\n");
	   ft_printf("%%123 %s %s%s!\n", NULL, "abc", " start");
	   ft_printf("你是豬\n");
	   ft_printf("00 %d\n", 0);
	   ft_printf("01 %d\n", d);
	   ft_printf("02 %0d\n", d);
	   ft_printf("03 %-d\n", d);
	   ft_printf("04 %+d\n", d);
	   ft_printf("05 % d\n", d);

	   ft_printf("06 %0-d\n", d);
	   ft_printf("07 %0+d\n", d);
	   ft_printf("08 %0 d\n", d);
	   ft_printf("09 %-+d\n", d);
	   ft_printf("10 %- d\n", d);
	   ft_printf("11 %+ d\n", d);

	   ft_printf("12 %0-+d\n", d);
	   ft_printf("13 %0- d\n", d);
	   ft_printf("14 %0+ d\n", d);
	   ft_printf("15 %-+ d\n", d);
	   ft_printf("16 %0-+ d\n", d);

	   ft_printf("21 %10d\n", d);
	   ft_printf("22 %010d\n", d);
	   ft_printf("23 %-10d\n", d);
	   ft_printf("24 %+10d\n", d);
	   ft_printf("25 % 10d\n", d);

	   ft_printf("26 %0-10d\n", d);
	   ft_printf("27 %0+10d\n", d);
	   ft_printf("28 %0 10d\n", d);
	   ft_printf("29 %-+10d\n", d);
	   ft_printf("30 %- 10d\n", d);
	   ft_printf("31 %+ 10d\n", d);

	   ft_printf("32 %0-+10d\n", d);
	   ft_printf("33 %0- 10d\n", d);
	   ft_printf("34 %0+ 10d\n", d);
	   ft_printf("35 %-+ 10d\n", d);
	   ft_printf("36 %0-+ 10d\n", d);

	   ft_printf("41 %10.7d\n", d);
	   ft_printf("42 %010.7d\n", d);
	   ft_printf("43 %-10.7d\n", d);
	   ft_printf("44 %+10.7d\n", d);
	   ft_printf("45 % 10.7d\n", d);

	   ft_printf("46 %0-10.7d\n", d);
	   ft_printf("47 %0+10.7d\n", d);
	   ft_printf("48 %0 10.7d\n", d);
	   ft_printf("49 %-+10.7d\n", d);
	   ft_printf("50 %- 10.7d\n", d);
	   ft_printf("51 %+ 10.7d\n", d);

	   ft_printf("52 %0-+10.7d\n", d);
	   ft_printf("53 %0- 10.7d\n", d);
	   ft_printf("54 %0+ 10.7d\n", d);
	   ft_printf("55 %-+ 10.7d\n", d);
	   ft_printf("56 %0-+ 10.7d\n", d);

	   d = -d;
	   ft_printf("\nft_printf negtive_number:\n\n");
	   ft_printf("01 %d\n", d);
	   ft_printf("02 %0d\n", d);
	   ft_printf("03 %-d\n", d);
	   ft_printf("04 %+d\n", d);
	   ft_printf("05 % d\n", d);

	   ft_printf("06 %0-d\n", d);
	ft_printf("07 %0+d\n", d);
	ft_printf("08 %0 d\n", d);
	ft_printf("09 %-+d\n", d);
	ft_printf("10 %- d\n", d);
	ft_printf("11 %+ d\n", d);

	ft_printf("12 %0-+d\n", d);
	ft_printf("13 %0- d\n", d);
	ft_printf("14 %0+ d\n", d);
	ft_printf("15 %-+ d\n", d);
	ft_printf("16 %0-+ d\n", d);

	ft_printf("21 %10d\n", d);
	ft_printf("22 %010d\n", d);
	ft_printf("23 %-10d\n", d);
	ft_printf("24 %+10d\n", d);
	ft_printf("25 % 10d\n", d);

	ft_printf("26 %0-10d\n", d);
	ft_printf("27 %0+10d\n", d);
	ft_printf("28 %0 10d\n", d);
	ft_printf("29 %-+10d\n", d);
	ft_printf("30 %- 10d\n", d);
	ft_printf("31 %+ 10d\n", d);

	ft_printf("32 %0-+10d\n", d);
	ft_printf("33 %0- 10d\n", d);
	ft_printf("34 %0+ 10d\n", d);
	ft_printf("35 %-+ 10d\n", d);
	ft_printf("36 %0-+ 10d\n", d);

	ft_printf("41 %10.7d\n", d);
	ft_printf("42 %010.7d\n", d);
	ft_printf("43 %-10.7d\n", d);
	ft_printf("44 %+10.7d\n", d);
	ft_printf("45 % 10.7d\n", d);

	ft_printf("46 %0-10.7d\n", d);
	ft_printf("47 %0+10.7d\n", d);
	ft_printf("48 %0 10.7d\n", d);
	ft_printf("49 %-+10.7d\n", d);
	ft_printf("50 %- 10.7d\n", d);
	ft_printf("51 %+ 10.7d\n", d);

	ft_printf("52 %0-+10.7d\n", d);
	ft_printf("53 %0- 10.7d\n", d);
	ft_printf("54 %0+ 10.7d\n", d);
	ft_printf("55 %-+ 10.7d\n", d);
	ft_printf("56 %0-+ 10.7d\n", d);

	printf("---------------------------------------------------\n");
	d = -d;
	printf("printf:\n\n");
	printf("你是豬\n");
	printf("00 %d\n", 0);
	printf("01 %d\n", d);
	printf("02 %0d\n", d);
	printf("03 %-d\n", d);
	printf("04 %+d\n", d);
	printf("05 % d\n", d);

	printf("06 %0-d\n", d);
	printf("07 %0+d\n", d);
	printf("08 %0 d\n", d);
	printf("09 %-+d\n", d);
	printf("10 %- d\n", d);
	printf("11 %+ d\n", d);

	printf("12 %0-+d\n", d);
	printf("13 %0- d\n", d);
	printf("14 %0+ d\n", d);
	printf("15 %-+ d\n", d);
	printf("16 %0-+ d\n", d);

	printf("21 %10d\n", d);
	printf("22 %010d\n", d);
	printf("23 %-10d\n", d);
	printf("24 %+10d\n", d);
	printf("25 % 10d\n", d);

	printf("26 %0-10d\n", d);
	printf("27 %0+10d\n", d);
	printf("28 %0 10d\n", d);
	printf("29 %-+10d\n", d);
	printf("30 %- 10d\n", d);
	printf("31 %+ 10d\n", d);

	printf("32 %0-+10d\n", d);
	printf("33 %0- 10d\n", d);
	printf("34 %0+ 10d\n", d);
	printf("35 %-+ 10d\n", d);
	printf("36 %0-+ 10d\n", d);

	printf("41 %10.7d\n", d);
	printf("42 %010.7d\n", d);
	printf("43 %-10.7d\n", d);
	printf("44 %+10.7d\n", d);
	printf("45 % 10.7d\n", d);

	printf("46 %0-10.7d\n", d);
	printf("47 %0+10.7d\n", d);
	printf("48 %0 10.7d\n", d);
	printf("49 %-+10.7d\n", d);
	printf("50 %- 10.7d\n", d);
	printf("51 %+ 10.7d\n", d);

	printf("52 %0-+10.7d\n", d);
	printf("53 %0- 10.7d\n", d);
	printf("54 %0+ 10.7d\n", d);
	printf("55 %-+ 10.7d\n", d);
	printf("56 %0-+ 10.7d\n", d);

	d = -d;
	printf("\nprintf negtive_number:\n\n");
	printf("01 %d\n", d);
	printf("02 %0d\n", d);
	printf("03 %-d\n", d);
	printf("04 %+d\n", d);
	printf("05 % d\n", d);

	printf("06 %0-d\n", d);
	printf("07 %0+d\n", d);
	printf("08 %0 d\n", d);
	printf("09 %-+d\n", d);
	printf("10 %- d\n", d);
	printf("11 %+ d\n", d);

	printf("12 %0-+d\n", d);
	printf("13 %0- d\n", d);
	printf("14 %0+ d\n", d);
	printf("15 %-+ d\n", d);
	printf("16 %0-+ d\n", d);

	printf("21 %10d\n", d);
	printf("22 %010d\n", d);
	printf("23 %-10d\n", d);
	printf("24 %+10d\n", d);
	printf("25 % 10d\n", d);

	printf("26 %0-10d\n", d);
	printf("27 %0+10d\n", d);
	printf("28 %0 10d\n", d);
	printf("29 %-+10d\n", d);
	printf("30 %- 10d\n", d);
	printf("31 %+ 10d\n", d);

	printf("32 %0-+10d\n", d);
	printf("33 %0- 10d\n", d);
	printf("34 %0+ 10d\n", d);
	printf("35 %-+ 10d\n", d);
	printf("36 %0-+ 10d\n", d);

	printf("41 %10.7d\n", d);
	printf("42 %010.7d\n", d);
	printf("43 %-10.7d\n", d);
	printf("44 %+10.7d\n", d);
	printf("45 % 10.7d\n", d);

	printf("46 %0-10.7d\n", d);
	printf("47 %0+10.7d\n", d);
	printf("48 %0 10.7d\n", d);
	printf("49 %-+10.7d\n", d);
	printf("50 %- 10.7d\n", d);
	printf("51 %+ 10.7d\n", d);

	printf("52 %0-+10.7d\n", d);
	printf("53 %0- 10.7d\n", d);
	printf("54 %0+ 10.7d\n", d);
	printf("55 %-+ 10.7d\n", d);
	printf("56 %0-+ 10.7d\n", d);

	*/


		//---------------------------------------------------------------
		//	printf("%.10800000000d\n", d); //%.10700000000d can print out zeros
		return (0);
}
