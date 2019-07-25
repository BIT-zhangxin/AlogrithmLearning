//#include <stdio.h>
//#include <string.h>
//
//void plus(char *a, char *b, char *c);
//void minus(char *a, char *b, char *c);
//void multiply(char *a, char *b, char *c);
//
//int main()
//{
//	char a[1000];
//	char b[1000];
//	char c[1000];
//	char s[2];
//	while (scanf("%s %s %s", a, s, b) == 3) {
//		if (s[0] == '+') {
//			plus(a, b, c);
//		}
//		else if (s[0] == '-') {
//			minus(a, b, c);
//		}
//		else if (s[0] == '*') {
//			multiply(a, b, c);
//		}
//		printf("%s\n", c);
//	}
//	return 0;
//}
//
//void plus(char *a, char *b, char *c)
//{
//	memset(c, 0, 1000);
//	while (*a == '0'&&*(a + 1) != 0) a++;
//	while (*b == '0'&&*(b + 1) != 0) b++;
//	int a_len = strlen(a);
//	int b_len = strlen(b);
//	int max = (a_len > b_len) ? a_len : b_len;
//	for (int i = 0; i < max; i++)
//	{
//		int A = (a_len - 1 - i < 0) ? 0 : a[a_len - 1 - i] - '0';
//		int B = (b_len - 1 - i < 0) ? 0 : b[b_len - 1 - i] - '0';
//		c[i] = A + B;
//	}
//	for (int i = 0; i < max; i++)
//	{
//		c[i + 1] += c[i] / 10;
//		c[i] = c[i] % 10;
//	}
//	if (c[max] > 0) max++;
//	for (int i = max - 1; i > 0; i--)
//	{
//		if (c[i] == 0) max--;
//		else break;
//	}
//	for (int i = 0; i < max; i++)
//	{
//		c[i] += '0';
//	}
//	for (int i = 0; i < max / 2; i++)
//	{
//		char tmp = c[i];
//		c[i] = c[max - 1 - i];
//		c[max - 1 - i] = tmp;
//	}
//	c[max] = 0;
//}
//
//void minus(char *a, char *b, char *c)
//{
//	memset(c, 0, 1000);
//	while (*a == '0'&&*(a + 1) != 0) a++;
//	while (*b == '0'&&*(b + 1) != 0) b++;
//	int a_len = strlen(a);
//	int b_len = strlen(b);
//	int max = (a_len > b_len) ? a_len : b_len;
//	int carry = 0;
//	for (int i = 0; i < max; i++)
//	{
//		int A = ((a_len - 1 - i < 0) ? 0 : a[a_len - 1 - i] - '0');
//		int B = ((b_len - 1 - i < 0) ? 0 : b[b_len - 1 - i] - '0') + carry;
//		if (A < B)
//		{
//			c[i] = A + 10 - B;
//			carry = 1;
//		}
//		else
//		{
//			c[i] = A - B;
//			carry = 0;
//		}
//	}
//	for (int i = max - 1; i > 0; i--)
//	{
//		if (c[i] == 0) max--;
//		else break;
//	}
//	for (int i = 0; i < max; i++)
//	{
//		c[i] += '0';
//	}
//	if (carry == 1)
//	{
//		minus(b, a, c);
//		printf("-");
//		return;
//	}
//	for (int i = 0; i < max / 2; i++)
//	{
//		char tmp = c[i];
//		c[i] = c[max - 1 - i];
//		c[max - 1 - i] = tmp;
//	}
//	c[max] = 0;
//}
//
//void multiply(char *a, char *b, char *c)
//{
//	memset(c, 0, 1000);
//	while (*a == '0'&&*(a + 1) != 0) a++;
//	while (*b == '0'&&*(b + 1) != 0) b++;
//	int a_len = strlen(a);
//	int b_len = strlen(b);
//	for (int i = 0; i < a_len; i++)
//	{
//		for (int j = 0; j < b_len; j++)
//		{
//			c[i + j] += (a[a_len - 1 - i] - '0')*(b[b_len - 1 - j] - '0');
//		}
//		for (int j = 0; j < b_len; j++)
//		{
//			c[i + j + 1] += c[i + j] / 10;
//			c[i + j] = c[i + j] % 10;
//		}
//	}
//	int c_len = 1000;
//	for (int i = 999; i > 0; i--)
//	{
//		if (c[i] == 0) c_len--;
//		else break;
//	}
//	for (int i = 0; i < c_len; i++)
//	{
//		c[i] += '0';
//	}
//	for (int i = 0; i < c_len / 2; i++)
//	{
//		char tmp = c[i];
//		c[i] = c[c_len - 1 - i];
//		c[c_len - 1 - i] = tmp;
//	}
//	c[c_len] = 0;
//}
