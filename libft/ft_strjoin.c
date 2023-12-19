/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuske <yuske@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/31 05:33:51 by yuske             #+#    #+#             */
/*   Updated: 2023/03/31 05:34:19 by yuske            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

//18L
/**
 * @brief 
 * 
 * @param s1 
 * @param s2 
 * @return char* 
 */
char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*nu_str;
	size_t	i;
	size_t	j;

	if (!s1 || !s2)
		return (NULL);
	nu_str = (char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!nu_str)
		return (NULL);
	i = 0;
	j = 0;
	while (s1[j])
		nu_str[i++] = s1[j++];
	j = 0;
	while (s2[j])
		nu_str[i++] = s2[j++];
	nu_str[i] = '\0';
	return (nu_str);
}
