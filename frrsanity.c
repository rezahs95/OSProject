
#include "types.h"
#include "user.h"

int main(void) {

	int i;
	for( i = 0; i < 10; i++)
	{
		int forkID = fork();
		if(forkID < 0)
		{
			printf(3, "couldn't fork!\n");
			exit();
		}
		else if(forkID == 0)
		{
			int j;
			printf(3, "baba basse dg!\n");
			for(j = 0; j < 1000; j++);
			exit();
				
		}
	}
	
	for(i = 0; i < 10; i++)
		wait();
	exit();
}
