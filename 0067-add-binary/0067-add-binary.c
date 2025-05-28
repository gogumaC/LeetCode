char* addBinary(char* a, char* b) {

    int16_t a_idx = strlen(a)-1;
    int16_t b_idx = strlen(b)-1;

    uint16_t res_idx = (a_idx>b_idx?a_idx:b_idx)+1;
    char* res = (char*)malloc(res_idx+2);

    res[res_idx+1]='\0';
    memset(res,'0',res_idx+1);
    memcpy(res+(res_idx-a_idx-1)+1,a,a_idx+1);
    free(a);

    bool add=false;
    while(res_idx>=0){

        int r = res[res_idx]-'0';

        if(add) {
            r++;
            add=false;}
        if(b_idx>=0){

            int bb =b[b_idx]-'0';
             r+=bb; 
            b_idx--;
        } 
        if(r>=2){
                r%=2;
                add=true;
            }
        res[res_idx]='0'+r;
        if(!add&& b_idx<0){
            break;
        }
       
        res_idx--;

    }
    free(b);
    return res_idx>0? res+1:res;
    
}