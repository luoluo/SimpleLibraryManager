#include <stdio.h>
struct Book {

};
struct Reader {

};
int
init() {
	FILE *pfile;
	pfile = fopen("reader.txt", "wt+");
//	pfile.close();
	return 0;
}
int
bookManage() {
	printf("bm\n");
	return 0;
}
int
readerManage() {
	printf("rm\n");
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
		printf("1->bm\t2->rm\t3->lm\t4->lt\n");
		scanf("%d", &x);
		switch(x) {
			case 1: bookManage(); break;
			case 2: readerManage(); break;
			case 3: lendManage(); break;
			case 4: logout(); return 0;
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
