//#include <iostream>
//#include <queue>
//#include <vector>
//using namespace std;
//struct cmp
//{
//	bool operator ()(int &a, int &b) {
//		return a > b;//最小值优先  
//	}
//};
//int main()
//{
//	priority_queue<int, vector<int>, cmp>q;
//	int n, tmp;
//	scanf("%d", &n);
//	for (int i = 0; i < n; i++)
//	{
//		scanf("%d", &tmp);
//		q.push(tmp);
//	}
//	int ans = 0;
//	if (n == 1) ans = tmp;
//	for (int i = 1; i < n; i++)
//	{
//		int tmp1 = q.top();
//		q.pop();
//		int tmp2 = q.top();
//		q.pop();
//		int tmp3 = tmp1 + tmp2;
//		q.push(tmp3);
//		ans += tmp3;
//	}
//	printf("WPL=%d\n", ans);
//	return 0;
//}