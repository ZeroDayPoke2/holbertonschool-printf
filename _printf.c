#include "main.h"

/**
 * _printf - prints supported formats to SO
 * @format: input args format string
 * Return: number of chars printed or -1 on fail
 */
int _printf(const char *format, ...)
{
	int i = 0, j, totesWrite = 0;
	va_list varArg;
	_pcall betty[] = {{p_all_int, 'd'}, {p_all_int, 'i'},
	{p_all_char, 'c'}, {p_all_str, 's'}, {p_all_bin, 'b'}};

	if (format == NULL || (format[i] == '%' && !format[i + 1]))
		return (-1);
	va_start(varArg, format);
	while (format[i])
	{
		if (format[i] == '%' && format[i + 1])
		{
			if (format[i + 1] == '%')
				totesWrite += write_to_SO('%');
			else
			{
				for (j = 0; betty[j].formChar; j++)
					if (format[i + 1] == betty[j].formChar)
						totesWrite += betty[j].fun(varArg, 0);
				if ((format[i + 1] != 'd' && format[i + 1] != 'c' && format[i + 1] != 'b'
				&& format[i + 1] != 'i' && format[i + 1] != 's' && format[i + 1] != '%'))
				{
					totesWrite += write_to_SO('%');
					totesWrite += write_to_SO(format[i + 1]);
				}
			}
			i++;
		}
		else if (format[i] == '%' && !(format[i + 1]))
			totesWrite = -1;
		else
			totesWrite += write_to_SO(format[i]);
		i++;
	}
	va_end(varArg);
	return (totesWrite);
}
