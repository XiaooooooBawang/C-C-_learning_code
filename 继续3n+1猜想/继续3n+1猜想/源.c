#include<stdio.h>
int main()
{
	int k,j,t=0,max,temp;
	int a[100] = { 0 }, b[5000] = { 0 }, c[100] = {0};  /*pta�б����������b���Ƚϴ󡿣�Ҳֻ�бȽϴ����ͨ������vs����̫��*/
	scanf_s("%d", &k);
	/*��¼����*/
	for (int i = 0; i < k; i++)
	{
		scanf_s("%d", &a[i]);
		j = a[i];     
		if (b[j]==1)   /*ֻ���������������ж��Ƿ���֤������Ϊ�����ܳ�����֤�����е�ĳ����û����֤��*/
		{
			continue;
		}
		b[j] = 0;      /*�ܺõ��뷨������b������飬�൱�ڸ������������������ڱ���Ϊÿ���������Ƿ��Ѹ��ǣ�1��0�񣩣�����ٶԱ��ϵ�����������*/
		while (j!=1)
		{
			if (j%2==0)
			{
				j /= 2;
				b[j] = 1;
			}
			else
			{
				j = (3 * j+1) / 2;
				b[j] = 1;
			}
		}
	}
	for (int i = 0; i < k; i++)
	{
		if (b[a[i]]!=1)
		{
			c[t] = a[i];
			t++;
		}
	}
	/*�������*/
	for (int i = 0;  i < t;  i++)
	{
		max = c[i];
		for (int n = i+1; n <t+1 ; n++)
		{
			if (c[n]>=max)
			{
				temp = c[n];
				c[n] = c[i];
				c[i] = temp;
			}
		}
	}
	for (int i =0 ; i <t; i++)
	{
		printf("%d", c[i]);
		if (i!=t-1)
		{
			printf(" ");
		}
	}
	return 0;
}


