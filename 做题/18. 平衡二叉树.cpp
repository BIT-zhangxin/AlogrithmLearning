//#include <stdio.h>
//#include <stdlib.h>
//#include <string.h>
//using namespace std;
//
//typedef char Elemtype;
//
//typedef struct NODE
//{
//	Elemtype data;
//	int Balance_Factor;
//	int depth;
//	struct NODE *child[2];
//}NODE, *PNODE;
//PNODE head;
//
//void Rotate(PNODE &parent, int branch)
//{
//	PNODE child = parent->child[branch];
//	parent->child[branch] = child->child[!branch];
//	child->child[!branch] = parent;
//	parent = child;
//}
//
//void PreserveBalance(PNODE &P, int branch)
//{
//	PNODE child = P->child[branch];
//	if (child->Balance_Factor == ((!branch) ? 1 : -1))
//	{
//		P->Balance_Factor = child->Balance_Factor = 0;
//		Rotate(P, branch);
//	}
//	else
//	{
//		PNODE grandchild = child->child[!branch];
//		if (grandchild->Balance_Factor == 1)
//		{
//			P->Balance_Factor = ((!branch) ? -1 : 1);
//			child->Balance_Factor = 0;
//		}
//		else if (grandchild->Balance_Factor == -1)
//		{
//			P->Balance_Factor = 0;
//			child->Balance_Factor = ((!branch) ? 1 : -1);
//		}
//		else
//		{
//			P->Balance_Factor = child->Balance_Factor = 0;
//		}
//		grandchild->Balance_Factor = 0;
//		Rotate(P->child[branch], !branch);
//		Rotate(P, branch);
//	}
//}
//
//int Insert(PNODE &P, Elemtype data, bool &taller) {
//	int branch;
//	if (!P) {
//		P = (PNODE)calloc(sizeof(NODE), 1);
//		P->data = data;
//		taller = true;
//	}
//	else {
//		if (data == P->data) {
//			taller = false;
//			return 0;
//		}
//		if (data < P->data) branch = 0;
//		else branch = 1;
//		if (!Insert(P->child[branch], data, taller)) return 0;
//		if (taller)
//		{
//			if (P->Balance_Factor == ((!branch) ? 1 : -1))
//			{
//				PreserveBalance(P, branch);
//				taller = false;
//			}
//			else if (P->Balance_Factor == 0)
//			{
//				P->Balance_Factor = (!branch) ? 1 : -1;
//				taller = true;
//			}
//			else
//			{
//				P->Balance_Factor = 0;
//				taller = false;
//			}
//		}
//	}
//	return 1;
//}
//
//void UpdateDepth(PNODE &P, PNODE parent) {
//	if (P == NULL)
//		return;
//	if (parent == NULL)
//		P->depth = 1;
//	else
//		P->depth = parent->depth + 1;
//	UpdateDepth(P->child[0], P);
//	UpdateDepth(P->child[1], P);
//}
//
//void traversal(PNODE P, int mode)
//{
//	if (!P) return;
//	switch (mode)
//	{
//	case 1:
//		printf("%c", P->data);
//		traversal(P->child[0], mode);
//		traversal(P->child[1], mode);
//		break;
//	case 2:
//		traversal(P->child[0], mode);
//		printf("%c", P->data);
//		traversal(P->child[1], mode);
//		break;
//	case 3:
//		traversal(P->child[0], mode);
//		traversal(P->child[1], mode);
//		printf("%c", P->data);
//		break;
//	default:
//		break;
//	}
//}
//
//void preorder()
//{
//	printf("Preorder: ");
//	traversal(head, 1);
//	putchar('\n');
//}
//
//void inorder()
//{
//	printf("Inorder: ");
//	traversal(head, 2);
//	putchar('\n');
//}
//
//void postorder()
//{
//	printf("Postorder: ");
//	traversal(head, 3);
//	putchar('\n');
//}
//
//char printchar[100] = { 0 };
//int printdepth[100] = { 0 };
//int printnum = 0;
//
//void print_opposite_component(PNODE P)
//{
//	if (P) {
//		print_opposite_component(P->child[0]);
//		printdepth[printnum] = P->depth;
//		printchar[printnum] = P->data;
//		printnum++;
//		print_opposite_component(P->child[1]);
//	}
//}
//
//void print_opposite()
//{
//	print_opposite_component(head);
//	printf("Tree:\n");
//	for (int i = printnum - 1; i >= 0; --i) {
//		for (int j = 1; j < printdepth[i]; j++)
//			printf("    ");
//		printf("%c\n", printchar[i]);
//	}
//}
//
//int main() {
//	char tmp;
//	bool tmp_bool = true;
//	while (scanf("%c", &tmp) && tmp != '\n')
//	{
//		Insert(head, tmp, tmp_bool);
//	}
//	UpdateDepth(head, NULL);
//	preorder();
//	inorder();
//	postorder();
//	print_opposite();
//	return 0;
//}