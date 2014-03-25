#include "timer.hh"

using namespace std;


void timer::start() {
gettimeofday(&stoper, NULL);
t1=stoper.tv_usec; }


void timer::stop() {
gettimeofday(&stoper, NULL);
t2=stoper.tv_usec;
czas=t2-t1; }


void timer::wyswietl() {
cout<<"Czas sortowania: "<<czas<<" mikrosekund"<<endl; }
