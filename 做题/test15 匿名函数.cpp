//#include <cstdio>
//#include <algorithm>
//using namespace std;
//
//int main()
//{
//	struct node
//	{
//		int number;
//		int location;
//	};
//
//	node List[10];
//	for (int i = 0; i < 10; i++)
//	{
//		List[i].number = i;
//		List[i].location = 10 - i;
//	}
//	auto cmp = [](const void *a, const void *b)
//	{
//		return (*((node *)a)).location - (*((node *)b)).location;
//	};
//	qsort(List, 10, sizeof(node), cmp);
//	for (int i = 0; i < 10; i++)
//	{
//		printf("%d %d\n", List[i].number, List[i].location);
//	}
//}