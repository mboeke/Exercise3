//Tobias Egger, 16-728-016

#include <stdio.h>
#include <time.h>

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
void quicksort(int A[], int l, int r, int ascending){
	if (l<r){
		int m;
		if (ascending){
			m = lomuto(A,l,r,1);
		}else{
			m = lomuto(A,l,r,0);
		}
		quicksort(A,l,m-1, ascending);
		quicksort(A,m+1,r, ascending);
	}
}
void readFile(char filename[], int output[], int *n){
	FILE *f;
	int i;
	f=fopen(filename, "r");
	i=0;
	while(fscanf(f, "%d", &output[i]) == 1) i++;
	*n=i-1;
	fclose(f);
}
int main(){
	int A[48000];
	int n;
	readFile("ordered_desc_12000.txt", A, &n);
	clock_t start;
	clock_t end;
	float seconds;
	start = clock();
	// your sorting function
	quicksort(A,0,n,1);
	end = clock();
	seconds = (float)(end - start) / CLOCKS_PER_SEC;
	printf("secs: %f\n", seconds);
	return 0;
}
