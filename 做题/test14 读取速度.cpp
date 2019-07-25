//#include <cstdio>
//#include <ctime>
//using namespace std;
//
//#define SYSTEM (1 << 30)
//#define BLOCK1 (1 << 12)
//#define BLOCK2 (1 << 20)
//
//int Create()
//{
//	FILE *fp = fopen("test.fs", "rb");
//	if (fp != NULL)
//	{
//		return 2;
//	}
//	else
//	{
//		fp = fopen("test.fs", "wb");
//		fseek(fp, SYSTEM - 1, SEEK_SET);
//		char end = EOF;
//		fwrite(&end, 1, 1, fp);
//		fclose(fp);
//		return 0;
//	}
//}
//
//int Fread1(FILE *fp)
//{
//	fseek(fp, 0, SEEK_SET);
//	char buffer[BLOCK1];
//	int start = clock();
//	for (int i = 0; i < SYSTEM / BLOCK1; i++)
//	{
//		fread(buffer, sizeof(char), BLOCK1, fp);
//	}
//	int end = clock();
//	int time = end - start;
//	return time;
//}
//
//int Fread2(FILE *fp)
//{
//	fseek(fp, 0, SEEK_SET);
//	char buffer[BLOCK2];
//	int start = clock();
//	for (int i = 0; i < SYSTEM / BLOCK2; i++)
//	{
//		fread(buffer, sizeof(char), BLOCK2, fp);
//	}
//	int end = clock();
//	int time = end - start;
//	return time;
//}
//
//int main()
//{
//	//Create();
//	FILE *fp = fopen("test.fs", "rb");
//	int ans = fseek(fp, -100, SEEK_SET);
//	printf("%d\n", ans);
//	/*printf("��ȡ1G�ļ�����ʱ�䣺\n");
//	for (int i = 0; i < 10; i++)
//	{
//		printf("һ�ζ�ȡ4KB��ʱ��%dms\n", Fread1(fp));
//		printf("һ�ζ�ȡ1MB��ʱ��%dms\n", Fread2(fp));
//	}*/
//	return 0;
//}