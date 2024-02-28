/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convertor.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgarcia3 <jgarcia3@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 01:00:48 by jgarcia3          #+#    #+#             */
/*   Updated: 2024/02/28 02:15:18 by jgarcia3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	num_len(int n)
{
	long	j;
	int		len;
	int		neg;

	neg = 0;
	j = 1;
	len = 0;
	while ((long)n / j != 0)
	{
		j *= 10;
		len ++;
	}
	if (n < 0)
		len++;
	if (n == 0)
		len = 1;
	return (len);
}

int		wf_char(char a)
{
	return(ft_putchar_fd(a, 1), 1);
}
int		wf_str(char * a)
{
	write(1, a, ft_strlen(a));
	return(ft_strlen(a));
}
int	wf_int(int a)
{
	ft_putnbr_fd((a), 1);
	return (num_len(a));
}

int 	wf_unsg(unsigned int a)
{
	return(ft_putunsgnbr_fd(a, 1), 1);
}

int		wf_x_lw(int a)
{
	//printf("\n-%d-\n", ft_dec_to_hex(a, 0));
	return(ft_dec_to_hex(a, 0));
}
int		wf_x_up(int a)
{
	return(ft_dec_to_hex(a, 1));
}
int		wf_ptr(long a)
{
	write(1, "0x", 2);
	return(ft_dec_to_hex(a, 0) + 2);
}