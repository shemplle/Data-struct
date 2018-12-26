#include <bits/stdc++.h>
#include <time.h>

using namespace std;

const int maxn = 1e5 + 50 ;

int s[maxn] ;

void Insertsort() {
	int i ,j ;
	for( i = 2 ; i <= 10000 ; ++ i ) // 直接插入排序 
		if( s[i] < s[i-1] )
		{   										
			s[0]=s[i];
    		s[i]=s[i-1];
        	for( j = i-2 ; s[0] < s[j] ; -- j )
				s[j+1] = s[j];
        	s[j+1] = s[0];
		}
} 

void BinInsertsort() {
	int i ,j ,low ,high ,mid ;
	for ( i = 2 ; i <= 10000 ; i ++ ) { // 折半插入排序 
		s[0] = s[i];
		low = 1 ,high = i - 1;
		while ( low <= high ) {
			mid = (low + high) >> 1;
			if ( s[0] < s[mid] ) high = mid - 1;
			else low = mid + 1; 
		}
		for ( j = i - 1 ; j >= high + 1 ; j -- ) s[j + 1] = s[j] ;
		s[high + 1] = s[0] ;
	} 
}

void ShellInsert(int dk ) {
	int i ,j ;
	for (i = dk + 1 ; i <= 10000 ; i ++ ) {
		if ( s[i] < s[i-dk] ) {
			s[0] = s[i] ;
			for (j = i - dk ; j > 0 && s[0] < s[j] ; j-= dk)
				s[j+dk] = s[j] ;
			s[j+dk] = s[0];
		}
	}
}

int main() {
	FILE *fp ,*fstream ;
	clock_t start ,finish ;
	fp = fopen("SourceFile.txt" ,"r" ) ;
	fstream = fopen("ResultFile.txt" ,"aw") ;
	for (int i = 1 ; i <= 10000 ; i ++ ) {
		fscanf(fp ,"%d" ,&s[i] ) ;
	}
	start = clock() ;
	//Insertsort() ;
	//BinInsertsort() ;
	ShellInsert(1) ;
	finish = clock() ;
	for (int i = 1 ; i <= 10000 ; i ++ ) {
		printf("%d ",s[i]);
	} puts("") ;
	double tot_time = double(finish -start) / CLOCKS_PER_SEC;
	fprintf(fstream ,"10000个元素shell排序的时间为：%.3f\n" ,tot_time ) ;
	fclose(fp) ;fclose(fstream) ;
	return 0;
} 
