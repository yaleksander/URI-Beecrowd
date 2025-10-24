#include <stdio.h>
#include <math.h>

int ord(int n)
{
	int e = 0;
	while (n > 0)
	{
		n /= 10;
		e++;
	}
	return e;
}

void count(int n, int d[10], int i)
{
	while (n > 0)
	{
		d[n % 10] += i;
		n /= 10;
	}
}

int main()
{
	int a, b, d[10], e, k, p;
	scanf("%i%i", &a, &b);
	do
	{
		for (int i = 0; i < 10; i++)
			d[i] = 0;
		while (a <= b)
		{
			p = 10000000;
			while (p > 1 && b - a < p)
				p /= 10;
			while (p > 1 && (a / p) % 10 == 9)
				p /= 10;
			while (p > 1 && ord(p) > ord(a) + 1)
				p /= 10;
			e = ord(p) - 1;
			k = (a / p) % 10;
			if (p > 1 && k < 9)
			{
				count(a / (p * 10), d, p);
				for (int i = 0; i < 10; i++)
					d[i] += (p / 10) * e;
				d[k + 1] += a % p;
				if (a >= p)
					d[k] += p - a % p;
				a += p;
				continue;
			}
			count(a++, d, 1);
		}
		printf("%i", d[0]);
		for (int i = 1; i < 10; i++)
			printf(" %i", d[i]);
		printf("\n");
		scanf("%i%i", &a, &b);
	}
	while (b != 0);
	return 0;
}
