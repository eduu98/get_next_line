/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecruz-go <ecruz-go@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/20 13:33:44 by ecruz-go          #+#    #+#             */
/*   Updated: 2021/05/20 13:34:27 by ecruz-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
/*
 * Calculamos la longitud de una cadena
 */
size_t	ft_strlen(const char *s)
{
	size_t			i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

/*
 * Busca cierta letra dentro de una cadena de texto
 */
char	*ft_strchr(const char *s, int c)
{
	char	*ptr;

	ptr = (char *)s;
	while (*ptr != (char)c && *ptr != '\0')
	{
		ptr++;
	}
	if (*ptr == '\0' && (char)c != '\0')
		return (NULL);
	return (ptr);
}

/*
 * Devuelve un puntero a una nueva cadena, que es un duplicado de s1.
 * El puntero devuelto se puede pasar a free().
 * Se devuelve un puntero nulo si no se puede crear la nueva cadena.
 */
char	*ft_strdup(const char *s1)
{
	char			*s2;
	size_t			l;
	unsigned int	i;

	l = ft_strlen(s1);
	s2 = (char *)malloc(l + 1);
	i = 0;
	if (s2)
	{
		while (s1[i] != '\0' && i < l)
		{
			s2[i] = s1[i];
			i++;
		}
		s2[i] = '\0';
	}
	else
		return (0);
	return (s2);
}

/*
 * Reserva memoria y devuelve la cadena de caracteres que proviene de la cadena
 * pasada como argumento.
 * Esta nueva cadena comienza en el índice ’start’
 * y tiene como tamaño máximo ’len’
 */
char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*subst;
	size_t			size;
	size_t			i;
	size_t			j;

	if (!s)
		return (NULL);
	size = ft_strlen(s);
	if (start >= size)
		return (ft_strdup(""));
	subst = (char *)malloc(sizeof(char) * len + 1);
	if (!subst)
		return (NULL);
	i = start;
	j = 0;
	while (j < len && s[i] != '\0')
	{
		subst[j] = s[i];
		j++;
		i++;
	}
	subst[j] = '\0';
	return (subst);
}

/*
 * Reserva memoria y devuelve la cadena de caracteres que
 * que resulta de la concatenación de ’s1’ y ’s2’.
 */
char	*ft_strjoin(char const *s1, char const *s2)
{
	char			*str;
	unsigned int	i;
	unsigned int	j;

	if (!s2 || !s1)
		return (ft_strdup(""));
	str = (char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!str)
		return (NULL);
	i = 0;
	while (s1[i])
	{
		str[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j])
	{
		str[i + j] = s2[j];
		j++;
	}
	str[i + j] = '\0';
	return (str);
}
