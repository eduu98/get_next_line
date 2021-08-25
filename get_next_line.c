/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecruz-go <ecruz-go@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/22 13:29:08 by ecruz-go          #+#    #+#             */
/*   Updated: 2021/05/21 10:59:13 by ecruz-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <unistd.h>
/*
 * Obtenemos la linea final que retornaremos
 * Si no hemos leido nada la retornaremos vacia
 */
char	*ft_get_line(char *data, char **line, int readed)
{
	unsigned int	i;
	char			*aux;

	i = 0;
	while (data[i])
	{
		if (data[i] == '\n')
			break ;
		i++;
	}
	if (i < ft_strlen(data))
	{
		*line = ft_substr(data, 0, i);
		aux = ft_substr(data, i + 1, ft_strlen(data));
		free(data);
		data = ft_strdup(aux);
		free(aux);
	}
	else if (readed == 0)
	{
		*line = data;
		data = NULL;
	}
	return (data);
}

/*
 * Guardamos en data la linea leida.
 * Si teniamos algo anteriormente concatenaremos la cadena.
 */
char	*ft_save_readed(char *buffer, char *data)
{
	char	*aux;

	if (data)
	{
		aux = ft_strjoin(data, buffer);
		free(data);
		data = ft_strdup(aux);
		free(aux);
	}
	else
		data = ft_strdup(buffer);
	return (data);
}

/*
 * Leemos un fichero y obtenemos una linea, devolviendo 1.
 * Si hemos acabado la lectura devolveremos una cadena vacia y 0.
 * En caso de error devolveremos NULL y -1;
 */
int	get_next_line(int fd, char **line)
{
	static char	*data[4096];
	char		buffer[BUFFER_SIZE + 1];
	int			readed;

	readed = read(fd, buffer, BUFFER_SIZE);
	while (readed)
	{
		if (readed == -1)
			return (-1);
		buffer[readed] = '\0';
		data[fd] = ft_save_readed(buffer, data[fd]);
		if (ft_strchr(buffer, '\n'))
			break ;
		readed = read(fd, buffer, BUFFER_SIZE);
	}
	if (readed <= 0 && !data[fd])
	{
		*line = ft_strdup("");
		return (readed);
	}
	data[fd] = ft_get_line(data[fd], line, readed);
	if (readed <= 0 && !data[fd])
		return (readed);
	return (1);
}
