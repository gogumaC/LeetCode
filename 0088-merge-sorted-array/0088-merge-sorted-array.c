void merge(int* nums1, int nums1Size, int m, int* nums2, int nums2Size, int n) {

    int* tmp = malloc((m+n)*sizeof(int));

    int i1=0,i2=0,i=0;
    while(i<m+n){

        //printf("i %d/%d i1 %d/%d i2 %d/%d\n",i,m+n,i1,m,i2,n);
        if(i1<m && (i2==n || nums1[i1]<nums2[i2]) ) {
            tmp[i]=nums1[i1];
            //printf("1 : %d <-%d\n",i,nums1[i1]);
            i1++;
        }else if(i2<n && (i1==m || nums2[i2]<=nums1[i1])){
            tmp[i]=nums2[i2];
            //printf("2 : %d <-%d\n",i,nums2[i2]);
            i2++;
        }

        i++;
    }

    memcpy(nums1,tmp,(m+n)*sizeof(int));
    
}