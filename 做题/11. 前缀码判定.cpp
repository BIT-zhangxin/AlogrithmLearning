//#include <stdio.h>
//#include <stdlib.h>
//#include <string.h>
//
//typedef struct NODE
//{
//	char exist;
//	struct NODE *lp;
//	struct NODE *rp;
//}NODE, *PNODE;
//
//char A[50000] = { 0 };
//bool ans = false;
//
//void build(char *p,PNODE node)
//{
//	if (*p == '0')
//	{
//		if (*(p + 1) == 0)
//		{
//			if (node->lp == NULL)
//			{
//				node->lp = (PNODE)calloc(sizeof(NODE), 1);
//				node->lp->exist = 2;
//			}
//			else ans = true;
//		}
//		else
//		{
//			if (node->lp == NULL)
//			{
//				node->lp = (PNODE)calloc(sizeof(NODE), 1);
//				node->lp->exist = 1;
//			}
//			else
//			{
//				if (node->lp->exist == 2) ans = true;
//			}
//			build(p + 1, node->lp);
//		}
//	}
//	else if (*p == '1')
//	{
//		if (*(p + 1) == 0)
//		{
//			if (node->rp == NULL)
//			{
//				node->rp = (PNODE)calloc(sizeof(NODE), 1);
//				node->rp->exist = 2;
//			}
//			else ans = true;
//		}
//		else
//		{
//			if (node->rp == NULL)
//			{
//				node->rp = (PNODE)calloc(sizeof(NODE), 1);
//				node->rp->exist = 1;
//			}
//			else
//			{
//				if (node->rp->exist == 2) ans = true;
//			}
//			build(p + 1, node->rp);
//		}
//	}
//}
//
//void clear(PNODE node)
//{
//	if (node->lp) clear(node->lp);
//	if (node->rp) clear(node->rp);
//	free(node);
//	node = NULL;
//}
//
//int main()
//{
//	int n;
//	scanf("%d", &n);
//	PNODE head = (PNODE)calloc(sizeof(NODE), 1);
//	while (n--)
//	{
//		scanf("%s", A);
//		build(A,head);
//		if (ans)
//		{
//			printf("%s\n", A);
//			clear(head);
//			return 0;
//		}
//	}
//	if (!ans) printf("YES\n");
//	clear(head);
//	return 0;
//}