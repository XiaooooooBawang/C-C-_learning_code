#include<stdio.h>
#include<string.h>
int main()
{
	char String[7] = { "abcdef" }, Reverse[7] = {'\0'};
	int length,i;
	length = strlen(String);
	printf("ԭ�ַ�����%s\n", String);
	for (i = 0;i < 6; i++)
	{
		Reverse[length - i - 1] = String[i];
	}
	printf("��ת�ַ�����%s", Reverse);
	return 0;
}