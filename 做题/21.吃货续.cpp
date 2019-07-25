//#include <stdio.h>
//#include <stdlib.h>
//
//typedef struct
//{
//	short x, y;
//	int step;
//}node;
//
//typedef struct name
//{
//	node data;
//	struct name* next;
//}NODE;
//typedef NODE* PNODE;
//
//PNODE head1,head2;
//PNODE rear1,rear2;
//int start_len = 0;
//int end_len = 0;
//
//void push(node data,int pattern)
//{
//	if (pattern)
//	{
//		start_len++;
//		rear1->next = (PNODE)calloc(sizeof(NODE), 1);
//		rear1->next->data = data;
//		rear1 = rear1->next;
//	}
//	else
//	{
//		end_len++;
//		rear2->next = (PNODE)calloc(sizeof(NODE), 1);
//		rear2->next->data = data;
//		rear2 = rear2->next;
//	}
//}
//
//node front(int pattern)
//{
//	if(pattern) return head1->next->data;
//	else return head2->next->data;
//}
//
//void pop(int pattern)
//{
//	if (pattern)
//	{
//		start_len--;
//		PNODE p = head1->next;
//		head1->next = head1->next->next;
//		if (head1->next == NULL) rear1 = head1;
//		free(p);
//	}
//	else
//	{
//		end_len--;
//		PNODE p = head2->next;
//		head2->next = head2->next->next;
//		if (head2->next == NULL) rear2 = head2;
//		free(p);
//	}
//}
//
//int dx[] = { 0,1,0,-1 };
//int dy[] = { 1,0,-1,0 };
//
//int search(node s, node e, int m, int n, char **map, char **vis);
//
//int main()
//{
//	int m, n;
//	char tmp;
//	node s, e;
//	s.x = s.y = s.step = 0;
//	e.x = e.y = e.step = 0;
//	scanf("%d%d", &m, &n);
//	getchar();
//	char *map[2003];
//	char *vis[2003];
//	//if (m < 10 && n < 10)
//	{
//		for (int i = 0; i < m; i++)
//		{
//			map[i] = (char *)calloc(sizeof(char) * n, 1);
//		}
//		for (int i = 0; i < m; i++)
//		{
//			vis[i] = (char *)calloc(sizeof(char) * n, 1);
//		}
//	}
//	/*else
//	{
//		for (int i = 0; i < 2003; i++)
//		{
//			map[i] = (char *)calloc(sizeof(char) * 2003, 1);
//		}
//		for (int i = 0; i < 2003; i++)
//		{
//			vis[i] = (char *)calloc(sizeof(char) * 2003, 1);
//		}
//	}*/
//	for (int i = 0; i < m; i++)
//	{
//		for (int j = 0; j < n; j++)
//		{
//			scanf("%c", &tmp);
//			switch (tmp)
//			{
//			case '.':map[i][j] = 0; break;
//			case 'M':map[i][j] = 1; break;
//			case 'E':map[i][j] = 2; break;
//			case 'N':s.x = i, s.y = j, s.step = 0; map[i][j] = 0; break;
//			case 'C':e.x = i, e.y = j, e.step = 0; map[i][j] = 0; break;
//			}
//		}
//		getchar();
//	}
//	int ans = search(s, e, m, n, map, vis);
//	if (ans == -1) printf("Not Happy\n");
//	else printf("%d\n", ans);
//	return 0;
//}
//
//int search(node s, node e, int m, int n, char **map, char **vis)
//{
//	int min_start = 0, min_end = 0;
//	node now1, now2, next;
//	rear1 = head1 = (PNODE)calloc(sizeof(NODE), 1);
//	rear2 = head2 = (PNODE)calloc(sizeof(NODE), 1);
//	push(s, 1);
//	push(e, 0);
//	vis[s.x][s.y] = 1;
//	vis[e.x][e.y] = 2;
//	while (start_len&&end_len)
//	{
//		now1 = front(1);
//		int step1 = now1.step;
//		while (now1 = front(1), step1 == now1.step)
//		{
//			pop(1);
//			next.step = now1.step + 1;
//			for (int d = 0; d < 4; d++)
//			{
//				next.x = now1.x + dx[d];
//				next.y = now1.y + dy[d];
//				if (next.x >= 0 && next.x < m&&next.y >= 0 && next.y < n)
//				{
//					if (vis[next.x][next.y] == 1 || map[next.x][next.y] == 1)
//						continue;
//					if (map[next.x][next.y] == 2 && min_start == 0) min_start = next.step;
//					if (min_start != 0 && min_end != 0) return min_start + min_end;
//					else if (vis[next.x][next.y] == 2) return next.step * 2 - 1;
//					push(next, 1);
//					vis[next.x][next.y] = 1;
//				}
//			}
//			if (start_len == 0) break;
//		}
//		now2 = front(0);
//		int step2 = now2.step;
//		while (now2 = front(0), step2 == now2.step)
//		{
//			pop(0);
//			next.step = now2.step + 1;
//			for (int d = 0; d < 4; d++)
//			{
//				next.x = now2.x + dx[d];
//				next.y = now2.y + dy[d];
//				if (next.x >= 0 && next.x < m&&next.y >= 0 && next.y < n)
//				{
//					if (map[next.x][next.y] == 2 && min_end == 0) min_end = next.step;
//					if (min_start != 0 && min_end != 0) return min_start + min_end;
//					if (vis[next.x][next.y] == 2 || map[next.x][next.y] == 1)
//						continue;
//					else if (vis[next.x][next.y] == 1) return next.step * 2;
//					push(next, 0);
//					vis[next.x][next.y] = 2;
//				}
//			}
//			if (end_len == 0) break;
//		}
//	}
//	return -1;
//}
//
///*
//#include <stdio.h>
//#include <stdlib.h>
//
//typedef struct
//{
//	int x, y;
//	int step;
//}node;
//
//int start_len = 0;
//int end_len = 0;
//
//char map[2001][2001] = { 0 };
//char vis[2001][2001] = { 0 };
//
//int dx[4] = { 1,0,0,-1 };
//int dy[4] = { 0,1,-1,0 };
//
//struct name
//{
//	node data;
//	struct name *next;
//};
//typedef name NODE;
//
//NODE* push(NODE *point,node x,int pattern)
//{
//	if (pattern) start_len++;
//	else end_len++;
//	point->next = (NODE *)malloc(sizeof(NODE));
//	point->next->data = x;
//	point->next->next = NULL;
//	return point->next;
//}
//
//node front(NODE *head)
//{
//	return head->next->data;
//}
//
//void pop(NODE *head, int pattern)
//{
//	if (pattern) start_len--;
//	else end_len--;
//	NODE *p = head->next;
//	head = head->next;
//	free(p);
//}
//
//int search(node s, node e, int m, int n);
//
//int main()
//{
//	int m, n;
//	node start, end;
//	scanf("%d%d", &m, &n);
//	getchar();
//	for (int i = 0; i < m; i++)
//	{
//		for (int j = 0; j < n; j++)
//		{
//			scanf("%c", &map[i][j]);
//			if (map[i][j] == 'N')
//			{
//				start.x = i;
//				start.y = j;
//				start.step = 0;
//			}
//			if (map[i][j] == 'C')
//			{
//				end.x = i;
//				end.y = j;
//				end.step = 0;
//			}
//		}
//		getchar();
//	}
//	int ans = search(start, end, m, n);
//	if (ans == -1) printf("Not Happy\n");
//	else printf("%d\n", ans);
//	return 0;
//}
//
//int search(node s, node e, int m, int n)
//{
//	int min_start = 0, min_end = 0;
//	node now1, now2, next;
//	NODE *start_head = (NODE *)malloc(sizeof(NODE));
//	NODE *start_rear = (NODE *)malloc(sizeof(NODE));
//	NODE *end_head = (NODE *)malloc(sizeof(NODE));
//	NODE *end_rear = (NODE *)malloc(sizeof(NODE));
//	start_rear = push(start_head, s, 1);
//	vis[s.x][s.y] = 1;
//	end_rear = push(end_head, e, 0);
//	vis[e.x][e.y] = 1;
//	while (start_len || end_len)
//	{
//		if (start_len)
//		{
//			now1 = front(start_head);
//			pop(start_head, 1);
//		}
//		if (end_len)
//		{
//			now2 = front(end_head);
//			pop(end_head, 0);
//		}
//		if (map[now1.x][now1.y] == 'E'&&min_start == 0) min_start = now1.step;
//		if (map[now2.x][now2.y] == 'E'&&min_end == 0) min_end = now2.step;
//		if (min_start != 0 && min_end != 0) return min_start + min_end;
//		if (now1.x == now2.y&&now1.y == now2.y) return now1.step + now2.step;
//		//startËÑË÷
//		next.step = now1.step + 1;
//		for (int d = 0; d < 4; d++)
//		{
//			next.x = now1.x + dx[d];
//			next.y = now1.y + dy[d];
//			if (next.x >= 0 && next.x < m&&next.y >= 0 && next.y < n && vis[next.x][next.y] == 0 && map[next.x][next.y] != 'M')
//			{
//				if (!start_len) start_rear = push(start_head, next, 1);
//				else start_rear = push(start_rear, next, 1);
//				vis[next.x][next.y] = 1;
//			}
//		}
//		//endËÑË÷
//		next.step = now2.step + 1;
//		for (int d = 0; d < 4; d++)
//		{
//			next.x = now2.x + dx[d];
//			next.y = now2.y + dy[d];
//			if (next.x >= 0 && next.x < m&&next.y >= 0 && next.y < n && vis[next.x][next.y] == 0 && map[next.x][next.y] != 'M')
//			{
//				if (!end_len) end_rear = push(end_head, next, 0);
//				else end_rear = push(end_rear, next, 0);
//				vis[next.x][next.y] = 1;
//			}
//		}
//	}
//	return -1;
//}
//*/