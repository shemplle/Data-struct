#include <stdio.h>

const int maxn = 1002 ;

int fib[maxn] ;

int get_fib(int pos) {
	if ( fib[pos] ) return fib[pos] ;
	if ( pos == 1 || pos == 2 ) return 1;
	return fib[pos] = get_fib(pos - 1) + get_fib(pos - 2) ;
}

int main() {
	int n ;
	scanf("%d",&n) ;
	printf("%d\n",get_fib(n)) ;
	return 0 ;
}
