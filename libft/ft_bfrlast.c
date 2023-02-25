/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bfrlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalfahal <aalfahal@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/05 23:24:43 by aalfahal          #+#    #+#             */
/*   Updated: 2023/02/05 23:25:27 by aalfahal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_bfrlast(t_list *lst)
{
	t_list	*new_node;

	if (!lst)
		return (NULL);
	new_node = lst;
	while (new_node->next->next != NULL)
		new_node = new_node->next;
	return (new_node);
}
