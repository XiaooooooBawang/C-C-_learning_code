#include<stdio.h>
int a[100], n;
void quicksort(int left, int right)   /*left��Ҫ�������ж������λ����right��...��*/
{
	int i, j, temp, t;
	if (left >= right)    /*�ݹ��ʱ�����left>=right�����������ˣ�return�˳�*/
		return;
	temp = a[left];   /*������ߵ���Ϊ��׼������temp��¼*/
	i = left;
	j = right;    /*i,j���ڱ�*/
	while (i<j)
	{
		while (a[j] >= temp && i < j)       /*���ڱ�ǰ��*/ /*��������ȴ��ұ߿�ʼ*/  //���ڱ��Ȼ�׼��С��ͣ
		{
			j--;
		}
		while (a[i] <= temp && i < j)      //���ڱ��Ȼ�׼�����ͣ
		{
			i++;
		}
		if (i < j)
		{
			t = a[i];
			a[i] = a[j];    /*��ijû����֮ǰ��������������������*/
			a[j] = t;
		}
	}
	a[left] = a[i];    /*������λ��i��j���������׼��������ʹ��׼����λ*/
	a[i] = temp;
	quicksort(left, i - 1);
	quicksort(i + 1, right);      /*�����ڵ��ú����Լ�ʵ�ֵݹ�*/    /*��iλ�ѹ�λ*/
};
int main()
{
	scanf_s("%d", &n);
	for (int i = 0; i < n; i++)
	{
		scanf_s("%d", &a[i]);
	}
	quicksort(0, n - 1);
	for (int i = 0; i < n; i++)
	{
		printf("%d ", a[i]);
	}
	return 0;
}