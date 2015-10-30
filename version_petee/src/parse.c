/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_path_treatment.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lscopel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/21 19:03:36 by lscopel           #+#    #+#             */
/*   Updated: 2015/10/30 19:53:06 by lscopel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_minishell1.h"

char	*env_find_str(char *var, char **env)
{
	int i = 0;

	while (env[i])
	{
		if (!ft_strncmp(env[i], var, ft_strlen(var)))
			break ;
		i++;
	}
	if (env[i] == NULL)
		return (NULL);
	return (env[i]);
}

int		env_find_index(char *var, char **env)
{
	int i = 0;
	while (env[i])
	{
		if (!ft_strncmp(env[i], var, ft_strlen(var)))
			break ;
		i++;
	}
	if (env[i] == NULL)
		return (-1);
	return (i);
}

char	**parse_path_to_bin(char *var)
{
	char	**bin;
	int		i;

	i = 0;
	bin = ft_strsplit(var, ':');
	if (bin)
	while (bin[i])
	{
		bin[i] = ft_strjoin(bin[i], "/");
		i++;
	}
	else
		ft_putcolorendl("[ERROR] PATH not defined", 31);
	return (bin);
}

char		*parse_var_name(char *var, int equal)
{
	char	*var_name;
	int		i;

	i = 0;
	while (var[i] != '=')
		i++;
	if (equal)
		i += 1;
	var_name = (char *)malloc(sizeof(char) * i + 1);
	var_name = ft_strncpy(var_name, var, i);
	return (var_name);
}

char	*parse_permissions(char *path)
{
	char		*perm;
	struct stat	file_stat;

	perm = NULL;
	if (stat(path, &file_stat) == 0)
	{
		perm = ft_strnew(10);
		perm[0] = ((S_ISDIR(file_stat.st_mode)) ? 'd' : '-');
		perm[1] = ((file_stat.st_mode & S_IRUSR) ? 'r' : '-');
		perm[2] = ((file_stat.st_mode & S_IWUSR) ? 'w' : '-');
		perm[3] = ((file_stat.st_mode & S_IXUSR) ? 'x' : '-');
		perm[4] = ((file_stat.st_mode & S_IRGRP) ? 'r' : '-');
		perm[5] = ((file_stat.st_mode & S_IWGRP) ? 'w' : '-');
		perm[6] = ((file_stat.st_mode & S_IXGRP) ? 'x' : '-');
		perm[7] = ((file_stat.st_mode & S_IROTH) ? 'r' : '-');
		perm[8] = ((file_stat.st_mode & S_IWOTH) ? 'w' : '-');
		perm[9] = ((file_stat.st_mode & S_IXOTH) ? 'x' : '-');
	}
	return (perm);
}
