#include <stdio.h> 
#include <malloc.h> 
#include <iostream>

using namespace std;

typedef int SElemType; 
typedef int Status; 

#define INIT_SIZE 100 
#define STACKINCREMENT 10 
#define Ok 1 
#define Error 0 
#define True 1 
#define False 0 

typedef struct  { 
	SElemType *base; 
	SElemType *top; 
	int stacksize; 
}SqStack; 

//��ʼ��ջ 
Status InitStack(SqStack *s) 
{ 
	s->base = (SElemType *)malloc(INIT_SIZE * sizeof(SElemType)); 
	if(!s->base) { 
		puts("�洢�ռ����ʧ�ܣ�"); 
	    return Error; 
	} 
	s->top = s->base; 
	s->stacksize = INIT_SIZE; 
	return Ok; 
}
  
//���ջ 
Status ClearStack(SqStack *s){ 
	s->top = s->base; 
	return Ok; 
} 
  
//ջ�Ƿ�Ϊ�� 
Status StackEmpty(SqStack *s) { 
	if(s->top == s->base) return True; 
	else return False; 
}
  
//����ջ 
Status Destroy(SqStack *s) {
	free(s->base); 
	s->base = NULL; 
	s->top = NULL; 
	s->stacksize=0; 
	return Ok; 
} 
  
//���ջ��Ԫ�� 
Status GetTop(SqStack *s, SElemType &e) {
	if(s->top == s->base) return Error; 
	e = *(s->top - 1); 
	return Ok; 
} 
  
//ѹջ 
Status Push(SqStack *s, SElemType e) {
	if(s->top - s->base >= s->stacksize) { // ջ�� 
		s->base = (SElemType *)realloc(s->base, (s->stacksize + STACKINCREMENT) * sizeof(SElemType)); 
		if(!s->base) {
			puts("�洢�ռ����ʧ�ܣ�"); 
			return Error; 
		} 
		s->top = s->base + s->stacksize;//�޸�ջ��λ�� 
		s->stacksize += STACKINCREMENT;//�޸�ջ���� 
	} 
	*s->top++ = e; 
	return Ok; 
} 
  
//��ջ 
Status Pop(SqStack *s, SElemType *e) { 
	if(s->top == s->base) return Error; 
	--s->top; 
	*e = *(s->top); 
	return Ok; 
} 
  
//����ջ 
Status StackTraverse(SqStack *s,Status(*visit)(SElemType)) { 
	SElemType *b = s->base;//�˴�����ֱ����base��top�ƶ��������ܸı�ԭջ�Ľṹ 
	SElemType *t = s->top; 
	while(t > b) 
		visit(*b++); 
	printf("\n"); 
	return Ok; 
} 
  
Status visit(SElemType c) { 
	printf("%d ",c); 
	return Ok; 
} 

void menu() {
	cout<<" menu��"<<endl;
    cout<<"1.��ջ"<<endl;
    cout<<"2.��ջ"<<endl;
    cout<<"3.���"<<endl;
    cout<<"4.menu"<<endl;
    cout<<"0.����"<<endl;
}

int main()
{
    SqStack a ,*s = &a ;
    SElemType e;
    InitStack(s);  menu();
    int choose ,x ;
    while(true){
        cout<<"\n��ѡ��:";
        cin >> choose;
        int k = 0;
        switch(choose){
            case 1:
                printf("�������Ҫ��ջ�ĸ���:");
            	scanf("%d",&x);
                printf("������%d��Ԫ��:",x);
                while(x--){
                    scanf("%d",&e);
                    Push(s,e);
                }
                break;
            case 2:
                Pop(s,&e);
                printf("��ջ��Ԫ����:%d\n", e);
                break;
            case 3:
                StackTraverse(s, visit);
                printf("ջ��ȫ�����!\n");
                break;
            case 4:
                menu();
                break;
            case 0:
                k = 1;
                break;
            default:
                printf("���������룡");
                break;
        }
        if(k)   break;
    }
    Destroy(s);
    return 0;
}

