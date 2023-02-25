/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalfahal <aalfahal@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 19:23:54 by aalfahal          #+#    #+#             */
/*   Updated: 2023/02/24 16:52:04 by aalfahal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap.h"

int	sorted_index(t_list *stack, int val)
{
	int	i;

	i = 0;
	while (stack)
	{
		if (val == stack->content)
			return (i);
		stack = stack->next;
		i++;
	}
	return (i);
}

int	get_larg(t_list *stack)
{
	int	larg;

	if (ft_lstsize(stack) == 0)
		return (-1);
	larg = stack->content;
	while (stack)
	{
		if (larg < stack->content)
			larg = stack->content;
		stack = stack->next;
	}
	return (larg);
}

static int	check_vals(t_list *stack, int min, int max)
{
	if (ft_lstsize(stack) == 0)
		return (1);
	while (stack)
	{
		if (min <= stack->content && max >= stack->content)
			return (0);
		stack = stack->next;
	}
	return (1);
}

void	sorting_qrt(t_ps *ps, int min, int max)
{
	int	tmp;

	tmp = ps->s->stack_a->content;
	while (!check_vals(ps->s->stack_a, min, max))
	{
		if (ps->s->stack_a->content >= min \
		&& ps->s->stack_a->content <= max)
			push(&ps->s->stack_a, &ps->s->stack_b, 2);
		else
			rotate(&ps->s->stack_a, 1);
	}
	tmp = get_larg(ps->s->stack_b);
	while (ft_lstsize(ps->s->stack_b) != 0)
	{
		if (tmp == ps->s->stack_b->content)
		{
			push(&ps->s->stack_b, &ps->s->stack_a, 1);
			tmp = get_larg(ps->s->stack_b);
		}
		else if (sorted_index(ps->s->stack_b, tmp) \
		> ft_lstsize(ps->s->stack_b) / 2)
			reverse_rotate(&ps->s->stack_b, 2);
		else
			rotate(&ps->s->stack_b, 2);
	}
}

void	sort_small(t_ps *ps)
{
	if (ps->size == 2)
		swap(&ps->s->stack_a, 1);
	else if (ps->size == 3)
		sort_3nums(ps);
	else if (ps->size >= 4 && ps->size <= 10)
		sort_4to10nums(ps, ps->size - 3);
	clean_exit(ps, 3, 0, 0);
}
