#include<stdio.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node* next;
};
int main()
{
	struct node* head, * p, * q,*t;  /*head��ͷָ��,p����һ���ڵ㣬q���½ڵ�*/
	int n, a, i;
	scanf_s("%d", &n);
	head = NULL;
	for ( i = 0; i < n; i++)
	{
		scanf_s("%d", &a);
		p = (struct node*)malloc(sizeof(struct node));
		q = (struct node*)malloc(sizeof(struct node));

		if (p==NULL||q==NULL)
		{
			printf("��������ʧ��");
		}
		else
		{
			p->data = a;
			p->next = NULL;
			if (head == NULL)
			{
				head = p;
			}
			else
			{
				q->next = p;
			}
			q = p;
		}
	}
	t = head;
	while (t!=NULL)
	{
		printf("%d ", t->data);
		t = t->next;
	}
	free(q);

}