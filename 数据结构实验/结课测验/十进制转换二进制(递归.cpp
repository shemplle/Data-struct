#include <stack>
#include <cstdio>

using namespace std;

stack<int>sta;

void dfs(int num) {
	if ( !num ) return ;
	dfs(num/2) ;
	printf("%d",num%2) ;
}

int main() {
	int n ; scanf("%d",&n) ;
	dfs(n) ;
	return 0;
}
