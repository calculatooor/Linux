#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
int main(void)
{
	FILE* fp=fdopen(1,"w+");
	fprintf(fp,"fp =%s \n","hello");
	fclose(fp);
	return 0;

}

