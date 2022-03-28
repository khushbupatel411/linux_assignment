#include<unistd.h>
#include<sys/types.h>
int main()
{

	int i,fd[2],nbytes;
	pid_t childpid;
	char string[]="linux kernel techology..\n";
	char readbuffer[50];
	
	pipe(fd);


if((childpid=fork())==-1)
{
	perror("fork");		
	exit(1);
}
if(childpid==0)
{
	close(fd[0]);
	write(fd[1],string,(strlen(string)+1));
	exit(0);
}
else
{
	close(fd[1]);
	nbytes=read(fd[0],readbuffer,sizeof(readbuffer));
	for(i=0;readbuffer[i];i++)
	{
		if(readbuffer[i] >= 'a')
		readbuffer[i]=readbuffer[i]-32;
	}
	
	printf("received string==%s",readbuffer);
}
}
