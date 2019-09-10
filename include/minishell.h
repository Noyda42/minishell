/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: temehenn <temehenn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/03 18:36:32 by temehenn          #+#    #+#             */
/*   Updated: 2019/09/10 17:27:20 by temehenn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef 	MINISHELL_H
# define	MINISHELL_H
# include	"libft.h"
# include	"error.h"
# include	<stdio.h>
# define	TRUE	1
# define	FALSE	0
# define 	ECHO_OPT	"neE"

typedef	struct	s_option
{
	char 		*opt;
	char		opterr;
	int			optind;
}				t_option;

typedef struct	s_env
{
	char		*name;
	char		*content;
}				t_env;


int			ft_getopt(int ac, char **av, const char *opt_ref, t_option *opt);
void    	manage_error(int error_code);
void		free_tab(char **tab);
char		**copy_tab(char **tab);
int			ft_echo(char **tab);
void		free_elem_env_lst(void *env, size_t size);
t_list		*create_env_list(char **env);
void		print_env(t_list *env);
int			interpreter(t_list *env, char *line);
char		*get_env_content(t_list *env, char *env_name);

#endif