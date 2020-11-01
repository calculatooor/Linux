#include "ch02.h"
#define BUF_SIZE 8

int main(void)
{
    int fgets_yes;
    struct iobuf{
        char buf[BUF_SIZE];
        char buf2[BUF_SIZE];
    }buffer;
    memset(&buffer,'\0',sizeof(struct iobuf));
    do{
        fputs("use fgets() for 1 gets() for 2:\n",stdout);
        fgets_yes=fgetc(stdin);
        getchar();
        if(fgets_yes=='1')
        {
            fputs("input string :\n",stdout);
            fgets(buffer.buf,BUF_SIZE,stdin);
            fprintf(stdout,"fgets() get string \"%s\"\n",buffer.buf);
            while(buffer.buf[strlen(buffer.buf)-1]!='\n')
            {
                fgets(buffer.buf,BUF_SIZE,stdin);
                fprintf(stdout,"fgets() get string \"%s\"\n",buffer.buf);
            }
            fprintf(stdout,"buffer.buf2 is \"%s\"\n",buffer.buf2);
        }
        
        if(fgets_yes=='2')
        {
            fputs("input string :\n",stdout);
            gets(buffer.buf,BUF_SIZE,stdin);
            fprintf(stdout,"gets() get string \"%s\"\n",buffer.buf);
            fprintf(stdout,"buffer.buf2 is \"%s\"\n",buffer.buf2);
        }

        
        fputs("continue (y or n) :\n",stdout);
        fgets_yes=tolower(fgetc(stdin));
        getchar();
    }while(fgets_yes=='y');
}