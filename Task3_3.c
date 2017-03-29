// Tobias Egger, 16-728-016

#include <stdio.h>
#include <math.h>

int Parent(i){
	return floor(i/2);
}
int Left(i){
	return 2*i+1;
}
int Right(i){
	return 2*i+2;
}
void Swap(int i, int j, int A[]){
	int temp = A[i];
	A[i] = A[j];
	A[j] = temp;
}
void Heapify(int A[], int i, int s){
	int m = i;
	int l = Left(i);
	int r = Right(i);
	if (l<s && A[l]<A[m]){
		m = l;
	}
	if (r<s && A[r]<A[m]){
		m = r;
	}
	if (i != m){
		Swap(i,m,A);
		Heapify(A,m,s);	
	}
}
void buildMinHeap(int A[], int n){
	int i;
	for (i = floor(n/2); i >=0; i--){
		Heapify(A,i,n);
	}
}
void printHeap(int A[], int n){
	int i, p, l, r;
	printf("graph g {\n");
	for (i=0; i < floor(n/2); i++){
		p = i;
		l = Left(i);
		r = Right(i);
		if(l<n){
			printf("%d -- %d\n", A[p], A[l]);
		}
		if(r<n){
			printf("%d -- %d\n", A[p], A[r]);
		}
		
	}
	printf("}");
}
void heapSort(int A[], int n){
	int s, i;
	s = n;
	buildMinHeap(A,n);
	for (i = n-1;i >= 1; i--){
		Swap(0,i,A);
		s = s-1;
		Heapify(A,0,s);
	}
}
int main(){
	int i, n, A[100];
	i = 0;
	
	printf("Enter an Array to be sorted (type end to end the input)\n");
	while (scanf("%d", &A[i]) == 1){
		i++;
	}
	scanf("%*s");
	n = i;
	heapSort(A,n);
	printf("\nYour Array is now sorted:");
	for (i = 0; i<n; i++){
		printf(" %d",A[i]);
	}
	return 0;
}
