/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   target.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iouajjou <iouajjou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 18:32:31 by iouajjou          #+#    #+#             */
/*   Updated: 2024/02/05 17:28:55 by iouajjou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static int	target_smallest(t_stack *stack)
{
	int	smallest;
	int	target;
	int	pos;

	smallest = stack->nb;
	target = 0;
	pos = 0;
	smallest = 2147483647;
	while (stack)
	{
		if (stack->nb < smallest)
		{
			smallest = stack->nb;
			target = pos;
		}
		pos++;
		stack = stack->next;
	}
	return (target);
}

static int	get_target(t_stack *stack, t_stack *bstack)
{
	int	smallest;
	int	target;
	int	pos;

	pos = 0;
	target = -1;
	smallest = 2147483647;
	while (stack)
	{
		if (stack->nb > bstack->nb && stack->nb < smallest)
		{
			smallest = stack->nb;
			target = pos;
		}
		stack = stack->next;
		pos++;
	}
	return (target);
}

void	get_all_target(t_stack *stack, t_stack *bstack)
{
	while (bstack)
	{
		bstack->target = get_target(stack, bstack);
		if (bstack->target == -1)
			bstack->target = target_smallest(stack);
		bstack = bstack->next;
	}
}
