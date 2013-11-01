#include <stdio.h>
#include <string.h>
#define BOOKNUM 10000
#define READERNUM 1000
#define LENDNUM 1000
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

struct Book books[BOOKNUM];
struct Reader readers[READERNUM];
struct LendInfo lendInfos[LENDNUM];
int totalReader, totalBook, totalLend;
FILE *readerFile, *bookFile, *lendFile;
int
init() {
	readerFile = fopen("readerFile.txt", "a+");
	while (fscanf(readerFile, "%s\t%s", readers[totalReader].readerId, readers[totalReader].name) != EOF) {
		totalReader++;	
	}
	bookFile = fopen("bookFile.txt", "a+");
	while (fscanf(bookFile, "%s\t%s", books[totalBook].bookId, books[totalBook].name) != EOF) {
		totalBook++;	
	}
	lendFile = fopen("lendFile.txt", "a+");
	while (fscanf(lendFile, "%s\t%s", lendInfos[totalLend].bookId, lendInfos[totalLend].borrowDate) != EOF) {
		totalLend++;	
	}
	fclose(readerFile);
	fclose(bookFile);
	fclose(lendFile);
	return 0;
}
int
showBookInfo(struct Book book) {
	printf("%s\t%s\n", book.bookId, book.name);
	return 0;
}
int writeBookInfo(struct Book book) {
	fprintf(bookFile, "%s\t%s\n", book.bookId, book.name);
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
	int i;
	for (i = 0; i < totalBook; i++) {
		showBookInfo(books[i]);
	}
	return 0;
}
int
getBookInfo() {
	scanf("%s%s", books[totalBook].bookId, books[totalBook].name);
	return 0;
}
int
addBook() {
	getBookInfo();
	totalBook++;
	return 0;
}
int
editBook() {
	char changeId[5], changeArea[10];
	scanf("%s%s", changeId, changeArea);
	int i = searchBookById(changeId);
	if (i != -1) {
		if (strcmp(changeArea, "bookId") == 0) {
			char changeTo[5];
			scanf("%s", changeTo);
			strcpy(books[i].bookId, changeTo);
		}	
	} else {
		printf("no such book\n");
	}
	
	return 0;
}
int
bookInfoCopy(int i, int j) {
	strcpy(books[i].bookId, books[j].bookId);
	strcpy(books[i].name, books[j].name);
}
int
removeBook() {
	char changeId[5];
	scanf("%s", changeId);
	int i = searchBookById(changeId);
	if (i != -1) {
		int j;
		for (j = i+1; j < totalBook; j++) {
			bookInfoCopy(j-1, j);
		}
		totalBook--;
	} else {
		printf("no such book\n");
	}
	
	return 0;
}

int
searchBookById(char bookIdx[]) {
	int i;
	for (i = 0; i < totalBook; i++) {
		if (strcmp(books[i].bookId, bookIdx) == 0) {
			return i;
		}
	}
	return -1;
}
int
searchBook() {
	char bookIdx[5];
	scanf("%s", bookIdx); 
	int i = searchBookById(bookIdx);
	if (i != -1) {
		showBookInfo(books[i]);
	} else {
		printf("no such book\n");
	}
	return 0;
}
int
sortBook() {
	int i, j;
	for (i = 0; i < totalBook; i++) {
		for (j = i+1; j < totalBook; j++) {
			if (strcmp(books[j].bookId, books[j-1].bookId) < 0) {
				bookInfoCopy(BOOKNUM-1, j-1);
				bookInfoCopy(j-1, j);
				bookInfoCopy(j, BOOKNUM-1);
			}
		}
	}
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
	//write back
	int i;
	readerFile = fopen("readerFile.txt", "w");
	bookFile = fopen("bookFile.txt", "w");
	lendFile = fopen("lendFile.txt", "w");
	for (i = 0; i < totalBook; i++) {
		writeBookInfo(books[i]);
	}	
	fclose(readerFile);
	fclose(bookFile);
	fclose(lendFile);
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
