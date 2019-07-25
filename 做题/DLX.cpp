//#include <cstdio>
//#include <cstring>
//using namespace std;
//
//const int DLX_Row = 729;
//const int DLX_Col = 324;
//const int MAXN = 3241;
//const int INF = 2 << 29;
//
//int sudoku[9][9];
//
//char DLX[729][324];
//int Left[MAXN], Right[MAXN], Up[MAXN], Down[MAXN];
//int Row_Loc[MAXN], Col_Loc[MAXN], Col_Size[MAXN];
//int Head, Node_Number;
//
//int Create_Node(int left, int right, int up, int down)
//{
//	Left[Node_Number] = left; Right[left] = Node_Number;
//	Right[Node_Number] = right; Left[right] = Node_Number;
//	Up[Node_Number] = up; Down[up] = Node_Number;
//	Down[Node_Number] = down; Up[down] = Node_Number;
//	return Node_Number++;
//}
//
//void InitDLX() {
//	memset(DLX, 0, sizeof(DLX));
//	memset(Left, 0, sizeof(Left));
//	memset(Right, 0, sizeof(Right));
//	memset(Up, 0, sizeof(Up));
//	memset(Down, 0, sizeof(Down));
//	memset(Row_Loc, 0, sizeof(Row_Loc));
//	memset(Col_Loc, 0, sizeof(Col_Loc));
//	memset(Col_Size, 0, sizeof(Col_Size));
//	memset(Left, 0, sizeof(Left));
//	Node_Number = MAXN - 1;
//	for (int row = 0; row < 9; row++) 
//	{
//		for (int col = 0; col < 9; col++)
//		{
//			int num = row * 9 + col;
//			if (sudoku[row][col] == 0)
//			{
//				for (int i = 0; i < 9; i++)
//				{
//					DLX[num * 9 + i][num] = 1;
//					DLX[num * 9 + i][81 + row * 9 + i] = 1;
//					DLX[num * 9 + i][162 + col * 9 + i] = 1;
//					DLX[num * 9 + i][243 + (row / 3 * 3 + col / 3) * 9 + i] = 1;
//				}
//			}
//			else
//			{
//				int i = sudoku[row][col] - 1;
//				DLX[num * 9 + i][num] = 1;
//				DLX[num * 9 + i][81 + row * 9 + i] = 1;
//				DLX[num * 9 + i][162 + col * 9 + i] = 1;
//				DLX[num * 9 + i][243 + (row / 3 * 3 + col / 3) * 9 + i] = 1;
//			}
//		}
//	}
//	Head = Create_Node(Node_Number, Node_Number, Node_Number, Node_Number);//建立头结点
//	Node_Number = 0;
//	for (int i = 0; i < DLX_Col; i++)//建立辅助节点
//	{
//		Create_Node(Left[Head], Head, Node_Number, Node_Number);
//		Col_Loc[i] = i; Col_Size[i] = 0;
//	}
//	for (int i = 0; i < DLX_Row; i++)//建立内部节点
//	{
//		int loc = -1;
//		for (int j = 0; j < DLX_Col; j++)
//		{
//			if (!DLX[i][j]) continue;
//			if (loc == -1)
//			{
//				loc = Create_Node(Node_Number, Node_Number, Up[Col_Loc[j]], Col_Loc[j]);
//				Row_Loc[loc] = i; Col_Loc[loc] = j; Col_Size[j]++;
//			}
//			else
//			{
//				loc = Create_Node(loc, Right[loc], Up[Col_Loc[j]], Col_Loc[j]);
//				Row_Loc[loc] = i; Col_Loc[loc] = j; Col_Size[j]++;
//			}
//		}
//	}
//}
//
//void Remove(int Node)
//{
//	Left[Right[Node]] = Left[Node];
//	Right[Left[Node]] = Right[Node];
//	for (int i = Down[Node]; i != Node; i = Down[i])
//	{
//		for (int j = Right[i]; j != i; j = Right[j])
//		{
//			Up[Down[j]] = Up[j];
//			Down[Up[j]] = Down[j];
//			Col_Size[Col_Loc[j]]--;
//		}
//	}
//}
//
//void Resume(int Node)
//{
//	Right[Left[Node]] = Node;
//	Left[Right[Node]] = Node;
//	for (int i = Up[Node]; i != Node; i = Up[i])
//	{
//		for (int j = Left[i]; j != i; j = Left[j])
//		{
//			Col_Size[Col_Loc[j]]++;
//			Down[Up[j]] = j;
//			Up[Down[j]] = j;
//		}
//	}
//}
//
//int Solve()
//{
//	if (Right[Head] == Head) return 1;
//	int Node;
//	int Min = INF;
//	for (int i = Right[Head]; i != Head; i = Right[i])
//	{
//		if (Col_Size[i] < Min)
//		{
//			Min = Col_Size[i];
//			Node = i;
//		}
//	}
//	Remove(Node);
//	for (int i = Down[Node]; i != Node; i = Down[i])
//	{
//		int loc = Row_Loc[i];
//		sudoku[loc / 81][loc / 9 % 9] = loc % 9 + 1;
//		for (int j = Right[i]; j != i; j = Right[j]) Remove(Col_Loc[j]);
//		if (Solve()) return 1;
//		for (int j = Left[i]; j != i; j = Left[j]) Resume(Col_Loc[j]);
//	}
//	Resume(Node);
//	return 0;
//}
//
//void Scanf(char *X)
//{
//	for (int i = 0; i < 9; i++)
//	{
//		for (int j = 0; j < 9; j++)
//		{
//			if (X[i * 9 + j] == '.') sudoku[i][j] = 0;
//			else sudoku[i][j] = X[i * 9 + j] - '0';
//		}
//	}
//}
//
//void Print()
//{
//	for (int i = 0; i < 9; i++)
//	{
//		for (int j = 0; j < 9; j++)
//		{
//			printf((j > 0) ? " %d" : "%d", sudoku[i][j]);
//		}
//		putchar(10);
//	}
//	putchar(10);
//}
//
//int main() {
//	char tmp[100] = { 0 };
//	while (1)
//	{
//		scanf("%s", tmp);
//		Scanf(tmp);
//		InitDLX();
//		Solve();
//		Print();
//	}
//	return 0;
//}