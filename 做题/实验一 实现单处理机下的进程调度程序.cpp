//#include <cstdio>
//#include <algorithm>
//#include <queue>
//using namespace std;
//const int INF = 0x7fffffff;
//
//enum Algorithm
//{
//	Algorithm_FCFS = 1,//First Come First Served,先来先服务
//	Algorithm_SPF = 2,//Shortest Process First,短作业优先
//	Algorithm_SRTF = 3,//Shortest Remaining Time First,最短剩余时间优先
//	Algorithm_RR = 4,//Round Robin,时间片轮转
//	Algorithm_PSA = 5,//Priority Scheduling Algorithm,动态优先级
//};
//
//struct Process
//{
//	int processId;//进程序号
//	int arriveTime;//到达时间
//	int executionTime;//执行时间
//	int priority;//优先级
//	int timeSlice;//时间片
//};//进程
//
//struct Result
//{
//	int executionOrder;//执行顺序
//	int processId;//进程序号
//	int startTime;//开始运行时间
//	int endTime;//结束运行时间
//	int priority;//优先级
//};//运行结果
//
//Algorithm algorithm;
//int ProcessNumber = 0;//进程个数
//Process process[1000];
//int ResultNumber = 0;//结果个数
//Result result[1000];
//
//void FCFS()
//{
//	auto cmp = [](const void *a, const void *b)
//	{
//		if ((*((Process *)a)).arriveTime != (*((Process *)b)).arriveTime)
//			return (*((Process *)a)).arriveTime - (*((Process *)b)).arriveTime;
//		else return (*((Process *)a)).processId - (*((Process *)b)).processId;
//	};//按到达时间第一，进程id第二的优先级排序
//	qsort(&process, ProcessNumber, sizeof(Process), cmp);
//	int time = 0;
//	for (int i = 0; i < ProcessNumber; i++)
//	{
//		if (time < process[i].arriveTime) time = process[i].arriveTime;//该时间没有程序抵达时，时间向后跳
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
//	};//按到达时间排序
//	qsort(&process, ProcessNumber, sizeof(Process), cmp);
//	int time = 0;//当前时间
//	int num = 0;//已到达程序个数
//	for (int i = 0; i < ProcessNumber; i++)
//	{
//		if (i == num && time < process[num].arriveTime) time = process[num].arriveTime;//没有程序时跳向最近抵达程序的时间
//		for (int j = num; j < ProcessNumber; j++)
//		{
//			if (process[j].arriveTime <= time) num++;//统计该事件以到达程序的个数
//			else break;
//		}
//		int loc = INF;
//		for (int j = 0; j < num; j++)//选择一个已到达的执行时间最短且id最小的程序
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
//	};//按到达时间排序
//	qsort(&process, ProcessNumber, sizeof(Process), cmp);
//	int num = 0;//执行完的程序个数
//	int ploc = INF;//之前的执行地址
//	int ptime = 0;//之前的执行时间
//	int time = 0;
//	while (1)
//	{
//		int tmploc = INF;
//		for (int i = 0; i < ProcessNumber; i++)//选择一个已到达的执行时间最短且到达最早且id最小的程序
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
//		if (tmploc == INF)//如果没找到时间加一
//		{
//			time++;
//		}
//		else 
//		{
//			int timelength = 0;//此次执行时间长度
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
//					result[ResultNumber].startTime = time - ptime;//处理连续时间
//					result[ResultNumber].endTime = time;
//					ResultNumber++;
//				}
//				ploc = tmploc;
//				ptime = timelength;
//				process[ploc].executionTime -= timelength;
//			}
//			time += timelength;
//		}
//		if (num == ProcessNumber)//处理最后一次的情况
//		{
//			result[ResultNumber].executionOrder = ResultNumber + 1;
//			result[ResultNumber].processId = process[ploc].processId;
//			result[ResultNumber].priority = process[ploc].priority;
//			result[ResultNumber].startTime = time - ptime;//处理连续时间
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
//	};//按到达时间第一，进程id第二的优先级排序
//	qsort(&process, ProcessNumber, sizeof(Process), cmp);
//	queue <Process> q;//先进先出队列
//	Process now;
//	now.executionTime = 0;
//	int num = 0;//已到达程序个数
//	int time = 0;
//	while (1)
//	{
//		
//		for (int i = num; i < ProcessNumber; i++)
//		{
//			if (process[i].arriveTime <= time)
//			{
//				q.push(process[i]);//抵达的程序优先进入队列
//				num++;
//			}
//			else break;
//		}
//		if (now.executionTime != 0) q.push(now);//处理完的程序再进入队列
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
//	};//按到达时间排序
//	qsort(&process, ProcessNumber, sizeof(Process), cmp);
//	int num = 0;//执行完的程序个数
//	int arrivenum = 0;//到达程序个数
//	int time = 0;
//	while (1)
//	{
//		for (int i = arrivenum; i < ProcessNumber; i++)
//		{
//			if (process[i].arriveTime <= time) arrivenum++;
//			else break;
//		}
//		int tmploc = INF;
//		for (int i = 0; i < ProcessNumber; i++)//寻找一个优先级最低且抵达时间最小且进程id最小的程序
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
//			int timelength = 0;//此次执行时间长度
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
//			for (int i = arrivenum; i < ProcessNumber; i++)//在实际时间变化后再次寻找所有已抵达的程序
//			{
//				if (process[i].arriveTime < time) arrivenum++;
//				else break;
//			}
//			for (int i = 0; i < arrivenum; i++)//改变优先级
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
