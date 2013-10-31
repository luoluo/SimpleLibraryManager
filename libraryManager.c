#include <stdio.h>
struct Book {

};
struct Reader {

};
int
init() {
	FILE *readerFile, *bookFile, *lendFile;
	readerFile = fopen("readerFile.txt", "wt+");
	bookFile = fopen("bookFile.txt", "wt+");
	lendFile = fopen("lendFile.txt", "wt+");
//	pfile.close();
	close(readerFile);
	close(bookFile);
	close(lendFile);
	return 0;
}
int
displayBook() {
	return 0;
}
int
addBook() {
	return 0;
}
int
editBook() {
	return 0;
}
int
removeBook() {
	return 0;
}
int
searchBook() {
	return 0;
}
int
sortBook() {
	return 0;
}
int
goback() {
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
lendManage() {
	printf("lm\n");
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
