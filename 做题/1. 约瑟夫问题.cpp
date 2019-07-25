//#include <stdio.h>
//#include <stdlib.h>
//
//typedef struct name
//{
//	int data;
//	struct name *next;
//}NODE, *PNODE;
//
//PNODE head;
//PNODE rear;
//
//void set();
//void push(int data);
//void move(int k);
//int pop(int m);
//
//int main()
//{
//	int n, k, m;
//	scanf("%d,%d,%d", &n, &k, &m);
//	if (n < 1 || k < 1 || m < 1)
//	{
//		printf("n,m,k must bigger than 0.\n");
//		return 0;
//	}
//	else if (k > n)
//	{
//		printf("k should not bigger than n.\n");
//		return 0;
//	}
//	set();
//	for (int i = 1; i <= n; i++)
//	{
//		push(i);
//	}
//	move((k - 2 + n) % n);
//	for (int i = 1; i <= n; i++)
//	{
//		if (i % 10 == 1)
//		{
//			printf("%d", pop(m));
//		}
//		else if(i % 10 == 0)
//		{
//			printf(" %d\n", pop(m));
//		}
//		else
//		{
//			printf(" %d", pop(m));
//		}
//	}
//	if (n % 10 != 0) putchar(10);
//	return 0;
//}
//
////初始化
//void set()
//{
//	head = (PNODE)calloc(sizeof(NODE), 1);
//	head->data = -1;
//	head->next = NULL;
//	rear = (PNODE)calloc(sizeof(NODE), 1);
//	rear->data = -1;
//	rear->next = NULL;
//}
//
////在队尾添加一个元素
//void push(int data)
//{
//	if (head->next == NULL)
//	{
//		rear->next = (PNODE)calloc(sizeof(NODE), 1);
//		head->next = rear->next;
//	}
//	else
//	{
//		rear->next->next = (PNODE)calloc(sizeof(NODE), 1);
//		rear->next = rear->next->next;
//	}
//	rear->next->data = data;
//	rear->next->next = head->next;
//}
//
////将head向后移动k个
//void move(int k)
//{
//	for (int i = 0; i < k; i++)
//	{
//		head->next = head->next->next;
//	}
//}
//
////找到返回并删除head后的第m个元素
//int pop(int m)
//{
//	move(m - 1);
//	PNODE deletion = head->next->next;
//	head->next->next = deletion->next;
//	int tmp = deletion->data;
//	free(deletion);
//	return tmp;
//}
