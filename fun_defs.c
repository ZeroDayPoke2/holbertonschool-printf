#include "main.h"

/**
 * p_all_char - prints chars from _printf
 * @chrArg: inbound chrArg
 * Return: just prints to SO
 */
int p_all_char(va_list chrArg)
{
	int totesWrite = 0;

	totesWrite += write_to_SO(va_arg(chrArg, int));
	return (totesWrite);
}

/**
 * p_all_int - prints ints from _printf
 * @intArg: inbound intArg
 * Return: just prints to SO
 */
int p_all_int(va_list intArg)
{
	int totesWrite = 0;

	totesWrite += write_int(va_arg(intArg, int));
	return (totesWrite);
}

/**
 * p_all_str - prints strings from print_all
 * @strArg: inbound strArg
 * Return: just prints to SO
 */
int p_all_str(va_list strArg)
{
	int totesWrite = 0;
	char *charArr;

	charArr = va_arg(strArg, char *);
	totesWrite += write_string(charArr);
	return (totesWrite);
}
