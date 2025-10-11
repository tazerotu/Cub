/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl_test.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/01 09:15:07 by ttas              #+#    #+#             */
/*   Updated: 2025/10/06 11:15:05 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

static char	*ft_free_join(char *str1, char *str2)
{
	if (str1)
	{
		free(str1);
		str1 = NULL;
	}
	if (str2)
	{
		free(str2);
		str2 = NULL;
	}
	return (NULL);
}

char	*gnl_return(int bytes_read, char *res)
{
	if (bytes_read == 0)
	{
		if (res && *res != '\0')
			return (res);
		return (ft_free_join(NULL, res));
	}
	return (res);
}
