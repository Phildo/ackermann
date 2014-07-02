#include <stdlib.h>
#include <stdio.h>

#define msiz 10
#define nsiz 1000000
#define memo *(mem+((nsiz*m)+n))

typedef unsigned long long ull;

ull ack(ull m, ull n, ull*mem, int *err)
{
  if(m >= msiz || n >= nsiz) { fprintf(stderr,"ERROR- OVERFLOW (%llu,%llu)\n",m,n); *err = 1; return 0;}

  ull ans;
  ull t;
  if(memo) return memo;
  else if(m == 0)      ans = n+1;
  else if(n == 0)      ans = ack(m-1,1,mem, err);
  else
  {
    t = ack(m,n-1,mem,err);
    if(*err) return 0;
    ans = ack(m-1,t,mem,err);
  }

  if(*err) return 0;
  memo = ans;

  fprintf(stdout,"ack(%llu,%llu) = %llu\n",m,n,ans);
  return ans;
}

int main(int argc, char **argv)
{
ull m;
ull n;
int err;
ull *mem = calloc(msiz*nsiz,sizeof(ull));
if(!mem) return 1;

for(m = 0; m < 6; m++)
for(n = 0; n < 6; n++)
fprintf(stderr,"ack(%llu,%llu) = %llu\n",m,n,ack(m,n,mem,&err));
free(mem);

return 0;
}

