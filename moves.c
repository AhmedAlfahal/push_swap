/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalfahal <aalfahal@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/05 22:58:21 by aalfahal          #+#    #+#             */
/*   Updated: 2023/02/12 19:13:51 by aalfahal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_list **stack, int msg)
{
	t_list	*tmp;

	if (ft_lstsize((*stack)) == 1)
		return ;
	tmp = (*stack);
	(*stack) = (*stack)->next;
	tmp->next = (*stack)->next;
	(*stack)->next = tmp;
	if (msg == 1)
		ft_printf("sa\n");
	else if (msg == 2)
		ft_printf("sb\n");
	else if (msg == 3)
		ft_printf("ss\n");
}

void	rotate(t_list **stack, int msg)
{
	t_list	*tmp;

	tmp = (*stack);
	if (ft_lstsize(tmp) == 1)
		return ;
	tmp = (*stack);
	(*stack) = (*stack)->next;
	ft_lstlast(*stack)->next = tmp;
	tmp->next = NULL;
	if (msg == 1)
		ft_printf("ra\n");
	else if (msg == 2)
		ft_printf("rb\n");
	else if (msg == 3)
		ft_printf("rr\n");
}

void	reverse_rotate(t_list **stack, int msg)
{
	t_list	*tmp;

	if (ft_lstsize(*stack) == 1)
		return ;
	tmp = ft_lstlast(*stack);
	ft_bfrlast(*stack)->next = NULL;
	tmp->next = (*stack);
	(*stack) = tmp;
	if (msg == 1)
		ft_printf("rra\n");
	else if (msg == 2)
		ft_printf("rrb\n");
	else if (msg == 3)
		ft_printf("rrr\n");
}

void	push(t_list **first, t_list **second, int msg)
{
	t_list	*tmp;

	if (ft_lstsize(*first) == 0)
		return ;
	tmp = (*first);
	(*first) = (*first)->next;
	tmp->next = (*second);
	(*second) = tmp;
	if (msg == 1)
		ft_printf("pa\n");
	else if (msg == 2)
		ft_printf("pb\n");
}
