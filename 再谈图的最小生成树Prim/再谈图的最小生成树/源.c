#include<stdio.h>
int e[100][100],dis[100],book[100];
int n, m,inf=999999,count,sum,min;
int main()
{
	int u,v,w,j=0;
	scanf_s("%d%d", &n, &m);
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (i==j)
			{
				e[i][j] = 0;
			}
			else
			{
				e[i][j] = inf;
			}
		}
	}
	for (int i = 0; i < m; i++)
	{
		scanf_s("%d%d%d",&u,&v,&w);
		e[u-1][v-1] = w;
		e[v-1][u-1] = w;
	}
	for (int i = 0; i < n; i++)   //1�Ŷ���Ϊ���
	{
		dis[i] = e[0][i];
	}
	book[0] = 1;
	count=1;
	//prim�����㷨
	while (count < n)
	{
		min = inf;
		for (int i = 0; i < n; i++)            //ö��ѡ����������������������С�ĵ����������
		{
			if (book[i] == 0 && dis[i] < min)
			{
				min = dis[i];
				j = i;
			}
		}
		book[j] = 1;
		count++;
		sum += dis[j];
		for (int k = 0; k < n; k++)        //ö�ٸռ���ĵ�����г��ߣ��ɳ������������㵽����������̾���
		{
			if (book[k]==0&&dis[k]>e[j][k])
			{
				dis[k] = e[j][k];
			}
		}
	}
	printf("%d", sum);
	return 0;
}