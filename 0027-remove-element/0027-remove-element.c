#define SWAP(a,b) do{\
    int tmp = a;\
    a = b;\
    b= tmp;\ 
}while(0)

int removeElement(int* nums, int numsSize, int val) {
    int t = 0;
    int r = numsSize-1;

    while(t<=r){
        if(nums[t]==val){
            nums[t]='_';
            SWAP(nums[t],nums[r]);
            r--;
        }else{
            t++;
        }
    }

    return r+1;
}