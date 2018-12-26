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

void LinkedListCreatH(LinkedList &list) {
    Node *L,*s;
    list = new Node; list->next = NULL;
    L = list; ElemType x;
    while ( ~scanf("%d",&x) ) {
    	s = new Node;	
    	s->data = x; s->next = L->next; L->next = s;
    	L = s;
	}
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
    while(p->data != x) {               
        pre = p; 
        p = p->next;
    }
    pre->next = p->next;          
    free(p);
    return L;
} 

int main() {
    LinkedList list,start;
 	printf("�����뵥��������ݣ�"); 
   	LinkedListCreatH(list);
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
