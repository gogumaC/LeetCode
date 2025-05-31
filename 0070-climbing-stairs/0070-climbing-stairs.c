int climbStairs(int n) {

    if(n<3){
        return n;
    }


    int* step=malloc(sizeof(int)*(n+1));
    memset(step,0,sizeof(int)*(n+1));

    step[1]=1;
    step[2]=2;
    for(int i =3; i<=n;i++){
        step[i]= step[i-1]+step[i-2];
    }

    int res =step[n];
    free(step);
    
    return res;
}

