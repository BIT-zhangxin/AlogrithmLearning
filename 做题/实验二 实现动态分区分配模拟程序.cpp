//#include <cstdio>
//#include <algorithm>
//#include <list>
//using namespace std; 
//const int INF = 0x7fffffff;
//
//enum Algorithm
//{
//	Alogrithm_First_fit = 1,//�״���Ӧ
//	Algorithm_Best_fit = 2,//�����Ӧ
//	Alogrithm_Worst_fit = 3,//���Ӧ
//};
//
//struct Block//�ڴ����Ϣ
//{
//	int start;//��ʼ��ַ
//	int end;//������ַ
//	int processId;//����id��Ϊ-1�������
//};
//
//Algorithm algorithm;
//int max_capacity = 0;//���洢����
//int num = 0;//���
//int processId = 0;//���̺�
//int status = 0;//������ʽ
//int capacity = 0;//����
//
//list<Block> blocklist;//�洢��Ϣ��
//list<Block>::iterator blockiterator;//������
//
//void Release()
//{
//	for (blockiterator = blocklist.begin(); blockiterator != blocklist.end(); blockiterator++)
//	{
//		if ((*blockiterator).processId == processId)//������id���ʱ
//		{
//			list<Block>::iterator last = blockiterator;
//			if ((*blockiterator).start != 0) last--;//Ϊ0ʱlast������
//			list<Block>::iterator next = blockiterator;
//			if ((*blockiterator).end != max_capacity) next++;//Ϊmax_capacityʱnext������
//			if (last == blockiterator && next == blockiterator)//��0��max_capacity
//			{
//				(*blockiterator).processId = -1;
//			}
//			else if (last == blockiterator)//��0��ʼ
//			{
//				if ((*next).processId == -1)//����Ϊ������
//				{
//					(*blockiterator).end = (*next).end;
//					(*blockiterator).processId = -1;
//					blocklist.erase(next);
//				}
//				else//��Ϊ������
//				{
//					(*blockiterator).processId = -1;
//				}
//			}
//			else if (next == blockiterator)//��max_capacityΪֹ
//			{
//				if ((*last).processId == -1)//ǰ��Ϊ������
//				{
//					blocklist.back().start = (*blockiterator).start;
//					blocklist.back().processId = -1;
//					blocklist.erase(blockiterator);
//				}
//				else//��Ϊ������
//				{
//					blocklist.back().processId = -1;
//				}
//			}
//			else//��Ϊ�߽�����
//			{
//				if ((*last).processId == -1 && (*next).processId == -1)//ǰ��Ϊ������
//				{
//					(*blockiterator).start = (*last).start;
//					(*blockiterator).end = (*next).end;
//					(*blockiterator).processId = -1;
//					blocklist.erase(last);
//					blocklist.erase(next);
//				}
//				else if ((*last).processId == -1)//ǰ��Ϊ������
//				{
//					(*blockiterator).start = (*last).start;
//					(*blockiterator).processId = -1;
//					blocklist.erase(last);
//				}
//				else if ((*next).processId == -1)//����Ϊ������
//				{
//					(*blockiterator).end = (*next).end;
//					(*blockiterator).processId = -1;
//					blocklist.erase(next);
//				}
//				else//����Ϊ������
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
//		if ((*blockiterator).processId == -1)//�ҵ�һ��������
//		{
//			if ((*blockiterator).end - (*blockiterator).start + 1 > capacity)//��С���ڽ��̵�����������
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
//			else if ((*blockiterator).end - (*blockiterator).start + 1 == capacity)//��С���ڽ��̵�����
//			{
//				(*blockiterator).processId = processId;
//				break;
//			}
//		}//ʧ��ʱʲô������
//	}
//}
//
//void Best_fit()
//{
//	int best_capacity = INF;
//	for (blockiterator = blocklist.begin(); blockiterator != blocklist.end(); blockiterator++)
//	{
//		if ((*blockiterator).processId == -1)//�ҵ�һ��������
//		{
//			int now_capacity = (*blockiterator).end - (*blockiterator).start + 1;
//			if (now_capacity >= capacity && now_capacity < best_capacity)
//			{
//				best_capacity = now_capacity;
//			}
//		}
//	}//�ҵ������Ӧ��������С
//	if (best_capacity == INF) return;//ʧ��ֱ�ӷ���
//	for (blockiterator = blocklist.begin(); blockiterator != blocklist.end(); blockiterator++)
//	{
//		if ((*blockiterator).processId == -1)//�ҵ�һ��������
//		{
//			if ((*blockiterator).end - (*blockiterator).start + 1 == best_capacity)//�ҵ������Ӧ
//			{
//				if ((*blockiterator).end - (*blockiterator).start + 1 > capacity)//��С���ڽ��̵�����������
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
//				else if ((*blockiterator).end - (*blockiterator).start + 1 == capacity)//��С���ڽ��̵�����
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
//		if ((*blockiterator).processId == -1)//�ҵ�һ��������
//		{
//			if ((*blockiterator).end - (*blockiterator).start + 1 > worst_capacity)
//			{
//				worst_capacity = (*blockiterator).end - (*blockiterator).start + 1;
//			}
//		}
//	}//�ҵ����Ӧ��������С
//	if (worst_capacity < capacity) return;//������������ȻС������ֱ�ӷ��� 
//	for (blockiterator = blocklist.begin(); blockiterator != blocklist.end(); blockiterator++)
//	{
//		if ((*blockiterator).processId == -1)//�ҵ�һ��������
//		{
//			if ((*blockiterator).end - (*blockiterator).start + 1 == worst_capacity)//�ҵ������Ӧ
//			{
//				if ((*blockiterator).end - (*blockiterator).start + 1 > capacity)//��С���ڽ��̵�����������
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
//				else if ((*blockiterator).end - (*blockiterator).start + 1 == capacity)//��С���ڽ��̵�����
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
//void Init()//��ʼ��
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