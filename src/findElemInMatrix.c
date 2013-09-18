#include<stdio.h>

/*
在一个行和列都是升序的矩阵中查找元素elem。
如果找到则返回 r*col+c，否则返回-1

思路：
1.正向查找。找到即返回；找到第一个大于elem的则跳至其左下方，查找方向设为反向，跳至2。col越界则调至下方，保持正向查找
2.反向查找。找到即返回；大于elem，则继续反向查找；找到第一个小于elem的则跳至下方，反向不变（因为当前元素右边元素肯定大于elem，则其右下角肯定大于elem，也即其右下侧的元素均大于elem）；

总结：
只有开始会进行一次正向查找，之后当前处理元素只会 左跳/下跳。
由此可以优化算法，从第一行的最后一个元素开始查找，整个查找的元素只会 下跳/左跳， 不需要记录正向还是方向查找。
即初始时，令：
r=0;
c=col-1;
同时去掉//正向查找分支。
优化见findElemInMatrix1
 */
int findElemInMatrix(int *matrix,int row,int col,int elem){
  int r,c,d,index;

  r=0;
  c=0;
  d=1;

  while(r>=0 && r<row && c>=0 && c<col){
    index=r*col+c;
    if(matrix[index]==elem){
      return r*col+c;
    }
    //正向查找
    if(d==1){
      if(matrix[index]<elem){//小于，则继续正向。若行结束，则跳至下行继续
        c++;
        if(c==col){
          r++;
          c--;
          d=-1;
        }
      }else if(matrix[index]>elem){//大于，则调至下行前一列（本列肯定也大于）继续反向查找
        r++;
        c--;
        d=-1;    
      }
    }
    //方向查找
    else if(d==-1){//反向查找
      if(matrix[index]<elem){//小于，跳至下行继续正向查找
        r++;
      }else if(matrix[index]>elem){//大于，继续反向查找
        c--;
      }
    }
  }

  return -1;
}

int findElemInMatrix1(int *matrix,int row,int col,int elem){
  int r,c,index;

  r=0;
  c=col-1;

  while(r>=0 && r<row && c>=0 && c<col){
    index=r*col+c;
    if(matrix[index]==elem){
      return r*col+c;
    }
    
    if(matrix[index]<elem){//小于，跳至下行继续正向查找
      r++;
    }else if(matrix[index]>elem){//大于，继续反向查找
      c--;
    } 
  }

  return -1;
}

int main(int argc, char *argv[])
{
  int matrix[5*8]={
    1,2,3,4,5,6,7,8,
    9,10,11,12,13,14,15,16,
    17,18,19,20,21,22,23,24,
    25,26,27,28,29,30,31,32,
    33,34,35,36,37,38,39,40,
  };
  int i,elem;

  while(scanf("%d",&elem) && elem!=0 ){
    i=findElemInMatrix1(matrix,5,8,elem);
    if(i>=0){
      printf("%d is in the matrix(%d,%d)\n",elem,i/8,i%8);
    }else{
      printf("%d is not in the matrix\n",elem);
    }
  }
  return 0;
}
