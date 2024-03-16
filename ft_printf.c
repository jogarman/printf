/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgarcia3 <jgarcia3@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 20:48:00 by jgarcia3          #+#    #+#             */
/*   Updated: 2024/03/12 21:08:29 by jgarcia3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_which_format(char c, va_list argument)
{
	char	*s;

	s = NULL;
	if (c == 'c')
		return (wf_char(va_arg(argument, int)));
	else if (c == 's')
		return (wf_str(va_arg(argument, char *)));
	else if (c == 'd' || c == 'i')
		return (wf_int(va_arg(argument, int)));
	else if (c == 'u')
		return (wf_unsg(va_arg(argument, unsigned int)));
	else if (c == 'x')
		return (wf_x_lw(va_arg(argument, unsigned int)));
	else if (c == 'X')
		return (wf_x_up(va_arg(argument, unsigned int)));
	else if (c == 'p')
		return (wf_ptr(va_arg(argument, size_t)));
	return (0);
}

static void	aux(char *ptr, int *n_charact)
{
	write(1, ptr, 1);
	*n_charact += 1;
}

int	ft_printf(char const *str, ...)
{
	va_list	args;
	int		i;
	int		n_charact;

	n_charact = 0;
	i = 0;
	va_start(args, str);
	while (str[i])
	{
		if (str[i] != '%')
			aux((char *)&str[i], &n_charact);
		else if (str[i + 1])
		{
			if (str[i] == '%' && str[i + 1] == '%')
			{
				write(1, "%", 1);
				n_charact++;
			}
			else
				n_charact += ft_which_format(str[i + 1], args);
			i++;
		}
		i++;
	}
	return (n_charact);
}

/* #include <limits.h>
int main()
{
    printf("\n%d\n", printf("\001\002\007\v\010\f\r\n"));
	printf("%d", ft_printf("\001\002\007\v\010\f\r\n"));
} */
/*
It should return -1 if write() fails, but  it is not mandatory for the exercice
 */
/*
	////simple debugger:
	//ft_printf("Numero %d", 7);
	printf("\n%d\n", ft_printf("c:%c", 'C')); //bien
	printf("\n%d\n", ft_printf("str:%s", "caca")); // bien
	printf("\n%d\n", ft_printf("str:%d", 4242)); // bien
	printf("\n%d\n", ft_printf("str:%i", 4242)); // bien
	printf("\n%d\n", ft_printf("str:%u", 4242)); // bien
	printf("\n%d\n", ft_printf("h:%x", 17)); //bien
	printf("\n%d\n", ft_printf("H:%X", -1)); //bien
	printf("\n%d\n", ft_printf("por%%")); //bien

	printf("\n%d\n", ft_printf("ptr%p", &s1)); //BIEN!
	// Estrict: %s
	printf("\n8:\n");
	printf("\n%d\n", ft_printf("str:%s", "CACA"));
	printf("\n8:\n");
	printf("\n%d\n", ft_printf("%sstr:", "CACA"));
	printf("\n8:\n");
	printf("\n%d\n", ft_printf("st%sr:", "CACA"));
	printf("\n12:\n");
	printf("\n%d\n", ft_printf("%sstr:%s", "CACA", "Caca"));
	printf("\n???: error?\n");

	//// Estrict: %x
	printf("\n4:\n");
	printf("\n%d\n", ft_printf("::%x", 17));
	printf("\n4:\n");
	printf("\n%d\n", ft_printf("%x::", 17));
	printf("\n4:\n");
	printf("\n%d\n", ft_printf(":%x:", 17));
	printf("\n5:\n");
	printf("\n%d\n", ft_printf("%xh:%x", 17, 9));
	printf("\n7:\n");
	printf("\n%d\n", ft_printf("%x:%x:%x", 17, 9, 79));
	printf("\n%d\n", printf("%x:%x:%x", 17, 9, 79));

	///Estrict: %X
	printf("\n4:\n");
	printf("\n%d\n", ft_printf("::%X", 17));
	printf("\n4:\n");
	printf("\n%d\n", ft_printf("%X::", 17));
	printf("\n4:\n");
	printf("\n%d\n", ft_printf(":%X:", 17));
	printf("\n5:\n");
	printf("\n%d\n", ft_printf("%Xh:%X", 17, 9, 6));
	printf("\n7:\n");
	printf("\n%d\n", ft_printf("%X:%X:%X", 17, 9, 79));
	printf("\n%d\n", printf("%X:%X:%X", 17, 9, 79));


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