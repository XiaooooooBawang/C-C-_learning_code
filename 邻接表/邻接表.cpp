#include<stdio.h>
int  book[10], dis[10];
int u[11], v[11], w[11];    //u[i]�Ŷ��㵽v[i]�Ŷ���ı���w[i]
int first[10], next[10];   //first�����0-n-1�ŵ�Ԫ��ֱ������洢1-n�Ŷ���ĵ�һ���ߵı��
int main()
{
	int n, m,  start, min,inf=999999,k,x=0;       //n�Ƕ��������m�Ǳߵ�����,start����㣨Դ�㣩
	scanf("%d%d", &n, &m);
	printf("����ǣ�");
	scanf("%d", &start);
	//��ʼ��first����ֵ��Ϊ-1����ʾ1-n�Ŷ��㶼û�б�
	for (int i = 0; i < n; i++)
	{
		first[i] = -1;
	}
	//�ڽӱ�洢
	for (int i = 0; i < m; i++)
	{
		scanf("%d %d %d", &u[i],&v[i],&w[i]);   //����ÿһ����
		next[i] = first[u[i]];       
		first[u[i]] = i;
	}
	//��ʼ��dis���飬Ϊ��ԭʼ·��
	dis[start - 1] = 0;
	for (int i = 1; i < n; i++)
	{
		dis[i] = inf;
	}
	k = first[start - 1];
	while (k != -1)
	{
		dis[v[k]] = w[k];
		k = next[k];
	}
	for (int i = 0; i < n; i++)
	{
		book[i] = 0;
	}
	book[start - 1] = 1;
	//Dijkstra�����㷨
	for (int i = 0; i < n - 1; i++)
	{
		min = inf;
		for(int j=0;j<n;j++)
		{
			if(book[j]==0&&dis[j]<min)
			{
				min=dis[j];
				x=j;
			}
		}
		
		book[x] = 1;
		k = first[x];
		while (k != -1)
		{
			if (book[v[k]]==0&&dis[v[k]] > w[k]+dis[u[k]] )
			{
				dis[v[k]] = w[k]+dis[u[k]];
			}
			k = next[k];
		}
	}
	for (int i = 0; i < n; i++)
	{
		printf("%d ", dis[i]);
	}
	return 0;
}
