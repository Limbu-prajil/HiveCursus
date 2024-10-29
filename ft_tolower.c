int	ft_tolower(int c)
{
	if (c >= 'a' && c <= 'z')
	{
		return (c);
	}
	else
	{
		c += 32;
	}
	return (c);
}
