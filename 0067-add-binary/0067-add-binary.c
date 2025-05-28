char* addBinary(char* a, char* b) {

    int16_t a_idx = strlen(a)-1;
    int16_t b_idx = strlen(b)-1;

    uint16_t res_idx = (a_idx>b_idx?a_idx:b_idx)+1;
    char* res = (char*)malloc(res_idx+2);

    //printf("a %d b %d res %d\n",a_idx,b_idx,res_idx);
    res[res_idx+1]='\0';
        printf("size %d\n",strlen(res));
    memset(res,'0',res_idx+1);
    memcpy(res+(res_idx-a_idx-1)+1,a,a_idx+1);
    free(a);

    printf("\n");
    bool add=false;
    while(res_idx>=0){
           // printf( "res %d b %d add %d\n",res_idx,b_idx,add);

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
        //printf("res: %c , r %d\n",res[res_idx],r);
        if(!add&& b_idx<0){
            break;
        }
       
        res_idx--;

    }
    free(b);
    //printf("d %d\n",res_idx);
    return res_idx>0? res+1:res;
    
}