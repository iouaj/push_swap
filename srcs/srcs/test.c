/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iouajjou <iouajjou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 13:26:15 by iouajjou          #+#    #+#             */
/*   Updated: 2024/02/20 13:39:11 by iouajjou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	error(t_stack *stack)
{
	ft_putstr_fd("Error\n", 2);
	freestack(stack);
	exit(EXIT_FAILURE);
}

static int	check_nb(int nb, t_stack *stack)
{
	while (stack)
	{
		if (stack->nb == nb)
			error(stack);
		stack = stack->next;
	}
	return (1);
}

static int	is_valid(char *str, t_stack *stack)
{
	int		i;
	int		nb;
	char	*test;

	i = 0;
	if (!str || str[0] == 0)
		return (0);
	if (str && str[0] == '-')
		i++;
	while (str && str[i])
	{
		if (!ft_isdigit(str[i]))
			return (0);
		i++;
	}
	nb = ft_atoi(str);
	test = ft_itoa(nb);
	if (ft_strncmp(test, str, ft_strlen(str)))
	{
		free(test);
		return (0);
	}
	free(test);
	check_nb(nb, stack);
	return (1);
}

static t_stack	*add_splitter(char **splitter, t_stack *stack)
{
	int	j;

	j = 0;
	while (splitter[j])
	{
		if (!is_valid(splitter[j], stack))
		{
			free_splitter(splitter);
			error(stack);
		}
		addstack(&stack, newstack(ft_atoi(splitter[j])));
		j++;
	}
	free_splitter(splitter);
	return (stack);
}

t_stack	*split_argv(int argc, char *argv[], t_stack *stack)
{
	char	**splitter;
	int		i;

	i = 1;
	while (argc > i)
	{
		splitter = ft_split(argv[i], ' ');
		if (!splitter || !splitter[0])
		{
			free(splitter);
			error(stack);
		}
		stack = add_splitter(splitter, stack);
		i++;
	}
	return (stack);
}
