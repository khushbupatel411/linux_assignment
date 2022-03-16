#include<stdio.h>
#include<fcntl.h>

#include<unistd.h>
#include<sys/stat.h>
#include<sys/types.h>
#include<time.h>

int main( )
{
struct stat st;// st.st_size st.st_ino st_blksize
struct tm dt;
int fd;
stat("array.c", &st);//
printf("File size =%lu\n",(st.st_size));
printf("File inode =%lu \n", st.st_ino);
printf("size disc of blocks =%lu \n",st.st_blksize);
printf("\n\n");
printf("No. of 512 byte blocks allocated = %d\n",st.st_blocks);
printf("Permissions = %lo\n",st.st_mode);
printf("Owner id = %lu\n",st.st_uid);
printf("Group id = %lu\n",st.st_gid);
printf("Last modified time = %s\n",ctime(&st.st_mtime));
printf("Last accessed time = %s\n",ctime(&st.st_atime));
printf("\n");
close(fd);
return 0;

}
