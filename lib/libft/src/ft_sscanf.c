/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sscanf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmirzaie <mmirzaie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 13:47:03 by mmirzaie          #+#    #+#             */
/*   Updated: 2023/12/06 13:37:47 by mmirzaie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

static void	ft_id(int *num, char *string)
{
	int	number;

	number = ft_atoi(string);
	*num = number;
}

static void	ft_f(float *num, char *string)
{
	double	number;

	number = ft_atof(string);
	*num = number;
}

static void	ft_format(char *str, va_list args, const char format)
{
	if (format == 'd' || format == 'i')
		ft_id(va_arg(args, int *), str);
	else if (format == 'f')
		ft_f(va_arg(args, float *), str);
	free(str);
}

int	sscan_helper(const char *tosplit, int j, int *start)
{
	while (ft_isspace(tosplit[j]) || tosplit[j] == ',')
		j++;
	*start = j;
	while ((tosplit[j] && tosplit[j] != ' ' && tosplit[j] != ',') || \
		tosplit[j] == '.' || tosplit[j] == '-')
		j++;
	return (j);
}

void	ft_sscanf(const char *tosplit, const char *str, ...)
{
	size_t	i;
	va_list	args;
	char	*substring;
	int		j;
	int		start;

	i = 0;
	j = 0;
	va_start(args, str);
	while (str[i])
	{
		j = sscan_helper(tosplit, j, &start);
		if (j == start)
			exit(1);
		if (j > start)
			substring = ft_substr(tosplit, start, j);
		while (str[i] != '%')
			i++;
		if (str[i++] == '%')
			ft_format(substring, args, str[i]);
		i++;
	}
	va_end(args);
}
