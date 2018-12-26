#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

typedef int ElemType;

typedef struct linknode
{
       ElemType data;
       struct linknode *next;
}ListStack;

ListStack *s; 

void init() {
	s = (ListStack*) malloc(sizeof(ListStack));
	s->next = NULL;
}

void Push(ListStack *s,ElemType e) {  
    ListStack *p; 
    p=(ListStack*) malloc(sizeof(ListStack));
    p->data=e;
    p->next=s->next;
    s->next=p;   
} 
	
void Pop(ListStack *s) {  
	ListStack *temp;
	int e;
	if(s->next==NULL) {
		printf("��ǰջΪ��\n");
		return ;
	} else {  
		temp=s->next;
		printf("��ǰջ��Ԫ��Ϊ :%d\n",temp->data);
		s->next=temp->next;
		free(temp);  
	}
}
	
bool empty(ListStack *s) {
	if ( s->next == NULL ) return true;
	else return false; 
}

void printStack(ListStack *s) { 
    ListStack *p=s->next; 
    while(p!=NULL){
       	printf("%d ",p->data);
       	p=p->next;
    }      
}

void menu() {
	printf(
		   "***********************************************************************************************\n"
		   "                                               1.����                                     \n"
		   "                                               2.ɾ��                                     \n"
		   "                                               3.�ж��Ƿ�Ϊ��                             \n"
		   "                                               4.���ջ�е�Ԫ��                           \n"
		   "                                               0.�˳�                                     \n"
		   "***********************************************************************************************\n"
	);
}



int main() {
	menu(); init();
	int choose ,x ;
	while ( cin >> choose ) {
		switch (choose) {
			case 1:
				printf("����������Ԫ��: ");
				scanf("%d",&x);
				Push(s ,x );
				break; 
			case 2:
				Pop(s);
				break;
			case 3:
				if ( empty(s) ) printf("��ǰջΪ��\n");
				else printf("��ǰջ��Ϊ��\n"); 
				break;
			case 4:
				printf("��ǰջ�����Ԫ��Ϊ :");
				printStack(s); puts("");
				break;
			case 0: 
				break;
			default:
				printf("����������\n");
		}
		if ( !choose ) break;
	}
	return 0;
}
