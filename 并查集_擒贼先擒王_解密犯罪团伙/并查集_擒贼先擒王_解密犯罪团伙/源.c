#include<stdio.h>
int f[100];       //�����±��ʾǿ����ţ�����ֵ��ʾ�±�ǿ�����ϰ�
int getf(int v)    //�ҵ��ĵݹ麯��
{
	if (f[v] == v)
		return f[v];
	else
	{
		f[v] = getf(f[v]);
		return f[v];
	}
}
void merge(int u,int w)
{
	int t1, t2;
	t1 = getf(u);
	t2 = getf(w);
	if (t1!=t2)
	{
		f[t2] = t1;    //����ԭ��
	}
}
int main()
{
	int n, m,x,y,sum=0;         //n��������m����������
	scanf_s("%d%d", &n, &m);
	for (int i = 1; i <= n; i++)      //��ʼ��f���Լ������Լ��ϰ�
	{
		f[i] = i;
	}
	for (int i = 0; i < m; i++)
	{
		scanf_s("%d%d", &x, &y);
		merge(x, y);
	}
	for (int i = 1; i <= n; i++)
	{
		if (f[i]==i)
		{
			sum++;
		}
	}
	printf("%d", sum);
}