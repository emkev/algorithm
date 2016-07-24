
/* 2016.07.11 pm 19:42 , play array ordering   */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int array[6] = { 2 , 7 , 4 , 9 , 3 , 2 } ;
int array_length = 6 ;

/*  output factors of array  */
void printf_output(void)
{
  int i ;

  for(i = 0 ; i < array_length ; i++)
  {
    printf("%d " , array[i]);
  }

  printf("\n");

}

/*  from small to large  */
void ordering(void)
{
  int i , j ;
  int temp ;

  j = array_length - 1 ;

  while(j > 0)
  {
    for(i = 0 ; i < j ; i++)
    {
      if(array[i] > array[i + 1])
      {
        temp = array[i] ;
        array[i] = array[i + 1] ;
        array[i + 1] = temp ;
      }
    } /* for(i = 0 ; i < j ; i++)  */

    j-- ;

  } /* while(j < 0)  */

}

/*
void binary_ordering(void)
{
  int i , j , temp ;

  j = array_length / 2 ;

  while(j > 1)
  {
    if(array[j - 1] > array[j + 1])
    {
      temp = array[i - 1] ;
      array[i - 1] = array[i + 1] ;
      array[i + 1] = temp ;
    }

    j /= 2 ;

  }
}
*/

void plotcos(void)
{
  int i , a ;
  double k ;

  for(k = 1 ; k >= -1 ; k -= 0.1)
  {
    a = acos(k) * 10 ;

    for(i = 0 ; i < a ; i++)
    {
      printf(" ");
    }

    printf("*");

    for(i = a + 1 ; i < 62 - a ; i++)
    {
      printf(" ");
    }

    printf("*\n");

  } /*  for(k = ; k >= -1 ; k -= 0.1)  */

}

void print_scan(int i , int j)
{
  printf("scan numbers : %d and %d\n" , i , j);
}

void calu()
{
  int a , b , c ;

  printf("please input numbers :\n");
  scanf("%d %d" , &a , &b);

  c = a + b ;

  printf("result : %d\n" , c);

}

int main(int argc , char *argv[])
{
  int m , n , k ;

  //printf_output();
  //ordering();
  //printf_output();

  //plotcos();

  calu();

  printf("order\n");
  exit(1);

}
