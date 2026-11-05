//<循环队列>
#include<stdio.h>
#include<stdlib.h>
#define MAXSIZE 100
typedef struct
{
	int data[MAXSIZE];
	int front, rear;
}SeqQueue, * PseqQueue;
PseqQueue Init_SeqQueue();//初始化
int Empty_SeqQueue(PseqQueue Q);//判断队空
int In_SeqQueue(PseqQueue Q, int x);//入队
int Out_SeqQueue(PseqQueue Q, int* x);//出队
void View_SeqQueue(PseqQueue Q);//遍历队列
void Destroy_SeqQueue(PseqQueue* Q);//销毁队列
int main()
{
	PseqQueue Q;
	int x;
	Q = Init_SeqQueue();
	In_SeqQueue(Q, 2);
	In_SeqQueue(Q, 4);
	In_SeqQueue(Q, 5);
	In_SeqQueue(Q, 9);
	In_SeqQueue(Q, 12);
	printf("入队情况如下:\n");
	View_SeqQueue(Q);
	Out_SeqQueue(Q, &x);
	printf("\n首次出队元素 x=%d 后情况如下：\n", x);
	View_SeqQueue(Q);
	Destroy_SeqQueue(&Q);
	return 0;
}
PseqQueue Init_SeqQueue()
{
	PseqQueue Q;
	Q = (PseqQueue)malloc(sizeof(SeqQueue));
	if (Q)
	{
		Q->front = 0;
		Q->rear = 0;
	}
	return Q;
}
int Empty_SeqQueue(PseqQueue Q)
{
	if (Q && Q->front == Q->rear)
		return 1;
	else
		if (!Q)
			return -1;
		else
			return 0;
}
int In_SeqQueue(PseqQueue Q, int x)
{
	if ((Q->rear + 1) % MAXSIZE == Q->front)
	{
		printf("队满\n");
		return -1;
	}
	else
	{
		Q->rear = (Q->rear + 1) % MAXSIZE;
		Q->data[Q->rear] = x;
		return 1;
	}
}
int Out_SeqQueue(PseqQueue Q, int* x)
{
	if (Empty_SeqQueue(Q))
	{
		printf("队空\n");
		return -1;
	}
	else
	{
		Q->front = (Q->front + 1) % MAXSIZE;
		*x = Q->data[Q->front];
		return 1;
	}
}
void Destroy_SeqQueue(PseqQueue* Q)
{
	if (*Q)
		free(*Q);
	*Q = NULL;
}
void View_SeqQueue(PseqQueue Q)
{
	if (Empty_SeqQueue(Q))
	{
		printf("队空\n");
		return;
	}
	int list = Q->front;
	while (list != Q->rear)
	{
		list = (list + 1) % MAXSIZE;
		printf("%d ", Q->data[list]);
	}
}





//<链队列>
#include<stdio.h>
#include<stdlib.h>
typedef struct node {
	int data;
	struct node* next;
}Qnode, * PQnode;
typedef struct
{
	PQnode front, rear;
}LinkQueue, * PLinkQueue;
PLinkQueue Init_LinkQueue();//初始化
int Empty_LinkQueue(PLinkQueue Q);//判断队空
int In_LinkQueue(PLinkQueue Q, int x);//入队
int Out_LinkQueue(PLinkQueue Q, int* x);//出队
void View_LinkQueue(PLinkQueue Q);//遍历队列
void Destroy_LinkQueue(PLinkQueue* Q);//销毁队列
int main()
{
	PLinkQueue Q;
	int x;
	Q = Init_LinkQueue();
	In_LinkQueue(Q, 2);
	In_LinkQueue(Q, 4);
	In_LinkQueue(Q, 5);
	In_LinkQueue(Q, 7);
	In_LinkQueue(Q, 8);
	printf("入队结果为：\n");
	View_LinkQueue(Q);
	Out_LinkQueue(Q, &x);
	printf("出队元素 x=%d 后结果为：\n", x);
	View_LinkQueue(Q);
	Destroy_LinkQueue(&Q);
	return 0;
}
PLinkQueue Init_LinkQueue()
{
	PLinkQueue Q;
	Q = (PLinkQueue)malloc(sizeof(LinkQueue));
	if (Q)
	{
		Q->front = NULL;
		Q->rear = NULL;
	}
	return Q;
}
int Empty_LinkQueue(PLinkQueue Q)
{
	if (Q && Q->front == NULL && Q->rear == NULL)
		return 1;
	else
		return 0;
}
int In_LinkQueue(PLinkQueue Q, int x)
{
	PQnode p;
	p = (PQnode)malloc(sizeof(Qnode));
	if (!p)
	{
		printf("内存溢出\n");
		return 0;
	}
	p->data = x;
	p->next = NULL;
	if (Empty_LinkQueue(Q))
		Q->rear = Q->front = p;
	else
	{
		Q->rear->next = p;
		Q->rear = p;
	}
	return 1;
}
int Out_LinkQueue(PLinkQueue Q, int* x)
{
	PQnode p;
	if (Empty_LinkQueue(Q))
	{
		printf("队空\n");
		return 0;
	}
	*x = Q->front->data;
	p = Q->front;
	Q->front = Q->front->next;
	free(p);
	if (!Q->front)
		Q->rear = NULL;
	return 1;
}
void View_LinkQueue(PLinkQueue Q)
{
	if (Empty_LinkQueue(Q))
	{
		printf("队空\n");
		return;
	}
	PQnode p;
	p = Q->front;
	while (p)
	{
		printf("%d ", p->data);
		p = p->next;
	}
	printf("\n");
}
void Destroy_LinkQueue(PLinkQueue* Q)
{
	PQnode p;
	if (*Q)
	{
		while ((*Q)->front)
		{
			p = (*Q)->front;
			(*Q)->front = (*Q)->front->next;
			free(p);
		}
		free(*Q);
	}
	*Q = NULL;
}