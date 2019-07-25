//#include <stdio.h>
//#include <stdlib.h>
//
//class GLIST
//{
//private:
//	typedef enum ElemTag
//	{
//		ATOM,
//		LIST,
//	}ElemTag;
//public:
//	typedef struct Gnode//�����ڵ�ģ��
//	{
//		ElemTag tag;
//		union
//		{
//			char atom;
//			struct
//			{
//				struct Gnode *hp, *tp;
//			}ptr;
//		};
//	}Gnode, *Glist;
//private:
//	Glist zero;
//	char *Find(char *p)//Ѱ���ַ�ƥ�䵽��β��λ��
//	{
//		int Depth = 0;
//		while (*p++ && Depth >= 0)
//		{
//			if (*p == '(')
//			{
//				Depth++;
//			}
//			else if (*p == ')')
//			{
//				Depth--;
//			}
//			if (*p == ','&&Depth == 0)
//			{
//				return p;
//			}
//		}
//		return NULL;
//	}
//
//	int ChangeGlist_number = 0;//ChangeGlist���
//	char *ChangeGlist_str = NULL;//ChangeGlist���
//	void ChangeGlist_Component(Glist Left, int sign)//ChangeGlist���
//	{
//		if (Left == NULL) return;
//		else if (Left->tag == ATOM) ChangeGlist_str[ChangeGlist_number++] = Left->atom;
//		else
//		{
//			if (sign == 1) ChangeGlist_str[ChangeGlist_number++] = '(';
//			else ChangeGlist_str[ChangeGlist_number++] = ',';
//			ChangeGlist_Component(Left->ptr.hp, 1);
//			ChangeGlist_Component(Left->ptr.tp, 2);
//			if (sign == 1) ChangeGlist_str[ChangeGlist_number++] = ')';
//		}
//	}
//
//	void PrintGlist_Component(Glist Left, int sign)//PrintGlist���
//	{
//		if (Left == NULL) return;
//		else if (Left->tag == ATOM) putchar(Left->atom);
//		else
//		{
//			if (sign == 1) putchar('(');
//			else putchar(',');
//			PrintGlist_Component(Left->ptr.hp, 1);
//			PrintGlist_Component(Left->ptr.tp, 2);
//			if (sign == 1) putchar(')');
//		}
//	}
//public:
//	Glist Head = NULL;
//	GLIST()
//	{
//		zero = (Glist)calloc(sizeof(Gnode), 1);
//		zero->tag = LIST;
//	}
//	GLIST(char *str)
//	{
//		zero = (Glist)calloc(sizeof(Gnode), 1);
//		zero->tag = LIST;
//		CreateGList(Head, str);
//	}
//	//��ȡ�ַ���ת��Ϊ�����
//	void CreateGList(Glist &Left, char *p)
//	{
//		if (!p) return;
//		else if (*p == '(' || *p == ',')
//		{
//			Left = (Glist)calloc(sizeof(Gnode), 1);
//			Left->tag = LIST;
//			CreateGList(Left->ptr.hp, p + 1);
//			p = Find(p);
//			CreateGList(Left->ptr.tp, p);
//		}
//		else if ('a' <= *p && *p <= 'z')
//		{
//			Left = (Glist)calloc(sizeof(Gnode), 1);
//			Left->tag = ATOM;
//			Left->atom = *p;
//		}
//	}
//	//��ñ�ͷ
//	Glist GetHead(Glist Left)
//	{
//		if (Left == NULL) return NULL;
//		else if (Left->tag == ATOM) return NULL;
//		else return Left->ptr.hp;
//	}
//	//��ñ�β
//	Glist GetTail(Glist Left)
//	{
//		if (Left == NULL) return NULL;
//		/*else if (Left->ptr.tp == NULL)
//		{
//			return zero;
//		}*/
//		else return Left->ptr.tp;
//	}
//	//ɾ�������
//	void DestroyGlist(Glist &Left)
//	{
//		if (Left == NULL) return;
//		else if (Left->tag == LIST)
//		{
//			DestroyGlist(Left->ptr.hp);
//			Left->ptr.hp = NULL;
//			DestroyGlist(Left->ptr.tp);
//			Left->ptr.tp = NULL;
//			free(Left);
//			Left = NULL;
//		}
//		else if (Left->tag == ATOM) free(Left);
//	}
//	//�������ת��Ϊ�ַ���
//	void ChangeGlist(Glist Left, char *string)
//	{
//		ChangeGlist_number = 0;
//		ChangeGlist_str = string;
//		ChangeGlist_Component(Left, 1);
//		ChangeGlist_str[ChangeGlist_number] = 0;
//	}
//	//��ӡ�����
//	void PrintGlist(Glist Left)
//	{
//		PrintGlist_Component(Left, 1);
//		putchar('\n');
//	}
//	bool IsATOM(Glist Left)
//	{
//		if (Left == NULL) return false;
//		else if (Left->tag == ATOM) return true;
//		else return false;
//	}
//	bool IsLIST(Glist Left)
//	{
//		if (Left == NULL) return false;
//		else if (Left->tag == LIST) return true;
//		else return false;
//	}
//};
//
//int max_degree = 0;
//int num_of_degree[100] = { 0 };
//
//void Degree(GLIST LIST, GLIST::Glist Left)
//{
//	int n = 0;
//	while (1)
//	{
//		Left = LIST.GetTail(Left);
//		if (Left != NULL) n++;
//		else break;
//	}
//	if (n > max_degree) max_degree = n;
//	num_of_degree[n]++;
//}
//
//void PrintAtom(int Tab_number,char atom)
//{
//	while (Tab_number--) printf("    ");
//	putchar(atom);
//	putchar(10);
//}
//
//void PrintTree(GLIST LIST,GLIST::Glist Left,int Tab_number)
//{
//	if (Left == NULL) return;
//	if (LIST.IsATOM(Left))
//	{
//		PrintAtom(Tab_number, Left->atom);
//	}
//	else if (LIST.IsATOM(Left->ptr.hp))
//	{
//		Degree(LIST, Left);
//	}
//	PrintTree(LIST, LIST.GetHead(Left), Tab_number + 1);
//	PrintTree(LIST, LIST.GetTail(Left), Tab_number);
//}
//
//int main()
//{
//	char str[1000] = { 0 };
//	scanf("%s", str);
//	GLIST LIST(str);
//	PrintTree(LIST, LIST.Head, -1);
//	printf("Degree of tree: %d\n", max_degree);
//	for (int i = 0; i <= max_degree; i++)
//	{
//		printf("Number of nodes of degree %d: %d\n", i, num_of_degree[i]);
//	}
//	LIST.DestroyGlist(LIST.Head);
//	return 0;
//}