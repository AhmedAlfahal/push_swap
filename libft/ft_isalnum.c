/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalfahal <aalfahal@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/23 19:52:41 by aalfahal          #+#    #+#             */
/*   Updated: 2023/02/09 18:57:41 by aalfahal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalnum(char *s)
{
	int	i;
	int	x;

	i = 0;
	x = 0;
	if (!s)
		return (0);
	while (s[i])
	{
		if ((s[i] >= 'a' && s[i] <= 'z') \
			|| (s[i] >= 'A' && s[i] <= 'Z') \
			|| (s[i] >= '0' && s[i] <= '9') \
			|| (s[i] == ' ' && x == 1))
			x = 1;
		else if (i == (int)ft_strlen(s) - 1 && x == 0)
			return (0);
		i++;
	}
	return (x);
}
