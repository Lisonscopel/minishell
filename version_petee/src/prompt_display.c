#include "ft_minishell1.h"

void	prompt_display(t_env *env)
{
	char *pwd;
	char buff[BUFFLENGHT];

	if ((pwd = getcwd(buff, BUFFLENGHT)) == NULL)
		pwd = ft_strrchr_exclude(env_find_str("PWD", env->env), '=');
	pwd = ft_strrchr_exclude(pwd, '/');
	if (!ft_strcmp(pwd, "lscopel"))
		pwd = ft_strdup("~");
	pwd = ft_strjoin(pwd, " > ");
	ft_putcolor(pwd, 33);
	bzero(buff, BUFFLENGHT);
	free(pwd);
}
