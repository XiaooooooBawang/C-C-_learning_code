#include<stdio.h>
#include<stdlib.h>
int main()
{
	int* Array,i;
	Array = (int*)calloc(3,sizeof(int));/*���߿���	Array = (int*)malloc( sizeof(int[3]));��Array = (int*)malloc(3*sizeof(int))*/
	if (Array  == NULL)
	{
		printf("fail");
	}
	else
	{
		printf("please input three number into the Array:\n");
		for (i = 0; i < 3; i++)
		{
			scanf_s("%d", (Array + i));/*��������int��3�������д��Array��i������������ʽ*/

		}
		for (i = 0; i < 3; i++)
		{
			printf("Array[%d]=%d\n", i, *(Array + i));
		}
	}
	free(Array);
	return 0;
}