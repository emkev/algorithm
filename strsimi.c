/* 2016.05.21 pm 23:33 , try coding for similarity of two strings
from the microsoft coding study book .
2016.05.23 pm continue to finish .
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *stringA , *stringB ;

int minValue(int n1 , int n2 , int n3)
{
  int result ;

  if(n1 < n2)
    result = n1 ;
  else
    result = n2 ;

  if(result < n3)
    return result ;
  else
    return n3 ;
}

int way(char *strA , int pAbegin , int pAend , char *strB , int pBbegin , int pBend)
{
  int t1 , t2 , t3 ;

  /* condition of break */
  if(pAbegin > pAend)
  {
    if(pBbegin > pBend)
      return 0 ;
    else
      return pBend - pBbegin + 1 ;
  }
  if(pBbegin > pBend)
  {
    if(pAbegin > pAend)
      return 0 ;
    else
      return pAend - pAbegin + 1 ;
  }

  if(strA[pAbegin] == strB[pBbegin])
  {
    return way(strA , pAbegin+1 , pAend , strB , pBbegin+1 , pBend) ;
  }
  else
  {
    t1 = way(strA , pAbegin+1 , pAend , strB , pBbegin , pBend) ;
    t2 = way(strA , pAbegin , pAend , strB , pBbegin+1 , pBend) ;
    t3 = way(strA , pAbegin+1 , pAend , strB , pBbegin+1 , pBend) ;

    return minValue(t1 , t2 , t3) + 1 ; 
  }

}


int main()
{
  int strAlen = 0 , strBlen = 0 ; 
  int times = -1 ;
  double simi ;

  stringA = "aqf" ;
  stringB = "wrf" ;

  strAlen = strlen(stringA) ;
  strBlen = strlen(stringB) ;
  printf("strAlen = %d\n" , strAlen);

  times = way(stringA , 0 , strAlen - 1 , stringB , 0 , strBlen - 1);

  printf("distance from A to B = %d\n" , times);

  if(times == 0)
    simi = 1 ;
  else
    simi = 1.0 / (double)(times+1) ;

  printf("similarity = %f\n" , simi) ;
  printf("similarity of strings\n");

  return(1);
}
