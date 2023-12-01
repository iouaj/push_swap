/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iouajjou <iouajjou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 17:16:30 by iouajjou          #+#    #+#             */
/*   Updated: 2023/12/01 18:02:32 by iouajjou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void freestack(t_stack *stack)
{
	t_stack *temp;

	while (stack)
	{
		temp = stack->next;
		free(stack);
		stack = temp;
	}

}

t_stack *newstack(char *value)
{
	t_stack *new;

	new = malloc(sizeof(t_stack));
	new->value = value;
	new->position = 1;
	new->next = NULL;
	new->head = new;
	return (new);
}

void addstack(t_stack **stack, t_stack **new)
{
	int position;

	if (!(*new))
		return ;
	position = 1;
	if (!(*stack))
	{
		*stack = *new;
	}
	else
	{
		(*new)->head = (*stack)->head;
		while ((*stack)->next)
		{
			*stack = (*stack)->next;
			position++;
		}
		(*stack)->next = *new;
		(*new)->position = position;
	}
}
