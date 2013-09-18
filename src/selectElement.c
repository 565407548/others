#include<stdlib.h>
#include<stdio.h>
#include<time.h>
/*
从已经知道的数据总数为n的数组中等概率选取m个数
 */
void selectElement1(int *arr,int n,int m){
  int i,index,tmp;
  srand(time(NULL));

  for(i=0;i<m;i++){
    //等概率选取i~n中的一个元素
    index=(rand()%100)/100.0*(n-i+1)+i;

    tmp=arr[index];
    arr[index]=arr[i];
    arr[i]=tmp;
  }
}

/*
从未知输入流中，等概率选取m个数
 */
void selectElement2(int *arr,int m){
  int index,elem;
  index=0;
  
  srand(time(NULL));
  
  while(scanf("%d",&elem)==1){
    if(index<m){
      arr[index]=elem;
    }else{
      if((rand()%100)/100.0 < m/(index+0.0)){// m/index 概率选取当前元素
        arr[(int)(rand()%100/100.0*m)]=elem;// 以 1/m 概率选取arr中的一个元素，用elem替换
      }
    }
    index++;
  }
}

int main(int argc, char *argv[])
{
  int i,m;
  
  scanf("%d",&m);
  int *arr=(int*)malloc(sizeof(int)*m);
  selectElement2(arr,m);
  
  for(i=0;i<m;i++){
    printf("%d ",arr[i]);
  }
  /* for(i=0;i<=1000;i++){ */
  /*   printf("%d ",i); */
  /* } */
  
  return 0;
}
