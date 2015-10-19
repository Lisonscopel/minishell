#include "libft.h"

char		*ft_strrchr_exclude(const char *s, int c)
{
	int		lenght;
	char	*s_new;

	s_new = (char *)s;
	if (s)
	{
		lenght = ft_strlen(s);
		while (lenght >= 0)
		{
			if (s_new[lenght] == c)
				return (s_new + lenght + 1);
			lenght--;
		}
	}
	return (NULL);
}
