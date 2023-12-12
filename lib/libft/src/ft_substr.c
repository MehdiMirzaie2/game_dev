/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmirzaie <mmirzaie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 10:50:12 by mmirzaie          #+#    #+#             */
/*   Updated: 2023/12/06 13:28:24 by mmirzaie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t end)
{
	const int	len = end - start;
	char		*substr;
	int			i;

	i = 0;
	substr = malloc(sizeof(char) * len + 1);
	while (start < end)
		substr[i++] = s[start++];
	substr[i] = '\0';
	return (substr);
}
