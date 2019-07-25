//#include <stdio.h>
//#include <stdlib.h>
//
//typedef struct
//{
//	int a, b, num;
//}node;
//node x[1000003];
//
//int cmp(const void *a, const void *b)
//{
//	return (*(node *)b).a - (*(node *)a).a;
//}
//
//int main()
//{
//	int n;
//	scanf("%d", &n);
//	for (int i = 0; i < n; i++)
//	{
//		x[i].num = i;
//		scanf("%d", &x[i].a);
//	}
//	for (int i = 0; i < n; i++)
//	{
//		scanf("%d",&x[i].b);
//	}
//	qsort(x, n, sizeof(node), cmp);
//	int k = n / 2 + 1;
//	int i = 0;
//	printf("%d\n%d", k, x[i++].num + 1);
//	if (n % 2 == 0) printf(" %d", x[i++].num + 1);
//	while (i < n)
//	{
//		if (x[i].b > x[i + 1].b) printf(" %d", x[i].num + 1);
//		else printf(" %d", x[i + 1].num + 1);
//		i += 2;
//	}
//	putchar(10);
//	return 0;
//}