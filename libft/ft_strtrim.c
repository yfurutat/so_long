/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuske <yuske@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 05:24:16 by yuske             #+#    #+#             */
/*   Updated: 2023/04/04 18:41:21 by yuske            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// strtrim:未尾+1, 先頭-1 を見てしまっている

#include "libft.h"

//19L
/**
 * @brief 
 * 
 * @param str 
 * @param trimmer_set 
 * @return char* 
 */
char	*ft_strtrim(char const *str, char const *trimmers)
{
	char	*trimmed;
	size_t	start;
	size_t	end;
	size_t	len;

	if (!str || !trimmers)
		return (NULL);
	start = 0;
	end = ft_strlen(str);
	if (end > 0)
	{
		while (ft_strchr(trimmers, str[start]) && str[start] != '\0')
			start += 1;
		end -= 1;
		while (ft_strchr(trimmers, str[end]) && end > start)
			end -= 1;
	}
	len = end - start;
	trimmed = ft_strndup(&str[start], len + 1);
	return (trimmed);
}
	// trimmed = ft_substr(str, start, len + 1);

//23L
// char	*ft_strtrim(char const *str, char const *trimmer_set)
// {
// 	char	*trimmed;
// 	size_t	head;
// 	size_t	tail;
// 	size_t	i;

// 	if (str == NULL || trimmer_set == NULL)
// 		return (NULL);
// 	else if (*str == '\0')
// 		return (ft_strdup(""));
// 	head = 0;
// 	while (ft_strchr(trimmer_set, str[head]) && str[head] != '\0')
// 		head += 1;
// 	tail = ft_strlen(str) - 1;
// 	while (ft_strchr(trimmer_set, str[tail]) && tail > head)
// 		tail -= 1;
// 	trimmed = (char *)ft_calloc(sizeof(char), (tail - head + 2));
// 	if (trimmed != NULL)
// 	{
// 		i = 0;
// 		while (head <= tail)
// 			trimmed[i++] = str[head++];
// 	}
// 	return (trimmed);
// }

// char* ft_strtrim(const char* str, const char* trimmer)
// {
//     if (!str || !trimmer)
//         return NULL;

//     size_t start_index = 0;
//     size_t end_index = strlen(str) - 1;

//     // Find the start index of the trimmed string
//     while (start_index <= end_index && strchr(trimmer, str[start_index]))
//         start_index++;

//     // Find the end index of the trimmed string
//     while (end_index > start_index && strchr(trimmer, str[end_index]))
//         end_index--;

//     // Check if the resulting string is empty
//     if (start_index > end_index)
//         return calloc(1, sizeof(char));

//     // Allocate memory for the trimmed string
//     size_t trimmed_length = end_index - start_index + 1;
//     char* trimmed = malloc(trimmed_length + 1);
//     if (!trimmed)
//         return NULL;

//     // Copy the trimmed string into the allocated memory
//     strncpy(trimmed, str + start_index, trimmed_length);
//     trimmed[trimmed_length] = '\0';

//     return trimmed;
// }
