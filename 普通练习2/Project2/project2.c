#include<stdio.h>
#define PAI 3.141592653589793;

int main()
{
	double R;
	double Result=0;
	printf("������Բ�뾶��");
	scanf_s("%lf", &R);
	Result = R * R * PAI;
	printf("Բ������ǣ�%lf", Result);
	return 0;
}