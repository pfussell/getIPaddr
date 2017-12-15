/* This is a simple program to display the
ip address on Windows or Linux system. It
checks for the completion of ifconfig and
runs an alt on failure. */

#include <stdio.h>
#include <unistd.h>  // exec func
#include <errno.h> // errno var
#include <string.h> // display errors with strerror()

int main()
{
    if(execl("/sbin/ifconfig", "/sbin/ifconfig", NULL) == -1)
      if(execlp("ipconfig", "ipconfig", NULL) == -1) {
        fprintf(stderr, "Cannont run ipconfig: %s\n", strerror(errno));
        return 1;
      }
    return 0;
}
