#include<stdio.h>
void calculate ()
{
	static int num = 3;
	num = num * 3;
	printf("%d\n", num);
}
int main()
{
	printf("3��ƽ���ǣ�");
	calculate();
	printf("3�������ǣ�");
	calculate();
	return 0;
}