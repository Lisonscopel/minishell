#include <string.h>
void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	int					a;
	unsigned char		*b;
	const unsigned char	*c;

	if (!dst || !src)
		return (NULL);
	a = 0;
	b = (unsigned char*)dst;
	c = (const unsigned char*)src;
	while (n--)
	{
		b[a] = c[a];
		++a;
	}
	return (dst);
}
/*
   void	*ft_memcpy(void *dst, const void *src, size_t n)
   {
   char *d;
   char *s;
   int		i;
   int		j;

   d = (char*)dst;
   s = (char*)src;
   i = 0;
   j = 0;
   while (n)
   {
   d[i++] = s[j++];
   n--;
   }
   return (dst);
   }
   */
