/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuske <yuske@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/31 06:48:22 by yuske             #+#    #+#             */
/*   Updated: 2023/04/01 08:10:55 by yuske            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief 
 * 
 * @param node 
 * @param fnc 
 */
void	ft_lstiter(t_list *node, void (*fnc)(void *))
{
	if (fnc == NULL || node == NULL)
		return ;
	while (node != NULL)
	{
		fnc(node->content);
		node = node->next;
	}
}
