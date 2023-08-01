#include<iostream>
#include<stdlib.h>

using namespace std;

int main() {
	int *A, n, ch, x,i,j;
	printf("Enter dimension\n");
	scanf("%d",&n);
	A = new int[n];
	do {
		//Display();
		scanf("%d",&ch);
		switch(ch) {
			case 1: for (int i = 1; i <= n; i++) {
				scanf("%d", &A[i - 1]);
			}
				break;
			case 2: printf("Enter indices");
				scanf("%d%d",&i,&j);
				if (i == j) printf("%d",A[i - 1]);
				else printf("0");
				break;
			case 3:	printf("Enter row, col and el");
				scanf("%d%d%d",i,j,x);
				if (i == j) A[i - 1] = x;
				break;
			case 4: for(int i = 0; i <=n;i++) {
				for(j = 1; j<=n;j++) {
					if(i == j) printf("%d", A[i - 1]);
					else printf("0 ");
				}
				printf("\n");
			}
				break;
		}
	} while (true);
	return 0;
}
