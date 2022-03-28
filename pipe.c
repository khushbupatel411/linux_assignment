#include<unistd.h>
main()

{
	int fds[2];
	int res, i;
	char *buff1="aaaaaaaaaaaaaaaaaaaa";
	char *buff2="bbbbbbbbbbbbbbbbbbbb";
	char buf2[40];
	res = pipe(fds);
	if(res==-1)
{
	perror("pipe");
	exit(1);
}
	write(fds[1],buff1,20);
	write(fds[1],buff2,20);
	read(fds[0],buf2,40);
	for(i=0;i<40;i++)
{
	printf("%c",buf2[i]);
}
printf("\n");
}
