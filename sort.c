
/*  2016.11.14 , sort algorithm code  */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int number[6] = { 2 , 8 , 9 , 4 , 8 , 6 } ;
int numbers_len = 6 ;


void show(int *num_show , int num_show_len)
{
  int i ;

  for(i = 0 ; i < num_show_len ; i++) {
    printf("%d " , num_show[i]);
  }

  printf("\n");
}

/*  exchange two numbers */
void exchange(int *ex1 , int *ex2)
{
  int tmp ;

  tmp = *ex1 ;
  *ex1 = *ex2 ;
  *ex2 = tmp ;
}


void insertion(int *em , int em_len)
{
  int i , j , tmp ;

  for(i = 0 ; i < em_len ; i++) {
    for(j = i ; j > 0 ; j--) {

      if( em[j] < em[j - 1] )
        exchange(&em[j] , &em[j-1]);

    }
  }

  show(em , em_len);
}


/*  
    select the MIN one in unsorted list , 
    and exchange new i and MIN one 
    for adding MIN one into sorted list .
*/
void selection(int *em , int len)
{
  int i , j , min , tmp ;

  for(i = 0 ; i < len - 1 ; i++) {

    min = i ;
    for(j = i + 1 ; j < len ; j++) {
      if(em[j] < em[min]) 
        min = j ;
    }

    exchange(&em[i] , &em[min]);    
  }

  show(em , len);

}


/*
   exchange the one and its neighhood 
   again and again .
*/
void bubble(int *em , int len)
{
  int i , j , tmp ;

  for(i = 0 ; i < len - 1 ; i++) {
    for( j = i + 1 ; j < len ; j++) {
    
      if(em[j] < em[i]) 
        exchange(&em[j] , &em[i]);
    }
  }

  show(em , len);

}


void bubble2(int *em , int len)
{
  int i , j , tmp ;

  j = len - 1 ;

  while(j > 0) {

    for(i = 0 ; i < j ; i++) {
      if(em[i] > em[i + 1])
        exchange(&em[i] , &em[i+1]);
    }

    j-- ;

  } /*  while(j > 0) */

  show(em , len);
}


/* 
   shell
 
   math.floor(x) :
   returns a floating-point value representing the largest 
   integer that <= x . 

   returns integer one that >= x 
   by the fractional part as to four-out-and-five-in way 
*/
void shell(int *em , int len)
{
  int h , i , j ;
  
  h = 1 ;

  while( h < floor(len/3) ) {
    h = h * 3 + 1 ;
  }

  while(h >= 1) {

    for(i = h ; i < len ; i++) {
      for(j = i ; j >= h ; j -= h) {

        if(em[j] < em[j - h])
          exchange(&em[j] , &em[j - h]);
      }
    }

    h = floor( h / 3 ) ;
  } /*  while(  */

  show(em , len);
}


int main(int argc , char *argv[])
{
  printf("ini   : ");
  show(number , numbers_len);

  printf("sorted: ");
  //insertion(number , numbers_len);
  //selection(number , numbers_len);
  //bubble(number , numbers_len);
  //bubble2(number , numbers_len);
  shell(number , numbers_len);

  printf("sort\n");
  exit(1);

}
