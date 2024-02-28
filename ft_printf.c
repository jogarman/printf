/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgarcia3 <jgarcia3@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 20:48:00 by jgarcia3          #+#    #+#             */
/*   Updated: 2024/02/28 02:30:38 by jgarcia3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
/*
cc -Wextra -Werror -Wall *.c ./libft/asterisco.c
*/
/*
v  %c Imprime un solo carácter.
v  %s Imprime una string (como se define por defecto en C).
  **%p El puntero void * dado como argumento se imprime en formato hexadecimal.
v %d Imprime un número decimal (base 10).
• %i Imprime un entero en base 10.
• %u Imprime un número decimal (base 10) sin signo.
• %x Imprime un número hexadecimal (base 16) en minúsculas.
• %X Imprime un número hexadecimal (base 16) en mayúsculas.
• % % para imprimir el símbolo del porcentaje.
*/

//static void ft_change_base();

static int	ft_which_format(char c, va_list argument)
{
	char	*s;

	s = NULL;
	if (c == 'c')
		return(wf_char(va_arg(argument, int)));
	else if (c == 's')
		return(wf_str(va_arg(argument, char *)));
	else if (c == 'd' || c == 'i')
		return(wf_int(va_arg(argument, int)));
	else if (c =='u')
		return(wf_unsg(va_arg(argument, unsigned int)));
	else if (c == 'x')
		return(wf_x_lw(va_arg(argument, int)));
	else if (c == 'X')
		return(wf_x_up(va_arg(argument, int)));
	else if (c == 'p')
		return(wf_ptr((va_arg(argument, long))));
	return (-1);
}

int	ft_printf(char const *str, ...)
{
	va_list args;
	int		i;
	int		n_charact;

	n_charact = 0;
	i = 0;
	va_start(args, str);
	while (str[i]) //&& (str[i - 1] == '%' && str[i + 1] == '\0')) No funciona
	{
		if (str[i] != '%')
		{
			if ((i == 0) || (i >= 1 && str[i - 1] != '%')) // CAMBIAR?
			{
				write(1, &str[i], 1);
				n_charact++;
				//printf("n_caracter1: %d", n_charact);
			}
		}
		else if(str[i + 1])
		{
			if (str[i + 1] == '%')
			{
				write(1, "%", 1);
				n_charact++;
				//printf("n_caracter2: %d", n_charact);
			}
			else
			{
				n_charact += ft_which_format(str[i + 1], args);
				//printf("n_caracter3: %d", n_charact);
			}
		}
		i++;
	}
	return (n_charact);
}
/*
int main()
{
	//char	*ptr = "hola";
	//unsigned int = 6;
	char	*s1="'%d%%', 5";

	//ft_printf("Numero %d", 7);
	printf("\n%d\n", ft_printf("c:%c", 'C')); //+1
	printf("\n%d\n", ft_printf("str:%s", "caca")); // +1
	printf("\n%d\n", ft_printf("str:%d", 4242)); // bien
	printf("\n%d\n", ft_printf("str:%i", 4242)); // bien
	printf("\n%d\n", ft_printf("str:%u", 4242)); // bien
	printf("\n%d\n", ft_printf("h:%x", 17)); //+1
	printf("\n%d\n", ft_printf("H:%X", -1)); //+1
	printf("\n%d\n", ft_printf("por%%")); //bien
	////////////////////
	printf("\n%d\n", ft_printf("ptr%p", &s1)); //BIEN!
	printf("\n%d\n", printf("ptr%p", &s1)); //TEST


	printf("\n%d\n", ft_printf("%d%%", 5)); //bien

	//ft_printf("La dirección del puntero es: %", 2147483647);
	//printf("\nHex: %x", 1234);
}
*/
/*
v  %c Imprime un solo carácter.
v  %s Imprime una string (como se define por defecto en C).
v %d Imprime un número decimal (base 10).
• %i Imprime un entero en base 10.
• %u Imprime un número decimal (base 10) sin signo.
• %x Imprime un número hexadecimal (base 16) en minúsculas.
• %X Imprime un número hexadecimal (base 16) en mayúsculas.
  **%p El puntero void * dado como argumento se imprime en formato hexadecimal.
• % % para imprimir el símbolo del porcentaje.
*/