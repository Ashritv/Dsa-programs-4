#include<stdio.h>
#include<Stdlib.h>
#include<string.h>

int Length(char *strings)
{
    int i;
    for(i=0;strings[i]!='\0';++i);

    return i;
}
void read_linesFromFile(char lines[10][100], int *num_lines)
{
    FILE *file = fopen("input.txt","r");
    if (file == NULL)
    {
        printf("Could not open file input.txt");
        return;
    }
    char line[100];
    while (*num_lines < 10 && fgets(line, 100, file) != NULL)
    {
        //fprintf(file,"%s ",*num_lines);
        strncpy(lines[*num_lines], line, 100);
        (*num_lines)++;
    }
    fclose(file);
}

/*void write_linesFromFile(char lines[10][100], int *num_lines)
{
    FILE *file = fopen("input.txt","w");
    char line[100];

    /*while (*num_lines < 10 && fgets(line, 100, file) != NULL)
    {
        //fprintf(file,"%s ",*num_lines);
        strncpy(lines[*num_lines], line, 100);
        (*num_lines)++;
    }
    fclose(file);
}*/
void search(char *pat,char *txt)
{
    int n=Length(txt);
    int m=Length(pat);

    for(int i=0;i<n-m;i++)
    {
        int j;
        for( j=0;j<m;j++)
        {
            if(txt[i+j]!=pat[j])
                break;
        }
            if(j==m)
                printf("%s\n",txt);

    }
}
int main()
{
 char lines[10][100];
    int num_lines = 0;
    char pat[10];//="ould";
    printf("Reading from the file\n");
    read_linesFromFile(lines, &num_lines);
    printf("Enter the word you want to search in the file:");
    printf("%s",pat);
    scanf("%s",pat);
        for(int i=0;i<10;i++)
    {
        search(pat,lines[i]);
    }
    printf("Enter the word you want to replace:");
    scanf("%s",pat);

}
