
#include <libft.h>

wchar_t		*ft_wstrffjoin(wchar_t **dst, wchar_t **src)
{
	wchar_t *tmp;

	if (*dst == NULL)
		*dst = ft_wstrdup(L"");
	tmp = ft_wstrdup(*dst);
	ft_memdel((void **)&(*dst));
	*dst = ft_wstrjoin(tmp, *src);
	ft_memdel((void **)&tmp);
	ft_memdel((void **)&(*src));
	return (*dst);
}
