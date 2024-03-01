/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgarcia3 <jgarcia3@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 20:48:00 by jgarcia3          #+#    #+#             */
/*   Updated: 2024/03/01 15:27:37 by jgarcia3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
/*
cc -Wextra -Werror -Wall *.c ./libft/asterisco.c
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
		return(wf_x_lw(va_arg(argument, unsigned int)));
	else if (c == 'X')
		return(wf_x_up(va_arg(argument, unsigned int)));
	else if (c == 'p')
		return(wf_ptr(va_arg(argument, size_t)));
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

/* #include <limits.h>
int main()
{
    printf("\n%d\n", printf(" %x ", LONG_MAX));
	printf("\n%d\n", ft_printf(" %x ", LONG_MAX));
} */
/*
	Paco no pasa el test 24, 25, 27 y 29 por esto. Pero la función original no puede compilar sin un casteo a void *.
	Mi funcion funcion con el casteo y sin el casteo, luego está mejor.
    printf("\n%d\n", printf(" %p ", (void *)LONG_MAX)); // Me explota la cabeza
	printf("\n%d\n", ft_printf(" %p ", (void *)LONG_MAX)); //Si le quito el void el mio funciona y el suyo no
*/

/*
NI IDEA-> printf(" %p %p ", LONG_MIN, LONG_MAX);
30:     TEST(6, print(" %p %p ", LONG_MIN, LONG_MAX));
32:     TEST(8, print(" %p %p ", ULONG_MAX, -ULONG_MAX));

*/
/*
ERRORES:

47:     TEST(23, print(" %x ", INT_MIN));
48:     TEST(24, print(" %x ", LONG_MAX));
50:     TEST(26, print(" %x ", UINT_MAX));
51:     TEST(27, print(" %x ", ULONG_MAX));
52:     TEST(28, print(" %x ", 9223372036854775807LL));
*/
/*
	////simpple debugger:
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