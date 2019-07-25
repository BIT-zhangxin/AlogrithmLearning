#pragma once
#ifndef _MY_QSORT
#define _MY_QSORT

#include <time.h>

class QSORT
{
private:
	const int CUTOFF = 8;
	//public:
	//	//自定义cmp
	//	int(*cmp)(const void *, const void *);

	//全功能快排
public:
	//真快排1
	void Qsort1(void *Base, int size_of_array, int size_of_element, int(*cmp)(const void *, const void *))
	{
		Qsort1_Compoment(Base, 0, size_of_array - 1, size_of_element, cmp);
	}
private:
	void Qsort1_Compoment(void *Base, int left, int right, int size_of_element, int(*cmp)(const void *, const void *))
	{
		if (left < right)
		{
			void *flag = (char *)Base + size_of_element * right;
			int i = left - 1;
			for (int j = left; j < right; j++)
			{
				if (cmp((char *)Base + size_of_element * j, (char *)Base + size_of_element * right))
				{
					i++;
					Qsort_Exchange(Base, size_of_element, i, j);
				}
			}
			Qsort_Exchange(Base, size_of_element, ++i, right);
			Qsort1_Compoment(Base, left, i - 1, size_of_element, cmp);
			Qsort1_Compoment(Base, i + 1, right, size_of_element, cmp);
		}
	}

public:
	//真快排2,选排优化
	void Qsort2(void *Base, int size_of_array, int size_of_element, int(*cmp)(const void *, const void *))
	{
		Qsort2_Compoment(Base, 0, size_of_array - 1, size_of_element, cmp);
	}
private:
	void Qsort2_Compoment(void *Base, int left, int right, int size_of_element, int(*cmp)(const void *, const void *))
	{
		if (left >= right) return;
		if (right - left <= CUTOFF)
		{
			Qsort_Shortsort(Base, size_of_element, left, right, cmp);
		}
		else
		{
			void *flag = (char *)Base + size_of_element * right;
			int i = left - 1;
			for (int j = left; j < right; j++)
			{
				if (cmp((char *)Base + size_of_element * j, (char *)Base + size_of_element * right))
				{
					i++;
					Qsort_Exchange(Base, size_of_element, i, j);
				}
			}
			Qsort_Exchange(Base, size_of_element, ++i, right);
			Qsort1_Compoment(Base, left, i - 1, size_of_element, cmp);
			Qsort1_Compoment(Base, i + 1, right, size_of_element, cmp);
		}
	}

public:
	void Qsort3(void *Base, int size_of_array, int size_of_element, int(*cmp)(const void *, const void *))
	{
		//Qsort3_compoment(Base, 0, size_of_array - 1, size_of_element, cmp);
	}

private:
	//组件
	void Qsort_Exchange(void *Base, int size_of_element, int i, int j)
	{
		char *a = (char *)Base + size_of_element * i;
		char *b = (char *)Base + size_of_element * j;
		if (a != b)
		{
			char tmp;
			while (size_of_element--)
			{
				tmp = *a;
				*a++ = *b;
				*b++ = tmp;
			}
		}
	}

	void Qsort_Shortsort(void *Base, int size_of_element, int left, int right, int(*cmp)(const void *, const void *))
	{
		for (int i = left; i <= right; i++)
		{
			int minposition = i;
			for (int j = i; j <= right; j++)
			{
				if (cmp((char *)Base + size_of_element * j, (char *)Base + size_of_element * minposition)) minposition = j;
			}
			Qsort_Exchange(Base, size_of_element, i, minposition);
		}
	}

	//选择中位数
	int Qsort_ChooseMiddle(void *Base, int size_of_element, int left, int right, int(*cmp)(const void *, const void *))
	{
		int mid = (left + right) / 2;
		if (cmp((char *)Base + size_of_element * left, (char *)Base + size_of_element * mid))
		{
			if (cmp((char *)Base + size_of_element * left, (char *)Base + size_of_element * right))
			{
				if (cmp((char *)Base + size_of_element * mid, (char *)Base + size_of_element * right)) return mid;
				else return right;
			}
			else return left;
		}
		else
		{
			if (cmp((char *)Base + size_of_element * mid, (char *)Base + size_of_element * right))
			{
				if (cmp((char *)Base + size_of_element * left, (char *)Base + size_of_element * right)) return left;
				else return right;
			}
			else return right;
		}
	}

	//int型快排
public:
	//最老版本的写法，头做flag
	void q1(int *Base, int left, int right)
	{
		if (left < right)
		{
			int tmp_left = left, tmp_right = right, tmp_zero = Base[left];
			while (tmp_left < tmp_right)
			{
				while (tmp_left < tmp_right&&Base[tmp_right] > tmp_zero) tmp_right--;
				if (tmp_left < tmp_right) Base[tmp_left++] = Base[tmp_right];
				while (tmp_left < tmp_right&&Base[tmp_left] <= tmp_zero) tmp_left++;
				if (tmp_left < tmp_right) Base[tmp_right--] = Base[tmp_left];
			}
			Base[tmp_left] = tmp_zero;
			q1(Base, left, tmp_left - 1);
			q1(Base, tmp_right + 1, right);
		}
	}
	//下为算法导论

	//取尾作为flag，没有选排优化
	void q2(int *Base, int left, int right)
	{
		if (left < right)
		{
			int flag = Base[right];
			int i = left - 1;
			for (int j = left; j < right; j++)
			{
				if (Base[j] <= flag)
				{
					i++;
					Exchange(Base, i, j);
				}
			}
			Exchange(Base, ++i, right);
			q2(Base, left, i - 1);
			q2(Base, i + 1, right);
		}
	}

	//取中间值为flag,有选排优化
	void q3(int *Base, int left, int right)
	{
		if (left >= right) return;
		if (right - left <= CUTOFF)
		{
			Shortsort(Base, left, right);
		}
		else
		{
			Exchange(Base, ChooseMiddle(Base, left, right), right);
			int flag = Base[right];
			int i = left - 1;
			for (int j = left; j < right; j++)
			{
				if (Base[j] <= flag)
				{
					i++;
					Exchange(Base, i, j);
				}
			}
			Exchange(Base, ++i, right);
			q3(Base, left, i - 1);
			q3(Base, i + 1, right);
		}
	}

	//随机flag，有选排优化
	void q4(int *Base, int left, int right)
	{
		if (left >= right) return;
		if (right - left <= CUTOFF)
		{
			Shortsort(Base, left, right);
		}
		else
		{
			Exchange(Base, Random(left, right + 1), right);
			int flag = Base[right];
			int i = left - 1;
			for (int j = left; j < right; j++)
			{
				if (Base[j] <= flag)
				{
					i++;
					Exchange(Base, i, j);
				}
			}
			Exchange(Base, ++i, right);
			q4(Base, left, i - 1);
			q4(Base, i + 1, right);
		}
	}

private:
	//插入排序,用于小规模时加速
	void Shortsort(int *Base, int left, int right)
	{
		for (int i = left; i <= right; i++)
		{
			int minposition = i;
			for (int j = i; j <= right; j++)
			{
				if (Base[j] < Base[minposition]) minposition = j;
			}
			Exchange(Base, i, minposition);
		}
	}

	//交换i和j位置的元素
	void Exchange(int *Base, int i, int j)
	{
		int tmp = Base[i];
		Base[i] = Base[j];
		Base[j] = tmp;
	}

	//选择Base[left],Base[mid],Base[right]的中位数
	int ChooseMiddle(int *Base, int left, int right)
	{
		int mid = (left + right) / 2;
		if (Base[left] <= Base[mid])
		{
			if (Base[left] <= Base[right])
			{
				if (Base[mid] <= Base[right]) return mid;
				else return right;
			}
			else return left;
		}
		else
		{
			if (Base[mid] <= Base[right])
			{
				if (Base[left] <= Base[right]) return left;
				else return right;
			}
			else return right;
		}
	}

	//生成left到right-1之间的随机数
	int Random(int left, int right)
	{
		unsigned int randSeed = time(0);
		randSeed = 1194211693u * randSeed + 12345u;
		return left + (randSeed) % (right - left);
	}
};

#endif // _MY_QSORT
