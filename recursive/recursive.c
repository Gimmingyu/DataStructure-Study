#include  "recursive.h"

int	factorial(int n)
{
	int	ret = 0;

	if (n <= 1)
		ret = 1;
	else
		ret = n * factorial(n - 1);
	return (ret);
}

int	factorial_iter(int n)
{
	int	ret = 1;

	while (n)
		ret *= n--;
	return (ret);
}

int	fibonazzi(int n)
{
	if (n == 0)
		return (0);
	else if (n == 1)
		return (1);
	return (fibonazzi(n - 1) + fibonazzi(n - 2));
}

int	fibonazzi_iter(int n)
{
	if (n == 0)
		return (0);
	else if (n == 1)
		return (1);
	int	minus1 = 1;
	int	minus2 = 0;
	int	ret = 0;
	while (n-- - 1)
	{
		ret = minus2 + minus1;
		minus2 = minus1;
		minus1 = ret;
	}
	return (ret);
}

void	hanoi_tower(int n, int from, int to, int temp)
{
	if (n == 1)
		printf("%d move from %c to %c\n",n, from, to);
	else
	{
		hanoi_tower(n - 1, from, temp, to);
		printf("%d move from %c to %c\n",n , from, temp);
		hanoi_tower(n - 1, temp, to, from);
		printf("%d move from %c to %c\n",n , temp, to);
	}
}

int	main(void)
{
	int	t = 5;
	int	k = 2;
	int	i = 1;
	int	j = 0;

	printf("===============factorial===============\n");
	printf("%d! = %d\n", t, factorial(t));
	printf("%d! = %d\n", k, factorial(k));
	printf("%d! = %d\n", i, factorial(i));
	printf("%d! = %d\n", j, factorial(j));

	printf("===============factorial===============\n");
	printf("%d! = %d\n", t, factorial_iter(t));
	printf("%d! = %d\n", k, factorial_iter(k));
	printf("%d! = %d\n", i, factorial_iter(i));
	printf("%d! = %d\n", j, factorial_iter(j));

	printf("===============fibonazzi===============\n");
	printf("%d! = %d\n", t, fibonazzi(t));
	printf("%d! = %d\n", k, fibonazzi(k));
	printf("%d! = %d\n", i, fibonazzi(i));
	printf("%d! = %d\n", j, fibonazzi(j));

	printf("===============fibonazzi_iter===============\n");
	printf("%d! = %d\n", t, fibonazzi_iter(t));
	printf("%d! = %d\n", k, fibonazzi_iter(k));
	printf("%d! = %d\n", i, fibonazzi_iter(i));
	printf("%d! = %d\n", j, fibonazzi_iter(j));

	int	from = 'Z';
	int	to = 'A';
	int	temp = 'a';
	int	n = 2;
	printf("===============hanoi_tower===============\n");
	printf("from = %c, to = %c, temp = %d, n = %d\n", from, to, temp, n);
	hanoi_tower(n, from, to, temp);

	return (0);
}
