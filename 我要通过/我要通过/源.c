/*
  ��ֻ����PAT�����ַ�
  ��PT����ֻ����һ��
  ��A������һ��
  ��P��T���
  ��PT��������һ��A
  ��P��ߵ�A*PT֮���A=T�ұߵ�A
  ��p���A��t�ҵ�A����PAT�Գ�
  */
#include<stdio.h>
#include<string.h>
int main()
{
	char str[100] = {0};
	int n,i,j,len;   /*ѭ����������*/
	int pi, ti;     /*pat���Ե�λ��*/
	int pleft = 0, pt = 0, tright = 0;   /*p��ߡ�pt�䡢t�ұ�a�ĸ���*/
	int pnum=0, anum=0,tnum=0;   /*pat�����ַ�������*/
	scanf_s("%d", &n);
	for (i = 0; i < n; i++)
	{
		scanf_s("%s", str,100);
		len = strlen(str);
		for (j = 0; j < len; j++)         /*ͳ��pat��������*/
		{
			if(str[j]=='P')
			{
				pi = j;
				pnum++;
			}
			else if (str[j] == 'A')
			{
				anum++;
			}
			else if (str[j] == 'T')
			{
				ti = j;
				tnum++;
			}
		}
		pleft = pi - 0;
		pt = ti - pi - 1;             
		tright = len - ti - 1;
		if (pnum!=1||tnum!=1||anum==0||pi>=ti||(pnum+anum+tnum)!=len||pt<1)   /*�Ȱ�ûA��P��T�ұߣ����������ַ����ȿ���*/
		{
			printf("NO\n");
		}
		else                                /*Ȼ����Ƕ�ֻ��pat�ַ��Ľ�����ѧ���ų�*/
		{
			if (pt=1)
			{
				if (pleft!=tright)
				{
					printf("NO\n");
				}
				else
				{
					printf("YES\n");

				}
			}
			else
			{
				if ()
				{

				}
			}
		}
	}
	|| (pi - 0) * (ti - pi - 1) != (len - ti - 1)
}