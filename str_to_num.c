#include "main.h"
// int str_to_num(char *s)
// {
//     int i = 0;

//     if (!s)
//     {
//         dprintf(2, "L%i: usage: push integer\n", line_number);
//         exit(EXIT_FAILURE);
//     }
//     if (s[0] == '-')
// 		i = 1;
//     while (s[i])
//     {
//         if (!isdigit(s[i]))
//             return (0);
//         i++;
//     }
//     return (atoi(s));
// }
int str_to_num(char *s)
{
	int i = 0, n = 0;

	if (!s)
	{
		dprintf(2, "L%i: usage: push integer\n", line_number);
		return (-1);
	}
	if (s[0] == '-')
		i = 1;
	for (; s[i] != '\0'; i++)
		if (!isdigit(s[i]))
		{
			dprintf(2, "L%i: usage: push integer\n", line_number);
			return (-1);
		}
	n = atoi(s);
	return (n);
}