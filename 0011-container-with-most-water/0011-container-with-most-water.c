#define MAX(a,b) ((a>b)?a:b)
#define MIN(a,b) ((a<b)?a:b)

int maxArea(int* height, int heightSize) {
    int left=0;
    int right = heightSize-1;
    int max=0;
    while(left<right){
        int h = MIN(height[left],height[right]);
        int area = h*(right-left);

        max = MAX(max, area);
        if(height[left]<height[right]){
            left++;
        }else{
            right--;
        }

    }

    return max;
    
    
}