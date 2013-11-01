#include <stdio.h>
struct Book {
	char bookId[5];
	char name[23];
	char author[15];
	char press[19];
	char date[8];
	double pirce; 
	char sort[6];
	char readerId[5];
};

struct LendInfo {
	char bookId[5];
	char borrowDate[11];
	char revertDate[11];
};

struct Reader {
	char readerId[5];
	char name[9];
	char sex[3];
	char stuId[7];
	struct LendInfo lendInfo[20];
};
int
init() {
	FILE *readerFile, *bookFile, *lendFile;
	readerFile = fopen("readerFile.txt", "a+");
	bookFile = fopen("bookFile.txt", "a+");
	lendFile = fopen("lendFile.txt", "a+");
//	pfile.close();
	fclose(readerFile);
	fclose(bookFile);
	fclose(lendFile);
	return 0;
}
int
displayBook() {
//	char bookId[5];
//	char name[23];
//	char author[15];
//	char press[19];
//	char date[8];
//	double pirce; 
//	char sort[6];
//	char readerId[5];
	FILE *bookFile;
	bookFile = fopen("bookFile.txt", "r");
	struct Book book;
	char info[100];
	while (fscanf(bookFile, "%s\t%s", book.bookId, book.name) != EOF) {
		printf("%s\t%s\n", book.bookId, book.name);
	}
	fclose(bookFile);
	return 0;
}
int
addBook() {
	FILE *bookFile;
	bookFile = fopen("bookFile.txt", "a");
	char info[100];
	struct Book book;
	scanf("%s%s", book.bookId, book.name);
	fprintf(bookFile, "%s\t%s\n", book.bookId, book.name);
	fclose(bookFile);
	return 0;
}
int
editBook() {
	FILE *bookFile;
	bookFile = fopen("bookFile.txt", "a");
	char info[100];
	scanf("%s", info);
	fprintf(bookFile, "%s\n", info);
	fclose(bookFile);
	return 0;
}
int
removeBook() {
	FILE *bookFile;
	bookFile = fopen("bookFile.txt", "a");
	char info[100];
	scanf("%s", info);
	fprintf(bookFile, "%s\n", info);
	fclose(bookFile);
	return 0;
}
int
searchBook() {
	FILE *bookFile;
	bookFile = fopen("bookFile.txt", "a");
	char info[100];
	scanf("%s", info);
	fprintf(bookFile, "%s\n", info);
	fclose(bookFile);
	return 0;
}
int
sortBook() {
	FILE *bookFile;
	bookFile = fopen("bookFile.txt", "a");
	char info[100];
	scanf("%s", info);
	fprintf(bookFile, "%s\n", info);
	fclose(bookFile);
	return 0;
}
int
goback() {
	printf("returning...\n");
	return 0;
}
int
bookManage() {
	while (1) {
		printf("bm\n1->dip\t2->add\t3->edit\t4->remove\t5.search\t6.sort\t0->return\n");
		int x;
		scanf("%d", &x);
		switch(x) {
			case 1: displayBook(); break;
			case 2: addBook(); break;
			case 3: editBook(); break;
			case 4: removeBook(); break;
			case 5: searchBook(); break;
			case 6: sortBook(); break;
			case 0: goback(); return 0;
			default: ;
		}
	}
	return 0;
}
int
displayReader() {
	return 0;
}
int
addReader() {
	return 0;
}
int
editReader() {
	return 0;
}
int
removeReader() {
	return 0;	
}
int
searchReader() {
	return 0;
}
int
sortReader() {
	return 0;
}
int
readerManage() {
	while (1) {
		printf("rm\n1->dip\t2->add\t3->edit\t4->remove\t5.search\t6.sort\t0->return\n");
		int x;
		scanf("%d", &x);
		switch(x) {
			case 1: displayReader(); break;
			case 2: addReader(); break;
			case 3: editReader(); break;
			case 4: removeReader(); break;
			case 5: searchReader(); break;
			case 6: sortReader(); break;
			case 0: goback(); return 0;
			default: ;
		}
	}
	return 0;
}
int
searchBorrow() {
	return 0;
}
int
borrow() {
	return 0;
}
int
revert() {
	return 0;
}
int
lendManage() {
	while (1) {
		printf("lm\n1->search\t2->borrow\t3->revert\t0->return");
		int x;
		scanf("%d", &x);
		switch(x) {
			case 1: searchBorrow(); break;
			case 2: borrow(); break;
			case 3: revert(); break;
			case 0: goback(); return 0; 
			default: ;
		}
	}
	return 0;
}
int
logout() {
	printf("lt\n");
	return 0;
}
int operation() {
	while (1) {
		int x;
		printf("1->bm\t2->rm\t3->lm\t0->lt\n");
		scanf("%d", &x);
		switch(x) {
			case 1: bookManage(); break;
			case 2: readerManage(); break;
			case 3: lendManage(); break;
			case 0: logout(); return 0;
			default: ;
		}
	}

}
int
main() {
	init();
	operation();
	return 0;
}
