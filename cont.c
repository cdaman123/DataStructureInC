#include <stdio.h>
#include<math.h>
int fib(int n){
    if(n==0)
        return 0;
    else if(n==1)
        return 1;
    else
        return (fib(n-1)+fib(n-2))%10;
}
int main(void) {
	long long int T,N;
    int n = 1,i,F;
	scanf("%lld",&T);
	for(i=0;i<T;i++){
	    scanf("%lld",&N);
        while(N != 1){
            N = N/2;
            n*=2;
            n%=60;
        }
        F = fib(n);
	    printf("%d\n",F);
    }
	return 0;
}

