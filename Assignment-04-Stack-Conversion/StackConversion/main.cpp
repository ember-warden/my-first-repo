#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
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
void View_Seqstack(PSeqStack S);//遍历栈元素
void Destroy_SeqStack(PSeqStack* S);//销毁顺序栈
int main()
{
	PSeqStack S;
	S = Init_SeqStack();
	if (S == NULL)
	{
		printf("内存分配失败\n");
		return 1;
	}
	int a, b, x;
	printf("请输入一个十进制数：\n");
	if (scanf("%d", &a) != 1) {
		printf("输入的不是整数,请再次运行重新输入!\n");
		Destroy_SeqStack(&S);
		return 1;
	}
	printf("请输入想找转换的进制数(2-36)\n");
	if (scanf("%d", &b) != 1 || b < 2 || b>36) {
		printf("输入的转换制数不合理,请再次运行重新输入!\n");
		Destroy_SeqStack(&S);
		return 1;
	}
	printf("转换为%d进制数后为：\n", b);
	if (a < 0)
	{
		printf("-");
		a = -a;
	}
	while (a != 0)
	{
		x = a % b;
		if (x > 9)x = x - 10 + 'A';
		else x = x + '0';
		Push_SeqStack(S, x);
		a = a / b;
	}
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
void View_Seqstack(PSeqStack S)//遍历栈元素
{
	int i;
	if (Empty_SeqStack(S))
	{
		printf("0\n");
		return;
	}
	for (i = S->top; i >= 0; i--)
		printf("%c", S->data[i]);
	printf("\n");
}
void Destroy_SeqStack(PSeqStack* S)//销毁顺序栈
{
	if (*S)
		free(*S);
	*S = NULL;
	return;
}
