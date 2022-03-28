#include<unistd.h>
#include<sys/types.h>
int main()
{
	int p[2];
	pipe(p);
	printf("read end of pipe:%d \t and write end of pipe : %d\n",p[0],p[1]);
	if(fork())
{
	char s[20];
	printf("\nin parent enter class\n");
	scanf("%s",s);
	write(p[1],s,strlen(s)+1);
}
	else
{
	char buf[20];
	printf("in child..\n");
	read(p[0],buf,sizeof(buf));
	printf("child pro printing..data of the parent process..=%s\n",buf);
}
return 0;
}
