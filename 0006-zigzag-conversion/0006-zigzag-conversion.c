#define MAX 3000
static char ns[MAX]={0};
static int li[MAX]={0};

int get_row_st_idx(int row,int numRows){

    int unit = MAX/(2*(numRows-1));
    if(unit==0) unit++;
    int res=0;
    if(row==0){
        res= 0;
    }else if(row==1){
        res= unit;
    }else if(row==numRows){
        res= MAX-unit;
    }else{
        res= 2*unit*row - unit;
    }
    return res;
}
char* convert(char* s, int numRows) {

    if(numRows==1) return s;

    for(int i=0;i<numRows;i++){
        li[i]=get_row_st_idx(i,numRows);
       // printf("row %d - idx %d\n",i,li[i]);
    }


    int set= 2*numRows-2;
    
    for(int i=0;i<strlen(s);i++){
        int idx=i%set;
        if(idx<numRows){
            int row = idx;
            ns[li[row]]=s[i];
            li[row]++;
        //    printf("1-idx %i - val %c - row %d - saved %d\n",i,s[i],row,li[row]-1);
        }else{
            int row = set-idx;
            ns[li[row]]=s[i];
            li[row]++;
           // printf("2-idx %i - val %c - row %d - saved %d\n",i,s[i],row,li[row]-1);
        }
    }
    int t_idx=0;
    for(int i=0;i<numRows;i++){
        for(int j=get_row_st_idx(i,numRows);j<li[i];j++){
            s[t_idx++]=ns[j];
        }
    }

    return s;
    
}