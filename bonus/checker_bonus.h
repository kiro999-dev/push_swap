/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zkhourba <zkhourba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 18:04:34 by zkhourba          #+#    #+#             */
/*   Updated: 2025/01/09 19:45:21 by zkhourba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
#define CHECKER_H
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
long long	ft_atoi(const char *str,int *flagerr);
int			ft_strncmp(const char *s1, const char *s2, size_t n);
void 		add_to_stack(t_stack **head,int num,int pos);
void 		free_stack(t_stack **head);
void		parsing(char **argv, t_stack **head);
void 		s(t_stack **stack,int flag);
int 		list_len(t_stack *stack);
void    	pa(t_stack **stack_a ,t_stack **stack_b,int flag);
void  		pb(t_stack **stack_a ,t_stack **stack_b,int flag);
void 		r(t_stack **stack,int flag);
void 		ss(t_stack **stack_a , t_stack **stack_b);
void 		rev_r(t_stack **stack,int flag);
t_stack 	*ft_last(t_stack *stack);
void		rr(t_stack **stack_a,t_stack **stack_b);
void		rrr(t_stack **stack_a,t_stack **stack_b);
char		*get_next_line(int fd);
#endif 