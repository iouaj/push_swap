/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iouajjou <iouajjou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 13:26:15 by iouajjou          #+#    #+#             */
/*   Updated: 2024/02/05 17:28:55 by iouajjou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	error(t_stack *stack)
{
	ft_putstr_fd("Error\n", 2);
	freestack(stack);
	exit(EXIT_FAILURE);
}

int	check_nb(int nb, t_stack *stack)
{
	while (stack)
	{
		if (stack->nb == nb)
			error(stack);
		stack = stack->next;
	}
	return (1);
}

int	is_valid(char *str, t_stack *stack)
{
	int		i;
	int		nb;
	char	*test;

	i = 0;
	if (!str || str[0] == 0)
		error(stack);
	if (str && str[0] == '-')
		i++;
	while (str && str[i])
	{
		if (!ft_isdigit(str[i]))
			error(stack);
		i++;
	}
	nb = ft_atoi(str);
	test = ft_itoa(nb);
	if (ft_strncmp(test, str, ft_strlen(str)))
	{
		free(test);
		error(stack);
	}
	free(test);
	check_nb(nb, stack);
	return (1);
}
