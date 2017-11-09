#include<stdio.h>
#include<signal.h>

static void sighandler(int signo) {
	switch(signo) {
		case SIGINT:
			printf("Your program is stupid and tried to go to a bad place \n");
			exit(1);
			break;
		case SIGUSR1:
			printf("uh the sigid is %d, not sure how to grab a \"parent's\" id\n", getpid());
			break;
	}
}

int main() {
	signal(SIGINT, sighandler);
	signal(SIGUSR1, sighandler);

	while (1) {
		printf("I'm just gonna occupy ur computer real quick, I'm %d \n", getpid());
		sleep(1);
	}
	return 0;
}
