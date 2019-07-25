#pragma once
#ifndef _MY_GLIST
#define _MY_GLIST

#include <stdio.h>
#include <stdlib.h>

class GLIST
{
private:
	typedef enum ElemTag
	{
		ATOM,
		LIST,
	}ElemTag;
public:
	typedef struct Gnode//广义表节点模板
	{
		ElemTag tag;
		union
		{
			char atom;
			struct
			{
				struct Gnode *hp, *tp;
			}ptr;
		};
	}Gnode, *Glist;
private:
	Glist zero;
	char *Find(char *p)//寻找字符匹配到结尾的位置
	{
		int Depth = 0;
		while (*p++ && Depth >= 0)
		{
			if (*p == '(')
			{
				Depth++;
			}
			else if (*p == ')')
			{
				Depth--;
			}
			if (*p == ','&&Depth == 0)
			{
				return p;
			}
		}
		return NULL;
	}

	int ChangeGlist_number = 0;//ChangeGlist组件
	char *ChangeGlist_str = NULL;//ChangeGlist组件
	void ChangeGlist_Component(Glist L, int sign)//ChangeGlist组件
	{
		if (L == NULL) return;
		else if (L->tag == ATOM) ChangeGlist_str[ChangeGlist_number++] = L->atom;
		else
		{
			if (sign == 1) ChangeGlist_str[ChangeGlist_number++] = '(';
			else ChangeGlist_str[ChangeGlist_number++] = ',';
			ChangeGlist_Component(L->ptr.hp, 1);
			ChangeGlist_Component(L->ptr.tp, 2);
			if (sign == 1) ChangeGlist_str[ChangeGlist_number++] = ')';
		}
	}

	void PrintGlist_Component(Glist L, int sign)//PrintGlist组件
	{
		if (L == NULL) return;
		else if (L->tag == ATOM) putchar(L->atom);
		else
		{
			if (sign == 1) putchar('(');
			else putchar(',');
			PrintGlist_Component(L->ptr.hp, 1);
			PrintGlist_Component(L->ptr.tp, 2);
			if (sign == 1) putchar(')');
		}
	}
public:
	Glist Head = NULL;
	GLIST()
	{
		zero = (Glist)calloc(sizeof(Gnode), 1);
		zero->tag = LIST;
	}
	GLIST(char *str)
	{
		zero = (Glist)calloc(sizeof(Gnode), 1);
		zero->tag = LIST;
		CreateGList(Head, str);
	}
	~GLIST()
	{
		DestroyGlist(Head);
	}
	//读取字符串转化为广义表
	void CreateGList(Glist &L, char *p)
	{
		if (!p) return;
		else if (*p == '(' || *p == ',')
		{
			L = (Glist)calloc(sizeof(Gnode), 1);
			L->tag = LIST;
			CreateGList(L->ptr.hp, p + 1);
			p = Find(p);
			CreateGList(L->ptr.tp, p);
		}
		else if ('a' <= *p && *p <= 'z')
		{
			L = (Glist)calloc(sizeof(Gnode), 1);
			L->tag = ATOM;
			L->atom = *p;
		}
	}
	//获得表头
	Glist GetHead(Glist L)
	{
		if (L == NULL) return NULL;
		else if (L->tag == ATOM) return NULL;
		else return L->ptr.hp;
	}
	//获得表尾
	Glist GetTail(Glist L)
	{
		if (L == NULL) return NULL;
		else if (L->ptr.tp == NULL)
		{
			return zero;
		}
		else return L->ptr.tp;
	}
	//删除广义表
	void DestroyGlist(Glist &L)
	{
		if (L == NULL) return;
		else if (L->tag == LIST)
		{
			DestroyGlist(L->ptr.hp);
			L->ptr.hp = NULL;
			DestroyGlist(L->ptr.tp);
			L->ptr.tp = NULL;
			free(L);
			L = NULL;
		}
		else if (L->tag == ATOM) free(L);
	}
	//将广义表转化为字符串
	void ChangeGlist(Glist L, char *string)
	{
		ChangeGlist_number = 0;
		ChangeGlist_str = string;
		ChangeGlist_Component(L, 1);
		ChangeGlist_str[ChangeGlist_number] = 0;
	}
	//打印广义表
	void PrintGlist(Glist L)
	{
		PrintGlist_Component(L, 1);
		putchar('\n');
	}
	bool IsATOM(Glist L)
	{
		if (L == NULL) return false;
		else if (L->tag == ATOM) return true;
		else return false;
	}
	bool IsLIST(Glist L)
	{
		if (L == NULL) return false;
		else if (L->tag == LIST) return true;
		else return false;
	}
};

#endif // _MY_GLIST