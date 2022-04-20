#include <stdio.h>
 
int main(int argc, char const *argv[]) {
 
	int T, a, b;
 
	scanf("%d", &T);
	for(int i = 0; i < T; i++){
		scanf("%d %d", &a, &b);
		printf("%d\n", a + b);
	}
 
	return 0;
}