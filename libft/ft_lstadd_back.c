/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuske <yuske@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/31 06:11:48 by yuske             #+#    #+#             */
/*   Updated: 2023/04/01 08:02:36 by yuske            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief 
 * 
 * @param node 
 * @param new_node 
 */
void	ft_lstadd_back(t_list **node, t_list *new_node)
{
	t_list	*last_node;

	if (node == NULL || new_node == NULL)
		return ;
	else if (*node == NULL)
		*node = new_node;
	else
	{
		last_node = ft_lstlast(*node);
		last_node->next = new_node;
	}
}
