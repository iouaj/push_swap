/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iouajjou <iouajjou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 17:05:04 by iouajjou          #+#    #+#             */
/*   Updated: 2024/02/05 17:28:55 by iouajjou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

t_stack	*min_stack(t_stack *stack)
{
	t_stack	*min;

	min = stack;
	stack = stack->next;
	while (stack)
	{
		if (stack->nb < min->nb)
			min = stack;
		stack = stack->next;
	}
	return (min);
}

t_stack	*min_after(t_stack *stack, t_stack *start)
{
	t_stack	*min;

	min = NULL;
	while (stack)
	{
		if (!min && stack->nb > start->nb)
			min = stack;
		else if (min && stack->nb < min->nb && stack->nb > start->nb)
			min = stack;
		stack = stack->next;
	}
	return (min);
}

int	is_sort(t_stack *stack)
{
	while (stack->next)
	{
		if (stack->nb > stack->next->nb)
			return (0);
		stack = stack->next;
	}
	return (1);
}

int	abso(int nb)
{
	if (nb < 0)
		return (nb * (-1));
	return (nb);
}

void	do_simple(t_stack *minus, t_stack **stack, t_stack **bstack)
{
	while (minus->cost_b > 0)
	{
		rotate(bstack);
		ft_printf("rb\n");
		minus->cost_b--;
	}
	while (minus->cost_b < 0)
	{
		reverse(bstack);
		ft_printf("rrb\n");
		minus->cost_b++;
	}
	while (minus->cost_a > 0)
	{
		rotate(stack);
		ft_printf("ra\n");
		minus->cost_a--;
	}
	while (minus->cost_a < 0)
	{
		reverse(stack);
		ft_printf("rra\n");
		minus->cost_a++;
	}
}
