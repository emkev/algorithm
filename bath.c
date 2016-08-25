/* 2016.08.23 am 02:26 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double total=100, curtotal=20 ;
double invel = 20 , outvel = -10 ;
double full = curtotal / total ;
double time = 2.0 ;
double counttime = 0.0 ;

double cal_curtotal()
{
  return curtotal + (invel + outvel) * time ;
}

double cal_curtotal_2()
{
  int inttime = (int)time ;
  int i ;

  for(i = 0 ; i < inttime ; i++)
  {
    curtotal += invel ;
    curtotal += outvel ;
  }

  return curtotal ;
}

double get_run_time()
{
  int count = 0 ;

  counttime = 0.0 ;

  if( curtotal>total||curtotal<0 )
    return -1 ;

  if(fabs(invel)==fabs(outvel))
  {
     return 0 ;
  }

  if( curtotal == 0 
   && fabs(invel)<fabs(outvel) )
  {
    return 0 ;
  }

  if( curtotal == 100
   && fabs(invel)>fabs(outvel) )
  {
    return 0 ;
  }


  while(1)
  {
    curtotal += invel ;
    curtotal += outvel ;

    counttime += 1 ;
    count++ ;

    if( curtotal >= total 
     || curtotal <= 0 ) 
      break ;

    if(count >= 100) break ;
  }

  return counttime ;
}

int main()
{
  //printf("%f\n" , cal_curtotal_2());

  printf("time = %f\n" , get_run_time());
  printf("curtotal = %f\n" , curtotal) ;

  printf("bath !\n");
  exit(1);
}
