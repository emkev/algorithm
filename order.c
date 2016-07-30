
/* 2016.07.11 pm 19:42 , play array ordering   */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

//int array[6] = { 2 , 4 , 8 , 9 , 8 , 2 } ;
int array[6] ;
int array_length = 6 ;

int arraytime[11] ; 
int arraytime_length = 11 ;


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

/*  suit for same-data being most and data-domain ...   */
void order_time()
{
  int i , j , t ;

  for(i = 0 ; i < arraytime_length ; i++)
  {
    arraytime[i] = 0 ;
  }

  /*
  for(i = 0 ; i < array_length ; i++)
  {
    arraytime[array[i]] += 1 ;
  }
  */

  for(i = 0 ; i < array_length ; i++)
  {
    scanf("%d" , &t);
    arraytime[t]++ ;
  }

  for(i = 0 ; i < arraytime_length ; i++)
  {
    for(j = 0 ; j < arraytime[i] ; j++)
    {
      printf("%d " , i) ;
    }
  }

  printf("\n");

}

void resur_change(int spos , int epos)
{
  int a , b , mv , temp ;

  if(spos > epos) return ;

  mv = array[spos] ;
  a = spos ;
  b = epos ;

  while(1)
  {
    /*  It must compute end-pos direction at first .   */
    while(b > a)
    {
      if(array[b] < mv) break ;
      b-- ;
    }

    while(a < b)
    {
      if(array[a] > mv) break ;
      a++ ;
    }

    if(a < b)
    {
      temp = array[a] ;
      array[a] = array[b] ;
      array[b] = temp ;
    }

    if(a == b) break ;

  }

  /*  exchange spos with the same number ( means the situation a==b )  */
  array[spos] = array[a] ;
  array[a] = mv ;

  /*  continue to call   */
  resur_change(spos , a - 1) ;

  resur_change(a + 1 , epos) ;

}


/*  speeding order  */
void order_speeding()
{
  int i , j , n , t ;

  printf("Please input array length :\n");
  scanf("%d" , &n);

  printf("Please input array factors :\n");

  /*  get values  */
  for(i = 0 ; i < n ; i++)
  {
    scanf("%d" , &t) ;
    array[i] = t ;
  }

  resur_change(0 , array_length - 1) ;

  /*  display  */
  for(i = 0 ; i < n ; i++)
  {
    printf("%d " , array[i]);
  }
  printf("\n");

}

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

void calu()
{
  int a , b , c ;
  char s ;

  printf("please input numbers :\n");
  scanf("%d %c %d" , &a , &s , &b);

  if(s == '+')
    c = a + b ;
  else if(s == '-')
    c = a - b ;
  else if(s == '*')
    c = a * b ;
  else if(s == '/')
    c = a / b ;

  printf("result : %d\n" , c);
  printf("sign : %c\n" , s);

}

int main(int argc , char *argv[])
{
  int m , n , k ;

  //printf_output();
  //ordering();
  //printf_output();

  //plotcos();

  //calu();

  //order_time();

  order_speeding();

  printf("order\n");
  exit(1);

}
