#include <stdio.h>
#include <stdlib.h>
 
typedef int ElemType;
 
typedef struct Node {
    ElemType data;               
    struct Node *next;          
}Node,*LinkedList;

LinkedList LinkedListInit() {
    Node *L;
    L = (Node *)malloc(sizeof(Node)); 
    if(L == NULL) { 
        printf("�����ڴ�ռ�ʧ��\n");
    }
    L->next = NULL;                  
 	return L;
}

LinkedList LinkedListCreatH() {
    Node *L;
    L = (Node *)malloc(sizeof(Node));   
    L->next = NULL;                     
     
    ElemType x;                         
    while(scanf("%d",&x) != EOF) {
        Node *p;
        p = (Node *)malloc(sizeof(Node));    
        p->data = x;                      
        p->next = L->next;                    
        L->next = p; 
    }
    return L; 
} 

LinkedList LinkedListInsert(LinkedList L,int i,ElemType x) {
    Node *pre;                     
    pre = L;
    int tempi = 0;
    for (tempi = 1; tempi < i; tempi++) {
    	pre = pre->next;                  
	}
    Node *p;                                
    p = (Node *)malloc(sizeof(Node));
    p->data = x; 
    p->next = pre->next;
    pre->next = p;
     
    return L;                           
} 

LinkedList LinkedListDelete(LinkedList L,ElemType x)
{
    Node *p,*pre;                    
    p = L->next;
    pre = L; 
	/**************************
		����� per = L; ������
		ԭ�� : �տ�ʼ per û�и�ֵ���ɾ����һ��Ԫ�� 
			   ���������ΪperΪ��ָ��������ָ��ʧ������ 
	***************************/
	while(p->data != x) {               
        pre = p; 
        p = p->next;
    }
    pre->next = p->next;          
    free(p);
    return L;
} 

int findder(LinkedList L,int x) { //���ҹ��� 
	/*
	* @ x ��Ҫ���ҵ�ֵ 
	* @ L ��Ҫ����������
	* ���� -1 ʱ��ʾ������û�����ڵ�ֵ 
	*/ 
	LinkedList start; int i = 1;
	L = L->next;
	for (start = L;start != NULL;start = start->next) {
		if ( start->data == x ) {
			return i;
		}
		i++;
	} 
	return -1;
}

LinkedList Delete(LinkedList L,int st,int en) { // ��������ɾ������ 
	/*
	* @ st ɾ������ʼλ�� 
	* @ en ɾ������ֹΪֹ 
	* @ L ��Ҫ�����ĵ����� 
	*/
	bool flag1 = false;
	Node *per,*p;
	per = L;
	L = L->next; int i = 1;
	LinkedList start;
	for (start = L;start != NULL ; start = start->next ) {
		if ( st == i ) {
			flag1 = true;
		}
		if ( en == i ) {
			per->next = start->next;
			break;
		}
		i++;
		if ( !flag1 )
			per = start;
	}
	return L;
}

int main() {
    LinkedList list,start;
 	printf("�����뵥��������ݣ�"); 
   	list = LinkedListCreatH();
	for(start = list->next; start != NULL; start = start->next) {
		printf("%d ",start->data);
	}
	printf("\n");
    int i;
    ElemType x;
    printf("������������ݵ�λ�ã�");
    scanf("%d",&i);
    printf("������������ݵ�ֵ��");
    scanf("%d",&x);
    LinkedListInsert(list,i,x);
    for(start = list->next; start != NULL; start = start->next) {
    	printf("%d ",start->data);
	}
    printf("\n");
    printf("������Ҫɾ����Ԫ�ص�ֵ��");
    scanf("%d",&x);
    LinkedListDelete(list,x); 
    for(start = list->next; start != NULL; start = start->next) {
    	printf("%d ",start->data);
	}
    printf("\n"); 
    return 0;
}
