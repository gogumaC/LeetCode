int climbStairs(int n) {

    if(n<3){
        return n;
    }

    int step1=1;
    int step2=2;
    int current=0;

    for(int i =3; i<=n;i++){
        current=step1+step2;
        step1=step2;
        step2=current;
    }

    return current;
}

