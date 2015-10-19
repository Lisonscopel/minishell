#include "ft_minishell1.h"

void	prompt_display()
{
	char *pwd;
	char buf[BUFFLENGHT];

	pwd = getcwd(buf, BUFFLENGHT);
	pwd = ft_strrchr_exclude(pwd, '/');
	if (!ft_strcmp(pwd, "lscopel"))
		pwd = ft_strdup("~");
	pwd = ft_strjoin(pwd, " > ");
	ft_putcolor(pwd, 33);
	bzero(buf, BUFFLENGHT);
	free(pwd);
}
