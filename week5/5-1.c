#include "ch05.h"
int main()
{
     printf("Hello!");
    //printf("Hello!\n");//方法一
    //方法二
    /*int i;
    for(i=0;i<1024;i++)
    printf(" ");*/
    //setvbuf(stdout,NULL,_IONBF,0);//方法三
    //fclose(stdout);//方法四
    //fflush(stdout);//方法五
    while(1);
    return 0;
}