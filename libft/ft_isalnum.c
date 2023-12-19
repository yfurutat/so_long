/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuske <yuske@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 15:37:25 by yuske             #+#    #+#             */
/*   Updated: 2023/03/31 04:50:27 by yuske            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief 
 * 
 * @param chr 
 * @return int 
 */
int	ft_isalnum(int chr)
{
	return (ft_isalpha(chr) || ft_isdigit(chr));
}

// int	ft_isalnum(int chr)
// {
// 	return ((chr >= 'A' && chr <= 'Z') || (chr >= 'a' && chr <= 'z')
// 		|| (chr >= '0' && chr <= '9'));
// }
