#include<stdio.h>
#include<string.h>
#include<math.h>
char T[51] = {0};
char P[51] = {0};
int count, flag;
int main()
{
	scanf_s("%s", T, 51);
	scanf_s("%s", P, 51);
	int Tlength = strlen(T);
	int Plength = strlen(P);
	for (int i = 0; i < (Tlength - Plength +1); i++)    
	{
		count = 0;
		for (int j = i; j < (Plength +i); j++)
		{
			if (abs(T[j] - P[j - i]) == 0 || abs(T[j] - P[j - i]) == 32)    //������strlwr���ַ���ȫ��ת��Сд�Ͳ��ÿ�ASCII��
			if (abs(T[j] - P[j - i]) == 0 || abs(T[j] - P[j - i]) == 32)    //������strlwr���ַ���ȫ��ת��Сд�Ͳ��ÿ�ASCII��
			{
				count++;
			}
			else
				break;
		}
		if (count== Plength)
		{
			flag = 1;
			printf("%d", i);
			break;
		}
	}
	if (flag == 0)
		printf("������");
	return 0;
}