#include<stdio.h>
#include<string.h>


int main(){
  int n,m;
  printf("Enter the size of the first list: ");
  scanf("%d",&n);
  
  char a[n][20];
  
  printf("Enter the products :\n");
  for (int i=0;i<n;i++){
      scanf("%s",a[i]);
  }
  printf("Enter the size of the second  list: ");
  scanf("%d",&m);
  
  char b[m][20];
  printf("Enter the products :\n");
  for (int i=0;i<m;i++){
      scanf("%s",b[i]);
  }


  int i=0,j=0;
  
  printf("Merge Sorted Lists are: \n");
  
  while(i<n && j<m){
    if (strcmp(a[i],b[j])<0){
      printf("%s  ",a[i]);
      i++;
    }
  else{
    printf("%s  ",b[j]);
    j++;
  }
}                                                                                                                                                                     
  while(i<n){
    printf("%s  ",a[i]);
    i++;
  }
  while(j<m){
    printf("%s  ",b[j]);
    j++;
  }
return 0;
}