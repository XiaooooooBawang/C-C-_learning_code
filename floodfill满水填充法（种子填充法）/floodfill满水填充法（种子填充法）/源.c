#include<stdio.h>
int a[20][20] = { 0 }, book[20][20] = { 0 };
int  mapx, mapy, tx, ty,num=0;
int way[4][2] = { {0,1},{1,0},{-1,0},{0,-1} };

void dfs(int x,int y,int color)
{
	a[x][y] = color;
	for (int k = 0; k < 4; k++)
	{
		tx = x + way[k][0];
		ty = y + way[k][1];
		if (tx < 0 || ty < 0 || tx >= mapx || ty >= mapy)
			continue;
		if (a[tx][ty]>0&&book[tx][ty]==0)
		{
			book[tx][ty] = 1;
			dfs(tx, ty, color);
		}
	}
	return;
};
int main()
{
	scanf_s("%d%d", &mapx, &mapy);    //�����ͼ��С
	printf("�뵼���ͼ��0�Ǻ���0������½��\n");
	for (int i = 0; i < mapx; i++)
	{
		for (int j = 0; j < mapy; j++)
		{
			scanf_s("%d", &a[i][j]);
		}
	}
	for (int i = 0; i < mapx; i++)
	{
		for (int j = 0; j < mapy; j++)
		{
			if (a[i][j]>0)
			{
				num--;      //С����ҪȾ����ɫ�ı�ţ�ÿ����һ��С��ҪͿ��ͬ����ɫ������ÿ��Ҫ��1
				book[i][j] = 1;
				dfs(i,j,num);

			}
		}
	}
	for (int i = 0; i < mapx; i++)
	{
		for (int j = 0; j < mapy; j++)
		{
			printf("%3d", a[i][j]);
		}
		printf("\n");
	}
	printf("��%d��С��", -num);
	return 0;
}