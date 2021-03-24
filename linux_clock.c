#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int kbhit() {
   struct timeval tv = { 0L, 0L };
   fd_set fds;
   FD_ZERO(&fds);
   FD_SET(0, &fds);
   return select(1, &fds, NULL, NULL, &tv);
}

static void disp_time() {
    time_t rawt;
    struct tm *t;
    time(&rawt);
    t = localtime(&rawt);
    printf("Time: %02d:%02d:%02d\r", t->tm_hour, t->tm_min, t->tm_sec);
    fflush(stdout);
}

int main( void ) {
    while(1) {
       if(kbhit()) {
           printf("End!\n");
           exit(0);
       }
       disp_time();
       sleep(1);
    }

    return 0;
}
