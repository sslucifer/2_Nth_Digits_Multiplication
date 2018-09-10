#include<iostream>
#include<string.h>
#define MAX 1000
using namespace std;

void reverse(char *str1, char *str2)
{
    int len=strlen(str1);
    for(int l=0;l<len;l++)
      str2[l]=str1[len-l-1];
    str2[len]='\0';
}
void mul(char *num1,char *num2,char *result)
{
    int n1,n2,r=0,hold,res,n1len,n2len,tlen;
    char num1r[MAX],num2r[MAX],temp[MAX];

    n1len=strlen(num1);
    n2len=strlen(num2);
    reverse(num1,num1r);
    reverse(num2,num2r);
    tlen=n1len+n2len;
    for(n1=0;n1<=tlen;n1++)
      temp[n1]='0';
    temp[n1]='\0';
    for(n2=0;n2<n2len;n2++)
    {
        hold=0;
        for(n1=0;n1<n1len;n1++)
        {
            res=(num1r[n1]-'0')*(num2r[n2]-'0') + hold+(temp[n1+n2]-'0');
            temp[n1+n2]=res%10+'0';
            hold=res/10;
            if(n1+n2>r)
              r=n1+n2;
        }
        while(hold!=0)
        {
            res=hold+temp[n1+n2]-'0';
            hold=res/10;
            temp[n1+n2]=res%10+'0';
            if(r<n1+n2)
              r=n1+n2;
            n1++;
        }
    }
    for(;r>0 && temp[r]=='0';r--);
      temp[r+1]='\0';
    reverse(temp,result);
}
int main()
{
    char num1[MAX],num2[MAX],result[MAX];
    int len;
    cout<<"\n Enter No.1: ";
    gets(num1);
    cout<<"\n Enter No.2: ";
    gets(num2);
    mul(num1,num2,result);
    len=strlen(result);
    cout<<"\n Answer: ";
    for(int i=0;i<len;i++)
      cout<<result[i];
    return 0;
}
