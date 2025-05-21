int removeElement(int* nums, int numsSize, int val) {
    int t = 0;
    int r = numsSize-1;

    while(t<=r){
        if(nums[t]==val){
            nums[t]=nums[r];
            r--;
        }else{
            t++;
        }
    }

    return r+1;
}