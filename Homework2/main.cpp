//
//  main.cpp
//  ParallelComputing
//
//  Created by Omar Mohammed on 5/31/20.
//  Copyright © 2020 Omar Mohammed. All rights reserved.
//

#include <iostream>
#include <omp.h>
#include <unistd.h>
#include <limits>
#include <stdio.h>
typedef std::numeric_limits<double> dbl;
int main (int argc, char *argv[])
{
    long num_steps = 100000000;
    int PAD=8;
    int NUM_THREADS =2;
    if(argc==3)
    {
        num_steps=(long) argv[0];
        NUM_THREADS=atoi(argv[1]);
        PAD=atoi(argv[2]);
    }
    
       double step;
       double n;
       int fd[2];
       pid_t pid;
       char line[255];
       int i, nthreads; double pi, sum[NUM_THREADS][PAD];
       step = 1.0/(double) num_steps;
       omp_set_num_threads(NUM_THREADS);
       std::cout.precision(dbl::max_digits10)
       if (pipe(fd) < 0) {
           printf("Error while call function pipe\n");
           return 1;
       }

       if ((pid = fork()) < 0) {
           printf("Error while call function fork\n");
           return 1;
       } else if (pid > 0) {
           close(fd[0]);
           #pragma omp parallel
               { int i, id,nthrds;
                   
                  
                   id = omp_get_thread_num();
                   nthrds = omp_get_num_threads();
                   
                   if (id == 0) threadNumbers = nthrds;
                
                   #pragma omp parallel for
                   
                   for (i=0;i< num_steps; i+=nthrds)
                       
                   {
                       
                       x = (i+0.5)*step;
                       #pragma omp critical
                       sum[id][0] += 4.0/(1.0+x*x);
                       
                   }
                   
               }

           for(i=0, pi=0.0;i<threadNumbers;i++)pi += sum[i][0] * step;
           std::string pitosend=std::to_string(pi);
           write(fd[1],pitosend.c_str(),1000);
       } else {
           close(fd[1]);
           n = read(fd[0], line, 255);
           std::cout.precision(n);
           printf("Message coming from another process (PI value): %s \n", line);
       }
       
   
    
    return 0;
}

