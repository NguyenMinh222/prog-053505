#include<stdio.h>
#include<math.h>
#include<locale.h>
float x, e;
int n = 0;
double action(double p)
{
	double a, b;
	if (fabs(p) < e) return p;
	else
	{
		n++;
		a = 2*n;
		b = 2*n+1;
		return p + action(-p * x * x / a / b);
	}
}
double iter()
{
	double p, sum, a, b;
	sum = p = x;
	n = 1;
	while (fabs(p) > e)
	{
		a = 2 * n;
		b = 2 * n + 1;
		p *= -x * x / a / b;
		sum += p;
		n++;
	}
	return sum;
}
int main()
{
	char* locale = setlocale(LC_ALL, "Rus");
	printf("������� �������� �: ");
	scanf_s("%f", &x);
	printf("������� ����� e: ");
	scanf_s("%f", &e);
	printf("sin(x): %f\n", sin(x));
	printf("�������� sin(x): %f\n", action(x));
	printf("����������� ��������� ���������� �� sin x �����, ��� �� �������� ����������� � ��� n: %d\n", ++n);
	printf("��������� sin(x): %f\n", iter());
	printf("����������� ��������� ���������� �� sin x �����, ��� �� �������� ����������� � ��� n : % d\n", ++n);
	system("pause");
	return 0;
}
