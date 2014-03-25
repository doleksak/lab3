#ifndef TIMER_HH
#define TIMER_HH
#include <iostream>
#include <sys/time.h>
#include <cstdlib>

using namespace std;


class timer 
{
public:	
timeval stoper;	
long double t1, t2, czas, sekundy;	

void start();
void stop();
void wyswietl();

};
#endif