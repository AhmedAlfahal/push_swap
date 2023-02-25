/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalfahal <aalfahal@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 15:13:54 by aalfahal          #+#    #+#             */
/*   Updated: 2023/02/19 23:05:39 by aalfahal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	val(const char *va, int sgn, int n, t_ps *ps)
{
	long	res;

	res = 0;
	while (va[n] == '0' && va[n] != '\0')
		n++;
	while (va[n] != '\0' && va[n] >= '0' && va[n] <= '9')
	{
		res = (res * 10) + (va[n] - '0');
			n++;
		if ((res > 2147483647 && sgn == 1) || (res > 2147483648 && sgn == -1))
		{
			free_stack(&ps->clone);
			clean_exit(ps, 1, 0, 1);
		}
	}
	return (res);
}

static int	ft_ai(const char *str, t_ps *ps)
{
	int					i;
	int					sgn;
	long long			res;

	i = 0;
	sgn = 1;
	res = 0;
	while (str[i] == ' ' || ((str[i] >= 9) && (str[i] <= 13)))
		i++;
	while (str[i] == '-' || str[i] == '+')
	{
		if ((str[i] == '-' || str[i] == '+')
			&& (str[i + 1] == '-' || str[i + 1] == '+'))
			return (0);
		else if (str[i] == '-')
				sgn = -1;
			i++;
	}
	res = val (str, sgn, i, ps);
	return (res * sgn);
}

static void	dup_check(t_ps *ps)
{
	t_list	*tmp1;
	t_list	*tmp2;

	tmp1 = ps->s->stack_a;
	while (tmp1)
	{
		tmp2 = tmp1->next;
		while (tmp2)
		{
			if (tmp1->content == tmp2->content)
			{
				free_stack(&ps->clone);
				clean_exit(ps, 1, 0, 1);
			}
			tmp2 = tmp2->next;
		}
		tmp1 = tmp1->next;
	}
}

static void	letting_num_in(t_ps *ps)
{
	int	i;

	i = 0;
	while (ps->split[i])
		i++;
	i--;
	while (i >= 0)
	{
		ft_lstadd_front(&ps->s->stack_a, ft_lstnew(ft_ai(ps->split[i], ps)));
		ft_lstadd_front(&ps->clone, ft_lstnew(ft_ai(ps->split[i], ps)));
		i--;
	}
	dup_check(ps);
}

void	checking_digits(t_ps *ps)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	if (!*ps->split)
		clean_exit(ps, 0, 0, 1);
	while (ps->split[i])
	{
		j = 0;
		while (ps->split[i][j])
		{
			if (!ft_isdgt(ps->split[i][j]))
				clean_exit(ps, 0, 0, 1);
			else if ((ps->split[i][j] == '-' || ps->split[i][j] == '+') \
			&& j != 0)
				clean_exit(ps, 0, 0, 1);
			j++;
		}
		i++;
	}
	letting_num_in(ps);
	if (!is_sorted(ps->s->stack_a, 1))
		sort(ps);
	clean_exit(ps, 3, 0, 0);
}
