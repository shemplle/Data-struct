#include <bits/stdc++.h>

using namespace std;

const int maxn = 1e5 + 50 ;

vector<int>G[maxn];
stack<int>sta ;
int n ,m ,st ,u ,v ; 

void DFS(int st) {
	sta.push(st) ;
	while ( !sta.empty() ) {
		int top = sta.top(); sta.pop();
		int len = G[top].size();
		for (int i = 0 ; i < len ; i ++ ) {
			sta.push(G[top][i]);
		}
		printf("%d ",top);
	}
}

int main() {
	printf("�������������ͱߵ�����: ");
	scanf("%d %d",&n ,&m ) ;
	for (int i = 1 ; i <= m ; i ++ ) {
		printf("�������%d���ߵ�����յ�: ",i ); 
		scanf("%d %d",&u ,&v ) ;
		G[u].push_back(v);
	}
	printf("���������λ��: ");
	scanf("%d",&st);
	printf("DFS�ݹ�������Ϊ: ");
	DFS(st);
	return 0;
}

