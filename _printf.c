#include "main.h"

/**
 * p_all_char - prints chars from _printf
 * @chrArg: inbound chrArg
 * Return: just prints to SO
 */
void p_all_char(va_list chrArg)
{
	write_to_SO(va_arg(chrArg, int));
}

/**
 * p_all_int - prints ints from _printf
 * @intArg: inbound intArg
 * Return: just prints to SO
 */
void p_all_int(va_list intArg)
{
	write_int(va_arg(intArg, int));
}

/**
 * _printf - prints to SO
 * @format: input args format string
 * Return: void (none)
 */
int _printf(const char *format, ...)
{
	int i = 0, j;
	va_list varArg;
	char *delim = "";
	char Arr[] = "ci";
	_pcall betty[] = {{p_all_char}, {p_all_int}};

	va_start(varArg, format);
	while (format && format[i])
	{
		j = 0;
		while (Arr[j])
		{
			if (format[i] == Arr[j])
			{
				betty[j].fun(varArg);
			}
			j++;
		}
		i++;
	}
	va_end(varArg);
	write_to_SO(10);
}
