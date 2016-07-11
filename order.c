
/* 2016.07.11 pm 19:42 , play array ordering   */

#include <stdio.h>
#include <stdlib.h>

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

int main(int argc , char *argv[])
{
  printf_output();
  ordering();
  printf_output();

  printf("order\n");
  exit(1);

}
