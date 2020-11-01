#include "my.h"
int main()
{

        fputs("Welcome to telephone book!\n",stdout);
        fputs("Do you want to input?(y or n)\n",stdout);
        int c,answer;
        c=tolower(fgetc(stdin));
        answer=c;
        while(c !='\n' && c!=EOF)
            c=fgetc(stdin);
        if(answer=='y')
        {
            MyInput();
            do
            {
                getchar();
                fputs("continue?\n",stdout);
                c=tolower(fgetc(stdin));
                answer=c;
                while(c !='\n' && c!=EOF)
                    c=fgetc(stdin);
                if(answer=='y') MyInput();
            }while(answer=='y');
        }
        //判断是否输出数据
        fputs("Do you want to view telephone book?(y or n)\n",stdout);
        c=tolower(fgetc(stdin));
        answer=c;
        while(c !='\n' && c!=EOF)
            c=fgetc(stdin);
        if(answer=='y')
        {
            fputs("Sort by letter from a to z?(y or n)\n",stdout);
            c=tolower(fgetc(stdin));
            answer=c;
            while(c !='\n' && c!=EOF)
                c=fgetc(stdin);
            if(answer=='y'){
                MySort(0);  
            }else{
                MySort(1);
            }
        }
        
    
    return 0;
}