#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <sys/stat.h>
#include <time.h>
#include <sys/types.h>
#include <dirent.h>


int main(){
  int b = 0;
  printf("Forking twice!\n");
  int a = fork();
  if(a){
    b = fork();
  }
  else{
    b = 1;
  }
  if(!(a && b)){
    printf("pid: %d\n",getpid());
    srand(time(NULL) + a);
    int sleeptime = rand() % 15 + 5;
    printf("sleeping for %d seconds...\n",sleeptime);
    sleep(sleeptime);
    printf("Process %d is done!\n", getpid());
    return sleeptime;
  }
  int status;
  int childpid = waitpid(-1,&status,0);
  printf("Child %d finished: slept for %d seconds.\n",childpid,WEXITSTATUS(status));

  printf("Parent signing off.\n");
    
  return 0;
}
