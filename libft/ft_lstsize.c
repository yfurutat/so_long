/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuske <yuske@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/31 06:56:19 by yuske             #+#    #+#             */
/*   Updated: 2023/03/31 06:56:20 by yuske            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief take a linked list as the parameter to determine its size
 * 		it's like the strlen() linked list edition.
 * @param node the pointer to the current node of the linked list
 * @return int the number of nodes actually counted
 */
int	ft_lstsize(t_list *node)
{
	int	nbr;

	nbr = 0;
	while (node != NULL)
	{
		node = node->next;
		nbr += 1;
	}
	return (nbr);
}
