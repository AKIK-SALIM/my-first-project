#include<stdio.h>
#include<string.h>
int main()
{
    int a;
    scanf("%d",&a);
   SyraxNumber(a);
    return 0;
}
void SyraxNumber(int a){
    int c,p;
    c=checkerFunc1(a);
    p=primeChecker(a);

    if(c&&p)
        printf("Yes\n");
    else
        printf("No\n");
}

int checkerFunc1(int a){

     int r,e,o;
     e=0;
     o=0;

     while(a>0){
        r=a%10;
        a=a/10;
        if(r%2==0)
            e=e+r;
        if(r%2!=0)
            o=o+r;
     }
   if(o<e)
    return 1;
   else
     return -1;

}
int primeChecker(int a){
    int i;
    for(i=1;i<=(a/2);i++){
        if(a%i==0)
            return 1;
        else
            return -1;
    }
}
