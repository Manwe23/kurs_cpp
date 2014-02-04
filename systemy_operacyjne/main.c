#include <stdio.h>	
#include <stdlib.h>     
#include <unistd.h>	
#include <time.h>	
#include <sys/types.h>                                                                   
#include <sys/ipc.h>   
#include <sys/sem.h>	

union semun {
    int val;
    struct semid_ds *buf;
    ushort *array;
};

#define NUM_LOOPS	10	
int main(int argc, char* argv[])
{
    int sem_set_id;	     
    union semun sem_val;     
    int child_pid;	     
    int i;		   
    struct sembuf sem_op;   
    int rc;		     
    struct timespec delay;
    int count;
    if ( argc < 4 )
    {
        printf("This program requires 4 arguments at least!\n");
	return 0;
    }
    int customerDelayFrom = *argv[1] - 48;
    int customerDelayto = *argv[2] - 48 ;
    int producerDelayFrom = *argv[3] - 48 ;
    int producerDelayto = *argv[4] - 48 ;
    
    sem_set_id = semget(IPC_PRIVATE, 2, 0600);
    if (sem_set_id == -1) {
	perror("main: semget");
	exit(1);
    }
    printf("semaphore set created, semaphore set id '%d'.\n", sem_set_id);

    sem_val.val = 0;
    rc = semctl(sem_set_id, 0, SETVAL, sem_val);
    child_pid = fork();
    switch (child_pid) {
	case -1:	
	    perror("fork");
	    exit(1);
	case 0:		
	    for (i=0; i<NUM_LOOPS; i++) {
		sem_op.sem_num = 0;
		sem_op.sem_op = -1;
		sem_op.sem_flg = 0;
		semop(sem_set_id, &sem_op, 1);
		printf("consumer: '%d'\n", i);
		if (! (i % 3))
		{
			sem_op.sem_num = 1;
			sem_op.sem_op = 1;
			sem_op.sem_flg = 0;
			semop(sem_set_id, &sem_op, 1);
		}
		if (customerDelayto == customerDelayFrom)
			sleep(customerDelayFrom);
		else
                	sleep(customerDelayFrom + (rand() % (customerDelayto - customerDelayFrom)));
	    }
	    break;
	default:	
	    for (i=0; i<NUM_LOOPS; i++)
            {
		printf("producer: '%d'\n", i);
		fflush(stdout);
		sem_op.sem_num = 0;
		sem_op.sem_op = 1;
		sem_op.sem_flg = 0;
		semop(sem_set_id, &sem_op, 1);
		if (producerDelayFrom == producerDelayto)
			sleep(producerDelayto);
		else
			sleep(producerDelayFrom + (rand() % (producerDelayto - producerDelayFrom)));
		if (! (i % 3))
                {
                        sem_op.sem_num = 1;
                        sem_op.sem_op = -1;
                        sem_op.sem_flg = 0;
                        semop(sem_set_id, &sem_op, 1);
                }
	    }
	    break;
    }

    return 0;
}
