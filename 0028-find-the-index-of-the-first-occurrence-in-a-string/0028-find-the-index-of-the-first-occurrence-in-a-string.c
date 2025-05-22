int strStr(char* haystack, char* needle) {

    uint16_t res = 0;
    bool flag =false;
    uint16_t h_len = strlen(haystack);
    uint16_t n_len = strlen(needle);
    for(uint8_t i=0 ; i<=h_len-n_len; i++){
        for(uint8_t j=0 ; j<n_len; j++){

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