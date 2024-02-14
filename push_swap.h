/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbakrim <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/04 20:22:23 by hbakrim           #+#    #+#             */
/*   Updated: 2024/02/07 19:09:01 by hbakrim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <fcntl.h>
# include <limits.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 2
# endif

typedef struct s_list
{
	int				data;
	struct s_list	*next;
}					t_list;

// link_list
t_list				*create_node(int data);
void				lstadd_front(t_list **lst, t_list *new);
void				lstadd_back(t_list **lst, t_list *new);
int					lst_size(t_list *lst);
t_list				*lstlast(t_list *head);

// moves
void				sa(t_list **stack_a);
void				sb(t_list **stack_b);
void				ra(t_list **stack_a);
void				rb(t_list **stack_b);
void				rra(t_list **stack_a);
void				rrb(t_list **stack_b);
void				pb(t_list **stack_b, t_list **stack_a);
void				pa(t_list **stack_a, t_list **stack_b);
void				ss(t_list **stack_a, t_list **stack_b);
void				rr(t_list **stack_a, t_list **stack_b);
void				rrr(t_list **stack_a, t_list **stack_b);

// moves_bonus
void				sa_bonus(t_list **stack_a);
void				sb_bonus(t_list **stack_b);
void				ra_bonus(t_list **stack_a);
void				rb_bonus(t_list **stack_b);
void				rra_bonus(t_list **stack_a);
void				rrb_bonus(t_list **stack_b);
void				pb_bonus(t_list **stack_b, t_list **stack_a);
void				pa_bonus(t_list **stack_a, t_list **stack_b);
void				ss_bonus(t_list **stack_a, t_list **stack_b);
void				rr_bonus(t_list **stack_a, t_list **stack_b);
void				rrr_bonus(t_list **stack_a, t_list **stack_b);

// reuls
void				swap_r(t_list **stack);
void				rotate(t_list **stack);
void				reverse_rotate(t_list **stack);
void				push(t_list **stack_1, t_list **stack_2);

// utilis
int					ft_atoi(char *str);
int					is_sorted(t_list **stack);
void				ft_putendl_fd(char *s, int fd);
void				ft_free(char **str);
void				free_stack(t_list **stack);

// sort_simple
void				simpel_sort(t_list **stacke_a, t_list **stacke_b);
void				sort_3(t_list **stack_a);
void				sort_4(t_list **stack_a, t_list **stack_b);

// condition
int					index_stack(t_list **stack);
int					get_max(t_list **stack);
int					index_minstack(t_list **stack);
int					get_min(t_list **stack);

// sort_comple
void				sort_comple(t_list **stack_a, t_list **stack_b);
int					*copy_to_arr(t_list **stack_a);

// sort_arr
void				bubble_sort(int arr[], int size);
void				swap(int *a, int *b);

// push_to_stack_b
int					find_or_not(t_list **stack_a, int tab[], int start,
						int end);
int					position(t_list **stack_a, int *tab, int start, int end);
int					bestmove(t_list **stack_a, int arr[], int start, int end);
void				modif_start_end(int *start, int *end, int *offset,
						int size);
void				push_sort_to_b(t_list **stack_a, t_list **stack_b,
						int arr[], int size);
void				push_sort_to_b_100(t_list **stack_a, t_list **stack_b,
						int arr[], int size);
void				push_sort_to_b_500(t_list **stack_a, t_list **stack_b,
						int arr[], int size);

// push_to_stack_a
void				push_sort_to_a(t_list **stack_b, t_list **stack_a,
						int arr[], int size);
int					search(t_list **stack_b, int size);
void				bestmov_b(t_list **stack_b);
void				move(t_list **stack_b, t_list **stack_a, t_list **head,
						int *size);
void				botom_0(t_list **stack_b, t_list **stack_a, t_list **head,
						int *botom);
void				botom_1(t_list **stack_b, t_list **stack_a, int elem,
						int *botom);
void				norminette_1(t_list **stack_b, t_list **stack_a, int *size,
						t_list **head);

// ft_split
char				**ft_split(char const *s, char c);

// check_args
int					ft_isnum(char *num);
int					check_d(t_list **stack_a);
void				ft_error(char *msg);
int					ft_isdigit(int c);
int					check_int(char *str);

// bonus
// get_next_line
char				*get_next_line(int fd);
char				*ft_read_creat(int fd, char *s);
char				*ft_extract_line(char *s);

// get_next_line_utilis.c
char				*ft_strdup(const char *s);
char				*ft_strjoin(char *s, char *buf);
char				*ft_strchr(const char *s, int c);
size_t				ft_strlen(const char *s);

//ft_strcmp
int					ft_strcmp(char *s1, char *s2);

#endif
