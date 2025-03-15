char* longestCommonPrefix(char** strs, int strsSize) {
    if(strsSize==0){
        return 0;
    }
    char* common = strs[0];
    for(int i =0; i<strsSize; i++){
        while(*common){
            if(strstr(strs[i],common)!=strs[i]){
                common[strlen(common)-1]='\0';
            }else{
                break;
            }
        }
        
    }
    return common;
}