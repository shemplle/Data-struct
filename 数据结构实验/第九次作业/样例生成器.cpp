#include <bits/stdc++.h>
#include <time.h>

using namespace std;

int Random(int start, int end){
    int dis = end - start;
    return rand() % dis + start;
}

int main() {
	FILE *fp ;
	fp = fopen("SourceFile.txt" ,"a" );
	int lenght = 10000;
	for (int j = 1 ; j <= lenght ; j ++ ) {
		fprintf(fp , "%d " , Random(0 ,10000 )) ;
	} fprintf(fp , "\n") ;
	fclose(fp) ;
	return 0;
}
