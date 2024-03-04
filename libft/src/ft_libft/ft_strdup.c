/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: allan <allan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 16:27:00 by allan             #+#    #+#             */
/*   Updated: 2023/12/03 10:11:43 by allan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s);

char	*ft_strdup(const char *s)
{
	size_t	slen;
	char	*scopy;

	slen = ft_strlen(s);
	scopy = malloc((slen + 1) * sizeof(char));
	if (!scopy)
		return (NULL);
	while (*s)
		*scopy++ = *s++;
	*scopy = '\0';
	scopy = scopy - ((slen) * sizeof(char));
	return (scopy);
}
