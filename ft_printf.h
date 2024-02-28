/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgarcia3 <jgarcia3@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/18 20:49:13 by jgarcia3          #+#    #+#             */
/*   Updated: 2024/02/28 02:12:59 by jgarcia3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF
# define FT_PRINTF

# include <stdarg.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include "libft/libft.h"

int 	ft_dec_to_hex(long n, int caps);
int 	ft_printf(char const *str, ...);
void	ft_putunsgnbr_fd(unsigned int n, int fd);

int		wf_char(char a);
int		wf_str(char * a);
int		wf_int(int a);
int 	wf_unsg(unsigned int a);
int		wf_x_lw(int a);
int		wf_x_up(int a);
int		wf_ptr(long a);

#endif
