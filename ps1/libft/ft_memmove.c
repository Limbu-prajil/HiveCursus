#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	if (src < dst)
	{
		while (len > 0)
		{
			len--;
			*((unsigned char *)dst + len) = *((unsigned char *)src + len);
		}
	}
	else if (dst < src)
		return (ft_memcpy(dst, src, len));
	return (dst);
}
