#include<stdio.h>
#include<unistd.h>
int main(int argc, char**argv)
{
    int rc = fork();
    int child = 0;
    switch(rc){
        case -1:
            /*
             * This only happens if the system is severly low on resources,
             * or the user's process limit has been exceeded*/
            fprintf(stderr,"Unable to fork!\n");
            return 1;
            break;
        case 0:
            printf("I am the child! I am born\n");
            child++;
            break;
        default:
            printf("I am the parent!, Going to sleep and now wait()ing\n");
            sleep(60);
    }
    printf("%s exiting\n", (child ? "child": "parent"));
    return 0;
}
