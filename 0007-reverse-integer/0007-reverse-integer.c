
#define SWAP(a,b) do{int tmp=a; a=b; b=tmp;}while(0)

char buf[12];

int reverse(int x){
    int c =sprintf(buf,"%d",x);
    
    int left=(buf[0]=='-')?1:0; int right = c-1;
    while(left<right){
        //printf("%c %c\n",buf[left],buf[right]);
        SWAP(buf[left],buf[right]);
        left++;
        right--;
    }


    long res = strtol(buf,NULL,10);
    return (res<=INT_MAX && res>=INT_MIN)?res:0;

}