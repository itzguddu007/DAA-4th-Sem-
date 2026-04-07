#include<stdio.h>

int findFirstBad(int *arr,int n){
    
      int low=0,high=n-1;
      int mid;
      int ans=-1;
      while(low <=high){
           mid=(low+high)/2;
  
          if(arr[mid]==1){
            ans=mid;
            high=mid-1;
            }
          else{
            low=mid+1;  //go right 
          }
             
      }
      return ans;  
  
}

int main(){
  int n;

  
  printf("Enter the number of  Commits: ");
  scanf("%d",&n);
  
  int arr[n];
    
  printf("Enter the Commit status(0 = good, 1=bad):\n ");
  for(int i=0;i<n;i++){
    scanf("%d",&arr[i]);
  }
  
  int result=findFirstBad(arr,n);
    
  if (result!=-1)
    printf("First Bad Commit at index  %d",result);

  else
      printf("No bad commit is  Found!!\n");

  return 0;
}