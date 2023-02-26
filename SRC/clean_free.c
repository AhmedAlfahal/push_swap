/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_free.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalfahal <aalfahal@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 14:39:50 by aalfahal          #+#    #+#             */
/*   Updated: 2023/02/17 17:18:48 by aalfahal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	clean_exit(t_ps *ps, int stack, int join, int ex)
{
	if (join == 1)
		free(ps->joined);
	else if (join == 0)
	{
		free_2d_array(ps, stack);
		free(ps->joined);
	}
	if (ex == 1)
		write(2, "Error\n", 7);
	exit(ex);
}

void	free_2d_array(t_ps *ps, int stack)
{
	int	i;

	i = 0;
	while (ps->split[i])
		free(ps->split[i++]);
	free(ps->split);
	if (stack == 2)
	{
		free_stack(&ps->s->stack_a);
		free_stack(&ps->s->stack_b);
	}
	else if (stack == 3)
	{
		free_stack(&ps->clone);
		free_stack(&ps->s->stack_a);
		free_stack(&ps->s->stack_b);
	}
	else if (stack == 1)
		free_stack(&ps->s->stack_a);
}

void	free_stack(t_list **stack)
{
	t_list	*tmp;

	tmp = (*stack);
	while (*stack)
	{
		(*stack) = (*stack)->next;
		free(tmp);
		tmp = (*stack);
	}
}
