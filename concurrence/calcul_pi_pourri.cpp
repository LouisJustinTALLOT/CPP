#include <iostream>
#include <thread>
#include <mutex>
#include <vector>
//g++ calcul_pi_pourri.cpp -o calcul_pi_pourri -l pthread
std::mutex mtx;

void pi_thread_worker(const uint& nbpoint, const uint tid, const uint nbthread, double& pi){
    double s = 0.;
    double l = 1./nbpoint;
    int start = tid*(nbpoint/nbthread);
    int stop = (tid+1)*(nbpoint/nbthread);
    if( tid == nbthread-1){
        stop += nbpoint%nbthread;
    }

    double x;
    for( int i=start; i<stop; i++){
        x = l * ( i + 0.5 );
        mtx.lock();
        pi += l * ( 4. / (1 + x*x ) );
        mtx.unlock();   
    }
}

int main(int argc, char* argv []){
    if( argc == 1 ){
        std::cerr << "Specify the number of thread" << std::endl;
        return 1;
    }

    int nb_point = 100000000;
    int nb_thread = atoi(argv[1]);

    double pi=0;
    std::vector<std::thread> threads;
    for( int i=0; i<nb_thread; i++){
        threads.push_back( std::thread( pi_thread_worker, nb_point, i, nb_thread, std::ref(pi) ) );
    }

    for( int i=0; i<nb_thread; i++){
        threads[i].join();
    }

    return 0;
}