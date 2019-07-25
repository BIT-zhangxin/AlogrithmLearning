//#include <cstdio>
//#include <cstdlib>
//#include <list>
//using namespace std;
//const int INF = 0x7fffffff;
//const int EMPTY = -1;//��ҳ����
//
//enum Algorithm
//{
//	Alogrithm_OPT = 1,//����㷨
//	Algorithm_FIFO = 2,//�Ƚ��ȳ��㷨
//	Alogrithm_LRU = 3,//�������ʹ���㷨
//};
//
//Algorithm algorithm;
//int List[1000];//װ��ҳ���
//int list_num = 0;//ҳ����С
//int capacity[100] = { 0 };//פ����
//int help[100] = { 0 };//��������
//int capacity_num = 0;//פ�����������
//int flag = 0;//ȱҳ��־��0Ϊȱҳ��1Ϊ����
//int lack_num = 0;//ȱҳ����
//int time = 0;//ʱ��
//
//list<int> l;
//list<int>::iterator literator;
//
//void OPT(int num)
//{
//	time++;
//	for (int i = 0; i < capacity_num; i++)
//	{
//		if (capacity[i] == List[num])//�ҵ�ҳ��
//		{
//			flag = 1;
//			return;
//		}
//	}
//	for (int i = 0; i < capacity_num; i++)//δ�ҵ�ҳ��
//	{
//		if (help[i] == 0)//��ҳ��Ϊ�ս���ʱ�滻
//		{
//			capacity[i] = List[num];
//			help[i] = time;
//			flag = 0;
//			lack_num++;
//			return;
//		}
//	}
//	int *tmp = (int *)malloc(capacity_num * sizeof(int));//��ʱ����
//	int find_num = 0;//�ҵ��ĸ���
//	for (int i = 0; i < capacity_num; i++)
//	{
//		tmp[i] = INF;
//	}
//	for (int j = num + 1; j < list_num; j++)//��ѯ���е�פ����ҳ������һ�η��ʵĳ���
//	{
//		for (int i = 0; i < capacity_num; i++)
//		{
//			if (List[j] == capacity[i] && tmp[i] == INF)//���ҵ�һ�������ĳ���
//			{
//				tmp[i] = j - num;
//				find_num++;
//			}
//		}
//	}
//	if (capacity_num - find_num < 2)
//	{
//		int max_loc = 0;//��Զҳ���λ��
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
//		if (capacity[i] == List[num])//�ҵ�ҳ��
//		{
//			flag = 1;
//			return;
//		}
//	}
//	for (int i = 0; i < capacity_num; i++)//δ�ҵ�ҳ��
//	{
//		if (help[i] == 0 || help[i] == 1)//��ҳ��Ϊ�ջ��������ʱ�滻
//		{
//			capacity[i] = List[num];
//			help[i] = capacity_num + 1;
//			flag = 0;
//			lack_num++;
//			break;
//		}
//	}
//	for (int i = 0; i < capacity_num; i++)//��ҳ��Ľ���ʱ���־����ά��
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
//void Print(int status)//ֻҪ����0���Ͷ����һ��/
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