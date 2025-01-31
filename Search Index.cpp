#include<stdio.h>
int searchInsert(int arr[], int n, int target) {
    for(int i=0; i<n;i++){
        if(arr[i]==target){
            return i;
        }
            else if(arr[i]>target){
                return i;
            }
        }
        return n;
    }
    int main(){
    int size, target;
	printf("Enter target:");
	scanf("%d", &target);
	printf("Enter size: ");
	scanf("%d", &size);
	int arr[size];
	printf("Enter array elements: ");
	for(int i=0; i<size;i++){
	scanf("%d", &arr[i]);
    }
	printf("%d", searchInsert( arr, size, target));
	return 0;
	}
