#include <stdio.h>
#include <algorithm>

using namespace std;

#define maxn 100050

int par[maxn] ,n ,m ;

struct edge {
	int u ,v ,w ; // u��� v �յ� w ��Ȩ 
} ss[maxn * 10] ;

void init() { // ���鼯�ĳ�ʼ������ʼ��ʱ��������ָ���Լ� 
	for (int i = 0 ; i < maxn ; i ++ ) {
		par[i] = i;
	}
}

//���鼯 �������������������Ļ����Բο�һ��֮ǰ������Ƶ 
int find(int x) {
	if ( par[x] == x ) return x;
	return par[x] = find(par[x]) ; //·��ѹ�� 
}

void unite(int x,int y) { // �ϲ����������� 
	x = find(x) ,y = find(y) ;
	if ( x != y ) par[x] = y; 
} 

//�ȽϺ��������ṹ�尴��w��һ�������Ӵ�С���� 
// �μ� :  https://blog.csdn.net/latte_z/article/details/17049479
int cmp(edge x,edge y) {
	return x.w < y.w ;
} 

int kruskal() {
	int nedge = 0 ,sum = 0 ; 
	//sumͳ����С��������Ȩֵ��
	//nedgeͳ�Ƽ���ıߵ�������n������Ҫ����n-1���ߣ��������n-1����˵��û���γ���С������ 
	for (int i = 1 ; i <= m ; i ++ ) {
		if ( find(ss[i].u) != find(ss[i].v) ) { //��������յ�û����һ�����ϣ���ô���������� 
			sum += ss[i].w ; // ���������ߵı�Ȩ 
			unite(ss[i].u ,ss[i].v ) ; //Ȼ�����������Ϻϲ� 
			nedge ++ ; //�����Ӽ� 
		}
	}
	if ( nedge == n - 1 ) return sum ;
	else return -1 ;
}

int main() {
	init() ;   
	scanf("%d %d",&n ,&m ) ; // n������� m�ߵ����� 
	for (int i = 1 ; i <= m ; i ++ ) {
		scanf("%d %d %d",&ss[i].u ,&ss[i].v ,&ss[i].w ) ; // �����ʽ:   ���  �յ�  ��Ȩ  
	} 
	// sort���� 
	sort(ss + 1 ,ss + m + 1 ,cmp ) ;
	int ans = kruskal() ;
	if ( ans == -1 ) {
		printf("��С������������\n") ;
	} else {
		printf("��С��������: %d\n",ans) ;
	}
	return 0;
}

/*
����������� : 
 
5 4
1 2 5
2 4 6
1 4 7
3 5 5

5 10
1 2 11
1 3 30
1 4 9
1 5 10
2 3 7
2 4 11
2 5 20
3 4 16
3 5 21
4 5 18
*/
