int romanToInt(char* s) {

    int size = strlen(s);

    char str[] = {'I', 'V', 'X', 'L', 'C', 'D', 'M'};
    int map[] = {1,5,10,50,100,500,1000};
    int str_size = sizeof(str);
    

    int current =0;
    char tmp[3]; 
    int sum =0 ;
    while(current<size){

        bool found = false;
        if(current<size-1){
            memcpy(tmp,s+current,2);
            tmp[2] = '\0';
            if(strcmp(tmp,"IV")==0){
                sum+=4;
                found=true;
            }
            else if(strcmp(tmp,"IX")==0){
                sum+=9;
                found=true;
            }
            else if(strcmp(tmp,"XL")==0){
                sum+=40;
                found=true;
            }
            else if(strcmp(tmp,"XC")==0){
                sum+=90;
                found=true;
            }
            else if(strcmp(tmp,"CD")==0){
                sum+=400;
                found=true;
            }
            else if(strcmp(tmp,"CM")==0){
                sum+=900;
                found=true;
            }
        }
        
        if(found)
        {
            current+=2;
        }
        else 
        {
            for(int i=0;i<str_size;i++){
                if(s[current]==str[i]){
                    sum+=map[i];
                    current++;
                    break;
                }
            } 
        }
    }
    return sum;
}