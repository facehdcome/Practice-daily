#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

#define ROW 3
#define COL 3

//��ʼ������
void InitBoard(char board[ROW][COL], int row, int col);
//��ӡ����
void PrintBoard(char board[ROW][COL], int row, int col);
//�������
int PlayerBoard(char board[ROW][COL], int row, int col);
//��������
void ComputerBoard(char board[ROW][COL], int row, int col);
//�ж���Ӯ
char IsWin(char board[ROW][COL], int row, int col);