//#include <stdio.h>
//#include <stdlib.h>
//
//struct name
//{
//	int data;
//	struct name *next;
//};
//typedef name NODE;
//typedef NODE* PNODE;
//PNODE head;
//PNODE rear;
//void push(int data)
//{
//	rear->next = (PNODE)calloc(sizeof(NODE), 1);
//	rear->next->data = data;
//	rear = rear->next;
//}
//
//int front()
//{
//	return head->next->data;
//}
//
//void pop()
//{
//	PNODE p = head->next;
//	head->next = head->next->next;
//	free(p);
//	if (head->next == NULL) rear = head;
//}
//
//int main()
//{
//	int n = 10;
//	rear = head = (PNODE)calloc(sizeof(NODE), 1);
//	for (int i = 0; i < n; i++)
//	{
//		push(i);
//	}
//	printf("yes\n");
//	for (int i = 0; i < n; i++)
//	{
//		printf("%d\n", front());
//		pop();
//	}
//	getchar();
//	push(10);
//	printf("%d\n", front());
//	return 0;
//}