#include<stdio.h>//顺序栈
#include<stdlib.h>
#define Maxsize 100
typedef struct {
	int data[Maxsize];
	int top;
}SeqStack, * PSeqStack;


PSeqStack Init_SeqStack(void);//初始化空栈
int Empty_SeqStack(PSeqStack S);//判断栈空
int Push_SeqStack(PSeqStack S, int x);//入栈
int Pop_SeqStack(PSeqStack S, int* x);//出栈
int GetTop_SeqStack(PSeqStack S, int* x);//取出栈顶元素
void View_Seqstack(PSeqStack S);//遍历栈元素
void Destroy_SeqStack(PSeqStack* S);//销毁顺序栈

int main()
{

	PSeqStack S;
	int x1, x2;
	S = Init_SeqStack();
	if (S == NULL)
	{
		printf("初始化失败\n");
		return 1;
	}
	Push_SeqStack(S, 1);
	Push_SeqStack(S, 3);
	Push_SeqStack(S, 7);
	Push_SeqStack(S, 2);
	Push_SeqStack(S, 4);
	Push_SeqStack(S, 6);
	Pop_SeqStack(S, &x1);
	printf("出栈元素为：%d\n", x1);
	GetTop_SeqStack(S, &x2);
	printf("此时栈顶元素为：%d\n", x2);
	View_Seqstack(S);
	Destroy_SeqStack(&S);
	return 0;
}
PSeqStack Init_SeqStack(void)//初始化空栈
{
	PSeqStack S;
	S = (PSeqStack)malloc(sizeof(SeqStack));
	if (S)
		S->top = -1;
	return S;
}
int Empty_SeqStack(PSeqStack S)//判断栈空
{
	if (S->top == -1)
		return 1;//栈空
	else
		return 0;//非空
}
int Push_SeqStack(PSeqStack S, int x)//入栈
{
	if (S->top == Maxsize - 1)
		return 0;//栈满不能够入栈
	else
	{
		S->top++;
		S->data[S->top] = x;
		return 1;//入栈成功
	}
}
int Pop_SeqStack(PSeqStack S, int* x)//出栈
{
	if (Empty_SeqStack(S))
		return 0;//栈空，不能进行出栈
	else
	{
		*x = S->data[S->top];
		S->top--;
		return 1;//出栈成功
	}
}
int GetTop_SeqStack(PSeqStack S, int* x)//取出栈顶元素
{
	if (Empty_SeqStack(S))
		return 0;//栈为空
	else
	{
		*x = S->data[S->top];
		return 1;//成功取出
	}
}
void View_Seqstack(PSeqStack S)//遍历栈元素
{
	int i;
	if (Empty_SeqStack(S))
		return;//空栈无法遍历
	printf("栈内元素遍历如下：\n");
	for (i = S->top; i >= 0; i--)
	{
		printf("%d ", S->data[i]);
	}
	printf("\n栈内元素遍历完成\n");
}
void Destroy_SeqStack(PSeqStack* S)//销毁顺序栈
{
	if (*S)
		free(*S);
	*S = NULL;
	return;
}



#include<stdio.h>//链栈
#include<stdlib.h>
typedef struct node
{
	int data;
	struct node* next;
}StackNode, * PStackNode;
typedef struct
{
	PStackNode top;
}LinkStack, * PLinkStack;
PLinkStack Init_LinkStack(void);//初始化空栈
int Empty_LinkStack(PLinkStack S);//判断栈空
int Push_LinkStack(PLinkStack S, int x);//入栈
int Pop_LinkStack(PLinkStack S, int* x);//出栈
int GetTop_LinkStack(PLinkStack S, int* x);//取栈顶元素
void View_LinkStack(PLinkStack S);//遍历栈
void Destroy_LinkStack(PLinkStack* LS);//销毁栈
int main()
{
	PLinkStack S;
	int x1, x2;
	S = Init_LinkStack();
	Push_LinkStack(S, 2);
	Push_LinkStack(S, 4);
	Push_LinkStack(S, 6);
	Push_LinkStack(S, 1);
	Push_LinkStack(S, 9);
	Push_LinkStack(S, 7);
	printf("入栈操作完成\n");
	printf("进行一次出栈\n");
	Pop_LinkStack(S, &x1);
	printf("出栈元素为：%d\n", x1);
	printf("进行取栈顶元素操作\n");
	GetTop_LinkStack(S, &x2);
	printf("栈顶元素为:%d\n", x2);
	View_LinkStack(S);
	Destroy_LinkStack(&S);
	return 0;
}
PLinkStack Init_LinkStack(void)//初始化空栈
{
	PLinkStack S;
	S = (PLinkStack)malloc(sizeof(LinkStack));
	if (S)
		S->top = NULL;
	printf("初始化操作完成\n");
	return S;
}
int Empty_LinkStack(PLinkStack S)//判断栈空
{
	return (S->top == NULL);
}
int Push_LinkStack(PLinkStack S, int x)//入栈
{
	PStackNode p;
	p = (PStackNode)malloc(sizeof(StackNode));
	if (!p)
	{
		printf("内存溢出\n");
		return 0;
	}
	p->data = x;
	p->next = S->top;
	S->top = p;
	return 1;//入栈完成
}
int Pop_LinkStack(PLinkStack S, int* x)//出栈
{
	PStackNode p;
	if (Empty_LinkStack(S))
	{
		printf("栈空，不能出栈\n");
		return 0;
	}
	*x = S->top->data;
	p = S->top;
	S->top = S->top->next;
	free(p);
	return 1;//出栈成功
}
int GetTop_LinkStack(PLinkStack S, int* x)//取栈顶元素
{
	if (Empty_LinkStack(S))
	{
		printf("栈空\n");
		return 0;
	}
	*x = S->top->data;
	return 1;//取出栈顶元素成功
}
void View_LinkStack(PLinkStack S)//遍历栈
{
	if (Empty_LinkStack(S))
	{
		printf("栈为空，无法进行遍历\n");
		return;
	}
	PStackNode p;
	p = S->top;
	printf("栈内元素遍历如下：\n");
	while (p)
	{
		printf("%d ", p->data);
		p = p->next;
	}
	printf("\n栈内元素遍历完成\n");
}
void Destroy_LinkStack(PLinkStack* LS)//销毁栈
{
	PStackNode p, q;
	if (*LS)
	{
		p = (*LS)->top;
		while (p)
		{
			q = p;
			p = p->next;
			free(q);
		}
		free(*LS);
	}
	*LS = NULL;
	return;
}