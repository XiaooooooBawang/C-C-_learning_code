#include<stdio.h>   //ע�⣡�����������õ������鶼�Ǵӵ�0��ʼ�洢���ݣ���uv������Ե�ֵ�������ʵ�ʶ����ֵ�������õ�uv���鸴�����������ʱ��uv����ֵҪ-1����next���ù�-1
int  book[100], dis[100];
int u[11], v[11], w[11];    //u[i]�Ŷ��㵽v[i]�Ŷ���ı���w[i]
int first[100], next[100];   //first�����0-n-1�ŵ�Ԫ��ֱ������洢1-n�Ŷ���ĵ�һ���ߵı��
int main()
{
	int n, m,  start, min,inf=999999,k,x=0;       //n�Ƕ��������m�Ǳߵ�����,start����㣨Դ�㣩
	scanf_s("%d%d", &n, &m);
	printf("����ǣ�");
	scanf_s("%d", &start);
	//��ʼ��first����ֵ��Ϊ-1����ʾ1-n�Ŷ��㶼û�б�
	for (int i = 0; i < n; i++)
	{
		first[i] = -1;
	}
	//�ڽӱ�洢
	for (int i = 0; i < m; i++)
	{
		scanf_s("%d %d %d", &u[i],&v[i],&w[i]);   //����ÿһ����
		next[i] = first[u[i]-1];       
		first[u[i]-1] = i;
	}
	//��ʼ��dis���飬Ϊ��ԭʼ·��
	for (int i = 0; i < n; i++)
	{
		dis[i] = inf;
	}
	dis[start - 1] = 0;

	k = first[start - 1];
	while (k != -1)
	{
		dis[v[k]-1] = w[k];
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
		k = first[start - 1];            //�ڲ���Ѱ����Դ������������ʱ����Ҫ���ڽӱ���������Ϊ��Դ������ֵ�ǲ�����dis�и��µģ����ڽӱ��ǲ�����
		min = inf;
		while (k!=-1)
		{
			if (book[v[k]-1]==0&&dis[v[k]-1]<min)
			{
				min = dis[v[k] - 1];
				x = v[k]-1;
			}
			k = next[k];
		}
		/*min = inf;
		for (int j = 0; j < n; j++)
		{
			if (book[j] == 0 && dis[j] < min)
			{
				min = dis[j];
				x = j;
			}
		}*/
		book[x] = 1;
		k = first[x];             //�������������ڽӱ�����Ϊ����Ҫͨ�������ҵ������������ʵ���ɳڣ��Ǳ������Ǹ����г��߲ſ��Խ���
		while (k != -1)
		{
			if (book[v[k]-1]==0&&dis[v[k]-1] > w[k]+dis[u[k]-1] )
			{
				dis[v[k]-1] = w[k]+dis[u[k]-1];
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