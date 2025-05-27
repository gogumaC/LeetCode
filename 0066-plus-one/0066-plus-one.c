/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* plusOne(int* digits, int digitsSize, int* returnSize) {

    *returnSize = digitsSize;
    int* res=digits;
    for(int i=digitsSize-1;i>=0;i--){
        printf("%d\n",i);
        if(digits[i]==9){
            digits[i]=0;
            if(i==0){
                res = (int*)malloc(sizeof(int)*(digitsSize+1));
                memcpy(res+1,digits,sizeof(int)*digitsSize);
                res[0]=1;
                free(digits);
                (*returnSize)++;
            }
            
        }else{
            digits[i]++;
            break;
        }
    }


    return res;
    
}