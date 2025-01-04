#include <math.h>

bool isPalindrome(int x) {

    if(x & 0x80000000)
    {
        //printf("Minus\n");
        return false;
    }
    else
    {
        //find biggest digit
        int xx=x;
        int idx=0;
        do
        {
            idx++;
            xx/=10;
        }while(xx);

        if(idx==1)
        {
            return true;
        }

        int cur_idx = idx;

        while(x!=0)
        {
            int tmp= pow(10,cur_idx-1);
            int a = x%10;
            int b = x/tmp;
            //printf("%d %d\n",a,b);
            if(a!=b)
            {
                return false;
            }
            cur_idx-=2;
            x%=tmp;
            x/=10;
            
           // printf("%d\n",x);
        }




    }

   return true;
}