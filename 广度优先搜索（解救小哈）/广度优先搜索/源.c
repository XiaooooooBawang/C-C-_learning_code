#include<stdio.h>
struct note
{
	int x;
	int y;
	int s;
}queue[400];
int main()
{
	int a[20][20] = { 0 }, book[20][20] = { 0 };
	int head = 0, tail = 0;    //���г�ʼ��
	int way[4][2] = { {0,1},{1,0},{-1,0},{0,-1} };
	int startx, starty, m, n, mapx, mapy,tx,ty;
	int flag = 0;     //��������Ƿ񵽴��յ㣬0Ϊ��1Ϊ��
	scanf_s("%d%d", &mapx, &mapy);    //�����ͼ��С
	printf("�뵼���ͼ��0�ǿյأ�1���ϰ���\n");
	for (int i = 0; i < mapx; i++)
	{
		for (int j = 0; j < mapy; j++)
		{
			scanf_s("%d", &a[i][j]);
		}
	}
	printf("������꣺\n");
	scanf_s("%d%d", &startx, &starty);
	printf("�յ����꣺\n");
	scanf_s("%d%d", &m, &n);
	book[startx][starty] = 1;
	a[m][n] = 0;

	//�����㷨��ʼ
	queue[tail].x = startx;
	queue[tail].y = starty;
	queue[tail].s = 0;
	tail++;                 //�������в����ʼ����
	while (head<tail)    //���в�Ϊ��ʱ����ѭ����������չ��һ����
	{
		for (int k = 0; k < 4; k++)     //�����о���չ����һ������ĸ�����
		{
			tx =queue[head].x+ way[k][0];
			ty = queue[head].y+way[k][1];      //���㸸������һ���������
			if (tx<0||ty<0||tx>=mapx||ty>=mapy)
				continue;
			if (a[tx][ty]==0&&book[tx][ty]==0)
			{
				book[tx][ty] = 1;
				queue[tail].x = tx;
				queue[tail].y = ty;
				queue[tail].s = queue[head].s + 1;
				tail++;                             //���ֺ��ʵĵ����
				
			}
			if (tx==m&&ty==n)
			{
				flag = 1;
				break;    //��������յ㣬����forѭ��������������һ����չ�о�
			}
		}
		if (flag == 1)
			break;       //��������յ㣬����whileѭ��������������һ����չ�о٣�������break����Ϊ��for��while����ѭ����Ҫ��������
		head++;      //��һ��������չ����һ�����Ҫ�Ժ���ĵ������չ
	}
	printf("���·���ǣ�%d", queue[tail - 1].s);
	return 0;
}