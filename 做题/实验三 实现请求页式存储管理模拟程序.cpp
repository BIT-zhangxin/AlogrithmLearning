//#include <cstdio>
//#include <cstdlib>
//#include <list>
//using namespace std;
//const int INF = 0x7fffffff;
//const int EMPTY = -1;//空页面标号
//
//enum Algorithm
//{
//	Alogrithm_OPT = 1,//最佳算法
//	Algorithm_FIFO = 2,//先进先出算法
//	Alogrithm_LRU = 3,//最近最少使用算法
//};
//
//Algorithm algorithm;
//int List[1000];//装入页面表
//int list_num = 0;//页面表大小
//int capacity[100] = { 0 };//驻留集
//int help[100] = { 0 };//辅助数组
//int capacity_num = 0;//驻留集最大容量
//int flag = 0;//缺页标志，0为缺页，1为命中
//int lack_num = 0;//缺页次数
//int time = 0;//时间
//
//list<int> l;
//list<int>::iterator literator;
//
//void OPT(int num)
//{
//	time++;
//	for (int i = 0; i < capacity_num; i++)
//	{
//		if (capacity[i] == List[num])//找到页面
//		{
//			flag = 1;
//			return;
//		}
//	}
//	for (int i = 0; i < capacity_num; i++)//未找到页面
//	{
//		if (help[i] == 0)//当页面为空进入时替换
//		{
//			capacity[i] = List[num];
//			help[i] = time;
//			flag = 0;
//			lack_num++;
//			return;
//		}
//	}
//	int *tmp = (int *)malloc(capacity_num * sizeof(int));//临时数组
//	int find_num = 0;//找到的个数
//	for (int i = 0; i < capacity_num; i++)
//	{
//		tmp[i] = INF;
//	}
//	for (int j = num + 1; j < list_num; j++)//查询所有的驻留集页面离下一次访问的长度
//	{
//		for (int i = 0; i < capacity_num; i++)
//		{
//			if (List[j] == capacity[i] && tmp[i] == INF)//查找第一次遇见的长度
//			{
//				tmp[i] = j - num;
//				find_num++;
//			}
//		}
//	}
//	if (capacity_num - find_num < 2)
//	{
//		int max_loc = 0;//最远页面的位置
//		for (int i = 1; i < capacity_num; i++)
//		{
//			if (tmp[max_loc] < tmp[i])
//			{
//				max_loc = i;
//			}
//		}
//		capacity[max_loc] = List[num];
//		help[max_loc] = time;
//		flag = 0;
//		lack_num++;
//	}
//	else
//	{
//		int earlist_loc = INF;
//		for (int i = 0; i < capacity_num; i++)
//		{
//			if (tmp[i] == INF)
//			{
//				if (earlist_loc == INF) earlist_loc = i;
//				else if (help[i] < help[earlist_loc]) earlist_loc = i;
//			}
//		}
//		capacity[earlist_loc] = List[num];
//		help[earlist_loc] = time;
//		flag = 0;
//		lack_num++;
//	}
//	free(tmp);
//}
//
//void FIFO(int num)
//{
//	for (int i = 0; i < capacity_num; i++)
//	{
//		if (capacity[i] == List[num])//找到页面
//		{
//			flag = 1;
//			return;
//		}
//	}
//	for (int i = 0; i < capacity_num; i++)//未找到页面
//	{
//		if (help[i] == 0 || help[i] == 1)//当页面为空或最早进入时替换
//		{
//			capacity[i] = List[num];
//			help[i] = capacity_num + 1;
//			flag = 0;
//			lack_num++;
//			break;
//		}
//	}
//	for (int i = 0; i < capacity_num; i++)//对页面的进入时间标志进行维护
//	{
//		if (help[i] != 0) help[i]--;
//	}
//}
//
//void LRU(int num)
//{
//	for (literator = l.begin(); literator != l.end(); literator++)
//	{
//		if (*literator == List[num])
//		{
//			l.erase(literator);
//			l.push_back(List[num]);
//			flag = 1;
//			goto sign;
//		}
//	}	
//	if (l.size() == capacity_num) l.pop_front();
//	l.push_back(List[num]);
//	flag = 0;
//	lack_num++;
//
//	sign:
//	literator = l.begin();
//	for (int i = 0; i < capacity_num; i++)
//	{
//		if (literator == l.end()) capacity[i] = EMPTY;
//		else capacity[i] = *(literator++);
//	}
//}
//
//void Init()
//{
//	for (int i = 0; i < capacity_num; i++)
//	{
//		capacity[i] = EMPTY;
//	}
//}
//
//void Scanf()
//{
//	scanf("%d", &algorithm);
//	scanf("%d", &capacity_num);
//	while (scanf("%d,", &List[list_num++]) != EOF);
//	list_num--;
//}
//
//void Switch(int num)
//{
//	switch (algorithm)
//	{
//	case Algorithm::Alogrithm_OPT:
//		OPT(num);
//		break;
//	case Algorithm::Algorithm_FIFO:
//		FIFO(num);
//		break;
//	case Algorithm::Alogrithm_LRU:
//		LRU(num);
//		break;
//	default:
//		break;
//	}
//}
//
//void Print(int status)//只要不是0，就多输出一个/
//{
//	if (status != 0) putchar('/');
//	for (int i = 0; i < capacity_num; i++)
//	{
//		if (capacity[i] == EMPTY) printf("-,");
//		else printf("%d,", capacity[i]);
//	}
//	printf("%d", flag);
//}
//
//int main()
//{
//	Scanf();
//	Init();
//	for (int i = 0; i < list_num; i++)
//	{
//		Switch(i);
//		Print(i);
//	}
//	printf("\n%d\n", lack_num);
//}