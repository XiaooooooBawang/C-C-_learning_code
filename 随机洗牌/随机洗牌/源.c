#include<stdlib.h>
#include<time.h>
#include<stdio.h>
int main()
{
	int a[10],random,temp,result[10];
	for (int i = 0; i < 10; i++)
	{
		scanf_s("%d", &a[i]);
	}
	for (int i = 0; i < 10; i++)
	{
		srand((unsigned int)time(0));
		random = rand() % 10;   //����0-9��Χ�ڵ��������������a���±�
		if (random==i)
		{
			i--;
		}
		else
		{
			temp = a[i];
			a[i] = a[random];
			a[random] = temp;
		}
	}
	for (int i = 0; i < 10; i++)
	{
		result[i] = a[i];
		printf("%d ", result[i]);
	}
	return 0;
}