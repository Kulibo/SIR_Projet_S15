#include "mcqueen.hpp"
#include <iostream>
#include <random>
#include <cmath>
#include <complex>

double norme(std::complex<double> p){
    return sqrt(p.real()*p.real() + p.imag()*p.imag());
}

int main(){
    std::default_random_engine generator;
    std::uniform_real_distribution<double> distribution(0.0,1.0);
    std::complex<double> p1(0.0, 0.0);
    std::complex<double> p2(0.0, 2.0);
    std::complex<double> p3(2.0, 0.0);
    std::complex<double> p4(2.0, 2.0);
    mq::Mcqueen<std::complex<double>> learner(4, &norme); 
    for(unsigned int i(0); i < 100; i++){
        learner.update(p1 +std::complex<double>( distribution(generator), distribution(generator)));
        learner.update(p2 + std::complex<double>( distribution(generator), distribution(generator)));
        learner.update(p3 + std::complex<double>( distribution(generator), distribution(generator)));
        learner.update(p4 + std::complex<double>( distribution(generator), distribution(generator)));
    }
    
    for(auto proto : learner.prototypes())
    {
        std::cout << proto << "\n";
    }
    std::cout << std::endl;
}
