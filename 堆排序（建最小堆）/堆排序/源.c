#include<stdio.h>     //Ҫʹ��������ȫ������������Ҫ����Ǵ�h��1����ʼ��h��0����ȥ
int heap[101];
int n,num;
void swap(int x, int y)     //��������x��y�Žڵ��ֵ
{
	int temp;
	temp = heap[x];
	heap[x] = heap[y];
	heap[y] = temp;
};

void siftdown(int w)
{
	int t, flag = 0;
	while (flag == 0 && 2 * w <= n)       //����������Ӿ��ܼ�������   //���Ѻ�ȡ����Сֵ������Ҫ�õ����µ�������������Ҫ�����ܵ�
	{
		if (heap[w] > heap[2 * w])
		{
			t = 2 * w;
		}
		else
		{
			t = w;
		}
		if ((2 * w + 1) <= n)    //������Ҷ���
		{
			if (heap[t] > heap[2 * w + 1])
			{
				t = 2 * w + 1;
			}
		}
		if (t != w)
		{
			swap(w, t);
			w = t;
		}
		else
		{
			flag = 1;
		}
	}
};

void creat()       //���ѣ�ÿ��С����ֵ�����µ������������������ǽڵ����ϵ���
{
	for (int i = n/2; i >=1; i--)     //���ϵ���
	{
		siftdown(i);        //���µ���
	}
};
int deletemin()      //ȡ����Сֵ
{
	int j;
	j = heap[1];
	heap[1] = heap[n];
	n--;
	siftdown(1);    //�ӵ�һ���ڵ㿪ʼ����
	return j;
};
int main()
{
	scanf_s("%d", &num);
	n = num;     //num�Ƕ���ʵ�Ĵ�С��n�Ƕѿɴ���Ĵ�С����ʱdeletemin��n--����С�ѿɴ���Ĵ�С
	for (int i = 1; i <= num; i++)
	{
		scanf_s("%d", &heap[i]);
	}
	creat();
	for (int i = 1; i <= num; i++)
	{
		printf("%d ",deletemin());
	}
}