#include <stdio.h>
#include <stdlib.h>
#include<process.h>
int main()
{
	int count = 0;
	FILE* fp;
	FILE* cp;
	char ch = {0};
	char name[100] = {0};
	errno_t err;
	if ((err = fopen_s(&fp, "C:/Users/С����/Desktop/data", "r")) != 0)
	{
		printf("can not open1!");
		exit(0);
	}
	while ((fscanf_s(fp, "%s", name, 100)) == 1)
	{
		if ((err = fopen_s(&cp, name, "r")) != 0)
		{
			printf("can not open2!");
			exit(0);
		}
		while ((ch = fgetc(cp))!= EOF)
			{
					if (ch == '\n')
						count++;
			}	
	}
	
	printf("��������д��%d�д��룬����ˡ�ʮ���д��롱Ŀ���%d%%\n", count,count/1000);
	fclose(fp);
}