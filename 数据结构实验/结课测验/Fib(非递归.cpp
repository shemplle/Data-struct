#include <stdio.h>

const int maxn = 1002 ;
// maxn 可以根据自己的需求设 

int fib[maxn] ;

int main() {
	fib[1] = fib[2] = 1 ;
	for (int i = 3 ; i < maxn ; i ++ ) {
		fib[i] = fib[i-1] + fib[i-2] ;
	}
	return 0;
}
