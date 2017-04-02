//Tobias Egger, 16-728-016

#include <stdio.h>

void swap(int A[], int i, int j){
	int t = A[i];
	A[i] = A[j];
	A[j] = t;
}
int lomuto(int A[], int l, int r, int smallerAtLeft){
	int x = A[r];
	int i = l-1;
	int j;
	if(smallerAtLeft){
	 	for (j = l; j < r; j++){
	 		if (A[j] <= x){
	 			i++;
	 			swap(A,i,j);
			 }
		 }
		 swap(A,i+1,r);
		 return i+1;
	}else{
		for (j = l; j < r; j++){
	 		if (A[j] > x){
	 			i++;
	 			swap(A,i,j);
			 }
		 }
		 swap(A,i+1,r);
		 return i+1;
	}
}

int main(){
	int A[9] = {4, 2, 5, 3, 6, 7, 8, 1, 0};
	int n = 9;
//	int A[7] = {2, 7, 6, 1, 3, 5, 4};
//	int n = 7;
	int i;
	
	for (i=0; i < n; i++){
		printf("%d ", A[i]);
	}
	
	printf("\n");
	
	int m = lomuto(A,0,n-1,0);
	for (i=0; i < n; i++){
		printf("%d ", A[i]);
	}
	printf("\n%d", m);
	return 0;
}
