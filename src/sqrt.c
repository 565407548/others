#include<stdio.h>

/* #define DEBUG */
#define PRECISE 0.001

/*
求一个数的平方，至少有两种方法：
1.折半查找法，时间复杂度为：lg(n/PRECISE)
2.牛顿迭代法
 */

double binSearch(int n,double l, double u){
#ifdef DEBUG
  printf("n=%d l=%lf u=%lf\n",n,l,u);
#endif
  double m,diff;
  m=(u+l)/2;

  diff=m*m-n;
  
  if(u-l<PRECISE || diff>=-PRECISE && diff<=PRECISE){
    return m;
  }
  if(diff>0){
    return binSearch(n,l,m);
  }else{
    return binSearch(n,m,u);
  }
}

//折半查找
double sqrt_b(int n){
  return binSearch(n,0,n);
}

//牛顿迭代
double sqrt_n(int n){
  double x0,y0,x1,y1;
  x0=n/2.0;
  y0=x0*x0-n;
  while(y0<-PRECISE || y0>PRECISE){
    x1=x0-y0/(2*x0);//(x1,0)位y=x^2-n的(x0,y0)处的切线与x轴的交点
    y1=x1*x1-n;
    if(y0>0 && y1 >0){
      x0=x0/2;
    }else if(y0<0 && y1<0){
      x0=2*x0;
    }
    else{
      x0=(x0+x1)/2;
    }
    y0=x0*x0-n;
  }
  return x0;
}

int main(int argc, char *argv[])
{
  int n,op;
  scanf("%d%d",&op,&n);
  if(op==1){
    printf("sqrt_b(%d)=%lf\n",n,sqrt_b(n));
  }
  else{
    printf("sqrt_n(%d)=%lf\n",n,sqrt_n(n));
  }
        
      
  return 0;
}
