bool compare_str(char*s1,char*s2,size_t size){
    while(--size){
        if(s1[size]!=s2[size]) return false;
    }
    return true;
}

int lengthOfLongestSubstring(char* s) {
    int len = strlen(s);
    int res=0;
    int start=0;
    for(int i=0;i<len;i++){
        bool has_dup=false;
        for(int j=start;j<i;j++){
            if(s[i]==s[j]){
                has_dup=true;
                start = j+1;
                break;
            }
        }
        if(!has_dup&&res<i-start+1) res=i-start+1;
    }
    return res;
    
}