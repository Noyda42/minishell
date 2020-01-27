/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: temehenn <temehenn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/03 18:36:32 by temehenn          #+#    #+#             */
/*   Updated: 2019/12/02 18:35:44 by temehenn         ###   ########.fr       */
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

typedef struct	s_buitlin
{
	char		name[16];
	int			(*buitlin)(t_list **, char **);
}				t_builtin;


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

int			update_pwd(t_list **env);
int			ft_getopt(int ac, char **av, const char *opt_ref, t_option *opt);
void    	manage_error(int error_code);
void		free_tab(char **tab);
char		**copy_tab(char **tab);
void		free_elem_env_lst(void *env, size_t size);
t_list		*create_env_list(char **env);
int			print_env(t_list *env);
int			interpreter(t_list **env, char *line);
char		*get_env_content(t_list *env, char *env_name);
int			is_in_dir(char *path, char **command);
int			detect_command(t_list *env, char **command);
char		*get_env_content(t_list *env, char *env_name);
int			exec_command(t_list **env, char **av);
int			is_builtin(char *command);
int			apply_expansion(t_list *env, char ***av);
int			dollar_expansion(t_list *env, char **av);
t_list		*find_component(t_list *env, char *env_name);
int			ft_setenv(t_list **env, char **arg);
int			ft_unsetenv(t_list **env, char **arg);
int			ft_cd(t_list **env, char **arg);
int			ft_echo(t_list **env, char **arg);
int			ft_exit(t_list **env, char **arg);
char		**envlst_to_envtab(t_list *env);
int			ft_env(t_list **env, char **arg);

#endif