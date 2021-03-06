
/* 2016.05.20 FRI pm 18:51 , 
try it after reading microsoft coding for interview .
2016.05.21 modified by the book .
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int *nPerson , floors = 6 ;


int finding()
{
  int i , j ;
  int targetFloor = -1 , moveFloors = 0  , tempFloors = 0 ;

  for(i = 0 ; i < floors ; i++)
  {
    moveFloors = 0 ;
    for(j = 0 ; j < i ; j++)
    {
      moveFloors += nPerson[j] * abs(i - j) ;
    }
    for(j = i + 1 ; j < floors ; j++)
    {
      moveFloors += nPerson[j] * abs(j - i) ;
    }

    // if(i == 0) tempFloors = moveFloors ;

    if(targetFloor == -1 || moveFloors < tempFloors)
    {
      tempFloors = moveFloors ;
      targetFloor = i ;
    }
  } /* for(i = 0 ; i < floors ; ... */
  targetFloor += 1 ;
  return targetFloor ;
}


int comparing()
{
  int i , j , k ;
  int n1 , n2 , n3 ;
  int nMinFloors , targetFloor = 0 ;

  /* begin from floor 1 , so n1 = 0 , , , .
     And enable i from floor 2 . 
   */
  for(n1 = 0 , n2 = nPerson[0] , n3 = 0 , i = 1 ; i < floors ; i++)
  {
    n3 += nPerson[i] ;
    //nMinFloors +=     
  }

  /* begin from floor 2 */
  for(i = 1 ; i < floors ; i++)
  {
    if(n1 + n2 < n3)
    {
      targetFloor = i ;
      n1 += n2 ;
      n2 = nPerson[i] ;
      n3 -= nPerson[i] ;
    } /* if(n1 + n2 > n3) */
    else
      break ;

  } /* for(i = 1 ; i < floors ; i++) */
  targetFloor += 1 ;
  return targetFloor ;
}


int findingforenergy()
{
  int i , j ;
  int targetFloor = -1 , moveFloors = 0  , tempFloors = 0 ;
  /* energy of cost for going up and down */
  int upEn = 5 , downEn = 1 ;
  int costEn = 0 , tempCost = 0 ;

  for(i = 0 ; i < floors ; i++)
  {
    moveFloors = 0 ;
    costEn = 0 ;

    for(j = 0 ; j < i ; j++)
    {
      moveFloors += nPerson[j] * abs(i - j) ;
      costEn += nPerson[j] * (i - j) * downEn ;
    }
    for(j = i + 1 ; j < floors ; j++)
    {
      moveFloors += nPerson[j] * abs(j - i) ;
      costEn += nPerson[j] * (j - i) * upEn ;
    }

    // if(i == 0) tempFloors = moveFloors ;

    if(targetFloor == -1 || costEn < tempCost)
    {
      tempCost = costEn ;
      targetFloor = i ;
    }
  } /* for(i = 0 ; i < floors ; ... */
  targetFloor += 1 ;

  return targetFloor ;
}

int main(int argc , char **argv)
{
  //int *nPerson ;
  int result = 0 ;

  nPerson = malloc(sizeof(int) * floors) ;
  nPerson[0] = 2 ;
  nPerson[1] = 4 ;
  nPerson[2] = 10 ;
  nPerson[3] = 7 ;
  nPerson[4] = 8 ;
  nPerson[5] = 5 ;

  // erro: nPerson = { 2,4,10,7,8,5 } ;

  //result = comparing();
  //result = finding();
  result = findingforenergy();

  printf("result = %d\n" , result);

  printf("coding study !\n");
  return(1);
}
