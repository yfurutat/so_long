/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuske <yuske@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/31 06:44:59 by yuske             #+#    #+#             */
/*   Updated: 2023/04/01 08:03:48 by yuske            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief 
 * 
 * @param node 
 * @param new_node 
 */
void	ft_lstadd_front(t_list **node, t_list *new_node)
{
	if (node == NULL || new_node == NULL)
		return ;
	else
	{
		new_node->next = *node;
		*node = new_node;
		return ;
	}
}
