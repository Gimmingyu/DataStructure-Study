# 재귀함수

재귀함수는 정의 단계에서 자기 자신을 재참조하는 함수를 뜻한다.

간단한 예시는 다음과 같다.

``` C

int factorial(int n)
{
	if (n == 1)
    	return (1);
    return (n * factorial(n - 1));
}

```

팩토리얼을 간략하게 구현해놓은 함수이다. 함수 내부의 정의에서 자기 자신을 다시 참조하는데, 이러한 구조를 지니는 함수를 재귀함수라고 한다. 

모든 반복문으로 이루어진 함수는 재귀로 표현이 가능하며, 그 역도 성립한다. 

재귀함수가 자기 자신을 호출할 때마다 콜스택에 쌓이게 된다. 특정 분기(종료 조건)을 만나게 될 때까지 스택처럼 쌓이게 될 것이다. 

이러한 재귀함수를 구현할 때 개발자의 실수로 종료 조건을 설정하지 않거나, 결과값이 제대로 수렴하지 않는 경우에는 스택 오버플로우가 일어날 수 있다.

## 재귀함수의 장점
1. 현재 상태를 저장할 때 변수를 새로 만들 필요가 없다. 재귀적으로 호출을 하면서 전달하게 되면 변수를 생성해 저장해둘 필요가 없게 된다.
2. 반복문을 이용할 때보다 코드가 간결해진다. 즉, 구현이 쉽다.

## 재귀함수의 단점
1. 지속적으로 함수를 호출하게 되면서 지역변수, 매개변수, 반환값을 모두 process stack에 저장해야한다. 이런 과정은 선언한 변수의 값만 사용하는 반복문에 비해서 메모리를 더 많이 사용하게 되고, 이는 속도 저하로 이어진다.
2. 함수 호출 -> 복귀를 위한 컨텍스트 스위칭에 비용이 발생하게 된다.

코드 예시

``` C
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

```


