int searchInsert(int* nums, int numsSize, int target) {

    //binary search

    int left,mid=0;
    int right = numsSize-1;
    
    while(left<=right){
        mid = left + (right -left)/2;
        if(mid>=numsSize){
            break;
        }
        //printf("left:%d right:%d mid:%d\n",left,right,mid);
        if(nums[mid]==target){
            left = mid;
            break;
        }
        else if(nums[mid]<target){
            left = mid+1;
        }else{
            right = mid-1;
        }
    }

    return left;
    
}