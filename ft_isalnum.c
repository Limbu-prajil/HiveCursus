int	ft_isalnum(int c)
{
	if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z')
                                || !(c >= 48 && c <= 57))
	{
		return (0);
	}
	else
	{
		return (1);
	}
}
