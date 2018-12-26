#include <queue>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

typedef struct node{
	int date;
	bool flag;
	struct node* nxt;
}node,*linklist;

void slove(int n,int m,int k) {
	
	linklist s ,tmp ;
	tmp = new node;
	tmp->date = 1; tmp->flag = false;
	tmp->nxt = tmp; s = tmp;
	for (int i = 2 ; i <= n ; i++ ) {
		tmp = new node;
		tmp->date = i; tmp->flag = false;
		tmp->nxt = s->nxt; s->nxt = tmp;
		s = tmp;
	} s = s->nxt;
	
	for (int i = 1;i<=n;i++) {
		if ( s->date == k ) break;
		s = s->nxt;
	}
	queue<int>que;
	int cnt = 0 ,count = 0;
	while( cnt < n ) {
		if ( !s->flag ) {
			count++;
			if ( count % m == 0 ) {
				cnt++; s->flag =true;
				que.push(s->date);
			}
		}
		s = s->nxt;
		
	}
	printf("The ans is :");
	while(!que.empty()) {
		printf("%d ",que.front()); que.pop();
	} puts("");
}

int main() {
	
	int n ,m ,k ,choose;
	while( 1 ) {
		printf("������ ����--����--��ʼ��λ��(�ո����) :\n");
		cin >> n >> m >> k; 
		slove(n ,m ,k );
		printf("������Ҫ������(1.����,0.ֹͣ):\n");
		cin >> choose;
		if(!choose) break;
	}
	return 0;
}
