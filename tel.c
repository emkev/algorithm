/* 2016.05.24 rewrite code about tel numbers program in microsoft coding interview book . Error of the code is too much . :-<
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

void way1()
{
  int i , j , k , n ;

  j = numlen ;
  //k=total[number[numlen-1]]-1;
  //k = 0 ;
  
  while(1)
  {
    for(i = 0; i < numlen ; i++)
      printf("%c" , c[number[i]][answer[i]]);
    printf("\n");
    
    k = n - 1 ;
    while(k >= 0)
    {
      if(anwser[k] < total[number[k]] - 1)
      {
        anwser[k]++ ;
        break ;
      }
      else
      {
        /* back to first alphabet  pos for next number pos */
        anwser[k] = 0 ;       
        k-- ;
      }
    } /* while(1) */

  if(j < 0)
    break ;

  } /* while(1) */
}

int main()
{
  //way1();

  printf("tel num\n");
  return(1);
}
