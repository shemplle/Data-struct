#include <bits/stdc++.h>

using namespace std;

const int maxn = 1e5 + 50 ;

vector<int>G[maxn] ;
int n ,m ,u ,v ,st ;

void DFS(int st) {
	int len = G[st].size();
	for (int i = 0 ; i < len ; i ++ ) {
		printf("%d ",G[st][i]);
		DFS(G[st][i]);
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
	printf("DFS�ݹ�������Ϊ: ");
	printf("%d ",st);
	DFS(st);
	return 0;
} 
