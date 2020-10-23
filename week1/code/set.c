#include "ch01.h"
int main()
{
    char hostname[MAXHOSTNAMELEN];
    size_t length=MAXHOSTNAMELEN;
    scanf("%s",hostname);
    sethostname(hostname,length);
}