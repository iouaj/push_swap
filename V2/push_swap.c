/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iouajjou <iouajjou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 17:12:45 by iouajjou          #+#    #+#             */
/*   Updated: 2023/12/01 18:04:00 by iouajjou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

void print_stack_all(t_stack *stack)
{
	while (stack)
	{
		printf("Stack %d, value : %s, next : %p, head : %p\n", stack->position, stack->value, stack->next, stack->head);
		stack = stack->next;
	}
}

int instack(t_stack *stack, char *value)
{
	int i;

	while (stack)
	{
		if (!ft_strncmp(stack->value, value, ft_strlen(value)))
			return (1);
		stack = stack->next;
	}
	return (0);
}

int main(int argc, char *argv[])
{
	t_stack *stacka;
	t_stack *stackb;
	t_stack *new;
	unsigned int i;

	i = 1;
	stacka = NULL;
	stackb = NULL;
	if (argc == 1)
		return (0);
	while (i < (argc))
	{
		new = newstack(argv[i]);
		if (!new || instack(stacka, new->value))
		{
			freestack(stacka);
			printf("echec malloc\n");
			return (1);
		}
		addstack(&stacka, &new);
		i++;
	}
	print_stack_all(stacka);
	freestack(stacka);
	return (0);
}
