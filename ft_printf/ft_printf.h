/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eelisaro <eelisaro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/17 20:32:37 by eelisaro          #+#    #+#             */
/*   Updated: 2022/12/18 16:54:26 by eelisaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include "./libft/libft.h"
# include <stdint.h>

int		ft_printf(const char *str, ...);
void	ft_putnbr_fd_mod(long n, int fd, int *len);
void	printconvfromdec(int tobase, uintptr_t number, char *set, int *len);
void	uintputnbr(unsigned int n, int fd, int *len);
void	convertx(int tobase, unsigned int number, char *set, int *len);
void	converter(va_list ap, int *countchar, char c);
void	casepercent(int	*countchar);
void	case_x(unsigned int d, int *countchar, char *set);
void	case_d(unsigned long long d, int *countchar);
void	case_p(unsigned long long d, int *countchar);
void	case_s(char *s, int *countchar);
void	case_c(char c, int *countchar);
void	converter(va_list ap, int *countchar, char c);

#endif
