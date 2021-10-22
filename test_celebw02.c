#include "types.h"
#include "user.h"

#define WNOHANG 1

int main(int argc, char *argv[]) {

	printf(1, "\nTest Program CELEBW02");

	int pid, retpid;
	int status;

	if ((pid = fork()) < 0) {
		// error
	}
	else if (pid == 0) {
		sleep(5);
		exit(1);
	}
	else do {
		if ((retpid = waitpid(pid, &status, WNOHANG)) == -1) {
			//error printf(2, "error")
		
		}
		else if (retpid == 0) {
			printf(1, "\nChild is still running");
			sleep(1);
		}
		else {
			printf(1, "\nChild exited with status of %d", status);
		}
	}
	while (retpid == 0);
	return 0;
}

