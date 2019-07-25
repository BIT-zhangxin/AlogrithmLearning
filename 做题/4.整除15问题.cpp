//#include <cstdio>
//#include <cstring>
//using namespace std;
//
//char list[1005] = { 0 };
//int digitnumber[10] = { 0 };
//
//int Delete(int exceed)
//{
//	for (int i = 0; i < 3; i++)
//	{
//		if (digitnumber[exceed + 3 * i])
//		{
//			digitnumber[exceed + 3 * i]--;
//			return 1;
//		}
//	}
//	return 0;
//}
//
//int Dispose_to_Mltilpe_of_Tree(int exceed)
//{
//	if (exceed == 0) return 1;
//	else
//	{
//		if (Delete(exceed)) return 1;
//		exceed = (exceed == 1) ? 2 : 1;
//		if (Delete(exceed) && Delete(exceed)) return 1;
//	}
//	return 0;
//}
//
//void Print(int lastnumber)
//{
//	int sum = 0;
//	for (int i = 1; i < 10; i++) sum += digitnumber[i];
//	if (!sum) digitnumber[0] = 0;//全0的时候删0,世道险恶
//	for (int i = 9; i >= 0; i--)
//	{
//		for (int j = 0; j < digitnumber[i]; j++) printf("%c", i + '0');
//	}
//	printf("%c\n", lastnumber + '0');
//}
//
//int main()
//{
//	while (scanf("%s", list) != EOF)
//	{
//		int len = strlen(list), lastnumber = 0;
//		for (int i = 0; i < len; i++) digitnumber[list[i] - '0']++;
//		int num1 = digitnumber[1] + digitnumber[4] + digitnumber[7];
//		int num2 = digitnumber[2] + digitnumber[5] + digitnumber[8];
//		if (digitnumber[0] > 0) lastnumber = 0;
//		else if (digitnumber[5] > 0) lastnumber = 5;
//		digitnumber[lastnumber]--;
//		if (digitnumber[0] < 0 || !Dispose_to_Mltilpe_of_Tree((num1 + 2 * num2) % 3)) printf("impossible\n");
//		else Print(lastnumber);
//		memset(digitnumber, 0, sizeof(digitnumber));
//	}
//	return 0;
//}