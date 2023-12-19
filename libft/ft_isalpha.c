/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuske <yuske@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 15:42:25 by yuske             #+#    #+#             */
/*   Updated: 2023/03/31 04:45:58 by yuske            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief 
 * 
 * @param chr 
 * @return int 
 */
int	ft_isalpha(int chr)
{
	return (ft_isupper(chr) || ft_islower(chr));
}

// int	ft_isalpha(int chr)
// {
// 	return ((chr >= 'A' && chr <= 'Z') || (chr >= 'a' && chr <= 'z'));
// }
