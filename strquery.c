/* 2016.05.29 begin , search for words ,get short content as search results .
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *text = "qwthcdywtdh" ;
char *str = "q y" ;
int len = 0 ;
int qstrlen = 0 ;
int targetlen = 0 ;
int pBegin = 0 , pEnd = 0 ;
int aBegin = 0 , aEnd = 0 ;

int reallen(char *inistr)
{
  int i , j = 0 , k ;
  int m = 0 , n = 0 ;
  int inistrlen = 0 ;
  int mark = 0 ;

  inistrlen = strlen(inistr);
  printf("len=%d\n" , inistrlen);
/* stupid way1

  for(i = 0 ; i < inistrlen ; i++)
  {
    printf("inistr=%c\n" , inistr[i]);

     judge space key in start pos  
    if(inistr[i]==' '&& j==0 && m==0)
    {
      printf("s1\n");
      j = 1 ;
      m = 1 ;  
    }
    else if((inistr[i]==' ')&&(j==1))
    {
      m++ ;
      printf("s1 , m=%d\n" , m);
    }
    else if((inistr[i]==' ') && (j!=1) && (k==0))
    {
       count spaces 
      n++ ;
      printf("s2 , n=%d\n" , n);
    }
    else if(inistr[i]!=' ')
    {
      n = 0 ;
      k = 0 ;
      j = 0 ;
    }

  }
*/

  // grace way2
  for(i = 0 ; i < inistrlen ; i++)
  {
    if(inistr[i]==' ')
      m++;
    else
      break ;
  }

  for(i = inistrlen-1 ; i >= 0  ; i--)
  {
    if(inistr[i]==' ')
      n++;
    else
      break ;
  }

  printf("s3 , m=%d , n=%d\n" , m , n);
  return (inistrlen - m - n) ;
}

char* grouping(char *inistr)
{
  int i , j = 0 , k = 0 ;
  char *strgroup ;
/*
  strgroup=malloc(sizeof(int)*(reallen(inistr)));

  j = 0 ;
  for(i = 0 ; i < qstrlen ; i++)
  {
    if(inistr[i] != ' ')
    {
      strgroup[j] = inistr[i] ;
      j++;
    }
  }

*/

  for(i = 0 ; i < qstrlen ; i++)
    if(inistr[i] != ' ')
      j++;

  strgroup=malloc(sizeof(int)*j);

  for(i = 0 ; i < qstrlen ; i++)
  {
    if(inistr[i] != ' ')
    {
      strgroup[k] = inistr[i] ;
      k++;
    }
  }

  return strgroup ;
}

int isExistedAll(int spos , int epos)
{
  int i , j , existed ;
  int qstrreallen ;
  char *strgroup ;

  strgroup = grouping(str);
  //printf("strgroup=%s\n",strgroup);

  qstrreallen = strlen(strgroup);

  for(i = 0 ; i < qstrreallen ; i++)
  {
    existed = 0 ;
    for(j = spos ; j <= epos ; j++)
    {
      if(strgroup[i] == text[j])
      {
        existed = 1 ;
      }
    }

    if(existed == 0)
      return 0 ;
  }

  return 1 ;
}

void catching()
{
  while(pEnd < len)
  {
    
    while(!isExistedAll(pBegin , pEnd) && pEnd < len )
    {
      pEnd++ ;
    }

    while(isExistedAll(pBegin , pEnd))
    {
      if(pEnd-pBegin < targetlen)
      {
        targetlen = pEnd-pBegin ;
        aBegin = pBegin ;
        aEnd = pEnd ;
      }
      pBegin++ ;
    }
    //if(pEnd >= len)
      //break;
  }
}

int main()
{
  int i ;
  char *str1 = "  st yr   " ;

  len = strlen(text);
  qstrlen = strlen(str);
  targetlen = len ;
/*
  char *str3 = " ";

  if(str3[0] == ' ')
    printf("s2\n");
*/
  //printf("reallen=%d\n" , reallen(str1));

  //printf("existed=%d\n" , isExistedAll(0,1));
/*
  for(i = 0 ; i < 3 ; i++)
  {
    printf("%c\n" , text[i]);
  }
  printf("%s\n" , text);
*/
  catching();

  printf("query=");
  for(i = aBegin ; i <= aEnd ; i++)
  {
    printf("%c" , text[i]);
  }
  printf("\n");

  printf("string query\n");
  return(1);
}
