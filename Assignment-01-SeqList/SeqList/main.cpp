#include<stdio.h>
#include<stdlib.h>
typedef struct Arr
{
	int* pBase;//数组第一个元素地址
	int len;//数组长度
	int count;//当前数组元素个数
}Array;
void init_arr(Array* pArr, int len);//初始化
void append_arr(Array* pArr, int val);//追加元素
int insert_arr(Array* pArr, int val, int position);//插入元素
int is_empty(Array* pArr);//判断是否是空表
int is_full(Array* pArr);//判断是否是满表
void delete_arr(Array* pArr, int val);//删除表中元素
void show_arr(Array* pArr);//打印表
void reverse_arr(Array* pArr);//倒置表
void sort_arr(Array* pArr);//将表排序
int main()
{
	Array arr;
	init_arr(&arr, 7);
	append_arr(&arr, 1);
	append_arr(&arr, 6);
	append_arr(&arr, 5);
	append_arr(&arr, 9);
	show_arr(&arr);
	insert_arr(&arr, 99, 3);
	show_arr(&arr);
	delete_arr(&arr, 6);
	show_arr(&arr);
	reverse_arr(&arr);
	show_arr(&arr);
	sort_arr(&arr);
	show_arr(&arr);
	free(arr.pBase);
	arr.pBase = NULL;
	return 0;
}
void init_arr(Array* pArr, int length)
{
	pArr->pBase = (int*)malloc(sizeof(int) * length);
	if (pArr->pBase == NULL)
	{
		printf("动态内存分配失败！\n");
		exit(-1);
	}
	else
	{
		pArr->len = length;
		pArr->count = 0;
	}
	return;
}
void append_arr(Array* pArr, int val)
{
	if (is_full(pArr))
	{
		printf("表满，追加元素失败！\n");
	}
	else {
		pArr->pBase[pArr->count] = val;
		(pArr->count)++;
		printf("追加元素:%d 成功\n", val);
	}
}
int insert_arr(Array* pArr, int val, int position)
{
	if (is_full(pArr))
	{
		printf("表满，无法插入元素\n");
		return 0;
	}
	if (position > pArr->count || position < 0)
	{
		printf("插入位置不合理\n");
		return 0;
	}
	int pos = pArr->count;
	while (pos > position && pos > 0)
	{
		pArr->pBase[pos] = pArr->pBase[pos - 1];
		pos--;
	}
	pArr->pBase[position] = val;
	pArr->count++;
	printf("成功插入元素:%d\n", val);
	return 1;
}
int is_empty(Array* pArr)
{
	return pArr->count == 0;
}
int is_full(Array* pArr)
{
	return pArr->count == pArr->len;
}
void delete_arr(Array* pArr, int val)
{
	if (is_empty(pArr))
	{
		printf("表中元素为空，请初始化后再进行删除。\n");
		return;
	}
	int position = 0;
	while (position < pArr->count && pArr->pBase[position] != val)
	{
		position++;
	}
	if (position == pArr->count)
	{
		printf("未找到要删除元素，删除失败！\n");
		return;
	}
	while (position < pArr->count - 1)
	{
		pArr->pBase[position] = pArr->pBase[position + 1];
		position++;
	}
	pArr->count--;
	printf("成功删除元素:%d\n", val);
}
void show_arr(Array* pArr)
{
	if (is_empty(pArr))
	{
		printf("表为空，打印失败\n");
		return;
	}
	printf("打印结果如下：\n");
	for (int i = 0; i < pArr->count; i++)
	{
		printf("%d ", pArr->pBase[i]);
	}
	printf("\n");
}
void reverse_arr(Array* pArr)
{
	int time = pArr->count / 2;
	for (int i = 0; i < time; i++)
	{
		int mid = pArr->pBase[pArr->count - i - 1];
		pArr->pBase[pArr->count - i - 1] = pArr->pBase[i];
		pArr->pBase[i] = mid;
	}
	printf("完成翻转\n");
}
void sort_arr(Array* pArr)
{
	int n = pArr->count;
	for (int i = 0; i < n - 1; i++)
	{
		for (int j = 0; j < n - i - 1; j++)
		{
			if (pArr->pBase[j] > pArr->pBase[j + 1])
			{
				int mid = pArr->pBase[j + 1];
				pArr->pBase[j + 1] = pArr->pBase[j];
				pArr->pBase[j] = mid;
			}
		}
	}
	printf("排序完成\n");
}
