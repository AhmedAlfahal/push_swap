/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdgt.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalfahal <aalfahal@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/09 20:46:32 by aalfahal          #+#    #+#             */
/*   Updated: 2023/02/07 22:42:30 by aalfahal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isdgt(int s)
{
	if ((s >= '0' && s <= '9') || s == '-' || s == '+' || s == ' ')
		return (1);
	else
		return (0);
}
