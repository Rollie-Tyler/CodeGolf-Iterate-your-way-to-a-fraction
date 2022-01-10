#include <stdio.h>

#define SIZE_SEQ 30

int n = 8;
int d = 9;
unsigned char seq[SIZE_SEQ];

typedef struct nbFrac{
  int n;
  int d;
} nbfrac;

nbfrac invf(nbfrac input)
{
  nbfrac result;

  result.n = input.n - input.d;
  result.d = input.d;

  return result;
}

nbfrac invg(nbfrac input)
{
  nbfrac result;

  result.n = input.d;
  result.d = -input.n;

  return result;
}

int main(void)
{
  nbfrac n1, n2;
  int step = 0;

  if(d < 0)
  {
    n1.n = -n;
    n1.d = -d;
  }
  else {
    n1.n = n;
    n1.d = d;
  }
  n2.n = n;
  n2.d = d;
  //printf("n1.n = %d - n1.d = %d\r\n", n1.n, n1.d);

  while(n1.n != 0 && step < SIZE_SEQ)
  {
    if(n1.n < 0)
    {
      n2 = invg(n1);
      printf("g");
      seq[step] = 'g';
    }
    else {
      n2 = invf(n1);
      printf("f");
      seq[step] = 'f';
    }

    //printf("n2.n = %d - n2.d = %d - step = %d - seq = %c \r\n", n2.n, n2.d, step, seq[step]);
    n1.n = n2.n;
    n1.d = n2.d;
    step++;
    //printf("n1.n = %d - n1.d = %d - n1.s = %d \r\n", n1.n, n1.d, n1.s);
  }
/*
  for(int i=0; i<SIZE_SEQ;i++)
  {
    if(seq[i] != 0)
      printf("%c ", seq[i]);
  }
*/
  return 0;
}
