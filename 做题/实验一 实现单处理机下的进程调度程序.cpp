//#include <cstdio>
//#include <algorithm>
//#include <queue>
//using namespace std;
//const int INF = 0x7fffffff;
//
//enum Algorithm
//{
//	Algorithm_FCFS = 1,//First Come First Served,�����ȷ���
//	Algorithm_SPF = 2,//Shortest Process First,����ҵ����
//	Algorithm_SRTF = 3,//Shortest Remaining Time First,���ʣ��ʱ������
//	Algorithm_RR = 4,//Round Robin,ʱ��Ƭ��ת
//	Algorithm_PSA = 5,//Priority Scheduling Algorithm,��̬���ȼ�
//};
//
//struct Process
//{
//	int processId;//�������
//	int arriveTime;//����ʱ��
//	int executionTime;//ִ��ʱ��
//	int priority;//���ȼ�
//	int timeSlice;//ʱ��Ƭ
//};//����
//
//struct Result
//{
//	int executionOrder;//ִ��˳��
//	int processId;//�������
//	int startTime;//��ʼ����ʱ��
//	int endTime;//��������ʱ��
//	int priority;//���ȼ�
//};//���н��
//
//Algorithm algorithm;
//int ProcessNumber = 0;//���̸���
//Process process[1000];
//int ResultNumber = 0;//�������
//Result result[1000];
//
//void FCFS()
//{
//	auto cmp = [](const void *a, const void *b)
//	{
//		if ((*((Process *)a)).arriveTime != (*((Process *)b)).arriveTime)
//			return (*((Process *)a)).arriveTime - (*((Process *)b)).arriveTime;
//		else return (*((Process *)a)).processId - (*((Process *)b)).processId;
//	};//������ʱ���һ������id�ڶ������ȼ�����
//	qsort(&process, ProcessNumber, sizeof(Process), cmp);
//	int time = 0;
//	for (int i = 0; i < ProcessNumber; i++)
//	{
//		if (time < process[i].arriveTime) time = process[i].arriveTime;//��ʱ��û�г���ִ�ʱ��ʱ�������
//		result[i].executionOrder = i + 1;
//		result[i].processId = process[i].processId;
//		result[i].priority = process[i].priority;
//		result[i].startTime = time;
//		result[i].endTime = result[i].startTime + process[i].executionTime;
//		time = result[i].endTime;
//		ResultNumber++;
//	}
//}
//
//void SPF()
//{
//	auto cmp = [](const void *a, const void *b)
//	{
//		return (*((Process *)a)).arriveTime - (*((Process *)b)).arriveTime;
//	};//������ʱ������
//	qsort(&process, ProcessNumber, sizeof(Process), cmp);
//	int time = 0;//��ǰʱ��
//	int num = 0;//�ѵ���������
//	for (int i = 0; i < ProcessNumber; i++)
//	{
//		if (i == num && time < process[num].arriveTime) time = process[num].arriveTime;//û�г���ʱ��������ִ�����ʱ��
//		for (int j = num; j < ProcessNumber; j++)
//		{
//			if (process[j].arriveTime <= time) num++;//ͳ�Ƹ��¼��Ե������ĸ���
//			else break;
//		}
//		int loc = INF;
//		for (int j = 0; j < num; j++)//ѡ��һ���ѵ����ִ��ʱ�������id��С�ĳ���
//		{
//			if (process[j].executionTime == 0) continue;
//			if (loc == INF) loc = j;
//			else if (process[j].executionTime < process[loc].executionTime) loc = j;
//			else if (process[j].executionTime == process[loc].executionTime
//				&& process[j].processId < process[loc].processId) loc = j;
//		}
//		result[i].executionOrder = i + 1;
//		result[i].processId = process[loc].processId;
//		result[i].priority = process[loc].priority;
//		result[i].startTime = time;
//		result[i].endTime = result[i].startTime + process[loc].executionTime;
//		time = result[i].endTime;
//		ResultNumber++;
//		process[loc].executionTime = 0;
//	}
//}
//
//void SRTF()
//{
//	auto cmp = [](const void *a, const void *b)
//	{
//		return (*((Process *)a)).arriveTime - (*((Process *)b)).arriveTime;
//	};//������ʱ������
//	qsort(&process, ProcessNumber, sizeof(Process), cmp);
//	int num = 0;//ִ����ĳ������
//	int ploc = INF;//֮ǰ��ִ�е�ַ
//	int ptime = 0;//֮ǰ��ִ��ʱ��
//	int time = 0;
//	while (1)
//	{
//		int tmploc = INF;
//		for (int i = 0; i < ProcessNumber; i++)//ѡ��һ���ѵ����ִ��ʱ������ҵ���������id��С�ĳ���
//		{
//			if (process[i].arriveTime > time) break;
//			if (process[i].executionTime == 0) continue;
//			if (tmploc == INF) tmploc = i;
//			else if (process[i].executionTime < process[tmploc].executionTime) tmploc = i;
//			else if (process[i].executionTime == process[tmploc].executionTime)
//			{
//				if (process[i].arriveTime < process[tmploc].arriveTime) tmploc = i;
//				else if (process[i].arriveTime == process[tmploc].arriveTime
//					&& process[i].processId < process[tmploc].processId) tmploc = i;
//			}
//		}
//		if (tmploc == INF)//���û�ҵ�ʱ���һ
//		{
//			time++;
//		}
//		else 
//		{
//			int timelength = 0;//�˴�ִ��ʱ�䳤��
//			if (process[tmploc].executionTime <= process[tmploc].timeSlice)
//			{
//				timelength = process[tmploc].executionTime;
//				num++;
//			}
//			else timelength = process[tmploc].timeSlice;
//			if (tmploc == ploc)
//			{
//				ptime += timelength;
//				process[ploc].executionTime -= timelength;
//			}
//			else
//			{
//				if (ploc != INF)
//				{
//					result[ResultNumber].executionOrder = ResultNumber + 1;
//					result[ResultNumber].processId = process[ploc].processId;
//					result[ResultNumber].priority = process[ploc].priority;
//					result[ResultNumber].startTime = time - ptime;//��������ʱ��
//					result[ResultNumber].endTime = time;
//					ResultNumber++;
//				}
//				ploc = tmploc;
//				ptime = timelength;
//				process[ploc].executionTime -= timelength;
//			}
//			time += timelength;
//		}
//		if (num == ProcessNumber)//�������һ�ε����
//		{
//			result[ResultNumber].executionOrder = ResultNumber + 1;
//			result[ResultNumber].processId = process[ploc].processId;
//			result[ResultNumber].priority = process[ploc].priority;
//			result[ResultNumber].startTime = time - ptime;//��������ʱ��
//			result[ResultNumber].endTime = time;
//			ResultNumber++;
//			break;
//		}
//	}
//}
//
//void RR()
//{
//	auto cmp = [](const void *a, const void *b)
//	{
//		if ((*((Process *)a)).arriveTime != (*((Process *)b)).arriveTime)
//		return (*((Process *)a)).arriveTime - (*((Process *)b)).arriveTime;
//		else return (*((Process *)a)).processId - (*((Process *)b)).processId;
//	};//������ʱ���һ������id�ڶ������ȼ�����
//	qsort(&process, ProcessNumber, sizeof(Process), cmp);
//	queue <Process> q;//�Ƚ��ȳ�����
//	Process now;
//	now.executionTime = 0;
//	int num = 0;//�ѵ���������
//	int time = 0;
//	while (1)
//	{
//		
//		for (int i = num; i < ProcessNumber; i++)
//		{
//			if (process[i].arriveTime <= time)
//			{
//				q.push(process[i]);//�ִ�ĳ������Ƚ������
//				num++;
//			}
//			else break;
//		}
//		if (now.executionTime != 0) q.push(now);//������ĳ����ٽ������
//		if (!q.empty())
//		{
//			now = q.front();
//			q.pop();
//			int timelength = 0;
//			if (now.executionTime <= now.timeSlice)
//			{
//				timelength = now.executionTime;
//			}
//			else timelength = now.timeSlice;
//			result[ResultNumber].executionOrder = ResultNumber + 1;
//			result[ResultNumber].processId = now.processId;
//			result[ResultNumber].priority = now.priority;
//			result[ResultNumber].startTime = time;
//			result[ResultNumber].endTime = time + timelength;
//			now.executionTime -= timelength;
//			ResultNumber++;
//			time += timelength;
//		}
//		else time++;
//		if (now.executionTime == 0 && num == ProcessNumber && q.empty()) break;
//	}
//}
//
//void PSA()
//{
//	auto cmp = [](const void *a, const void *b)
//	{
//		return (*((Process *)a)).arriveTime - (*((Process *)b)).arriveTime;
//	};//������ʱ������
//	qsort(&process, ProcessNumber, sizeof(Process), cmp);
//	int num = 0;//ִ����ĳ������
//	int arrivenum = 0;//����������
//	int time = 0;
//	while (1)
//	{
//		for (int i = arrivenum; i < ProcessNumber; i++)
//		{
//			if (process[i].arriveTime <= time) arrivenum++;
//			else break;
//		}
//		int tmploc = INF;
//		for (int i = 0; i < ProcessNumber; i++)//Ѱ��һ�����ȼ�����ҵִ�ʱ����С�ҽ���id��С�ĳ���
//		{
//			if (process[i].arriveTime > time) break;
//			if (process[i].executionTime == 0) continue;
//			if (tmploc == INF) tmploc = i;
//			else if (process[i].priority < process[tmploc].priority) tmploc = i;
//			else if (process[i].priority == process[tmploc].priority)
//			{
//				if (process[i].arriveTime < process[tmploc].arriveTime) tmploc = i;
//				else if (process[i].arriveTime == process[tmploc].arriveTime
//					&& process[i].processId < process[tmploc].processId) tmploc = i;
//			}
//		}
//		if (tmploc == INF) time++;
//		else
//		{
//			int timelength = 0;//�˴�ִ��ʱ�䳤��
//			if (process[tmploc].executionTime <= process[tmploc].timeSlice)
//			{
//				timelength = process[tmploc].executionTime;
//				num++;
//			}
//			else timelength = process[tmploc].timeSlice;
//			process[tmploc].priority += 3;
//			process[tmploc].executionTime -= timelength;
//			result[ResultNumber].executionOrder = ResultNumber + 1;
//			result[ResultNumber].processId = process[tmploc].processId;
//			result[ResultNumber].priority = process[tmploc].priority;
//			result[ResultNumber].startTime = time;
//			result[ResultNumber].endTime = time + timelength;
//			ResultNumber++;
//			time += timelength;
//			if (num == ProcessNumber) break;
//			for (int i = arrivenum; i < ProcessNumber; i++)//��ʵ��ʱ��仯���ٴ�Ѱ�������ѵִ�ĳ���
//			{
//				if (process[i].arriveTime < time) arrivenum++;
//				else break;
//			}
//			for (int i = 0; i < arrivenum; i++)//�ı����ȼ�
//			{
//				if (process[i].executionTime == 0 || i == tmploc) continue;
//				if (process[i].priority > 0) process[i].priority--;
//			}
//		}
//	}
//}
//
//void Scanf()
//{
//	scanf("%d\n", &algorithm);
//	while (scanf("%d/%d/%d/%d/%d",
//		&process[ProcessNumber].processId,
//		&process[ProcessNumber].arriveTime,
//		&process[ProcessNumber].executionTime,
//		&process[ProcessNumber].priority,
//		&process[ProcessNumber].timeSlice)
//		!= EOF) {
//		ProcessNumber++;
//	}
//}
//
//void Switch()
//{
//	switch (algorithm)
//	{
//	case Algorithm::Algorithm_FCFS:
//		FCFS();
//		break;
//	case Algorithm::Algorithm_SPF:
//		SPF();
//		break;
//	case Algorithm::Algorithm_SRTF:
//		SRTF();
//		break;
//	case Algorithm::Algorithm_RR:
//		RR();
//		break;
//	case Algorithm::Algorithm_PSA:
//		PSA();
//		break;
//	default:
//		break;
//	}
//}
//
//void Print()
//{
//	for (int i = 0; i < ResultNumber; i++)
//	{
//		printf("%d/%d/%d/%d/%d\n",
//			result[i].executionOrder,
//			result[i].processId,
//			result[i].startTime,
//			result[i].endTime,
//			result[i].priority);
//	}
//}
//
//int main()
//{
//	Scanf();
//	Switch();
//	Print();
//	return 0;
//}
