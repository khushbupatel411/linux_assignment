#include<unistd.h>

#include<stdio.h>
#include<fcntl.h>
void main(){
char buff[100];
int fd1,sizes;
fd1=open("free_space.txt",O_CREAT | O_RDWR,777);
sizes=write(fd1,buff,4000);
printf("size=%d",sizes);
close(fd1);
}
