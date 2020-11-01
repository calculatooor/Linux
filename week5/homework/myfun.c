#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#define err_exit(MESSAGE) (                \
    perror(MESSAGE),                       \
    exit(1)                                \
)

typedef struct USER{
    int id;
    char name[8];
    char htel[12];
    char tel[12];
};

int MyInput(void)
{
    struct USER user;
    printf("input user like (001 Tom 87893 19909722736) :\n");
    scanf("%d%s%s%s",&user.id,user.name,user.htel,user.tel);
    MyRanddat(user);
    MySave(user);
    return 0;
}

int MySave(struct USER user)
{
    FILE *stream;
    stream=fopen("user.dat","a");
    char str[40]="";
    sprintf(str,"%d",user.id);
    //strcat(str,user.id);
    strcat(str,"\t");
    strcat(str,user.name);
    strcat(str,"\t");
    strcat(str,user.htel);
    strcat(str,"\t");
    strcat(str,user.tel);
    strcat(str,"\n");
    
    fputs(str,stream);
    fclose(stream);
    
    MyOutput(user);
    return 0;
}


int MyCompar(const void *a,const void *b)
{
    int i=0;
    char *stra=((struct USER*)a)->name;
    char *strb=((struct USER*)b)->name;
    while(stra[i]!='\0'&&strb[i]!='\0')
    {
        if(stra[i]>strb[i])
        {
            return 1;
        }
        if(stra[i]<strb[i])
        {
            return -1;
        }
        i++;
    }
    if(stra[i]=='\0'&&strb[i]=='\0') return 0;
    if(stra[i]=='\0'&&strb[i]!='\0') return -1;
    if(stra[i]!='\0'&&strb[i]=='\0') return 1;
}

int MySort(int way)
{
    FILE *stream=fopen("user.dat","r");
    //测有多少条数据
    int sum=0;
    char c=fgetc(stream);
    while(!feof(stream))
    {
        if(c=='\n') sum++;
        //printf("now user:%d\n",sum);
        c=fgetc(stream);
    }
    //printf("all user:%d\n",sum);
    rewind(stream);
    
    
    //将数据读到数组中
    struct USER users[sum];
    int i=0;
    for(i=0;i<sum;i++)
    {
        char *str;
        size_t n=40;
        str=(char*)malloc(40);
        getline(&str,&n,stream); 
        //printf("%ld %s\n",n,str);
        sscanf(str,"%d %s %s %s",&users[i].id,users[i].name,users[i].htel,users[i].tel);
    }
    qsort(users,sum,sizeof(struct USER),MyCompar);
    if(way>0)
    {
        for(i=sum-1;i>=0;i--) MyOutput(users[i]);
    }else{
        for(i=0;i<sum;i++) MyOutput(users[i]);
    }

    
    return 0;
}

int MyRanddat(struct USER user)
{
    if(user.name[0]>'Z'||user.name[0]<'A')
        err_exit("The name must begin with a capital letter.");
    int i=0;
    while(user.name[i]!='\0')
    {
        i++;
        if(i>8) err_exit("The maximum number of names is 8.");
    }
    return 0;
}

int MyOutput(struct USER user)
{
    // printf("all user as follow\n");
    // FILE *stream;
    // stream=fopen("user.dat","r");
    // struct USER * users;
    // int i=0;
    // int c;
    // while(c=fgetc()!="\t"&&c!="\n")
    // {
    //         user.id=10*user.id+c;
    // }
    printf("%d\t%s\t%s\t%s\n",user.id,user.name,user.htel,user.tel);
    return 0;
}