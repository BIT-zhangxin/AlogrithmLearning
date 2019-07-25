//#define _CRT_SECURE_NO_WARNINGS
//#include <stdio.h>
//#include <string.h>
//#include <algorithm>
//#include <queue>
//#include <stack>
//using namespace std;
//const int INF = 0x7fffffff;
//
//int op;
//
//struct node {
//	int pid;//进程号
//	int come;//进程到达时间
//	int run;//进程运行时间
//	int pri;//进程优先级
//	int rt;//进程时间片
//}
//tmp;
//int cnt;
//struct node que[101010];
//bool vis[101010];
//
//int nowp;
//struct ANS {
//	int id;//运行序号
//	int pid;//进程号
//	int st;//进程开始运行时间
//	int en;//进程结束运行时间
//	int pri;//进程优先级
//}ans;
//
//node qu[101010];//就绪队列
//int he;//就绪队列头部 
//int ta;//就绪队列尾部
//
//void print(struct ANS e);//打印处理机所处理进程的信息，信息存储在struct ANS结构中
//
//bool fcfscmp(node a, node b);
////先来先服务算法进程排序规则，先按照到达时间升序，再按照进程号升序排列
//bool spfcmp(node a, node b);
////短作业优先算法进程排序规则，先按照到达时间升序，再按照运行时间升序，再按进程号升序排列
//bool rrcmp(node a, node b);
////时间片轮转算法进程排序规则，先按照到达时间升序，再按照进程号升序排列
//bool pricmp(node a, node b);
////动态优先级算法进程排序规则，先按照进程优先数升序，再按到达时间升序，再按进程号升序排列
//
//
//void FCFS();//先来先服务调度算法
//void SPF_N();//不可剥夺的短作业优先调度算法
//void SPF_P();//可剥夺的短作业优先调度算法
//void RR();//时间片轮转调度算法
//void PRI();//动态优先级调度算法
//
//int main() {
//	cnt = 0;
//	scanf("%d", &op);//
//	int r = 0;
//	while (~scanf("%d/%d/%d/%d/%d", &tmp.pid, &tmp.come, &tmp.run, &tmp.pri, &tmp.rt)) {
//		que[++cnt] = tmp;
//		r++;
//	}
//	if (cnt == 0)return 0;
//	switch (op) {
//	case 1:FCFS(); break;//先来先服务调度算法
//	case 2:SPF_N(); break;//不可剥夺的短作业优先调度算法
//	case 3:SPF_P(); break;//可剥夺的短作业优先调度算法
//	case 4:RR(); break;//时间片轮转调度算法
//	case 5:PRI(); break;//动态优先级调度算法
//	}
//	system("pause");
//	return 0;
//}
//void PRI() {
//	int runtime = 0, nowtime = 0;//当前运行时间和进程运行总时间
//	memset(vis, 0, sizeof(vis));
//	he = 1; ta = 0;
//	int t = 0;
//	ans.id = 0;
//	for (int i = 1; i <= cnt; i++)//计算进程运行总时间
//		runtime += que[i].run;
//	for (;;) {
//		for (int i = 1; i <= cnt; i++) {
//			if (vis[i] == 1)continue;
//			if (que[i].come <= t) {//将到达的进程加入就绪队列
//				qu[++ta] = que[i];
//				vis[i] = 1;
//			}
//		}
//		if (ta < he) {//就绪队列为空时，时钟加一，重新查找到达的进程
//			t++;
//			continue;
//		}
//		sort(qu + he, qu + ta + 1, pricmp);//将就绪队列中的进程排序
//		qu[he].pri += 3;//运行一个时间片的进程优先数加三
//		ans.pri = qu[he].pri;
//		ans.id++;//运行进程信息
//		ans.pid = qu[he].pid;
//		ans.st = t;
//		t += min(qu[he].rt, qu[he].run);//运行时间为需要运行时间和时间片的较小值
//		ans.en = t;
//		print(ans);
//		nowtime += ans.en - ans.st;
//		if (nowtime == runtime)return;//当前运行时间等于需要运行总时间时算法结束
//		node np = qu[he++];
//		for (int i = 1; i <= cnt; i++) {
//			if (vis[i] == 1)continue;
//			if (que[i].come<t) {//****将此刻之前的到达的进程都加入队列，为了后面的优先级改变
//				qu[++ta] = que[i];
//				vis[i] = 1;
//			}
//		}
//		for (int i = he; i <= ta; i++) {//将队列中的进程优先级数加一
//			node tmp = qu[i];
//			tmp.pri -= 1;//每个队列中的进程优先级数减一
//			if (tmp.pri < 0)//优先级数最小为0
//				tmp.pri = 0;
//			qu[i] = tmp;
//		}
//		np.run -= (ans.en - ans.st);
//		if (np.run != 0)//当前程序没有运行完，需要重新加入就绪队列
//			qu[++ta] = np;
//	}
//}
//
//void RR() {
//	memset(vis, 0, sizeof(vis));
//	queue<node>q;//就绪队列
//	int t = 0;
//	int runtime = 0, nowrun = 0;//当前运行时间和进程运行总时间
//	sort(que + 1, que + cnt + 1, rrcmp);//排序
//	for (int i = 1; i <= cnt; i++) { runtime += que[i].run; }//计算进程运行总时间
//	q.push(que[1]); vis[que[1].pid] = 1;//就绪队列中加入第一个进程
//	int p = que[1].pid;
//	int ip;
//	node np = q.front(); q.pop();
//	ans.id = 1;//第一个答案的信息
//	ip = 1;
//	t = np.come;
//	ans.st = np.come;
//	ans.pid = np.pid;
//	ans.pri = np.pri;
//	int flag1 = 0;
//	t += min(np.run, np.rt);//运行时间为时间片和需要运行时间的较小值
//							//更改进程运行时间，并增加时钟
//	for (;;) {
//		for (int i = 1; i <= cnt; i++) {
//			if (vis[que[i].pid] == 1 || que[i].pid == p)continue;
//			if (que[i].come <= t) {//将到达的进程加入就绪队列，并标志
//				q.push(que[i]);
//				vis[que[i].pid] = 1;
//			}
//		}
//		if (flag1 == 1) {//当前没有程序运行
//			if (q.empty()) {//现在就绪队列为空
//				t++;//继续时钟加一
//				continue;
//			}
//			else {//就绪队列不为空
//				np = q.front();//取出首个进程运行
//				q.pop(); p = np.pid;
//				ans.id++;//进程的信息
//				ans.pid = p;
//				ans.st = t;
//				ans.pri = np.pri;
//				t += min(np.run, np.rt); //更改进程运行时间，并增加时钟
//				continue;
//			}
//		}
//		else if (np.run <= np.rt) {//当前有进程运行时，如果需要运行时间小于等于时间片
//			vis[p] = 1;
//			ans.en = t;
//			nowrun += ans.en - ans.st;
//			print(ans);//打印答案
//			if (nowrun == runtime)return;//如果当前运行时间等于进程运行总时间，算法结束
//
//			if (q.empty()) {//就绪队列为空
//				flag1 = 1;//标志没有进程运行
//				t++;
//				continue;
//			}
//			flag1 = 0;//标志有进程运行
//			np = q.front();
//			q.pop(); p = np.pid;
//			ans.id++;//进程具体信息
//			ans.pid = p;
//			ans.st = t;
//			ans.pri = np.pri;
//			t += min(np.run, np.rt);//更改进程运行时间，并增加时钟
//			continue;
//		}
//		else {//当需要运行时间大于时间片，进程不会在这次运行完，还需要重新加入就绪队列
//			np.run -= np.rt;
//			q.push(np);//重新加入就绪队列
//			ans.en = t;
//			nowrun += ans.en - ans.st;
//			print(ans);
//			if (nowrun == runtime)return; //如果当前运行时间等于进程运行总时间，算法结束
//			flag1 = 0;//就绪队列不为空
//			np = q.front();//取出首个进程运行
//			q.pop(); p = np.pid;
//			ans.id++;//进程运行信息
//			ans.pid = p;
//			ans.st = t;
//			ans.pri = np.pri;
//			t += min(np.run, np.rt); //更改进程运行时间，并增加时钟
//		}
//	}
//}
//
//void SPF_P() {
//	memset(vis, false, sizeof(vis));
//	int t = 0;//时钟t
//	int d;
//	int rt;
//	int p, q;
//	int nowrun = 0;//当前程序运行时间
//	int runtime = 0;//程序运行总时间
//	for (int i = 1; i <= cnt; i++)runtime += que[i].run;
//	sort(que + 1, que + 1 + cnt, spfcmp);//进程排序
//	int id = 1;
//	ans.id = 1;//第一个运行的进程
//	ans.st = que[1].come;
//	ans.pid = que[1].pid;
//	ans.pri = que[1].pri;
//	ans.en  = ans.st;
//	p = 1; q = 2;
//	t = que[1].come + 1;
//	int flag1 = 0;
//	for (;; t++) {//时钟每次加一
//		if (flag1 == 0) {//如果处理机正在处理进程，进程的运行时间加一，应该运行时间减一
//			ans.en++; que[p].run--;
//		}
//		while (q <= cnt && que[q].come <= t) { q++; }//将到达的进程加入就绪队列
//		if (que[p].run == 0) {//当前正在运行的程序已经运行完
//			int mmin = INF;
//			for (int i = 1; i < q; i++) {//在就绪队列中查找可以运行的进程
//				if (que[i].run == 0)continue;
//				if (que[i].run < mmin || (que[i].run == mmin && que[i].come < que[p].come)) {
//					//选择运行时间短，运行时间相同时到达时间早的进程
//					mmin = que[i].run;
//					p = i;
//				}
//			}
//			nowrun += ans.en - ans.st;
//			print(ans);
//			if (nowrun == runtime)return;//如果当前运行时间等于进程运行总时间，处理结束
//			if (mmin == INF) {//没有找到可以运行的进程，也就是就绪队列为空
//				flag1 = 1;//标志没有进程正在进行，处理机空闲
//				continue;
//			}
//			flag1 = 0;//标志处理机在处理进程
//			ans.id++;//更新答案数据
//			ans.st = t;
//			ans.pid = que[p].pid;
//			ans.pri = que[p].pri;
//			ans.en = ans.st;
//		}
//		else {
//			int mmin = INF;
//			int np;
//			for (int i = 1; i < q; i++) {//在就绪队列中查找可以运行的进程
//				if (que[i].run == 0)continue;
//				if (que[i].run < mmin || (que[i].run == mmin && que[i].come < que[np].come)) {
//					//选择运行时间短，运行时间相同时到达时间早的进程
//					mmin = que[i].run;
//					np = i;
//				}
//			}
//			flag1 = 0; //标志处理机在处理进程
//			if (mmin == INF)continue;
//			if (que[np].run < que[p].run || (que[np].run == que[p].run&&que[np].come < que[p].come)) {
//				//选择运行时间短，运行时间相同时到达时间早的进程
//				nowrun += ans.en - ans.st;
//				print(ans);
//				if (nowrun == runtime)return; // 如果当前运行时间等于进程运行总时间，处理结束
//				p = np;
//				ans.id++;//更新答案数据
//				ans.st = t;
//				ans.en = t;
//				ans.pid = que[p].pid;
//				ans.pri = que[p].pri;
//			}
//		}
//	}
//
//}
//
//void SPF_N() {
//	int t = 0;//时钟t
//	int p = 1;
//	for (int i = 1; i <= cnt; i++) {//每个进程只运行一次，一共运行cnt个进程
//		int flag1 = 0;
//		while (flag1 == 0) {//当就绪队列中没有进程时，时钟t++，循环等待
//			for (int j = 1; j <= cnt; j++) {
//				if (que[j].run == 0)continue;//已经运行完成的进程
//				if (que[j].come > t)continue;//没有到达的进程
//				if (que[j].come <= t && flag1 == 0) {
//					p = j;
//					flag1 = 1;
//				}
//				else if (que[j].come <= t && flag1 == 1) {
//					if ((que[j].run<que[p].run) || (que[j].run == que[p].run&&que[j].pid<que[p].pid)) {
//						//运行时间短的进程优先，运行时间相同时，进程号小的优先
//						p = j;
//					}
//				}
//			}
//			if (flag1 == 0)t++;//就绪队列为空，时钟t++，循环等待
//		}
//		ans.id = i;//对结果信息赋值
//		ans.pid = que[p].pid;
//		ans.pri = que[p].pri;
//		ans.st = t;
//		ans.en = ans.st + que[p].run;
//		t = ans.en;
//		que[p].run = 0;
//		print(ans);//打印结果进程
//	}
//	return;
//}
//
//void FCFS() {
//	//将进程按照到达时间升序，进程号升序排列，然后按照排列依次运行各程序
//	int t = 0;
//	sort(que + 1, que + 1 + cnt, fcfscmp);//进程排序
//	for (int i = 1; i <= cnt; i++) {//依次运行各程序
//		ans.id = i; ans.pid = que[i].pid;
//		ans.st = max(t, que[i].come);
//		ans.en = ans.st + que[i].run;
//		ans.pri = que[i].pri;
//		t = ans.en;
//		print(ans);//打印程序的具体运行信息
//	}
//	return;
//}
//
//
//void print(struct ANS e) {
//	printf("%d/%d/%d/%d/%d\n", e.id, e.pid, e.st, e.en, e.pri);
//}
//
//bool fcfscmp(node a, node b) {
//	if (a.come != b.come)return a.come < b.come;
//	return a.pid < b.pid;
//}
//
//bool spfcmp(node a, node b) {
//	if (a.come != b.come)return a.come < b.come;
//	else if (a.run != b.run)return a.run < b.run;
//	else return a.pid < b.pid;
//}
//
//bool rrcmp(node a, node b) {
//	if (a.come != b.come)return a.come < b.come;
//	return a.pid < b.pid;
//}
//
//bool pricmp(node a, node b) {
//	if (a.pri != b.pri)return a.pri < b.pri;
//	if (a.come != b.come)return a.come < b.come;
//	return a.pid < b.pid;
//}
