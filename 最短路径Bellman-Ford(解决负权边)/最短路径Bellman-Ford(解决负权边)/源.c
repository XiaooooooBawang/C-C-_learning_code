#include<stdio.h>
int dis[10];
int u[11], v[11], w[11];    //u[i]�Ŷ��㵽v[i]�Ŷ���ı���w[i]
int main()
{
	int n, m, start, inf = 999999;       //n�Ƕ��������m�Ǳߵ�����,start����㣨Դ�㣩
	scanf_s("%d%d", &n, &m);
	printf("����ǣ�");
	scanf_s("%d", &start);
	for (int i = 0; i < m; i++)
	{
		scanf_s("%d %d %d", &u[i], &v[i], &w[i]);   //����ÿһ����
	}

	//��ʼ��dis���飬�����Լ�ȫ����inf�������������ѭ��������
	for (int i = 0; i < n; i++)
	{
		dis[i] = inf;
	}
	dis[start-1] = 0;
	//Bellmen-Ford�������
	for (int k = 0; k < n-1; k++)   //�ɳ�n-1��
	{
		for (int i = 0; i < m; i++)   //ö��ÿһ����
		{
			if (dis[v[i]-1]>dis[u[i]-1]+w[i])    //ע�⣡����dis�����õ�uv�����ֵҪ-1
			{
				dis[v[i]-1] = dis[u[i]-1] + w[i];
			}
		}
	}
	for (int i = 0; i < n; i++)
	{
		printf("%d ", dis[i]);
	}
	return 0;
}