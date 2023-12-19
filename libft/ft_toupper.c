/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuske <yuske@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 19:57:12 by yuske             #+#    #+#             */
/*   Updated: 2023/04/01 08:58:50 by yuske            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief 
 * 
 * @param chr 
 * @return int 
 */
int	ft_toupper(int chr)
{
	if (ft_islower(chr) != 0)
		chr += ('A' - 'a');
	return (chr);
}

// int	ft_toupper(int chr)
// {
// 	return (chr + ('A' - 'a') * (ft_islower(chr)));
// }

// int	ft_toupper(int chr)
// {
// 	return (chr + ('A' - 'a') * (chr >= 'a' && chr <= 'z'));
// }

// int	ft_toupper(int chr)
// {
// 	if (chr >= 'a' && chr <= 'z')
// 		chr += ('A' - 'a');
// 	return (chr);
// }
