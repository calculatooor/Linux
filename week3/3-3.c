#include <stdio.h>
//#include <sys/types.h>
//#include <sys/stat.h>
//#include <fcntl.h>
//#include <unistd.h>
#include <string.h>
int main(void)
{
	FILE* fd =fopen("./ftest.txt","w");
	char buf[80];
	//scanf('%s',buf);
	fgets(buf,sizeof(buf),stdin);
	printf("\nthe string is %s",buf);
	fwrite(buf,1,sizeof(buf),fd);
	memset(buf,0,sizeof(buf));
	fclose(fd);
	return 0;
}
