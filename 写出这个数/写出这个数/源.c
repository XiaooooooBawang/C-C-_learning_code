#include<stdio.h>   /*�����У��Ұ����ַ�������һ���ˣ�������main����*/
/*����ֻ��ʵ������10λ����*/
int count=0;
int reverse(int num)    /*��תֻ���sum*/
{
	int j, w = 0;
	while (num!=0)
	{
		j = num % 10;
		num /= 10;
		w = w * 10 + j;   /*ʵ����������ת��genius idea*/
		count++;    /*ͳ��λ��ֻ���������ܺ�sum��ԭ�����������ֻ���ÿһλ��ͣ�����ͳ��λ��*/
	}
	return w;
};
int main()
{
	int n, a, b, c, sum = 0, i;
	scanf_s("%d", &n);
	do
	{
		a = n / 10;
		b = n % 10;
		sum += b;
		n = a;
	} while (n!=0);
	i = reverse(sum);
	while (i!=0)
	{
		c = i % 10;
		i /= 10;
		count--;
		switch (c)
		{
		case 0:
			printf("ling");
			break;
		case 1:
			printf("yi");
			break;
		case 2:
			printf("er");
			break;
		case 3:
			printf("san");
			break;
		case 4:
			printf("si");
			break;
		case 5:
			printf("wu");
			break;
		case 6:
			printf("liu");
			break;
		case 7:
			printf("qi");
			break;
		case 8:
			printf("ba");
			break;
		case 9:
			printf("jiu");
			break;
		default:
			break;
		}
		if (count != 0)
		{
			printf(" ");
		}
	}
}


/*����Ҫ������ſ���ʵ��10λ�����ϵ����룬����pta������*/
int main()
{
	char number[100];
	int sum=0,j,c;
	scanf_s("%s", number,100);
	for (int i = 0; number[i]!='\0'; i++)
	{
		sum += (number[i] - 48);  /*48�ǡ�0���ַ���ASCII�룬��Ϊnum��������ַ��ͣ�������ÿ��Ԫ�ش����������ASCII��洢*/
	}

	j = reverse(sum);            /*�ó�sum����͸������һ��*/
	while (j != 0)
	{
		c = j % 10;
		j /= 10;
		count--;
		switch (c)
		{
		case 0:
			printf("ling");
			break;
		case 1:
			printf("yi");
			break;
		case 2:
			printf("er");
			break;
		case 3:
			printf("san");
			break;
		case 4:
			printf("si");
			break;
		case 5:
			printf("wu");
			break;
		case 6:
			printf("liu");
			break;
		case 7:
			printf("qi");
			break;
		case 8:
			printf("ba");
			break;
		case 9:
			printf("jiu");
			break;
		default:
			break;
		}
		if (count != 0)
		{
			printf(" ");
		}
	}
}