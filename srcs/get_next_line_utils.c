/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efmacm23 <efmacm23@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/30 20:07:37 by yuske             #+#    #+#             */
/*   Updated: 2023/12/18 01:31:01 by efmacm23         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

// 8L
char	*ft_strchr_gnl(char *str, int chr)
{
	if (str != NULL)
	{
		while (*str != (unsigned char)chr && *str != '\0')
			str++;
		if (*str == (unsigned char)chr)
			return ((char *)str);
	}
	return (NULL);
}

//6L
size_t	ft_strlen_gnl(const char *str)
{
	size_t	len;

	len = 0;
	while (str != NULL && str[len] != '\0')
		len += 1;
	return (len);
}

//16L
char	*ft_strdup_gnl(const char *str)
{
	char	*dup;
	size_t	i;

	if (str == NULL)
		return (NULL);
	dup = (char *)malloc(sizeof(char) * ft_strlen_gnl(str) + 1);
	if (!dup)
		return (NULL);
	i = 0;
	while (str[i] != '\0')
	{
		dup[i] = str[i];
		i++;
	}
	dup[i] = '\0';
	return (dup);
}

//22L
char	*ft_strjoin_gnl(char *str1, char *str2)
{
	char	*nu_str;
	size_t	i;
	size_t	j;

	if (!str1)
		str1 = ft_strdup_gnl("");
	if (!str1 || !str2)
		return (NULL);
	nu_str = (char *)malloc(ft_strlen_gnl(str1) + ft_strlen_gnl(str2) + 1);
	if (nu_str)
	{
		i = 0;
		j = 0;
		while (str1[j] != '\0')
			nu_str[i++] = str1[j++];
		j = 0;
		while (str2[j] != '\0')
			nu_str[i++] = str2[j++];
		nu_str[i] = '\0';
	}
	free(str1);
	return (nu_str);
}
	// i = ft_strlen(str1);
	// j = ft_strlen(str2);
		// nu_str = strcpy(nu_str, str1);
