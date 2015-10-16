#include <stdlib.h>
#include <stdio.h>
#include <time.h>


static double diff_in_second(struct timespec t1, struct timespec t2)
{
    struct timespec diff;
    if (t2.tv_nsec-t1.tv_nsec < 0) {
        diff.tv_sec  = t2.tv_sec - t1.tv_sec - 1;
        diff.tv_nsec = t2.tv_nsec - t1.tv_nsec + 1000000000;
    } else {
        diff.tv_sec  = t2.tv_sec - t1.tv_sec;
        diff.tv_nsec = t2.tv_nsec - t1.tv_nsec;
    }
    return (diff.tv_sec + diff.tv_nsec / 1000000000.0);
}

int main()
{
	double total_time = 0;
	double endtime = 0;
    struct timespec start, end;
    char c_arr[]={'c', 'f', 'j', 'p', 'v'};
    char temp;
    for(int i = 0; i < 10000; i++){
    	clock_gettime(CLOCK_REALTIME, &start);

        temp = 'a';
        while(temp++ <= 'z'){

#if defined(ITER)
            smallest_character(c_arr, temp);
#endif

#if defined(REC)
            smallest_character(c_arr, temp, 0);
#endif      
        }

        clock_gettime(CLOCK_REALTIME, &end);
        endtime =  diff_in_second(start, end);
        total_time += endtime;
    }

    FILE *fp;
    fp = fopen("time.dat","a");
    fprintf(fp, "Method\tTime\n");
#if defined(ITER)
    fprintf(fp, "iterative\t%.9lf\n",total_time);
#endif

#if defined(REC)
    fprintf(fp, "recursive\t%.9lf\n",total_time);
#endif    
	fclose(fp);
	printf("Total execution time is %.9lf\n", total_time);
    return 0;
}
