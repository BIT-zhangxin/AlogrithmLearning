//#include <cstdio>
//#include <cstring>
//
//class FileInfo
//{
//public:
//	char state;//文件状态
//	char name[8];//文件名
//	char extension[3];//扩展名
//	int date;//修改日期
//	int time;//修改时间
//	int parent;//父亲节点编号
//	int indexNumber;//索引编号
//	int size;//文件大小
//};
//
//void Zero(char *destination, int number)
//{
//	for (int i = 0; i < number; i++)
//	{
//		destination[i] = 0;
//	}
//}
//
//void Copy(char *destination,char *source)
//{
//	int number = strlen(source);
//	if (number > 8) number = 8;
//	for (int i = 0; i < number; i++)
//	{
//		destination[i] = source[i];
//	}
//}
//
//void ReadBuffer(FileInfo node, char *buffer)
//{
//	int loc = 0;
//	buffer[loc] = node.state;
//	loc += 1;
//	for (int i = 0; i < 8; i++)
//	{
//		buffer[loc + i] = node.name[i];
//	}
//	loc += 8;
//	for (int i = 0; i < 3; i++)
//	{
//		buffer[loc + i] = node.extension[i];
//	}
//	loc += 3;
//	*((int *)(buffer + loc)) = node.date;
//	loc += 4;
//	*((int *)(buffer + loc)) = node.time;
//	loc += 4;
//	*((int *)(buffer + loc)) = node.parent;
//	loc += 4;
//	*((int *)(buffer + loc)) = node.indexNumber;
//	loc += 4;
//	*((int *)(buffer + loc)) = node.size;
//	return;
//}
//
//void Copy_b(char *destination,char *source,int len)
//{
//	for (int i = 0; i < len; i++)
//	{
//		destination[i] = source[i];
//	}
//}
//
//int main()
//{
//	FileInfo Node[5];
//	{
//		int num = 0;
//		Node[num].state = 3;
//		Zero(Node[num].name, 8);
//		Zero(Node[num].extension, 3);
//		Node[num].date = 20180905;
//		Node[num].time = 101010;
//		Node[num].parent = -1;
//		Node[num].indexNumber = 0;
//		Node[num].size = 0;
//	}
//	{
//		int num = 1;
//		Node[num].state = 1;
//		Copy(Node[num].name, "aaaaaaaa");
//		Copy(Node[num].extension, "AAA");
//		Node[num].date = 20180905;
//		Node[num].time = 101010;
//		Node[num].parent = 0;
//		Node[num].indexNumber = 1;
//		Node[num].size = 100;
//	}
//	{
//		int num = 2;
//		Node[num].state = 0;
//		Zero(Node[num].name, 8);
//		Zero(Node[num].extension, 3);
//		Node[num].date = 0;
//		Node[num].time = 0;
//		Node[num].parent = 0;
//		Node[num].indexNumber = 0;
//		Node[num].size = 0;
//	}
//	{
//		int num = 3;
//		Node[num].state = 2;
//		Copy(Node[num].name, "bbbbbbbb");
//		Zero(Node[num].extension, 3);
//		Node[num].date = 20180905;
//		Node[num].time = 101010;
//		Node[num].parent = 0;
//		Node[num].indexNumber = 0;
//		Node[num].size = 0;
//	}
//	{
//		int num = 4;
//		Node[num].state = 1;
//		Copy(Node[num].name, "cccccccc");
//		Copy(Node[num].extension, "CCC");
//		Node[num].date = 20180905;
//		Node[num].time = 101010;
//		Node[num].parent = 3;
//		Node[num].indexNumber = 4;
//		Node[num].size = 1000;
//	}
//	char buffer32[32] = { 0 };
//	char buffer4096[4096] = { 0 };
//	ReadBuffer(Node[4], buffer32);
//	for (int i = 0; i < 5; i++)
//	{
//		ReadBuffer(Node[i], buffer32);
//		Copy_b(buffer4096 + i * 32, buffer32, 32);
//	}
//	FILE *fp = fopen("directory.fsd", "wb");
//	fwrite(buffer4096, sizeof(char), 4096, fp);
//	fclose(fp);
//	return 0;
//}