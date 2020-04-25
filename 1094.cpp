#include <stdio.h>
int check(int a);
int st = 128;
int cnt = 0;
int main()
{
   int num;
   scanf("%d", &num);
   for (;;)
   {
      num = check(num);
      if (num == 0)break;
   }
   printf("%d", cnt);
}
int check(int a)
{
   st = st / 2;
   if (a - st >= 0)
   { 
      a = a - st;
      cnt++;
   }
   return a;
}