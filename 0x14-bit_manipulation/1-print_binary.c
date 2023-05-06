#include "main.h"

/**
 * _power - calculate the (base and power)
 * @base: base of exponent
 * @pow: power of exponent
 * Return: value of the base & power
 */
unsigned long int _power(unsigned int base, unsigned int pow)
{
    unsigned long int num = 1;
    
    for (unsigned int i = 1; i <= pow; i++)
    {
        num *= base;
    }
    
    return num;
}

/**
 * print_binary - prints binary representation of a number
 * @n: the number to print in binary
 * Return: void
 */
void print_binary(unsigned long int n)
{
    unsigned long int mask = _power(2, sizeof(unsigned long int) * 8 - 1);
    int flag = 0;
    
    while (mask > 0)
    {
        if ((n & mask) == mask)
        {
            _putchar('1');
            flag = 1;
        }
        else if (flag == 1 || mask == 1)
        {
            _putchar('0');
        }
        
        mask >>= 1;
    }
}
