#include<stdio.h>
int e[10][10], book[10];
struct node
{
	int cur;    //��ǰ����
	int sum;   //ת������
}queue[100];
int main()
{
	int n, m,start,end,a,b,head=0,tail=0;
	int flag=0;
	scanf_s("%d%d", &n, &m);       //n���ж��ٸ�����,m���ж�����·
	scanf_s("%d%d", &start, &end);
	for (int i = 0; i < m; i++)        //��ʼ����Ӿ�������
	{
		scanf_s("%d%d", &a, &b);
		e[a - 1][b - 1] = 1;
		e[b - 1][a - 1] = 1;      //��ͼΪ����ͼ
	}
	queue[tail].cur = start;     //��ʼ�����
	queue[tail].sum = 0;
	book[start] = 1;
	tail++;
	while (head<tail)
	{
		for (int k = 0; k < n; k++)
		{
			if (e[queue[head].cur][k]!=0&&book[k]==0)
			{
				book[k] = 1;
				queue[tail].cur = k;
				queue[tail].sum=queue[head].sum+1;    //ֻ�дӸ�����չ�ɹ���һ����ܼ�һ
				tail++;
			}
			if (queue[tail].cur==end)
			{
				flag = 1;
				break;
			}
		}
		if (flag == 1)
			break;
		head++;
	}
	printf("����ת��%d��", queue[tail-1].sum);
	return 0;
}