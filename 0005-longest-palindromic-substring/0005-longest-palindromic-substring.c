bool isPalindrom(char* s, int len){
    for(int i=0;i<len/2;i++){
        if(s[i]!=s[len-i-1]){
            return false;
        }
    }
    return true;
}

char* longestPalindrome(char* s) {

    int max = 0;
    int len = strlen(s);
    int start = 0,end=0;

    for(int i=0;i<len;i++){
        for(int j=i;j<len;j++){
            int size = j-i+1;
            if(size<=max) continue;
            if(isPalindrom(s+i,size)){
                if(max<size){
                    max=size;
                    start=i; end=j;
                }
            }
            
        }
    }

    *(s+end+1) = '\0';

    return s+start;    
}