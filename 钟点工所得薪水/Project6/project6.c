#include<stdio.h>
int main()
{
	int iHoursWorked , iHoursRate , iMoney;
	printf("����ʱ�䣺");
	scanf_s("%d",&iHoursWorked);
	printf("ʱн�ǣ�");
	scanf_s("%d",&iHoursRate);
	iMoney = iHoursRate * iHoursWorked;
	printf("һ�칤���ǣ�%d\n", iMoney);
	return 0;
}