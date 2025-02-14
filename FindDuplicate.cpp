#include<stdio.h>
#include<stdlib.h>
int main(){
	int n, duplicateCount=0;
	printf("enter n: ");
	scanf("%d", &n);
	int arr[n];
	printf("enter array elements: ");
	for(int i=0;i<n;i++){
		scanf("%d", &arr[i]);
	}
	for(int i =0; i<n; i++){
		for(int j =1; j<n; j++){
		if(arr[i]== arr[j]){
			duplicateCount++;
  }
}
}
	return 0;
}
