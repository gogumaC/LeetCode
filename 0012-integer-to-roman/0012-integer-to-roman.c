int div_n[] = {1,4,5,9,10,40,50,90,100,400,500,900,1000};
char* roman[] = {"I","IV","V","IX","X","XL","L","XC","C","CD","D","CM","M"};

char* intToRoman(int num) {

    char* res=malloc(sizeof(char)*17);
    memset(res,0,sizeof(res));

    for(int i=12;i>=0;i--){
        int count = num/div_n[i];
        num%= div_n[i];
        while(count--){
            strcat(res,roman[i]);
        }
    }
    return res;
    
}