#include <stdarg.h>
#include <unistd.h>

/* ---- your helpers ---- */

int	ft_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_putstr(char *s)
{
	int	i;

	if (s == NULL)
		return (write(1, "NULL", 4));
	i = 0;
	while (s[i])
	{
		write(1, &s[i], 1);
		i++;
	}
	return (i);
}

/* put a SIMPLE ft_putnbr just for this test */
int ft_putnbr(int n)
{
	char buf[12];
	int i = 0;
	long nb = n;

	if (nb == 0)
		return (write(1, "0", 1));
	if (nb < 0)
	{
		write(1, "-", 1);
		nb = -nb;
	}
	while (nb > 0)
	{
		buf[i++] = '0' + (nb % 10);
		nb /= 10;
	}
	while (i--)
		write(1, &buf[i], 1);
	return (0); // (length calc not important for this test)
}

/* ---- your type_specifier and ft_printf from before ---- */

int type_specifier(va_list *args, char c)
{
	int	va;

	va = 0;
    if (c == 's')
        va = ft_putstr(va_arg(*args, char *));
    else if (c == 'c')
        va = ft_putchar(va_arg(*args, int));
    else if (c == 'i' || c == 'd')
        va = ft_putnbr(va_arg(*args, int));
    else if (c == '%')
        va = ft_putchar('%');
    return (va);
}

int ft_printf(const char *format, ...)
{
    va_list args; 
	int i;
    int str_len;

	va_start(args, format);
	i = 0;
    str_len = 0;
	while (format[i])
	{
		if (format[i] == '%')
        {
            if (format[i + 1] != '\0')
            {
                str_len += type_specifier(&args, format[i + 1]);
                i++;
            }
        }
        else
            str_len += ft_putchar(format[i]);
        i++;
	}
    va_end(args);
    return (str_len);
}

int main (void)
{
    int what = 10;

    ft_printf("hello %c%c%c%c%c\n", 'w', 'o', 'r', 'l', 'd');
    return (0);
}
