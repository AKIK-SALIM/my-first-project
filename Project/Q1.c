#include<stdio.h>
#include<string.h>
void UpdateCharacter(char str[],int n,char c );
int main()
{
    char string[100],str[50];
    char c;
    int n,i;
    gets(string);
    scanf("%c",&c);
    i=stringlength(string);
    UpdateCharacter(string,n,c);
    return 0;
}
int stringlength(char str[]){
    int i;
    i=strlen(str);
    return i;
}
void UpdateCharacter(char str[],int n,char c){

     for(int i=0;i<n;i++){
        if(str[i]==' ')
            str[i]=c;
     }

printf("%s",str);

}
