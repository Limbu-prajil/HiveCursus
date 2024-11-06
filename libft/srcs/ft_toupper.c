int	ft_toupper(int c)
{
	if (c >= 'A' && c <= 'Z')
	{
		return (c);
	}
	else
	{
		c -= 32;
	}
	return (c);
}
