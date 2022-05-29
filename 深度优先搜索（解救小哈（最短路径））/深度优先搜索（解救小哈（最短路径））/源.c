#include<stdio.h>
int  m,n,startx,starty,mapx,mapy,min=99999;   /*(m,n)��Ŀ������꣬(startx,starty)���������,mapx��mapy�ǵ����ͼ�ı߽�*/
int a[50][50],book[50][50];  /*a�ǵ�ͼ���飬book�ǡ�����*/
int way[4][2] = { {0,1},{1,0},{0,-1},{-1,0} };   /*�������飬��������˳ʱ��˳��*/
void dfs(int x,int y,int step)
{
	int tx, ty;
	if (x==m&&y==n)
	{
		if (min > step)
			min = step;
		return;
	}
	for (int i = 0; i < 4; i++)
	{
		tx = x + way[i][0];
		ty = y + way[i][1];
		if (tx<0||ty<0||tx>=mapx||ty>=mapy)
			continue;
		if (a[tx][ty]==0&&book[tx][ty]==0)
		{
			book[tx][ty] = 1;
			dfs(tx, ty, step + 1);
			book[tx][ty] = 0;
		}
	}
	return;
}
int main()
{
	scanf_s("%d%d", &mapx, &mapy);
	printf("�뵼���ͼ��0�ǿյأ�1���ϰ���\n");
	for (int i = 0; i < mapx; i++)
	{
		for (int j = 0; j < mapy; j++)
		{
			scanf_s("%d", &a[i][j]);
		}
	}
	printf("������꣺\n");
	scanf_s("%d%d",&startx,&starty );
	printf("�յ����꣺\n");
	scanf_s("%d%d", &m, &n);
	book[startx][starty] = 1;
	a[m][n] = 0;
	dfs(startx, starty, 0);
	printf("���ٲ�����%d", min);
	return 0;
}