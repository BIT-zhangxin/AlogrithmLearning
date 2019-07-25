//#include <stdio.h>
//#include <string.h>
//
//char A[23];
//char B[103];
//
//int letter[52] = { 0 };
//
//int search(char *A, char *B);
//
//int main()
//{
//	memset(A, 0, sizeof(A));
//	scanf("%s", A);
//	int A_len = strlen(A);
//	char *x = A;
//	if (*x == '^') x++;
//	while(1)
//	{
//		if (*(x + 1) == '?' || *(x + 1) == '*')
//		{
//			x += 2;
//		}
//		else if (*(x + 1) == '+')
//		{
//			if (*x == '.');
//			else if (*x >= 'A'&&*x <= 'Z')
//			{
//				letter[*x - 'A' + 26]++;
//			}
//			else if (*x >= 'a'&&*x <= 'z')
//			{
//				letter[*x - 'a']++;
//			}
//			x += 2;
//		}
//		else if (*x == 0 || *x == '$') break;
//		else 
//		{
//			if (*x == '.');
//			else if (*x >= 'A'&&*x <= 'Z')
//			{
//				letter[*x - 'A' + 26]++;
//			}
//			else if (*x >= 'a'&&*x <= 'z')
//			{
//				letter[*x - 'a']++;
//			}
//			x++;
//		}
//	}
//	while (scanf("%s", B) != EOF)
//	{
//		int ans = 0;
//		if (*A == '^')
//		{
//			ans = search(A + 1, B);
//		}
//		else
//		{
//			int b_len = strlen(B);
//			int tmp[52] = { 0 };
//			int flag = 0;
//			for (int i = 0; i < b_len; i++)
//			{
//				if (*(B + i) >= 'A'&&*(B + i) <= 'Z')
//				{
//					tmp[*(B + i) - 'A' + 26]++;
//				}
//				else if (*(B + i) >= 'a'&&*(B + i) <= 'z')
//				{
//					tmp[*(B + i) - 'a']++;
//				}
//			}
//			for (int i = 0; i < 52; i++)
//			{
//				if (letter[i] > tmp[i]) flag = 1;
//			}
//			if (flag == 0)
//			{
//				for (int i = 0; i < b_len; i++)
//				{
//					ans = search(A, B + i);
//					if (ans == 1) break;
//				}
//			}
//		}
//		if (ans==1)
//		{
//			printf("YES\n");
//		}
//		else printf("NO\n");
//		memset(B, 0, sizeof(B));
//	}
//	return 0;
//}
//
//int search(char *A, char *B)
//{
//	if (*A == '$')
//	{
//		if (*B == 0) return 1;
//		else return 0;
//	}
//	if (*A == 0) return 1;
//	if (*(A + 1) == '?')
//	{
//		if (search(A + 2, B) == 1) return 1;
//		if (*A == '.' || *A == *B)
//		{
//			if (search(A + 2, B + 1) == 1) return 1;
//		}
//		else return 0;
//	}
//	else if (*(A + 1) == '*')
//	{
//		if (search(A + 2, B) == 1) return 1;
//		if (*A == '.' || *A == *B)
//		{
//			char *C = B;
//			while (*C == *B) C++;
//			if (search(A + 2, C) == 1) return 1;
//			while (--C != B)
//			{
//				if (search(A + 2, C) == 1) return 1;
//			}
//		}
//		else return 0;
//	}
//	else
//	{
//		if (*A == '.'&&*B == 0) return 0;
//		if (*A != '.' && *A != *B) return 0;
//		if (*(A + 1) == '+')
//		{
//			if (search(A + 2, B + 1) == 1) return 1;
//			char *C = B;
//			while (*C == *B) C++;
//			if (search(A + 2, C) == 1) return 1;
//			while (--C != B)
//			{
//				if (search(A + 2, C) == 1) return 1;
//			}
//		}
//		else
//		{
//			return search(A + 1, B + 1);
//		}
//	}
//}