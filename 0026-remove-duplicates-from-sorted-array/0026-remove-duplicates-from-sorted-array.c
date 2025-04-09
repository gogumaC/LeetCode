int removeDuplicates(int* nums, int numsSize) {
    
    int target=-1;
    int current =0;

    while(current<numsSize){
        if(target<0 || nums[target]!=nums[current]){
            nums[++target]=nums[current++];
        }else{
            current++;
        }
    }
    
    return (target+1);
}