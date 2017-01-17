#include "types.h"
#include "user.h"
#include "stat.h"

const int fork_num = 10;

void start_proc(int index) {
	int i;
	for(i = 0;i < 1000; i++)
		printf(1, 	"Child %d prints for the %d time\n", index, i);
}

int main() {
	int i;
	for(i = 0; i < fork_num; i++) {
		int fork_id = fork();
		if(fork_id < 0)
			printf(1, "couldn't build child!\n");
		if(fork_id == 0)
			start_proc(i);	
	}
	for(i = 0; i < fork_num; i++) {
		int wtime, rtime;
		getPerformanceData(&wtime, &rtime);
		printf(1, "Child %d -> wtime: %d, rtime: %d, turnaround time: %d\n", wtime, rtime, wtime + rtime);  
	}
	return 0;
}
