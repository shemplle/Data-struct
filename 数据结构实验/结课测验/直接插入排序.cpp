#include <bits/stdc++.h>

using namespace std;

const int maxn = 1e5 + 50 ;

int s[maxn] ,n ;

int main() {
	int n ; cin >> n ;
	for (int i = 1 ; i <= n ; i ++ ) {
		scanf("%d" ,&s[i] ) ;
	}
	int i ,j ;
	for (i = 2 ; i <= n ; ++ i ) 
	if ( s[i] < s[i-1] )
	{   										
		s[0]=s[i];
    	s[i]=s[i-1];
       	for ( j = i-2 ; s[0] < s[j] ; -- j )
			s[j+1] = s[j];
       	s[j+1] = s[0];
	}
	for (i = 1 ; i <= n ; i ++ ) {
		printf("%d ",s[i]) ;
	} puts("") ;
	return 0;
} 
