/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aorcha-m <aorcha-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 10:11:53 by agu               #+#    #+#             */
/*   Updated: 2024/03/13 18:55:02 by aorcha-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

static	char	*concatenate_to_stash(char *stash, char *buffer)
{
	char	*temp_remainder;

	if (!stash)
		stash = ft_strdup("");
	temp_remainder = stash;
	stash = ft_strjoin(temp_remainder, buffer);
	free(temp_remainder);
	return (stash);
}

static char	*read_file(int fd, char *stash)
{
	char	buffer[BUFFER_SIZE + 1];
	int		chars_read;
	char	*newline_pos;

	chars_read = read(fd, buffer, BUFFER_SIZE);
	while (chars_read != 0)
	{
		if (chars_read == -1)
			return (0);
		buffer[chars_read] = '\0';
		newline_pos = ft_strchr(buffer, '\n');
		stash = concatenate_to_stash(stash, buffer);
		if (newline_pos != NULL)
			break ;
		chars_read = read(fd, buffer, BUFFER_SIZE);
	}
	return (stash);
}

static	char	*get_remaining_segment(char *line)
{
	size_t	counter;
	char	*remaining_segment;

	counter = 0;
	while (line[counter] != '\n' && line[counter] != '\0')
		counter++;
	if (line[counter] == '\0')
		return (0);
	remaining_segment = ft_substr(line, counter + 1, ft_strlen(line) - counter);
	if (*remaining_segment == '\0')
	{
		free(remaining_segment);
		remaining_segment = NULL;
	}
	line[counter + 1] = '\0';
	return (remaining_segment);
}

char	*get_next_line(int fd)
{
	char		*content;
	char		*line;
	static char	*stash[OPEN_MAX];

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	content = read_file(fd, stash[fd]);
	if (!content)
	{
		if (stash[fd])
		{
			free(stash[fd]);
			stash[fd] = NULL;
		}
		return (NULL);
	}
	line = content;
	stash[fd] = get_remaining_segment(line);
	return (line);
}
