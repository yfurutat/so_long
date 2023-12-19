/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuske <yuske@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/31 02:43:49 by yuske             #+#    #+#             */
/*   Updated: 2023/03/31 04:39:55 by yuske            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	digit_counter(long int num_uc);
static long int	divider_spiral(long int divider, size_t digits, size_t i);

//20L
/**
 * @brief 
 * 
 * @param nbr 
 * @param fd 
 */
void	ft_putnbr_fd(int nbr, int fd)
{
	long int	nbr_uc;
	long int	divider;
	int			sign;
	size_t		digits;

	sign = POSITIVE;
	if (nbr < 0)
		sign = NEGATIVE;
	nbr_uc = (long int)nbr * sign;
	digits = digit_counter(nbr_uc);
	divider = divider_spiral(1, digits, 0);
	if (sign == NEGATIVE)
		ft_putchar_fd('-', fd);
	while (digits)
	{
		ft_putchar_fd(nbr_uc / divider + '0', fd);
		nbr_uc %= divider;
		divider /= 10;
		digits -= 1;
	}
}

//11L
/**
 * @brief 
 * 
 * @param num_uc 
 * @return size_t 
 */
static size_t	digit_counter(long int num_uc)
{
	size_t	digits;

	digits = 0;
	if (num_uc == 0)
		digits += 1;
	while (num_uc > 0)
	{
		num_uc /= 10;
		digits += 1;
	}
	return (digits);
}

//8L
/**
 * @brief 
 * 
 * @param divider 
 * @param digits 
 * @param i 
 * @return long int 
 */
static long int	divider_spiral(long int divider, size_t digits, size_t i)
{
	while (i < digits - 1)
	{
		divider *= 10;
		i += 1;
	}
	return (divider);
}
	// divider = 1;
	// i = 0;

//malloced, but freed right after the output
// void	ft_putnbr_fd(int n, int fd)
// {
// 	char	*str;

// 	str = ft_itoa(n);
// 	ft_putstr_fd(str, fd);
// 	free (str);
// }
