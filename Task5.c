//Tobias Egger, 16-728-016

#include <stdio.h>
#include <math.h>
void swap(int A[], int i, int j){
	int t = A[i];
	A[i] = A[j];
	A[j] = t;
}

int isEven(int num){
	if (num%2 == 0){
		return 1;
	}else{
		return 0;
	}
}

int isOdd(int num){
	return !isEven(num);
}

void hoareOddEven(int A[], int l, int r){
	int i = l;
	int j = r;
	while(1){
		if (!isOdd(A[j])){
			j--;
		}
		if (!isEven(A[i])){
			i++;
		}
		if (i<j){
			swap(A,i,j);
		}else{
			break;
		}
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

	hoareOddEven(A,0,n-1);
	
	for (i=0; i < n; i++){
		printf("%d ", A[i]);
	}
	return 0;
}
