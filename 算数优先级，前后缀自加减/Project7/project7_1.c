#include<stdio.h>
int main()
{
	int iNum = 6, iNumPreAdd, iNumPreDel, iNumLastAdd, iNumLastDel;
	iNumPreAdd = ++iNum;
	iNumLastAdd = iNum++;
	printf("ԭ������%d", iNum);
	printf("ǰ׺�Լӣ�%d", iNumPreAdd);
	printf("��׺�Լӣ�%d", iNumLastAdd);
	iNum = 6;
	iNumPreDel = --iNum;
	iNumLastDel = iNum--;
	printf("ǰ׺�Լ���%d", iNumPreDel);
	printf("��׺�Լ���%d", iNumLastDel);
	return 0;
}