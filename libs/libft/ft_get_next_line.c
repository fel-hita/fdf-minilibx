/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fel-hita <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/15 01:33:22 by fel-hita          #+#    #+#             */
/*   Updated: 2018/12/29 21:48:55 by fel-hita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"


static unsigned int	ft_strxlen(char *fd_save)
{
	unsigned int	i;

	i = 0;
	while (fd_save[i] != '\n' && fd_save[i] != '\0')
		i++;
	return (i);
}

static char			*ft_strrejoin(char *s1, char *s2, size_t len)
{
	char		*str;
	int			nb;
	char		*tmp;

	len++;
	nb = ft_strlen(s1) + len;
	str = ft_strnew(nb);
	tmp = str;
	while (*s1)
		*str++ = *s1++;
	len--;
	while (*s2 && len > 0)
		*str++ = *s2++;
	*str = '\0';
	return (str - (str - tmp));
}

static char			*ft_helper(char *fd_save)
{
	if (ft_strchr(fd_save, '\n'))
	{
		ft_strcpy(fd_save, ft_strchr(fd_save, '\n') + 1);
		return (fd_save);
	}
	if (ft_strxlen(fd_save) > 0)
	{
		ft_strcpy(fd_save, ft_strchr(fd_save, '\0'));
		return (fd_save);
	}
	return (NULL);
}

int					get_next_line(int const fd, char **line)
{
	char		buff[BUFF_SIZE + 1];
	static char	*fd_save[256];
	int			len;
	char		*ptr;

	if (fd < 0 || BUFF_SIZE < 1 || !line || read(fd, buff, 0) < 0)
		return (-1);
	if (!(fd_save[fd]) && (fd_save[fd] = ft_strnew(0)) == NULL)
		return (-1);
	while (!(ft_strchr(fd_save[fd], '\n')) &&
			(len = read(fd, buff, BUFF_SIZE)) > 0)
	{
		buff[len] = '\0';
		ptr = fd_save[fd];
		fd_save[fd] = ft_strrejoin(ptr, buff, len);
		free(ptr);
	}
	*line = ft_strsub(fd_save[fd], 0, ft_strxlen(fd_save[fd]));
	if (ft_helper(fd_save[fd]) == NULL)
		return (0);
	return (1);
}
