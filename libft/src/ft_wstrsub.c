
#include <libft.h>

wchar_t	*ft_wstrsub(wchar_t const *s, unsigned int start, size_t len)
{
	wchar_t	*sub;
	size_t	i;

	i = 0;
	if (!s || NULL == (sub = ft_wstrnew(len)))
		return (NULL);
	while (i < len)
	{
		sub[i] = s[start + i];
		i++;
	}
	sub[i] = L'\0';
	return (sub);
}
