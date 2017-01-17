#include "types.h"
#include "user.h"
#include "stat.h"

int main() {
	printf(2, "Father pid is %d\n", getpid());
	int i;
	sleep(200);

	int forkID = fork();
	
	if(forkID < 0)
		printf(2, "couldn't fork\n");
	else if(forkID == 0)
		for(i = 0; i < 50; i++)
			printf(2, "process %d is printing for %d time\n", getpid(), i);
	 
	for(i = 0; i < 50; i++)
		printf(2, "process %d is printing for %d time\n", getpid(), i);
	return 0;
}
