int myAtoi(char* s) {

    long res=0;
    bool flag=false;
    bool started=false;


    for(int i=0;i<strlen(s);i++){
        // printf("%c ",s[i]);
        if(!started&&s[i]==' '){
            continue;
        }else if(!started&&s[i]=='+'){
            started=true;
            continue;
        }else if(!started&&!flag&&s[i]=='-'){
            started=true;
            flag = true;
            // printf("FLAG"//////);
            continue;
        }else if(s[i]>='0' && s[i]<='9'){
            int num=(s[i]-'0');
            res*=10;
            res+=(flag?(-1*num):num);
            if(res>INT_MAX ||res<INT_MIN) break;
            // printf("%d += %d\n",res,(flag?(-1*num):num));
        started=true;
        }else{
            break;
        }


    }

    res = (res>INT_MAX)?INT_MAX:res;
    res = (res<INT_MIN)?INT_MIN:res;

    return (int)res;
    
}