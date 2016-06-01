/* 2016.05.24 write code about tel numbers program in microsoft coding interview book .
2016.05.25 continue to finish .
*/

#include <stdio.h>
#include <stdlib.h>

int number[3]={2,3,9};
int answer[3]={0,0,0};
int numlen = 3 ;

int total[10]={0,0,3,3,3,3,3,4,3,4};
char c[10][10] = {
"",
"",
"abc",
"def",
"ghi",
"jkl",
"mno",
"pqrs",
"tuv",
"wxyz"
};

int count = 0 ;

void way1()
{
  int i , k ;

  //j = numlen ;
  //k=total[number[numlen-1]]-1;
  //k = 0 ;
  
  while(1)
  {
    for(i = 0; i < numlen ; i++)
      printf("%c" , c[number[i]][answer[i]]);
    printf("\n");
    count++ ;

    k = numlen - 1 ;
    while(k >= 0)
    {
      if(answer[k] < total[number[k]] - 1)
      {
        answer[k]++ ;
        break ;
      }
      else
      {
        /* back to first alphabet  pos for next number pos */
        answer[k] = 0 ;       
        k-- ;
      }
    } /* while(1) */

  if(k < 0)
    break ;

  } /* while(1) */
}

void way2(int *answer , int *number , int index , int numlen)
{
  int i ;

  if(index == numlen)
  {
    for(i = 0; i < numlen ; i++)
      printf("%c" , c[number[i]][answer[i]]);
    printf("\n");
    count++ ;

    return ;
  }

  for(answer[index] = 0; answer[index] < total[number[index]] ; answer[index]++)
  {
    way2(answer,number,index+1,numlen) ;
  }
}

int main()
{
  //way1(); 
  way2(answer,number,0,numlen) ;
  printf("count = %d\n" , count);
  printf("tel num\n");
  return(1);
}
