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
//	int pid;//���̺�
//	int come;//���̵���ʱ��
//	int run;//��������ʱ��
//	int pri;//�������ȼ�
//	int rt;//����ʱ��Ƭ
//}
//tmp;
//int cnt;
//struct node que[101010];
//bool vis[101010];
//
//int nowp;
//struct ANS {
//	int id;//�������
//	int pid;//���̺�
//	int st;//���̿�ʼ����ʱ��
//	int en;//���̽�������ʱ��
//	int pri;//�������ȼ�
//}ans;
//
//node qu[101010];//��������
//int he;//��������ͷ�� 
//int ta;//��������β��
//
//void print(struct ANS e);//��ӡ�������������̵���Ϣ����Ϣ�洢��struct ANS�ṹ��
//
//bool fcfscmp(node a, node b);
////�����ȷ����㷨������������Ȱ��յ���ʱ�������ٰ��ս��̺���������
//bool spfcmp(node a, node b);
////����ҵ�����㷨������������Ȱ��յ���ʱ�������ٰ�������ʱ�������ٰ����̺���������
//bool rrcmp(node a, node b);
////ʱ��Ƭ��ת�㷨������������Ȱ��յ���ʱ�������ٰ��ս��̺���������
//bool pricmp(node a, node b);
////��̬���ȼ��㷨������������Ȱ��ս��������������ٰ�����ʱ�������ٰ����̺���������
//
//
//void FCFS();//�����ȷ�������㷨
//void SPF_N();//���ɰ���Ķ���ҵ���ȵ����㷨
//void SPF_P();//�ɰ���Ķ���ҵ���ȵ����㷨
//void RR();//ʱ��Ƭ��ת�����㷨
//void PRI();//��̬���ȼ������㷨
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
//	case 1:FCFS(); break;//�����ȷ�������㷨
//	case 2:SPF_N(); break;//���ɰ���Ķ���ҵ���ȵ����㷨
//	case 3:SPF_P(); break;//�ɰ���Ķ���ҵ���ȵ����㷨
//	case 4:RR(); break;//ʱ��Ƭ��ת�����㷨
//	case 5:PRI(); break;//��̬���ȼ������㷨
//	}
//	system("pause");
//	return 0;
//}
//void PRI() {
//	int runtime = 0, nowtime = 0;//��ǰ����ʱ��ͽ���������ʱ��
//	memset(vis, 0, sizeof(vis));
//	he = 1; ta = 0;
//	int t = 0;
//	ans.id = 0;
//	for (int i = 1; i <= cnt; i++)//�������������ʱ��
//		runtime += que[i].run;
//	for (;;) {
//		for (int i = 1; i <= cnt; i++) {
//			if (vis[i] == 1)continue;
//			if (que[i].come <= t) {//������Ľ��̼����������
//				qu[++ta] = que[i];
//				vis[i] = 1;
//			}
//		}
//		if (ta < he) {//��������Ϊ��ʱ��ʱ�Ӽ�һ�����²��ҵ���Ľ���
//			t++;
//			continue;
//		}
//		sort(qu + he, qu + ta + 1, pricmp);//�����������еĽ�������
//		qu[he].pri += 3;//����һ��ʱ��Ƭ�Ľ�������������
//		ans.pri = qu[he].pri;
//		ans.id++;//���н�����Ϣ
//		ans.pid = qu[he].pid;
//		ans.st = t;
//		t += min(qu[he].rt, qu[he].run);//����ʱ��Ϊ��Ҫ����ʱ���ʱ��Ƭ�Ľ�Сֵ
//		ans.en = t;
//		print(ans);
//		nowtime += ans.en - ans.st;
//		if (nowtime == runtime)return;//��ǰ����ʱ�������Ҫ������ʱ��ʱ�㷨����
//		node np = qu[he++];
//		for (int i = 1; i <= cnt; i++) {
//			if (vis[i] == 1)continue;
//			if (que[i].come<t) {//****���˿�֮ǰ�ĵ���Ľ��̶�������У�Ϊ�˺�������ȼ��ı�
//				qu[++ta] = que[i];
//				vis[i] = 1;
//			}
//		}
//		for (int i = he; i <= ta; i++) {//�������еĽ������ȼ�����һ
//			node tmp = qu[i];
//			tmp.pri -= 1;//ÿ�������еĽ������ȼ�����һ
//			if (tmp.pri < 0)//���ȼ�����СΪ0
//				tmp.pri = 0;
//			qu[i] = tmp;
//		}
//		np.run -= (ans.en - ans.st);
//		if (np.run != 0)//��ǰ����û�������꣬��Ҫ���¼����������
//			qu[++ta] = np;
//	}
//}
//
//void RR() {
//	memset(vis, 0, sizeof(vis));
//	queue<node>q;//��������
//	int t = 0;
//	int runtime = 0, nowrun = 0;//��ǰ����ʱ��ͽ���������ʱ��
//	sort(que + 1, que + cnt + 1, rrcmp);//����
//	for (int i = 1; i <= cnt; i++) { runtime += que[i].run; }//�������������ʱ��
//	q.push(que[1]); vis[que[1].pid] = 1;//���������м����һ������
//	int p = que[1].pid;
//	int ip;
//	node np = q.front(); q.pop();
//	ans.id = 1;//��һ���𰸵���Ϣ
//	ip = 1;
//	t = np.come;
//	ans.st = np.come;
//	ans.pid = np.pid;
//	ans.pri = np.pri;
//	int flag1 = 0;
//	t += min(np.run, np.rt);//����ʱ��Ϊʱ��Ƭ����Ҫ����ʱ��Ľ�Сֵ
//							//���Ľ�������ʱ�䣬������ʱ��
//	for (;;) {
//		for (int i = 1; i <= cnt; i++) {
//			if (vis[que[i].pid] == 1 || que[i].pid == p)continue;
//			if (que[i].come <= t) {//������Ľ��̼���������У�����־
//				q.push(que[i]);
//				vis[que[i].pid] = 1;
//			}
//		}
//		if (flag1 == 1) {//��ǰû�г�������
//			if (q.empty()) {//���ھ�������Ϊ��
//				t++;//����ʱ�Ӽ�һ
//				continue;
//			}
//			else {//�������в�Ϊ��
//				np = q.front();//ȡ���׸���������
//				q.pop(); p = np.pid;
//				ans.id++;//���̵���Ϣ
//				ans.pid = p;
//				ans.st = t;
//				ans.pri = np.pri;
//				t += min(np.run, np.rt); //���Ľ�������ʱ�䣬������ʱ��
//				continue;
//			}
//		}
//		else if (np.run <= np.rt) {//��ǰ�н�������ʱ�������Ҫ����ʱ��С�ڵ���ʱ��Ƭ
//			vis[p] = 1;
//			ans.en = t;
//			nowrun += ans.en - ans.st;
//			print(ans);//��ӡ��
//			if (nowrun == runtime)return;//�����ǰ����ʱ����ڽ���������ʱ�䣬�㷨����
//
//			if (q.empty()) {//��������Ϊ��
//				flag1 = 1;//��־û�н�������
//				t++;
//				continue;
//			}
//			flag1 = 0;//��־�н�������
//			np = q.front();
//			q.pop(); p = np.pid;
//			ans.id++;//���̾�����Ϣ
//			ans.pid = p;
//			ans.st = t;
//			ans.pri = np.pri;
//			t += min(np.run, np.rt);//���Ľ�������ʱ�䣬������ʱ��
//			continue;
//		}
//		else {//����Ҫ����ʱ�����ʱ��Ƭ�����̲�������������꣬����Ҫ���¼����������
//			np.run -= np.rt;
//			q.push(np);//���¼����������
//			ans.en = t;
//			nowrun += ans.en - ans.st;
//			print(ans);
//			if (nowrun == runtime)return; //�����ǰ����ʱ����ڽ���������ʱ�䣬�㷨����
//			flag1 = 0;//�������в�Ϊ��
//			np = q.front();//ȡ���׸���������
//			q.pop(); p = np.pid;
//			ans.id++;//����������Ϣ
//			ans.pid = p;
//			ans.st = t;
//			ans.pri = np.pri;
//			t += min(np.run, np.rt); //���Ľ�������ʱ�䣬������ʱ��
//		}
//	}
//}
//
//void SPF_P() {
//	memset(vis, false, sizeof(vis));
//	int t = 0;//ʱ��t
//	int d;
//	int rt;
//	int p, q;
//	int nowrun = 0;//��ǰ��������ʱ��
//	int runtime = 0;//����������ʱ��
//	for (int i = 1; i <= cnt; i++)runtime += que[i].run;
//	sort(que + 1, que + 1 + cnt, spfcmp);//��������
//	int id = 1;
//	ans.id = 1;//��һ�����еĽ���
//	ans.st = que[1].come;
//	ans.pid = que[1].pid;
//	ans.pri = que[1].pri;
//	ans.en  = ans.st;
//	p = 1; q = 2;
//	t = que[1].come + 1;
//	int flag1 = 0;
//	for (;; t++) {//ʱ��ÿ�μ�һ
//		if (flag1 == 0) {//�����������ڴ�����̣����̵�����ʱ���һ��Ӧ������ʱ���һ
//			ans.en++; que[p].run--;
//		}
//		while (q <= cnt && que[q].come <= t) { q++; }//������Ľ��̼����������
//		if (que[p].run == 0) {//��ǰ�������еĳ����Ѿ�������
//			int mmin = INF;
//			for (int i = 1; i < q; i++) {//�ھ��������в��ҿ������еĽ���
//				if (que[i].run == 0)continue;
//				if (que[i].run < mmin || (que[i].run == mmin && que[i].come < que[p].come)) {
//					//ѡ������ʱ��̣�����ʱ����ͬʱ����ʱ����Ľ���
//					mmin = que[i].run;
//					p = i;
//				}
//			}
//			nowrun += ans.en - ans.st;
//			print(ans);
//			if (nowrun == runtime)return;//�����ǰ����ʱ����ڽ���������ʱ�䣬�������
//			if (mmin == INF) {//û���ҵ��������еĽ��̣�Ҳ���Ǿ�������Ϊ��
//				flag1 = 1;//��־û�н������ڽ��У����������
//				continue;
//			}
//			flag1 = 0;//��־������ڴ������
//			ans.id++;//���´�����
//			ans.st = t;
//			ans.pid = que[p].pid;
//			ans.pri = que[p].pri;
//			ans.en = ans.st;
//		}
//		else {
//			int mmin = INF;
//			int np;
//			for (int i = 1; i < q; i++) {//�ھ��������в��ҿ������еĽ���
//				if (que[i].run == 0)continue;
//				if (que[i].run < mmin || (que[i].run == mmin && que[i].come < que[np].come)) {
//					//ѡ������ʱ��̣�����ʱ����ͬʱ����ʱ����Ľ���
//					mmin = que[i].run;
//					np = i;
//				}
//			}
//			flag1 = 0; //��־������ڴ������
//			if (mmin == INF)continue;
//			if (que[np].run < que[p].run || (que[np].run == que[p].run&&que[np].come < que[p].come)) {
//				//ѡ������ʱ��̣�����ʱ����ͬʱ����ʱ����Ľ���
//				nowrun += ans.en - ans.st;
//				print(ans);
//				if (nowrun == runtime)return; // �����ǰ����ʱ����ڽ���������ʱ�䣬�������
//				p = np;
//				ans.id++;//���´�����
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
//	int t = 0;//ʱ��t
//	int p = 1;
//	for (int i = 1; i <= cnt; i++) {//ÿ������ֻ����һ�Σ�һ������cnt������
//		int flag1 = 0;
//		while (flag1 == 0) {//������������û�н���ʱ��ʱ��t++��ѭ���ȴ�
//			for (int j = 1; j <= cnt; j++) {
//				if (que[j].run == 0)continue;//�Ѿ�������ɵĽ���
//				if (que[j].come > t)continue;//û�е���Ľ���
//				if (que[j].come <= t && flag1 == 0) {
//					p = j;
//					flag1 = 1;
//				}
//				else if (que[j].come <= t && flag1 == 1) {
//					if ((que[j].run<que[p].run) || (que[j].run == que[p].run&&que[j].pid<que[p].pid)) {
//						//����ʱ��̵Ľ������ȣ�����ʱ����ͬʱ�����̺�С������
//						p = j;
//					}
//				}
//			}
//			if (flag1 == 0)t++;//��������Ϊ�գ�ʱ��t++��ѭ���ȴ�
//		}
//		ans.id = i;//�Խ����Ϣ��ֵ
//		ans.pid = que[p].pid;
//		ans.pri = que[p].pri;
//		ans.st = t;
//		ans.en = ans.st + que[p].run;
//		t = ans.en;
//		que[p].run = 0;
//		print(ans);//��ӡ�������
//	}
//	return;
//}
//
//void FCFS() {
//	//�����̰��յ���ʱ�����򣬽��̺��������У�Ȼ���������������и�����
//	int t = 0;
//	sort(que + 1, que + 1 + cnt, fcfscmp);//��������
//	for (int i = 1; i <= cnt; i++) {//�������и�����
//		ans.id = i; ans.pid = que[i].pid;
//		ans.st = max(t, que[i].come);
//		ans.en = ans.st + que[i].run;
//		ans.pri = que[i].pri;
//		t = ans.en;
//		print(ans);//��ӡ����ľ���������Ϣ
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
