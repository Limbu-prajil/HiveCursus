char	*ft_strstr(const char *big, const char *little, size_t len)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	if (little[j] == '\0')
		return (big);
	while (big[i] != '\0' && i < len - 1)
	{
		while (big[i + j] == little[j] && big[i + j] != '\0')
			j++;
		if (little[j] == '\0')
			return (big + j);
		i++;
		j = 0;
	}
	return (0);
}
