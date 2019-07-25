// /* PRESET CODE BEGIN - NEVER TOUCH CODE BELOW */
//
//#include <stdio.h>
//#include <stdlib.h>
//
//typedef struct node
//{
//	int    coef, exp;
//	struct node  *next;
//} NODE;
//
//void multiplication(NODE *, NODE *, NODE *);
//void input(NODE *);
//void output(NODE *);
//
//void input(NODE * head)
//{
//	int flag, sign, sum, x;
//	char c;
//
//	NODE * p = head;
//
//	while ((c = getchar()) != '\n')
//	{
//		if (c == '<')
//		{
//			sum = 0;
//			sign = 1;
//			flag = 1;
//		}
//		else if (c == '-')
//			sign = -1;
//		else if (c >= '0'&& c <= '9')
//		{
//			sum = sum * 10 + c - '0';
//		}
//		else if (c == ',')
//		{
//			if (flag == 1)
//			{
//				x = sign * sum;
//				sum = 0;
//				flag = 2;
//				sign = 1;
//			}
//		}
//		else if (c == '>')
//		{
//			p->next = (NODE *)malloc(sizeof(NODE));
//			p->next->coef = x;
//			p->next->exp = sign * sum;
//			p = p->next;
//			p->next = NULL;
//			flag = 0;
//		}
//	}
//}
//
//void output(NODE * head)
//{
//	while (head->next != NULL)
//	{
//		head = head->next;
//		printf("<%d,%d>,", head->coef, head->exp);
//	}
//	printf("\n");
//}
//
//int main()
//{
//	NODE * head1, *head2, *head3;
//
//	head1 = (NODE *)malloc(sizeof(NODE));
//	input(head1);
//
//	head2 = (NODE *)malloc(sizeof(NODE));
//	input(head2);
//
//	head3 = (NODE *)malloc(sizeof(NODE));
//	head3->next = NULL;
//	multiplication(head1, head2, head3);
//
//	output(head3);
//
//	return 0;
//}
//
///* PRESET CODE END - NEVER TOUCH CODE ABOVE */
//
//void multiplication(NODE *head1, NODE *head2, NODE *head3)
//{
//	NODE *p1 = head1;
//	NODE *p2 = head2;
//	NODE *p3 = head3;
//	while (p1->next != NULL)
//	{
//		p1 = p1->next;
//		p2 = head2;
//		p3 = head3;
//		while (p2->next != NULL)
//		{
//			p2 = p2->next;
//			int ans_coef = p1->coef*p2->coef;
//			int ans_exp = p1->exp + p2->exp;
//			while(1)
//			{
//				if (p3->next == NULL || ans_exp < p3->next->exp)//小于,插入添加
//				{
//					NODE *addition = (NODE *)malloc(sizeof(NODE));
//					addition->coef = ans_coef;
//					addition->exp = ans_exp;
//					addition->next = p3->next;
//					p3->next = addition;
//					break;
//				}
//				else if (ans_exp == p3->next->exp)//等于，将系数加进去
//				{
//					p3->next->coef += ans_coef;
//					break;
//				}
//				else if (ans_exp > p3->next->exp)//大于，继续往后搜索
//				{
//					p3 = p3->next;
//				}
//			}
//		}
//	}
//	p3 = head3;
//	while (p3->next != NULL)
//	{
//		if (p3->next->coef == 0)
//		{
//			NODE *deletion = p3->next;
//			p3->next = deletion->next;
//			free(deletion);
//		}
//		else p3 = p3->next;
//	}
//	p3 = head3;
//	if (p3->next == NULL)
//	{
//		p3->next = (NODE *)malloc(sizeof(NODE));
//		p3->next->coef = 0;
//		p3->next->exp = 0;
//		p3->next->next = NULL;
//	}
//}