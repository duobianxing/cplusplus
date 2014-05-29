#include <stdio.h>
#include <stdbool.h>
#include <iostream>
#include <math.h>
#define min(a,b) fmin(a,b)
#define max(a,b) fmax(a,b)
#define cout std::cout
void printMoves(int P[][100],int A[], int N){
	int P1, P2;
	int m=0, n=N-1;
	bool myTurn = true;
	while(m<n){
		P1 = P[m+1][n];
		P2 = P[m][n-1];
		printf ("P1 = %d \n", P1);
		printf ("P2 = %d \n", P2);
		cout <<(myTurn ? "I " : "you ") << "take coin no.";
		if (P1<P2){
		      cout<<m<<"("<<A[m]<<")";
		      m++;
		 }else if(P1>P2){
		      cout<<n<<"("<<A[n]<<")";
		      n--;
		}else {
		    if (A[m]>=A[n]){
		      cout<<m<<"("<<A[m]<<")";
		      m++;
		    }else{
		        cout<<n<<"("<<A[n]<<")";
		        n--;
		    }
		}
	        cout<<(myTurn ? ",\n" : ". \n");
	        myTurn = !myTurn;
	}
}

int maxMoney(int A[], int N){
	int P[100][100] = {0};
	int a, b, c;
	for (int i = 0; i< N; i++){
	       for ( int m = 0, n = i; n < N; n++, m++){
			a = (m+2<N ? P[m+2][n] : 0); 
			b = ((n-2>=0 && m < N) ? P[m][n-2] : 0);
			c = ((m+1 < N && n-1 >= 0) ? P[m+1][n-1] : 0);
			P[m][n] = max((A[m]+ min(a,c)),(A[n]+min(b,c)));
	       }
	}
	printMoves(P, A, N);
	return P[0][N-1];
}

int main(){
     int A [6] = { 3,2,2,3,1,2};
     printf("%d \n", maxMoney(A, 6));

}
