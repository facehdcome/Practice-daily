#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include "seqStack.h"
/*
�ӵ�һ���ַ���ʼɨ��
��������ͨ�ַ�ʱ���ԣ�
������������ʱѹ��ջ��
������������ʱ��ջ�е���ջ�����ţ�������ƥ��
ƥ��ɹ�������������һ���ַ�
ƥ��ʧ�ܣ�����ֹͣ��������
������
�ɹ�: �����ַ�ɨ����ϣ���ջΪ��
ʧ�ܣ�ƥ��
ʧ�ܻ������ַ�ɨ����ϵ�ջ�ǿ�
*/
int isLeft(char ch)
{
	return ch == '(';
}

int isRight(char ch)
{
	return ch == ')';
}

void printError(char* str, char* errMag, char* pos)
{
	printf("������Ϣ��%s\n", errMag);
	printf("%s\n", str);

	int num = pos - str;

	for (int i = 0; i < num; i++)
	{
		printf(" ");
	}
	printf("��\n");
}

void test01()
{
	char* str = "5+5*6)+9/3*1)-(1+3(";
	//char * str = "5+5*(6)+9/3*1-(1+3(";

	char *p = str;

	//��ʼ��ջ
	SeqStack myStack = init_SeqStack();

	while (*p != '\0')
	{
		if (isLeft(*p))
		{
			push_SeqStack(myStack, p);
		}

		if (isRight(*p))
		{
			if (size_SeqStack(myStack) > 0)
			{
				pop_SeqStack(myStack);
			}
			else
			{
				printError(str, "������û��ƥ�䵽��Ӧ��������!", p);
				break;
			}
		}
		p++;
	}

	//�������� �ж��Ƿ��� ������û��ƥ�䵽��Ӧ��������
	while (size_SeqStack(myStack) > 0)
	{
		printError(str, "������û��ƥ�䵽��Ӧ�������ţ�", top_SeqStack(myStack));
		pop_SeqStack(myStack);
	}
	destroy_SeqStack(myStack);
	myStack = NULL;
}




int main() {

	test01();

	system("pause");
	return EXIT_SUCCESS;
}