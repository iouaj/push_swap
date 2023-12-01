/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iouajjou <iouajjou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 17:12:43 by iouajjou          #+#    #+#             */
/*   Updated: 2023/12/01 18:01:49 by iouajjou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>

typedef struct s_stack
{
	struct s_stack	*next;
	struct s_stack	*head;
	char			*value;
	int				position;
} t_stack;

int	ft_strncmp(const char *s1, const char *s2, size_t n);
size_t	ft_strlen(const char *s);

t_stack *newstack(char *value);
void addstack(t_stack **stack, t_stack **new);
void freestack(t_stack *stack);

#endif
