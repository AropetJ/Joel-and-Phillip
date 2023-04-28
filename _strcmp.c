/**
 * _strcmp - function  compares the two strings str1 and str2.
 * @str1: first string
 * @str2: second strang
 *
 * Return: if s1 < s2 return negative, a positive if
 * s1 > s2 and zero if s1 == s2
 */

int _strcmp(char *str1, char *str2)
{
	if (*str2 && *str1)
	{
		if (*str1 != *str2)
			return (*str1 - *str2);
		str1++;
		str2++;
	}
	else if (*str1 == *str2)
		return (0);
	else
		return (*str1 < *str2 ? -1 : 1);
	return (0);
}
