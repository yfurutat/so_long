/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuske <yuske@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/31 06:52:39 by yuske             #+#    #+#             */
/*   Updated: 2023/03/31 06:53:02 by yuske            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief create the header node for a new linked list 
 *
 * @param stuff for the content of the header node of a new list
 * @return t_list* the header node as the newly created linked list
 * 
 * @note linked list: a collection of nodes, where each node contains a value
 * and a pointer to the next node in the list. The last node in the list has
 * a pointer to NULL. This function can be used to determine the last node in
 * a list, which is useful for various operations such as appending a new
 * node to the end of the list.
 */
t_list	*ft_lstnew(void *stuff)
{
	t_list	*new_node;

	new_node = (t_list *)malloc(sizeof(t_list));
	if (new_node != NULL)
	{
		new_node->content = stuff;
		new_node->next = NULL;
	}
	return (new_node);
}

// int	main(int argc, char *argv[])
// {
// 	t_list	*first_node;
// 	t_list	*last_node;
// 	t_list	*current_node;
// 	int		i;

// 	i = 1;
// 	while (i < argc)
// 	{
// 		if (i == 1)
// 		{
// 			first_node = ft_lstnew((char *)argv[i]);
// 			current_node = first_node;
// 			last_node = first_node;
// 		}
// 		else
// 		{
// 			last_node = ft_lstnew((char *)argv[i]);
// 			current_node->next = last_node;
// 			current_node = last_node;
// 		}
// 		i += 1;
// 	}
// 	current_node = first_node;
// 	while (current_node != NULL)
// 	{
// 		printf("%s\n", (char *)current_node->content);
// 		current_node = current_node->next;
// 	}
// 	return (0);
// }
