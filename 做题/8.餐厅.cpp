//#include <cstdio>
//#include <cstring>
//
//int main()
//{
//	int n;
//	scanf("%d", &n);
//	while(n--)
//	{
//		char tmp[205] = { 0 };
//		scanf("%s", tmp);
//		int length = strlen(tmp);
//		int SumMax = 0;
//		int TmpMax1 = 0;
//		int TmpMax2 = 0;
//		for (int i = 0; i < length; i++)
//		{
//			if (tmp[i] == '+')
//			{
//				TmpMax1++;
//				TmpMax2--;
//				
//			}
//			else
//			{
//				TmpMax1--;
//				TmpMax2++;
//			}
//			if (TmpMax1 > SumMax) SumMax = TmpMax1;
//			else if (TmpMax1 < 0) TmpMax1 = 0;
//			if (TmpMax2 > SumMax) SumMax = TmpMax2;
//			else if (TmpMax2 < 0) TmpMax2 = 0;
//		}
//		printf("%d\n", SumMax);
//	}
//	return 0;
//}