
#define _POSIX_SOURCE
#define _POSIX_C_SOURCE     199309L
#include <iostream>
#include <cstdio>
#include <unistd.h>
using namespace std;
 
static void charatatime(char *);

int main(void)
{
pid_t pid;
for(int i=0;i<100;i++)
{
pid=fork();
if (pid < 0) 
{
cout<<"fork error";
} 
else if (pid == 0) 
	{
	charatatime("output from child\n");
	}
	 else {
	charatatime("output from parent\n");
	}
}

	return(0);
}
static void charatatime(char *str)
{
char *ptr;
int c;
setbuf(stdout, NULL); /* set unbuffered */
for (ptr = str; (c = *ptr++) != 0; )
putc(c, stdout);
}

