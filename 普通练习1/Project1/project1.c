#include<stdio.h>
#define Height 10
int calculate(int Length, int Width);
int m_Length;
int m_Width;
int result;
int calculate(int Length, int Width)
{
	int result = Length * Width * Height;
	return result;
}
int main()
{
	printf("�����εĸ߶��ǣ�%d\n", Height);

	printf("�����볤��\n");
	scanf_s("%d", &m_Length);

	printf("��������\n");
	scanf_s("%d", &m_Width);
	result = calculate(m_Length, m_Width);
	printf("������������");
	printf("%d", result);
	return 0;
}