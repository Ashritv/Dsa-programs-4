#include<stdio.h>
void display(int n,char str[n][100]);
void main()
{
   int n,i;
   char str[n][100];
   printf("Enter the no.of lines\n");
   scanf("%d",&n);
   printf("Enter lines\n");
   for(i=0;i<=n;i++)
   {
     gets(str[i]);

    }
    display(n,str);

}
void display(int n,char str[n][100])
{
    int j,i,c=0,max=0,m;
    for(i=0;i<=n;i++)
    {

       for(j=0;str[i][j]!='\0';j++)
          {
               c++;
          }
          if(c>max)
            {
               max=c;
               m=i;
            }
              c=0;
    }
printf("The longest line is %d\n",m);
puts(str[m]);
}
