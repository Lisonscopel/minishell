/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_minishell1.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lscopel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/17 15:37:50 by lscopel           #+#    #+#             */
/*   Updated: 2015/12/08 21:12:17 by lscopel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_MINISHELL1_H
# define FT_MINISHELL1_H

# include "libft.h"
# include <sys/types.h>
# include <sys/wait.h>
# include <sys/uio.h>
# include <sys/stat.h>
# include <signal.h>

# define BUFFLENGHT 1024

typedef struct		s_env
{
	char			**env;
	char			*oldpwd_backup;
	char			cmdline[BUFFLENGHT];
	char			**cmd;
	char			**bin;
	char			*prompt;
}					t_env;

typedef	struct		s_fct
{
	char			*id;
	int				(*ptr_funct)(char **, t_env *);
	struct s_fct	*next;
}					t_fct;

typedef	struct		s_error
{
	int				*error;
	char			*(*ptr_funct)(char *);
	struct s_fct	*next;
}					t_error;

void				cmd_receive(t_env env);
int					cmd_exec(char **cmd, char **bin_path, char **env);
int					cmd_bin_path(int exe, char **cmd, char **bin, char **env);
int					cmd_builtin_export_good_usage(char *cmd);
void				cmd_split(t_env *env);
char				*env_find_str(char *var, char **env);
int					env_find_index(char *var, char **env);
void				env_building_min(t_env *env);
void				env_building(char **src, t_env *env);
char				**env_set(t_env *env, char *var_name, char *new_content);
char				**parse_path_to_bin(char *var);
char				*parse_var_name(char *var, int equal);
char				*parse_permissions(const char *path);
void				list_init_builtins(t_fct **list);
int					ft_isbuiltin(char **cmd, t_env *env);
int					builtin_cd(char **cmd, t_env *env);
void				builtin_env(char **cmd, t_env *env);
void				builtin_exit(char **cmd, t_env *env);
int					builtin_unset(char **cmd, t_env *env);
int					builtin_export(char **cmd, t_env *env);
void				prompt_display(t_env *env);
int					error_cmd_nf(const char *cmd, char **bin, const unsigned int error);
void				error_builtin(char **cmd, const unsigned int error);
char				*get_pwd(t_env *env);
int					path_in_cmd_is_exec(char **cmd, t_env *env);

#endif
