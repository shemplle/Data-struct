#include <bits/stdc++.h>

using namespace std;

const int maxn = 1e5 + 50 ;

vector<int>G[maxn] ;
int n ,m ,u ,v ,st ;

queue<int>que ;

void BFS(int st) {
	int len = G[st].size();
	for (int i = 0 ; i < len ; i ++ ) {
		que.push(G[st][i]);
	}
	if ( !que.empty() ) {
		int top = que.front() ; que.pop() ;
		printf("%d ",top) ;
		BFS(top) ;
	}
}

int main() {
	printf("�������������ͱߵ�����: ");
	scanf("%d %d",&n ,&m ) ;
	for (int i = 1 ; i <= m ; i ++ ) {
		printf("�������%d���ߵ�����յ�: ",i); 
		scanf("%d %d",&u ,&v ) ;
		G[u].push_back(v);
	}
	printf("���������λ��: ");
	scanf("%d",&st);
	printf("BFS�ݹ�������Ϊ: ");
	printf("%d ",st);
	BFS(st);
	return 0;
} 
