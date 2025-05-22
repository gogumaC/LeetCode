int strStr(char* haystack, char* needle) {

    int res = 0;
    int flag =false;
    int h_len = strlen(haystack);
    int n_len = strlen(needle);
    for(int i=0 ; i<=h_len-n_len; i++){
        for(int j=0 ; j<n_len; j++){

            if(haystack[i+j]!=needle[j]){
                break;
            }


            if(j==0){
                res = i;
            }
            if(j==n_len-1){
                flag = true;
                break;
            }
        }
        if(flag){
            break;
        }
    }

    return flag?res:-1;
    
}