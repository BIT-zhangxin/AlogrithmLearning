//#include <stdio.h>
//
//char s[100005] = { 0 };
//char t[100005] = { 0 };
//int dit[26] = { 0 };
//
//int judge(char x);
//
//int main()
//{
//	int len = 0;
//	char tmp;
//	while ((tmp = getchar()) != EOF)
//	{
//		if (tmp == '\n')
//		{
//			int stack_num = -1;
//			int letter_num = -1;
//			while (!dit[++letter_num]);
//			int i = 0;
//			while (i < len)
//			{
//				if (dit[letter_num])
//				{
//					//������ǰ����Сletter
//					if (s[i] == letter_num + 'a') putchar(s[i]);
//					else t[++stack_num] = s[i];
//					dit[s[i] - 'a']--;
//					i++;
//				}
//				else if (stack_num == -1 || judge(t[stack_num])) letter_num++;
//					//������ڱ�ջ��С��Ԫ�ػ�ջ��
//				else putchar(t[stack_num--]);
//					//�����ڱ�ջ��С��Ԫ�أ���ӡջ��
//				if (letter_num == 26) break;
//			}
//			while (stack_num >= 0) putchar(t[stack_num--]);
//			putchar(10);
//			len = 0;
//		}
//		else
//		{
//			s[len++] = tmp;
//			dit[tmp - 'a']++;
//		}
//	}
//	return 0;
//}
//
//int judge(char x)
//{
//	
//	for (int i = 0; i < x - 'a'; i++)
//	{
//		if (dit[i]) return 1;
//	}
//	return 0;
//}