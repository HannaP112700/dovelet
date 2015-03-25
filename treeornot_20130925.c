#include<stdio.h>
int main(){
 int arr[100];
 int arr2[100];
 int arr3[100];
 int f=1,e,count=0,non=0,i=0;
 int j=0,temp;

 scanf("%d %d", &arr[0],&arr2[0]);
 
 while(arr[f-1]!=0 && arr2[f-1]!=0){
  scanf("%d %d",&arr[f],&arr2[f]);
  f++;
  count++;
 }
 
 
 if(arr[0]==0 && arr2[0]==0)
 {
  printf("tree");
  non=2;
 }

/////부모 노드의 갯수 파악
 if(non!=2){
 i=0,f=0;
 e=0;temp=0;
 while(f<count){
 if(e==0){
  
  arr3[i]=arr[f];
  e++;f++;
  }
 
 else{
  for(i=0;i<e;i++){
   if(arr3[i]!=arr[f]){
    temp++;
   }
  }
 
   if(temp==e)
   {
    
    arr3[i]=arr[f];
    e++;
   }
   else{}
temp=0;
   f++;
 }
 }
 temp=0;
 //루트노드 한 개를 제외한 나머지 노드를 판독
 for(i=0;i<e;i++){
  for(j=0;j<count;j++)
  {
   if(arr3[i] == arr2[j])
   {
    temp++;
    
    break;
   }
  }
 }

 if(temp!=e-1)
{  non=3;
 printf("not a tree");
 }
 }

//////자식노드가 같은 노드를 향해 줄 수 없는 것을 판단
 if(non<2){
 e=0;
 f=1;
 while(arr2[e]!=arr2[f++]){
  if(count<=1){
   non=3;break;}
  if(f==count){
   e++;
   f=e+1;
   if(f==count){
    printf("tree");//조건 성립하면 트리
    non=1;
    break;
   }
  }
 }
 
 if(non==0 ){//반복문 실행 중 조건 불성립하여 제외 된 경우 not tree
  printf("not a tree");
 }
 
 
 if(non==3){
 printf("tree");
 }
 }
 
 return 0;
}
