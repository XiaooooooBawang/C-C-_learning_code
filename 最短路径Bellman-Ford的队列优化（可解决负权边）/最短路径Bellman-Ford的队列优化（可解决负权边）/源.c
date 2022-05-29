#include<stdio.h>
int dis[10], bak[10];
int u[11], v[11], w[11];    //u[i]�Ŷ��㵽v[i]�Ŷ���ı���w[i]
int first[11], next[11],book[11];
int queue[10], head, tail;  
int main()
{
	int n, m, start, inf = 999999, flag = 0, check = 0,k;       //n�Ƕ��������m�Ǳߵ�����,start����㣨Դ�㣩
	scanf_s("%d%d", &n, &m);
	printf("����ǣ�");
	scanf_s("%d", &start);
	for (int i = 0; i < n; i++)
	{
		first[i] = -1;
	}
	for (int i = 0; i < m; i++)
	{
		scanf_s("%d %d %d", &u[i], &v[i], &w[i]);   //����ÿһ����
		next[i] = first[u[i] - 1];                  //�ڽӱ�洢
		first[u[i]-1]=i;
	}

	//��ʼ��dis���飬�����Լ�ȫ����inf�������������ѭ��������
	for (int i = 0; i < n; i++)
	{
		dis[i] = inf;
	}
	dis[start - 1] = 0;
	head = 0;     //���г�ʼ��
	tail = 0;
	queue[head] = start;
	tail++;
	//Bellmen-Ford�������
	while (head<tail)
	{
		k = first[queue[head]-1];
		while (k!=-1)
		{
			if (dis[v[k]-1]>dis[u[k]-1]+w[k])   //�ɳ�
			{
				dis[v[k] - 1] = dis[u[k] - 1] + w[k];
				if (book[v[k]-1]==0)           //���Ǽ������
				{
					queue[tail] = v[k];
					tail++;
					book[v[k] - 1] = 1;
				}
			}
			k = next[k];
		}
		book[queue[head] - 1] = 0;     //����
		head++;
	}
	
	for (int i = 0; i < m; i++)      //��⸺Ȩ��·����������ȫ�����ɳں���Ȼ���ڴ����������и�Ȩ��·
	{
		if (dis[v[i] - 1] > dis[u[i] - 1] + w[i])
		{
			flag = 1;
		}
	}
	if (flag == 1)
	{
		printf("���ڸ�Ȩ��·");
	}
	else
	{
		for (int i = 0; i < n; i++)
		{
			printf("%d ", dis[i]);
		}
	}
	return 0;
}