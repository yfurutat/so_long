/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuske <yuske@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 15:45:15 by yuske             #+#    #+#             */
/*   Updated: 2023/03/31 04:46:31 by yuske            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief 
 * 
 * @param chr 
 * @return int 
 */
int	ft_isdigit(int chr)
{
	return (chr >= '0' && chr <= '9');
}
