#include<stdio.h>
int e[10][10],book[10];
int m, n, a, b, c,min=999999;

void dfs(int cur,int dis)     //cur�ǵ�ǰ����
{
	if (dis > min)        //�����ǰ����·���Ѿ�����֮ǰ�ҵ������·��û��Ҫ�����ߣ�ֱ�ӷ��أ���ʡʱ��
		return;
	if (cur==n-1)          //�ж��Ƿ񵽴�Ŀ��
	{
		if (dis < min)
			min = dis;     //����Ŀ���鿴��ǰ·�̣��ж��Ƿ��ܸ�����Сֵ
		return;
	}
	for (int j = 0; j < n; j++)
	{
		if (e[cur][j]!=0&&e[cur][j]!=999999&&book[j]==0)
		{
			book[j] = 1;
			dfs(j,dis+e[cur][j]);
			book[j] = 0;
		}
	}
	return;
};
int main()
{
	scanf_s("%d%d", &n, &m);
	for (int i = 0; i < n; i++)             //�ȳ�ʼ����Ӿ������飬���������븲��
	{
		for (int j = 0; j < n; j++)
		{
			if (i==j)
			{
				e[i][j] = 0;
			}
			else
			{
				e[i][j] = 999999;
			}
		}
	}
	for (int i = 0; i < m; i++)
	{
		scanf_s("%d%d%d", &a, &b, &c);
		e[a - 1][b - 1] = c;
	}
	book[0] = 1;    //���1�ţ�0����������
	dfs(0,0);     //��һ����1�ţ�0������
	printf("���·����%d",min);
}