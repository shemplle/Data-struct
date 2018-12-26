#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

#define maxsize 110
#define OK 1
#define ERROR 0
#define OVERFLOW -2

typedef int Status;
typedef int QElemType;

typedef struct {
	QElemType *base;
	int front ;
	int rear;
}SqQueue;

Status InitQueue(SqQueue & Q) {
	Q.base = new QElemType[maxsize];
	if (!Q.base) exit(OVERFLOW);
	Q.front = Q.rear = 0;
	return OK;
}

int QueueLenght(SqQueue Q) {
	return (Q.rear - Q.front + maxsize) % maxsize ;
}

Status EnQueue (SqQueue &Q ,QElemType e) {
	if ( (Q.rear + 1 ) % maxsize == Q.front ) return ERROR;
	Q.base[Q.rear] = e;
	Q.rear = ( Q.rear + 1 ) % maxsize ;
	return OK; 
}

Status DeQueue(SqQueue &Q ,QElemType &e) {
	if ( Q.front == Q.rear ) return ERROR;
	e = Q.base[Q.front];
	Q.front = (Q.front + 1 ) % maxsize;
	return OK;
}

Status GetHead(SqQueue Q) {
	if ( Q.front != Q.rear ) {
		return Q.base[Q.front];
	}
}

void menu() {
	printf( "1.��ʼ��\n"
			"2.����Ԫ��\n"
			"3.ɾ��Ԫ��\n"
			"4.ȡ�����г���\n"
			"5.ȡ���Ӷ�Ԫ��\n"
			"0.�˳�\n"
	);
}

int main() {
	menu();
	int choose = -1 ,e ; 
	SqQueue Q1;
	while ( true ) {
		printf("���������ѡ�� : \n");
		cin >> choose;
		switch (choose){
			case 1:
				InitQueue(Q1);
				break;
			case 2:
				printf("������Ҫ�����Ԫ�� : \n");
				cin >> e;
				if ( EnQueue(Q1 ,e ) ) {
					printf("����ɹ�\n");
				} else {
					printf("����ʧ��,��������\n"); 
				} break; 
			case 3:
				if ( DeQueue(Q1 ,e ) ) {
					printf("ɾ���ɹ�\n");
				} else {
					printf("ɾ��ʧ��,�����Կ�\n");
				}
				break;
			case 4:
				printf("���г���Ϊ: %d\n",QueueLenght(Q1));
				break; 
			case 5:
				if ( QueueLenght(Q1) == 0 ) {
					printf("error:�����Կ�\n");
				} else {
					printf("�Ӷ�Ԫ��Ϊ : %d\n" ,GetHead(Q1));
				} 
				break;
			case 0: 
				break;
		}	
		if ( choose == 0 ) break;
	}
	return 0;
} 
