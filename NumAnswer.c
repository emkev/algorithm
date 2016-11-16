
/* 2016.11.16
for mon's small question
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int numbers[3] = { 3,3,3} ;
int len = 3 ;
int count = 0 ;

int sg[4] = { 0,1,2,3 } ;

int answer = 6 ;

float lenF = (float)(len-1) ;
int quaArea;
quaArea = (int)pow(4.0 , lenF);
int show1[quaArea] ;
int show2[quaArea] ;
int counttime = 0 ;

int rec[len-1] ;
int recCount = 0 ;

int selQua = 10 ;
int sel[selQua][len-1] ;
int selCount = 0 ;

/*
void transfer(int **priEm , int pos , int len , int *subEm)
{
  int i ;

  for( i = 0 ; i < len ; i++ ) {
    priEm[pos][i] = subEm[i] ; 
  }
}
*/

int caluRun(int a, int s, int b)
{
  int c ;

  if(s == 0)
    c = a + b ;
  else if(s == 1)
    c = a - b ;
  else if(s == 2)
    c = a * b ;
  else if(s == 3)
    c = a / b ;

  return c ;
}

void calu(int *nb)
{
  int i , j , a ;
  int k1 , k2 , k3 ;

  for(i = 0 ; i < 4 ; i++) {
    k1 = caluRun( nb[0] , sg[i] ,            nb[1] ) ;

    for(j = 0 ; j < 4 ; j++) {
      k2 =  caluRun( k1  , 
                     sg[j] , 
                     nb[2] ) ;

      for(a = 0 ; a < 4 ; a++) {
        k3 =  caluRun( k2  , 
                     sg[a] , 
                     nb[3] ) ;

        printf("%d \n" , k3);             show1[counttime] = k3 ;
        counttime++ ;

      }

    }
  }

}


void caluResNum(int tmp)
{
  int i , k =0 , a = 0 , b ;

  for( i = 0 ; i < 4 ; i++ ) {

    if( count < len - 2 ) {
      
        k = caluRun(
              tmp ,
              sg[i] ,
              numbers[count+1] );

        rec[recCount] = sg[i] ;
        recCount++ ;

        count++ ;
        caluResNum( k ) ;
    }
    else {
      
      a = caluRun(
             tmp ,
             sg[i] ,
             numbers[count+1] ) ;

      rec[recCount] = sg[i] ;
      

      //printf("%d \n" , a );
      show2[counttime] = a ;
      counttime++ ;

      if( a == answer ) {
        for(b=0 ; i<len-1 ; i++) {
          sel[selCount][b]=rec[b];
        }
        selCount++ ;
      }

    }

  }

  count-- ;
  recCount-- ;
}

int compare(int *em1 , int *em2 , int len )
{
  int i ;

  for( i = 0 ; i < len ; i++ ) {
    if( em1[i] != em2[i] )
      return 0 ;
  }

  return 1 ;
}
/*
void output(int **em , int qua , int len)
{
  int i , j ;

  for( i = 0 ; i < qua ; i++ ) {
    for(j = 0 ; j < len ; j++) {
      printf("%d " , em[i][j]);
    }
    printf("\n");
  }
  printf("\n");
}
*/

int main(int argc , char *argv[])
{
  int a , i , j ;

  //calu(numbers);
  //counttime = 0 ;
  printf("\n");

  caluResNum(3);

  //printf("compare result : %d\n" ,compare(show1 , show2 , 64) );

  //output(sel , selQua , len-1);

  printf("select show : \n");
  for(i = 0 ; i < selQua ; i++ ) {
    for(j = 0 ; j < len-1 ; j++) {

      if(sel[i][j] == 0)
        printf("+ ");
      else if(sel[i][j] == 1)
        printf("- ");
      else if(sel[i][j] == 2)
        printf("* ");
      else if(sel[i][j] == 3)             printf("/ ");
    }
    printf("\n");
  }
  printf("\n");

  printf("small question\n");
  exit(1);
}
