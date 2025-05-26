int lengthOfLastWord(char* s) {
    int current=0;
    bool new_word = true;

    for(int i=0;i<strlen(s);i++){
        if(s[i]==' '){
            new_word=true;
        }else{
            if(new_word){
                current=0;
                new_word=false;
            }
            current++;
        }

    }

    return current;
    
}