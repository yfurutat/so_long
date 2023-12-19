/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuske <yuske@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 19:54:20 by yuske             #+#    #+#             */
/*   Updated: 2023/04/01 03:09:53 by yuske            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief 
 * 
 * @param chr 
 * @return int 
 */
int	ft_tolower(int chr)
{
	if (ft_isupper(chr) != 0)
		chr -= ('A' - 'a');
	return (chr);
}

// int	ft_tolower(int chr)
// {
// 	return (chr - ('A' - 'a') * (ft_isupper(chr)));
// }

// int	ft_tolower(int chr)
// {
// 	return (chr - ('A' - 'a') * (chr >= 'A' && chr <= 'Z'));
// }

// int	ft_tolower(int chr)
// {
// 	if (chr >= 'a' && chr <= 'z')
// 		chr -= ('A' - 'a');
// 	return (chr);
// }
