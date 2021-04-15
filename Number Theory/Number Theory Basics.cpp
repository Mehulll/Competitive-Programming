int power(int a,int b,int M){
    int result=1;
    while(b>0)
    {
        if(b % 2 ==1)
            result=(result * a)%M;
        a=(a*a)%M;
        b=b/2;
    }
    return result;
}
