#include<stdio.h>     //Ҫʹ��������ȫ������������Ҫ����Ǵ�h��1����ʼ��h��0����ȥ
//�ҵ�k��С�������ͽ���СΪk����С���󣩶ѣ��������ÿ������Ѷ��Ƚϣ�С�����ڶѶ���Ҫ����С���ڶѶ��ͽ����������ѣ������Ƚ������������ĶѶ����ǵ�k��С������

int heap[101];
int  num, k;
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
	while (flag == 0 && 2 * w <= k)       //����������Ӿ��ܼ�������   //���Ѻ�ȡ����Сֵ������Ҫ�õ����µ�������������Ҫ�����ܵ�
	{
		if (heap[w] > heap[2 * w])
		{
			t = 2 * w;
		}
		else
		{
			t = w;
		}
		if ((2 * w + 1) <= k)    //������Ҷ���
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

void creat(int j)       //���ѣ�ÿ��С����ֵ�����µ������������������ǽڵ����ϵ���
{
	for (int i = j / 2; i >= 1; i--)     //���ϵ���
	{
		siftdown(i);        //���µ���
	}
};
int main()
{
	scanf_s("%d", &num);
	scanf_s("%d", &k);        //���k�����
	for (int i = 1; i <= num; i++)
	{
		scanf_s("%d", &heap[i]);
	}
	creat(k);
	for (int i = k+1; i <=num ; i++)
	{
		if (heap[i] <= heap[1])
			continue;
		else
		{
			swap(1, i);
			siftdown(1);
		}
	}
	printf("%d", heap[1]);
}