#include <unistd.h>
#include <stdio.h>

size_t	count_words(const char *s, char c)
{
	size_t	words;
	size_t	i;
	int 	is_in_word;

	words = 0;
	i = 0;
	while (s[i] != '\0')
	{	
		is_in_word = 0;
		while (s[i] != '\0' && s[i] == c)
			i++;
		while (s[i] != '\0' && s[i] != c)
		{
			if (is_in_word == 0)
			{
				words++;
				is_in_word = 1;
			}
			i++;		
		}
	}
	return (words);	
}

int	main(void)
{
	printf("%ld\n", count_words("    hi   42  435  12   988  90\t 9   90  12  121   929\t\t\t\t\t\t\t 2     92   ", '\t'));

	return (0);
}