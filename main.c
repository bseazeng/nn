#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "list.h"
extern int run_list(int argc, char *argv[]);
int run_debug(int argc, char *argv[])
{
        printf("this is a  test\n");
        return 0;
}
typedef struct command_
{
	char *func_name;
	int (*fun)(int argc, char *argv[]);
}CMD;

#define REG_CMD(name){#name,run_##name}
CMD g_cmds[] = 
{
	REG_CMD(list),
	REG_CMD(debug),	
};


int main(int argc,char  *argv[])
{
	if( argc < 2)
	{
		printf("Usage:%s <func>\n",argv[0]);
		return -1;
	}
	int cmd_size=sizeof(g_cmds)/sizeof(g_cmds[0]);
        int i = 0;
        int len = strlen(argv[1]);
        for(i=0;i<cmd_size;i++)
        {
                int tmp_len = strlen(g_cmds[i].func_name);
                if(len == tmp_len && 0 == strncmp(argv[1],g_cmds[i].func_name,len))
                {
                        return g_cmds[i].fun(argc, argv);
                }
        }
        if(i==cmd_size)
        {
		printf("could not find run_%s\n",argv[1]);
        }

	return 0;
}
