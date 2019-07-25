//#include <cstdio>
//#include <cstring>
//#include <stack>
//#include <algorithm>
//using namespace std;
//
//typedef struct{
//	int pre;
//	int num;
//	long long int high;
//}NODE;
//NODE Node[100010];
//
//int main()
//{
//	int n;
//	while (1)
//	{
//		scanf("%d", &n);
//		if (n == 0) break;
//		memset(Node, 0, sizeof(Node));
//		for (int i = 0; i < n; i++)
//		{
//			scanf("%lld", &Node[i].high);
//			Node[i].num = i;
//			Node[i].pre = 0;
//		}
//		stack <NODE> s;
//		long long int ans = 0;
//		for (int i = 0; i <= n; i++)
//		{
//			while (!s.empty() && Node[i].high < s.top().high)
//			{
//				NODE tmp = s.top();
//				s.pop();
//				Node[i].pre += tmp.pre + 1;
//				ans = max(ans, tmp.high*(long long)(i - tmp.num + tmp.pre));
//			}
//			s.push(Node[i]);
//		}
//		printf("%lld\n", ans);
//	}
//	return 0;
//}