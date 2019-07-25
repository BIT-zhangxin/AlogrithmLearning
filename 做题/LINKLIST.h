#pragma once
#ifndef _MY_LINKLIST
#define _MY_LINKLIST

#include <stdlib.h>

template<typename Type>
class LINKLIST
{
private:
	struct name
	{
		Type data;
		struct name *next;
	};
	typedef name NODE;
	typedef NODE* PNODE;
	int Linked_list_number;
	PNODE head;
	PNODE rear;
public:
	//���캯��
	LINKLIST()
	{
		head = (PNODE)calloc(sizeof(NODE), 1);
		head->data = -1;
		head->next = NULL;
		rear = (PNODE)calloc(sizeof(NODE), 1);
		rear->data = -1;
		rear->next = NULL;
		Linked_list_number = 0;
	}
	//��������
	~LINKLIST()
	{
		clear();
		free(head);
		free(rear);
	}
	//��Ԫ����ӵ���β
	void push(Type data)
	{
		if (empty())
		{
			rear->next = (PNODE)calloc(sizeof(NODE), 1);
			head->next = rear->next;
		}
		else
		{
			rear->next->next = (PNODE)calloc(sizeof(NODE), 1);
			rear->next = rear->next->next;
		}
		rear->next->data = data;
		rear->next->next = NULL;
		Linked_list_number++;
	}
	//��Ԫ����ӵ���β
	void push_back(Type data)
	{
		if (empty())
		{
			rear->next = (PNODE)calloc(sizeof(NODE), 1);
			head->next = rear->next;
		}
		else
		{
			rear->next->next = (PNODE)calloc(sizeof(NODE), 1);
			rear->next = rear->next->next;
		}
		rear->next->data = data;
		rear->next->next = NULL;
		Linked_list_number++;
	}
	//��Ԫ����ӵ���ͷ
	void push_front(Type data)
	{
		if (empty())
		{
			push(data);
		}
		else
		{
			PNODE addition = (PNODE)calloc(sizeof(NODE), 1);
			addition->data = data;
			addition->next = head->next;
			head->next = addition;
			Linked_list_number++;
		}
	}
	//��Ԫ����ӵ���n��Ԫ�غ�
	void push_num(Type data,int n)
	{
		if (n < 0 || n > Linked_list_number) return;
		if (n == 0)
		{
			push(data);
			return;
		}
		PNODE p = head;
		while (n > 1)
		{
			if (p == NULL) return;
			else p = p->next;
			n--;
		}
		PNODE addition = (PNODE)calloc(sizeof(NODE), 1);
		p->next == rear->next && (rear->next = addition);
		addition->next = p->next;
		p->next = addition;
		Linked_list_number++;
	}
	//����ͷԪ��
	Type front()
	{
		if (empty()) return (Type)0;
		return head->next->data;
	}
	//����βԪ��
	Type back()
	{
		if (empty()) return (Type)0;
		return rear->next->data;
	}
	//���ص�n��Ԫ��
	Type visit(int n)
	{
		if (n == 0) return (Type)0;
		if (n > Linked_list_number) return (Type)0;
		PNODE p = head;
		while (n--)
		{
			p = p->next;
		}
		return p->data;
	}
	//���ҵ�һ�����Ԫ�صı��
	int find(Type data)
	{
		PNODE p = head;
		int num = 0;
		while (p->next)
		{
			p = p->next;
			num++;
			if (p->data == data) return num;
		}
		return -1;
	}
	//ɾ��ͷԪ��
	void pop()
	{
		if(empty()) return;
		PNODE deletion = head->next;
		head->next = deletion->next;
		free(deletion);
		Linked_list_number&&Linked_list_number--;
	}
	//ɾ����һ�����Ԫ��
	void pop_equal(Type data)
	{
		PNODE p = head;
		while (p->next)
		{
			if (p->next->data == data)
			{
				PNODE deletion = p->next;
				p->next = deletion->next;
				free(deletion);
				Linked_list_number&&Linked_list_number--;
				return;
			}
			p = p->next;
		}
		return;
	}
	//ɾ����ͷ��ʼ�ĵ�n��Ԫ��
	void pop_num(int n)
	{
		if (empty()) return;
		if (n < 1 || n > Linked_list_number) return;
		PNODE p = head;
		while (n > 1)
		{
			if (p == NULL) return;
			else p = p->next;
			n--;
		}
		p->next == rear->next && (rear->next = p);
		PNODE deletion = p->next;
		p->next = deletion->next;
		free(deletion);
		Linked_list_number&&Linked_list_number--;
	}
	//�������Ԫ��
	void clear()
	{
		PNODE p = head;
		while (p->next != NULL)
		{
			PNODE deletion = p->next;
			p->next = deletion->next;
			free(deletion);
		}
		rear->next = NULL;
		Linked_list_number = 0;
	}
	//���ض���Ԫ�ظ���
	int length()
	{
		return Linked_list_number;
	}
	//�����Ƿ�Ϊ��
	bool empty()
	{
		return Linked_list_number == 0;
	}
};

#endif // _MY_LINKLIST