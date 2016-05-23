
/* 2016.05.21 pm 23:33 , try coding for similarity of two strings
from the microsoft coding study book .
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *stringA , *stringB ;
/*
int way(strA , pAbegin , pAend , strB , pBbegin , pBend)
{
  
  if(pAbegin > pAend)
  {
    if(pBbegin > pBend)
      return 0 ;
    else
      return pBend - pBbegin + 1 ;
  }

}
*/

int main()
{
  int strAlen = 0 , strBlen = 0 ; 
  int times = -1 ;

  stringA = "aqf" ;
  stringB = "wrf" ;

  strAlen = strlen(stringA) ;
  strBlen = strlen(stringB) ;
  printf("strAlen = %d\n" , strAlen);

  //times = way(stringA , 0 , strAlen - 1 , stringB , 0 , strBlen - 1);

  printf("distance from A to B = %d\n" , times);
  printf("similarity of strings\n");

  return(1);
}
