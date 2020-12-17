#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct st_book{
	int category; // 분류코드 (0:전공, 1:교양, 2:취미)
	char title[100];  // 도서명
	char pub[100]; // 출판사
	int year;  // 출간년도
	int status; // 상태코드 (0:보관, 1:대여, 2:분실)
	char borrower[100]; // 대여자명
};
char CATEGORY[3][20] = {"전공","교양","취미"};
char STATUS[3][20] = {"보관","대여","분실"};


int load_books(struct st_book* list[]);		// 도서정보 읽어오기
void view_library(struct st_book* list[], int n);	// 현재 서재 정보 출력하기
void add_book(struct st_book* list[], int* n);		// 도서 추가하기
void lost_book(struct st_book* list[], int n);	// 도서 분실 처리하기
void find_books(struct st_book* list[], int n);	// 도서 검색
void update_book(struct st_book* list[], int n);	// 도서정보 수정하기
void save_report(struct st_book* list[], int n);	// 서재 정보 보고서 만들기

int main(){
	struct st_book* my_library[50]; 	// 최대 50개의 객실을 관리할 수 있는 구조체 포인터 배열
	int count;	// 현재 등록된 카드 수
	int menu;	// 메뉴번호
	printf("\n서재 정보입니다.\n");

	count = load_books(my_library);	// 도서정보 읽어오기
	while(1)
	{
		// 메뉴 출력
		printf("\n[1]목록 [2]추가 [3]분실 [4]검색 [5]수정 [6]저장 [0]종료 >> ");
		scanf("%d",&menu);	// 메뉴를 읽음

		if(menu==1){
			view_library(my_library, count);	// 현재 서재 정보 출력하기
		}
		else if(menu==2){
			add_book(my_library, &count);	// 도서 추가하기
		}
		else if(menu==3){
			lost_book(my_library, count); // 도서 분실 처리하기
		}
		else if(menu==4){
			find_books(my_library, count);	// 도서 검색
		}
		else if(menu==5){
			update_book(my_library, count);	// 도서정보 수정하기
		}
		else if(menu==6){
			save_report(my_library, count);	// 서재 정보 보고서 만들기
		}
		else {
			break;
		}
	}
}

int load_books(struct st_book* list[]){
	FILE *file;
	int n=0;
	char bookname[100];
	char line[100];
	file = fopen("books.txt","r");
	while(!feof(file)){
		if(!fgets(bookname, 100, file)) break;
		list[n]=(struct st_book*)malloc(sizeof(struct st_book));
		bookname[strlen(bookname)-1]='\0';
		strcpy(list[n]->title, bookname);
		fgets(line, 100, file);
		sscanf(line,"%d %s %d",&(list[n]->category),list[n]->pub,&(list[n]->year));
		list[n]->status=0;
		n++;
	}
	fclose(file);
	printf("%d개의 도서 정보를 읽었습니다.\n",n);
	return n;
}

void view_library(struct st_book* list[], int n){
	int i;
	printf("\n서재 정보입니다. (총 %d권)\n", n);
	printf("번호 / 분류 / 도서명 / 출판사 / 출간년도 / 상태\n");
	
	for(i=0; i<n; i++){
		printf("%2d / ", i+1);
		printf("%s / ", CATEGORY[list[i]->category]);
		printf("%s / ", list[i]->title);
		printf("%s / ", list[i]->pub);
		printf("%d년 / ", list[i]->year);
		printf("%s ", STATUS[list[i]->status]);
		if(list[i]->status==2) printf("(%s)", list[i]->borrower);
		printf("\n");
	}
}

////////// 여기부터 코드 작성 ////////////////////////

void add_book(struct st_book* list[], int* n){

}

void lost_book(struct st_book* list[], int n){

}

void find_books(struct st_book * list[], int n){

}

void update_book(struct st_book* list[], int n){

}

void save_report(struct st_book* list[], int n){

}	

