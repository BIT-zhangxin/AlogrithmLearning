//#include <stdio.h>
//
//int grid[4][4] = { 0 };
//
//void set()
//{
//	for (int i = 0; i < 16; i++)
//	{
//		scanf("%d", &grid[i / 4][i % 4]);
//	}
//}
//
//void move(bool line,bool order)//line的true为横，order的true为顺
//{
//	for (int n = 0; n < 4; n++)
//	{
//		int tmp1[4] = { 0 }, tmp2[4] = { 0 }, valid_pos = 0;
//		for (int i = 0; i < 4; i++)
//		{
//			tmp1[i] = grid[(line)*n + (!line)*((order ? 0 : 3) + (order ? 1 : -1)*i)]
//				[(!line)*n + (line)*((order ? 0 : 3) + (order ? 1 : -1)*i)];
//		}
//		for (int i = 0; i < 4; i++)
//		{
//			if (!tmp1[i]) continue;
//			else if (!tmp2[valid_pos])
//			{
//				tmp2[valid_pos] = tmp1[i];
//			}
//			else if (tmp2[valid_pos] == tmp1[i])
//			{
//				tmp2[valid_pos] += tmp1[i];
//				valid_pos++;
//			}
//			else
//			{
//				valid_pos++;
//				tmp2[valid_pos] = tmp1[i];
//			}
//		}
//		for (int i = 0; i < 4; i++)
//		{
//			grid[(line)*n + (!line)*((order ? 0 : 3) + (order ? 1 : -1)*i)]
//				[(!line)*n + (line)*((order ? 0 : 3) + (order ? 1 : -1)*i)] = tmp2[i];
//		}
//	}
//}
//
//void add(int new_position, int new_number)
//{
//	if (!grid[(new_position - 1) / 4][(new_position - 1) % 4])
//		grid[(new_position - 1) / 4][(new_position - 1) % 4] = new_number;
//	else add(new_position % 16 + 1, new_number);
//}
//
//void operation(char direction,int new_position,int new_number)
//{
//	
//	switch (direction)
//	{
//	case 'w':move(0, 1); break;
//	case 'a':move(1, 1); break;
//	case 's':move(0, 0); break;
//	case 'd':move(1, 0); break;
//	default:break;
//	}
//	add(new_position, new_number);
//}
//
//void print()
//{
//	for (int i = 0; i < 16; i++)
//	{
//		printf((!i) ? "%d" : " %d", grid[i / 4][i % 4]);
//	}
//	putchar('\n');
//}
//
//int main()
//{
//	set();
//	char direction;
//	int	new_position, new_number;
//	while (scanf("%*c%c %d%d", &direction, &new_position, &new_number) != EOF)
//	{
//		operation(direction, new_position, new_number);
//	}
//	print();
//	return 0;
//}