#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
extern int test_list(int argc, char *argv[]);

int main(int argc,char  *argv[])
{
	if( argc < 2)
	{
		printf("Usage:%s <func>\n",argv[0]);
		return -1;
	}
		
	return 0;
}
