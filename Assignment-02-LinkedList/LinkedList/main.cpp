#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
	int data;
	struct node* next;
}LNode, * LinkList;
LinkList Creat_LinkList(void);//创建空单链表
void Destroy_LinkList(LinkList* H);//销毁单链
int Length_LinkList(LinkList H);//求表长
int is_null(LinkList H);//判断表空
int Insert_LinkList_head(LinkList H, int x);//头插法插入节点，追加元素
int Insert_LinkList_tail(LinkList H, LinkList* tail, int x);//尾插法插入节点，追加元素
void traversal_LinkList(LinkList H);//遍历操作
LinkList Locate_LinkList_Pos(LinkList H, int i);//按序号查找节点
int Insert_LinkList(LinkList H, int i, int x);//在指定节点处实现插入操作
int Del_LinkList(LinkList H, int i);//删除指定节点
void Sort_LinkList(LinkList H);//利用冒泡排序法给链表进行升序排序
LinkList Get_tail(LinkList H);//找到尾节点位置
int main()
{
	LinkList H, tail;
	H = Creat_LinkList();
	tail = H;
	Insert_LinkList_head(H, 5);
	Insert_LinkList_head(H, 9);
	Insert_LinkList_head(H, 25);
	Insert_LinkList_head(H, 2);
	printf("新增加数据:5 9 25 2\n");
	printf("头插法追加数据结果如下：\n");
	traversal_LinkList(H);
	tail = Get_tail(H);
	Insert_LinkList_tail(H, &tail, 11);
	Insert_LinkList_tail(H, &tail, 14);
	Insert_LinkList_tail(H, &tail, 16);
	Insert_LinkList_tail(H, &tail, 8);
	printf("\n");
	printf("新增加数据:11 14 16 8\n");
	printf("尾插法插法追加数据结果如下：\n");
	traversal_LinkList(H);
	printf("\n");
	printf("表的长度为：\n");
	int length = Length_LinkList(H);
	printf("%d", length);
	Insert_LinkList(H, 2, 3);
	printf("\n");
	printf("在第二个节点处插入数据3结果如下：\n");
	traversal_LinkList(H);
	printf("\n");
	printf("删除第三个节点后的数据如下：\n");
	Del_LinkList(H, 3);
	traversal_LinkList(H);
	printf("\n");
	printf("所有数据进行排序后的结果如下：\n");
	Sort_LinkList(H);
	traversal_LinkList(H);
	Destroy_LinkList(&H);
	return 0;
}
LinkList Creat_LinkList(void)//创建空单链表
{
	LinkList H;
	H = (LinkList)malloc(sizeof(LNode));
	if (H)
		H->next = NULL;
	else
	{
		printf("链表创建失败\n");
		return NULL;
	}
	return H;
}
void Destroy_LinkList(LinkList* H)//销毁单链表
{
	LinkList p, q;
	p = *H;
	while (p)
	{
		q = p;
		p = p->next;
		free(q);
	}
	*H = NULL;
}
int Length_LinkList(LinkList H)//求表长
{
	LinkList p = H;
	int count = -1;
	while (p)
	{
		p = p->next;
		count++;
	}
	return count;
}
int is_null(LinkList H)//判断表空
{
	LinkList p;
	p = H;
	if (p == NULL || p->next == NULL)
		return 1;//表空
	else
		return 0;//表非空
}
int Insert_LinkList_head(LinkList H, int x)//头插法插入节点，追加元素
{
	LinkList p;
	p = (LinkList)malloc(sizeof(LNode));
	if (p == NULL)
	{
		printf("内存分配失败\n");
		return 0;//插入节点失败
	}
	p->data = x;
	p->next = H->next;
	H->next = p;
	return 1;//节点插入成功
}
int Insert_LinkList_tail(LinkList H, LinkList* tail, int x)//尾插法插入节点，追加元素
{
	LinkList p;
	p = (LinkList)malloc(sizeof(LNode));
	if (p == NULL)
	{
		printf("内存分配失败\n");
		return 0;//插入节点失败
	}
	p->data = x;
	p->next = NULL;
	(*tail)->next = p;
	(*tail) = p;
	return 1;//插入完成
}
void traversal_LinkList(LinkList H)//遍历操作
{
	LinkList p;
	if (is_null(H))
	{
		printf("表为空，无法进行遍历操作，请追加元素后再进行此操作\n");
		return;
	}
	p = H->next;
	while (p != NULL)
	{
		printf(" %d  ", p->data);
		p = p->next;
	}
}
LinkList Locate_LinkList_Pos(LinkList H, int i)//按序号查找节点
{
	LinkList p;
	p = H;
	int j = 0;
	while (p && j < i)
	{
		p = p->next;
		j++;
	}
	if (j != i || !p)
	{
		printf("参数i不合理或单链表不存在\n");
		return NULL;
	}
	return p;
}
int Insert_LinkList(LinkList H, int i, int x)//在指定节点处实现插入操作
{
	LinkList p, q;
	p = Locate_LinkList_Pos(H, i - 1);
	if (!p)
	{
		printf("i有误\n");
		return 0;
	}
	q = (LinkList)malloc(sizeof(LNode));
	if (!q)
	{
		printf("内存申请失败\n");
		return 0;
	}
	q->data = x;
	q->next = p->next;
	p->next = q;
	return 1;//插入成功
}
int Del_LinkList(LinkList H, int i)//删除指定节点
{
	LinkList p, q;
	if (is_null(H))
	{
		printf("表为空，无法进行删除操作\n");
		return 0;//删除失败
	}
	p = Locate_LinkList_Pos(H, i - 1);
	if (p == NULL || p->next == NULL)
	{
		printf("参数错误\n");
		return 0;
	}
	q = p->next;
	p->next = q->next;
	free(q);
	return 1;//删除成功
}
void Sort_LinkList(LinkList H)//利用冒泡排序法给链表进行升序排序
{
	LinkList p, q;
	int count = Length_LinkList(H);
	for (int i = 0; i < count - 1; i++)
	{
		p = H->next;
		for (int j = 0; j < count - i - 1; j++)
		{
			q = p->next;
			if (q != NULL && q->data < p->data)
			{
				int tmp = q->data;
				q->data = p->data;
				p->data = tmp;
			}
			p = p->next;
		}
	}
}
LinkList Get_tail(LinkList H)//找到尾节点位置
{
	LinkList p;
	p = H;
	while (p->next != NULL)
	{
		p = p->next;
	}
	return p;
}