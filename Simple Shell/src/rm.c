
//program for rm command in shell

#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>

int main( int arg, char *argvs[] )
{
	/*
	char inp[256];
	while(1)
	{
		printf("ashell:~$ ");
		fgets (inp, 256, stdin);
	
		char *args[100];
		int i=0;
		args[i] = strtok(inp," ");
		while( args[i]!=NULL )
		{
   			args[++i] = strtok(NULL," ");
		}
	*/

		int v = 0;
		int i = 0;
		int z2 = 0;
		while ( argvs[z2] != NULL )
		{
			int r1 = strncmp(argvs[z2],"-i",2);
			int r2 = strncmp(argvs[z2],"-v",2);
			if ( r1 == 0  )
			{
				i = 1;
				break;
			}
			if ( r2 == 0  )
			{
				v = 1;
				break;
			}
			z2++;
		}
	
		if ( v == 1 && i == 0 )
		{
			strtok(argvs[2],"\n");
			char *name = argvs[2];
			//printf("%s \n",name);
			int r = remove(name);
			if ( r != 0 )
			{
				printf("Error Removing File \n");
				return ;
			}
			printf("removed %s \n",name);
		}
		else if ( i == 1 && v == 0 )
		{
			strtok(argvs[2],"\n");
			char *name = argvs[2];
			printf("rm: remove regular empty file %s ?",name);
			char final[256];
			fgets (final, 256, stdin);
			//scanf("%s ", final);
			int yes = 0;
			int no = 0;
			if ( strncmp(final,"y",1) == 0 || strncmp(final,"Y",1) == 0 )
			{
				yes = 1;
			}
			if ( strncmp(final,"n",1) == 0 || strncmp(final,"N",1) == 0 )
			{
				no = 1;
			}
			if ( yes == 1 )
			{
				int r = remove(name);
				if ( r != 0 )
				{
					printf("Error Removing File \n");
					return ;
				}
			}

		}
		else
		{
			char *name = argvs[1];
			//printf("%s \n",name);
			int r = remove(name);
			if ( r != 0 )
			{
				printf("Error Removing File \n");
				return ;
			}
		}

	//}
}
