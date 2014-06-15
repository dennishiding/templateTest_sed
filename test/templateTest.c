#include "templateTest_u8.h"

#include <stdio.h>
#include <stdlib.h>

#define ARRAY_LENGTH(a) (sizeof(a)/sizeof(a[0]))

uint8_t data[]={0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20};
uint8_t v1[ARRAY_LENGTH(data)];
uint8_t v2[ARRAY_LENGTH(data)];




int main(int argc,char**argv)
{
  int errval=0;
  uint32_t numV1;
  uint32_t numV2;
  
  uint32_t I_length=0;
  uint32_t I_start=0;
  uint32_t I_select=0;
  uint32_t k;


  for(I_length=1;I_length<25;I_length++)
  {
    for(I_start=0;I_start<I_length;I_start++)
    {
      for(I_select=0;I_select<I_length;I_select++)
      {
        errval=vectorSeparate_u8(I_length,I_start,I_select
                                 ,data,ARRAY_LENGTH(data)
                                 ,v1,ARRAY_LENGTH(v1),&numV1
                                 ,v2,ARRAY_LENGTH(v2),&numV2);
        if(errval)
        {
          printf("%s(L%i):vectorSeparate returned errval=%i at %i,%i,%i\n"
                 ,__FILE__,__LINE__,errval
                 ,I_length,I_start,I_select);
          errval=-__LINE__;
          goto exiterror;
        }
        for(k=0;k<numV2;k++)
        {
          uint32_t temp;
          temp=v2[k];
          temp+=I_length;
          temp+=I_start;
          temp-= (temp/I_length)*I_length;  /* modulus I_length */
          if(temp!=I_select)
          {
            printf("%s(L%i):didn't expect v2[%i]=%i at %i,%i,%i\n"
                   ,__FILE__,__LINE__
                   ,k,v2[k]
                   ,I_length,I_start,I_select);
            errval=-__LINE__;
            for(k=0;k<numV2;k++)
            {
              printf("v2[%i]=%i\n",k,v2[k]);
            }
            for(k=0;k<numV1;k++)
            {
              printf("v1[%i]=%i\n",k,v1[k]);
            }
            goto exiterror;
          }
        }
        errval=vectorSeparate_u8(I_length,I_start,I_select
                                 ,data,ARRAY_LENGTH(data)
                                 ,v1,numV1,&numV1
                                 ,v2,numV2,&numV2);
        if(errval)
        {
          printf("%s(L%i):vectorSeparate returned errval=%i at %i,%i,%i\n"
                 ,__FILE__,__LINE__,errval
                 ,I_length,I_start,I_select);
          errval=-__LINE__;
          goto exiterror;
        }

      }
    }
  }

  
exiterror:
  return(errval);

}
