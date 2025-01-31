#include<stdio.h>
int removeEle(int arr[], int n, int val){
	int k=0;
	for(int i=0; i<n;i++){
		if(arr[i]!=val){
			arr[k]=arr[i];
			k++;
		}
	}
	for(int i=0; i<k;i++){
		printf("%d ", arr[i]);
	}
	printf("\n");
	return k;
}
int main(){
	int size, value;
	printf("Enter the value:");
	scanf("%d", &value);
	printf("Enter size: ");
	scanf("%d", &size);
	int arr[size];
	printf("Enter array elements: ");
	for(int i=0; i<size;i++){
	scanf("%d", &arr[i]);
}
	printf("%d", removeEle( arr, size, value));
	return 0;
}
