int maxArea(int* height, int heightSize) {
    int max=0;
    for(int x1=0;x1<heightSize;x1++){
        for(int x2=heightSize-1;x2>x1;x2--){
            int w= x2-x1;
            if(w*height[x1]<max) break;
            int h = (height[x1]>height[x2])?height[x2]:height[x1];
            int area = h*w;
           // printf("%d %d - %d\n",x1,x2,area);
            max = (area>max)?area:max;
        }
    }

    return max;
    
    
}