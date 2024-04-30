#include "sort.h"
/**
 * _printf - produces output according to a format
 * @format: The character string
 * Return: The len of the characters printed.
 */
int _printf(const char *format, ...)
{
	va_list ap;
	int i, len = 0;

	if (format == NULL)
		return (-1);
	va_start(ap, format);
	for (i = 0; format[i] != '\0'; i++)
	{
		if (format[i] != '%')
		{
			len += write(1, &format[i], 1);
			continue;
		}
		i++;
		switch (format[i])
		{
			/*case 'c':*/
				/*len += print_c((char)va_arg(ap, int));*/
				/*break;*/
			/*case 's':*/
				/*len += print_s(va_arg(ap, char *));*/
				/*break;*/
			case 'd':
			case 'i':
				len += print_int(va_arg(ap, int));
				break;
			/*case 'b':*/
				/*len += print_b(va_arg(ap, int));*/
				/*break;*/
			case '%':
				len += write(1, "%", 1);
				break;
			default:
				len += write(1, "%%", 1);
				len += write(1, &format[i], 1);
				break;
		}
	}
	va_end(ap);
	return (len);
}
