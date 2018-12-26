#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

const int maxn = 1e5+50;

struct book {
	string id;
	string name;
	double price;
	book () {}
	book (string _id,string _name,double _price) { id = _id; name = _name; price = _price;}
};

typedef struct {
	book* elem;
	int length;
} sqtable;

int init(sqtable &s) { //
	s.elem = new book[maxn];
	if ( !s.elem ) exit(-2);
	s.length = 0;
	return 1;
}

int delect(sqtable &s,int pos) {
	if ( s.length <= 0 || s.length < pos ) return 0;
	for (int i = pos ; i <= s.length - 1 ; i ++ ) {
		s.elem[i] = s.elem[i+1];
	} 
	s.length --;
	return 1;
}

int insert(sqtable &s,int pos,book val) {
	if ( s.length + 1 == pos ) {
		s.length ++; s.elem[s.length] = val; return 1;
	}
	if ( s.length >= maxn - 1 || pos > s.length ) return 0;
	for (int i = s.length ; i >= pos ; i -- ) {
		s.elem[i+1] = s.elem[i];
	}
	s.elem[pos] = val;
	++ s.length;
	return 1; 
}

void Print(sqtable &s) {
	if ( s.length == 0 ) printf("-----˳���Ϊ��-----\n");
	else {
		for (int i = 1 ; i <= s.length ; i ++ ) {
			cout << "id = "<<s.elem[i].id << " -- "<< "name = "<< s.elem[i].name << " -- "<< "price = "<< s.elem[i].price<< endl;
		}
	} 
}

int Scanner(int length,sqtable &s) {
	if ( s.length + length > maxn - 1) return 0;
	printf("*************************** ���������� id -- name -- price (ÿ��һ����Ϣ) *******************************\n");
	for (int i = s.length + 1 ; i <= s.length + length ; i ++ ) {
		cin >> s.elem[i].id >> s.elem[i].name >> s.elem[i].price ;
	} 
	s.length += length; 
	return 1;
}

int findder(sqtable &s,double price) {
	for (int i = 1 ; i <= s.length ; i ++) {
		if ( s.elem[i].price == price ) return i;
	}
	return 0;
}

int main() {
	int length ,val ; 
	double price;
	book temp; 
	while(true) {
		int choose = -1;
		puts("------------��ӭ����ͼ�����ϵͳ-------------");
		puts("");
		puts("**********************************************");
		puts("*******************1. ����********************");
		puts("*******************2. ����********************");
		puts("*******************3. ����********************");
		puts("*******************4. ����********************");
		puts("*******************5. ɾ��********************");
		puts("*******************6. ���********************");
		puts("*******************0. �˳�********************");
		puts("**********************************************");
		puts("");
		sqtable s;
		while(cin >> choose && choose) {
			if ( choose == 1 ) {
				if(!init(s)) printf("-----�ڴ����ʧ��-----\n");
				else printf("-----�ڴ����ɹ�-----\n");
			} else if ( choose == 2 ) {
				printf("��������Ҫ�������Ϣ�ĳ��� : \n");
				cin >> length;
				if ( Scanner(length ,s ) ) {
					printf("-----�������-----\n");
				} else {
					printf("----- error : �ڴ泬�� -----\n");
				}
			} else if ( choose == 3 ) {
				printf("������һ����ļ۸���Ϣ:\n");
				cin >> price;
				val = findder(s ,price );
				if ( val ) {
					printf("�������ϢΪ: ");
					cout << "id = "<< s.elem[val].id<< " -- "<< "name = "<< s.elem[val].name<< " -- "<< "price = "<< s.elem[val].price<< endl; 
				} else {
					printf("-----�Բ���:û�и������Ϣ-----\n");
				}
			} else if ( choose == 4 ) {
				printf("�����������鱾λ�ú���Ϣ (id--name--price):\n");
				cin >> val >> temp.id >> temp.name >> temp.price;
				if ( insert(s ,val ,temp ) ) {
					printf("-----����ɹ�-----\n");
				} else {
					printf("-----����ʧ��-----\n");
				}
			} else if ( choose == 5 ) {
				printf("������ɾ���鱾��λ��:\n");
				cin >> val;
				if ( delect(s ,val ) ) {
					printf("-----ɾ���ɹ�-----\n");
				} else {
					printf("-----ɾ��ʧ��-----\n"); 
				}
			} else if ( choose == 6 ) {
				Print(s);
				printf("-----������-----\n"); 
			} 
		}
		printf("-----ллʹ��-----\n������Ҫ����ʹ����?(1.����ʹ��,2.ֹͣʹ��)");
		cin >> val;
		if ( val == 1 ) continue;
		else if ( val == 2 ) break; 
	}
	return 0;
}
