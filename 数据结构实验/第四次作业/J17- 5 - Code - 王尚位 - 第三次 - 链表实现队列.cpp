#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

#define OK 1
#define ERROR 0

typedef int QElemType;
typedef struct QNode {
	QElemType data;
	struct QNode *next;
}QNode ,*QueuePtr;
typedef int Status ;

typedef struct {
	QueuePtr front;
	QueuePtr rear;
}LinkQueue;

Status InitQueue(LinkQueue &Q) {
	Q.front = Q.rear = new QNode;
	Q.front->next = NULL;
	return OK;
}

Status EnQueue (LinkQueue & Q ,QElemType e) {
	QueuePtr p;
	p = new QNode;
	p->data = e;
	p->next = NULL; Q.rear->next = p;
	Q.rear = p;
	return OK;
}

Status DeQueue(LinkQueue &Q ,QElemType e) {
	QueuePtr p;
	if ( Q.front == Q.rear ) return ERROR;
	p = Q.front->next;
	e = p->data;
	Q.front->next = p->next;
	if ( Q.rear == p ) Q.rear = Q.front;
	delete p;
	return OK;
}

QElemType GetHead(LinkQueue Q) {
	if ( Q.front != Q.rear ) {
		return Q.front->next->data;
	}
}

void menu() {
	printf(
		"1.��ʼ��\n"
		"2.����\n"
		"3.ɾ��\n"
		"4.ȡ���ж�\n"
		"0.�˳�\n"
	);
}

int main() {
	menu(); 
	LinkQueue Q1;
	int choose ,e ;
	while ( true ) {
		printf("���������ѡ�� :");
		cin >> choose ; cout << endl; 
		switch ( choose ) {
			case 1:
				InitQueue(Q1);
				break;
			case 2:
				printf("���������Ҫ�����Ԫ�� :");
				cin >> e; cout << endl; 
				EnQueue(Q1 ,e );
				printf("����ɹ�\n");
				break;
			case 3:
				if(DeQueue(Q1 ,e )) {
					printf("ɾ���ɹ�\n");
				} else {
					printf("error:�����Կ�\n");
				}
				break;
			case 4:
				printf("���ж���Ԫ��Ϊ: %d\n",GetHead(Q1));
				break;
			case 0:
				break;
		}
		if ( choose == 0 ) break;
	} 
	return 0;
}
