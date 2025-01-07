/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zkhourba <zkhourba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/05 19:35:17 by zkhourba          #+#    #+#             */
/*   Updated: 2025/01/07 18:32:18 by zkhourba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H
#include <limits.h>
#include <stdlib.h>
#include <unistd.h>


typedef struct s_stack 
{
	int				number;
	int				index;
	struct s_stack	*next;
	int				pos;
}	t_stack;

char		**ft_split(const char *s, char c);
void		ft_putstr_fd(char *s, int fd);
void		ft_free(char **ptr);
long long	ft_atoi(const char *str);
int			ft_strncmp(const char *s1, const char *s2, size_t n);
void 		add_to_stack(t_stack **head,int num,int pos);
void 		free_stack(t_stack **head);
void		parsing(char **argv, t_stack **head);
void 		s(t_stack **stack,int flag);
void   		pa(t_stack **stack_a ,t_stack **stack_b);
void   		pb(t_stack **stack_a ,t_stack **stack_b);
void 		r(t_stack **stack,int flag);
void 		rev_r(t_stack **stack,int flag);
int 		list_len(t_stack *stack);
t_stack 	*ft_last(t_stack *stack);
void		rrr(t_stack **stack_a,t_stack **stack_b,int flag);
void 		s(t_stack **stack,int flag);
void 		mini_sort(t_stack **a,t_stack **b,int n);
void		the_big_sort(t_stack **a,t_stack **b,int n);
#endif 
