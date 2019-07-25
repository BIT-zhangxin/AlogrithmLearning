//#include <cstdio>
//#include <algorithm>
//#include <list>
//using namespace std; 
//const int INF = 0x7fffffff;
//
//enum Algorithm
//{
//	Alogrithm_First_fit = 1,//首次适应
//	Algorithm_Best_fit = 2,//最佳适应
//	Alogrithm_Worst_fit = 3,//最坏适应
//};
//
//struct Block//内存块信息
//{
//	int start;//起始地址
//	int end;//结束地址
//	int processId;//进程id，为-1代表空闲
//};
//
//Algorithm algorithm;
//int max_capacity = 0;//最大存储容量
//int num = 0;//序号
//int processId = 0;//进程号
//int status = 0;//操作方式
//int capacity = 0;//容量
//
//list<Block> blocklist;//存储信息表
//list<Block>::iterator blockiterator;//迭代器
//
//void Release()
//{
//	for (blockiterator = blocklist.begin(); blockiterator != blocklist.end(); blockiterator++)
//	{
//		if ((*blockiterator).processId == processId)//当进程id相等时
//		{
//			list<Block>::iterator last = blockiterator;
//			if ((*blockiterator).start != 0) last--;//为0时last不可用
//			list<Block>::iterator next = blockiterator;
//			if ((*blockiterator).end != max_capacity) next++;//为max_capacity时next不可用
//			if (last == blockiterator && next == blockiterator)//从0到max_capacity
//			{
//				(*blockiterator).processId = -1;
//			}
//			else if (last == blockiterator)//从0开始
//			{
//				if ((*next).processId == -1)//后面为空闲区
//				{
//					(*blockiterator).end = (*next).end;
//					(*blockiterator).processId = -1;
//					blocklist.erase(next);
//				}
//				else//不为空闲区
//				{
//					(*blockiterator).processId = -1;
//				}
//			}
//			else if (next == blockiterator)//到max_capacity为止
//			{
//				if ((*last).processId == -1)//前面为空闲区
//				{
//					blocklist.back().start = (*blockiterator).start;
//					blocklist.back().processId = -1;
//					blocklist.erase(blockiterator);
//				}
//				else//不为空闲区
//				{
//					blocklist.back().processId = -1;
//				}
//			}
//			else//不为边界的情况
//			{
//				if ((*last).processId == -1 && (*next).processId == -1)//前后都为空闲区
//				{
//					(*blockiterator).start = (*last).start;
//					(*blockiterator).end = (*next).end;
//					(*blockiterator).processId = -1;
//					blocklist.erase(last);
//					blocklist.erase(next);
//				}
//				else if ((*last).processId == -1)//前面为空闲区
//				{
//					(*blockiterator).start = (*last).start;
//					(*blockiterator).processId = -1;
//					blocklist.erase(last);
//				}
//				else if ((*next).processId == -1)//后面为空闲区
//				{
//					(*blockiterator).end = (*next).end;
//					(*blockiterator).processId = -1;
//					blocklist.erase(next);
//				}
//				else//都不为空闲区
//				{
//					(*blockiterator).processId = -1;
//				}
//			}
//			break;
//		}
//	}
//}
//
//void First_fit()
//{
//	for (blockiterator = blocklist.begin(); blockiterator != blocklist.end(); blockiterator++)
//	{
//		if ((*blockiterator).processId == -1)//找到一个空闲区
//		{
//			if ((*blockiterator).end - (*blockiterator).start + 1 > capacity)//大小大于进程的容量，插入
//			{
//				Block block;
//				block.start = (*blockiterator).start + capacity;
//				block.end = (*blockiterator).end;
//				block.processId = -1;
//				(*blockiterator).end = (*blockiterator).start + capacity - 1;
//				(*blockiterator).processId = processId;
//				blocklist.insert(++blockiterator, block);
//				break;
//			}
//			else if ((*blockiterator).end - (*blockiterator).start + 1 == capacity)//大小等于进程的容量
//			{
//				(*blockiterator).processId = processId;
//				break;
//			}
//		}//失败时什么都不做
//	}
//}
//
//void Best_fit()
//{
//	int best_capacity = INF;
//	for (blockiterator = blocklist.begin(); blockiterator != blocklist.end(); blockiterator++)
//	{
//		if ((*blockiterator).processId == -1)//找到一个空闲区
//		{
//			int now_capacity = (*blockiterator).end - (*blockiterator).start + 1;
//			if (now_capacity >= capacity && now_capacity < best_capacity)
//			{
//				best_capacity = now_capacity;
//			}
//		}
//	}//找到最佳适应的容量大小
//	if (best_capacity == INF) return;//失败直接返回
//	for (blockiterator = blocklist.begin(); blockiterator != blocklist.end(); blockiterator++)
//	{
//		if ((*blockiterator).processId == -1)//找到一个空闲区
//		{
//			if ((*blockiterator).end - (*blockiterator).start + 1 == best_capacity)//找到最佳适应
//			{
//				if ((*blockiterator).end - (*blockiterator).start + 1 > capacity)//大小大于进程的容量，插入
//				{
//					Block block;
//					block.start = (*blockiterator).start + capacity;
//					block.end = (*blockiterator).end;
//					block.processId = -1;
//					(*blockiterator).end = (*blockiterator).start + capacity - 1;
//					(*blockiterator).processId = processId;
//					blocklist.insert(++blockiterator, block);
//					break;
//				}
//				else if ((*blockiterator).end - (*blockiterator).start + 1 == capacity)//大小等于进程的容量
//				{
//					(*blockiterator).processId = processId;
//					break;
//				}
//			}
//		}
//	}
//}
//
//void Worst_fit()
//{
//	int worst_capacity = 0;
//	for (blockiterator = blocklist.begin(); blockiterator != blocklist.end(); blockiterator++)
//	{
//		if ((*blockiterator).processId == -1)//找到一个空闲区
//		{
//			if ((*blockiterator).end - (*blockiterator).start + 1 > worst_capacity)
//			{
//				worst_capacity = (*blockiterator).end - (*blockiterator).start + 1;
//			}
//		}
//	}//找到最坏适应的容量大小
//	if (worst_capacity < capacity) return;//如果最大容量任然小于需求，直接返回 
//	for (blockiterator = blocklist.begin(); blockiterator != blocklist.end(); blockiterator++)
//	{
//		if ((*blockiterator).processId == -1)//找到一个空闲区
//		{
//			if ((*blockiterator).end - (*blockiterator).start + 1 == worst_capacity)//找到最佳适应
//			{
//				if ((*blockiterator).end - (*blockiterator).start + 1 > capacity)//大小大于进程的容量，插入
//				{
//					Block block;
//					block.start = (*blockiterator).start + capacity;
//					block.end = (*blockiterator).end;
//					block.processId = -1;
//					(*blockiterator).end = (*blockiterator).start + capacity - 1;
//					(*blockiterator).processId = processId;
//					blocklist.insert(++blockiterator, block);
//					break;
//				}
//				else if ((*blockiterator).end - (*blockiterator).start + 1 == capacity)//大小等于进程的容量
//				{
//					(*blockiterator).processId = processId;
//					break;
//				}
//			}
//		}
//	}
//}
//
//void Scanf_Init()
//{
//	scanf("%d", &algorithm);
//	scanf("%d", &max_capacity);
//	max_capacity--;
//}
//
//void Init()//初始化
//{
//	Block block;
//	block.start = 0;
//	block.end = max_capacity;
//	block.processId = -1;
//	blocklist.push_back(block);
//}
//
//void Scanf()
//{
//	if (scanf("%d/%d/%d/%d", &num, &processId, &status, &capacity) == EOF)
//		exit(0);
//}
//
//void Switch()
//{
//	if (status == 2)
//	{
//		Release();
//		return;
//	}
//	switch (algorithm)
//	{
//	case Algorithm::Alogrithm_First_fit:
//		First_fit();
//		break;
//	case Algorithm::Algorithm_Best_fit:
//		Best_fit();
//		break;
//	case Algorithm::Alogrithm_Worst_fit:
//		Worst_fit();
//		break;
//	default:
//		break;
//	}
//}
//
//void Print()
//{
//	printf("%d", num);
//	for (blockiterator = blocklist.begin(); blockiterator != blocklist.end(); blockiterator++)
//	{
//		if ((*blockiterator).processId == -1)
//		{
//			printf("/%d-%d.0", (*blockiterator).start, (*blockiterator).end);
//		}
//		else
//		{
//			printf("/%d-%d.1.%d", (*blockiterator).start, (*blockiterator).end, (*blockiterator).processId);
//		}
//	}
//	putchar('\n');
//}
//
//int main()
//{
//	Scanf_Init();
//	Init();
//	while (1)
//	{
//		Scanf();
//		Switch();
//		Print();
//	}
//}