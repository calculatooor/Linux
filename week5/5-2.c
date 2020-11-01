#include "ch05.h"
#include "y_or_n_ques.c"

int main()
{
   int answer;
   printf ("1: This is a buffer test program. ");
   // fflush(stdout);
   fprintf(stderr,"2: --test message\n");
   answer = y_or_n_ques("3: Hello, Are you a student?");
   if(answer == 1)      /* 响应回答. */
      printf("4: Hope you have high score.");
   else 
      printf("4: Hope you have good salary.");
   // fflush(stdout); */
   fprintf(stderr,"5: bye!\n");
}
