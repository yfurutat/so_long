/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efmacm23 <efmacm23@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/30 20:07:31 by yuske             #+#    #+#             */
/*   Updated: 2023/12/18 01:29:52 by efmacm23         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static void	id_initializer(t_id *id);
static char	*read_and_save(int fd, char *save, t_id *id);
static char	*line_arranger(char *save, t_id *id);
static char	*save_the_rest(char *save, t_id *id);

//13L
/**
 * @brief Get the lines from fd by the BUFFER_SIZE,
 * 			and arrange them with '\n' if needed.
 * 
 * @param fd : file descriptor number from which to read lines.
 * @return char* : line created through line_arranger().
 * @note you might need to use open() and close() in main().
 */
char	*get_next_line(int fd)
{
	static char	*save;
	char		*line_to_print;
	t_id		id;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	id_initializer(&id);
	save = read_and_save(fd, save, &id);
	if (!save)
		return (NULL);
	line_to_print = line_arranger(save, &id);
	save = save_the_rest(save, &id);
	return (line_to_print);
}

/**
 * @brief initialize all the elements in the struct.
 * 
 * @param id the struct contains index to make funcs more concise & go easier.
 */
static void	id_initializer(t_id *id)
{
	id->terminal = '\0';
	id->rd_len = 0;
	id->len = 0;
	id->i = 0;
}

//22L
/**
 * @brief read lines from the fd by the BUFFER_SIZE,
 * 			and put them into *buf, before copying them into save.
 * 			if any lines remain in *save, put them before the new lines
 * 			into save and combine them altogether.
 * 
 * @param fd file descriptor given through the input of g_n_l()
 * @param save if a line remains after the last process, 
 * 				it is carried over in this array.
 * @param id set of index, including rd_len
 * @return char* 
 */
static char	*read_and_save(int fd, char *save, t_id *id)
{
	char	*buf;

	buf = (char *)malloc(sizeof(char) * BUFFER_SIZE + 1UL);
	if (!buf)
		return (NULL);
	id->rd_len = 1;
	while (1)
	{
		id->rd_len = read(fd, buf, BUFFER_SIZE);
		if (id->rd_len <= 0)
			break ;
		buf[id->rd_len] = '\0';
		save = ft_strjoin_gnl(save, buf);
		if (save == NULL || ft_strchr_gnl(save, '\n') != NULL)
			break ;
	}
	free(buf);
	if (id->rd_len == -1)
		return (NULL);
	else if (ft_strchr_gnl(save, '\n') != NULL)
		id->terminal = '\n';
	return (save);
}

//21L
/**
 * @brief create the actual line to output, out of *save.
 * 
 * @param save array saved in the previous func.
 * @param id set of index, including len and i.
 * @return char* line created through this func, 
 * 			which will be returned in the end of g_n_l(), too.
 */
static char	*line_arranger(char *save, t_id *id)
{
	char	*line;

	id->i = 0;
	if (save[id->i] == '\0' || save == NULL)
		return (NULL);
	id->len = 0;
	while (save[id->len] != id->terminal)
		id->len++;
	if (id->terminal == '\n')
		line = (char *)malloc(sizeof(char) * (id->len + 2));
	else
		line = (char *)malloc(sizeof(char) * (id->len + 1));
	if (line == NULL)
		free(save);
	else
	{
		while (id->i < id->len + 1)
		{
			line[id->i] = save[id->i];
			id->i += 1;
		}
		if (id->terminal == '\n')
			line[id->i] = '\0';
	}
	return (line);
}

//17L
/**
 * @brief if the line saved in *save contains any '\n',
 * 			this func keep the rest after creating the line
 * 			in the previous func.
 * @param save array saved and carried over.
 * @param id set of index including len and i.
 * @return char* the rest of the lines saved 
 * 			after creating the line to output.
 */
static char	*save_the_rest(char *save, t_id *id)
{
	char	*for_next;

	for_next = NULL;
	if (save && id->terminal == '\n')
	{
		for_next = (char *)malloc(ft_strlen_gnl(save) - id->len + 1);
		if (for_next)
		{
			id->len++;
			id->i = 0;
			while (save[id->len] != '\0')
				for_next[id->i++] = save[id->len++];
			for_next[id->i] = '\0';
		}
	}
	free(save);
	return (for_next);
}
