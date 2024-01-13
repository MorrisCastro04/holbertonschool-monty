#include "monty.h"
/**
* Integer_check - Check if a string is a valid integer.
* @str: The input string to be checked.
* Return: 1 if @str is a valid integer, 0 otherwise.
*/
int Integer_check(const char *str)
{
	if (!str || !*str || (*str != '-' && !isdigit(*str)))
		return (0);

	for (int i = 1; str[i]; i++)
	{
		if (!isdigit(str[i]))
			return (0);
	}
	return (1);
}

