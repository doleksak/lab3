#ifndef TIMER_HH
#define TIMER_HH
#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

/*!
 * \file
 * \brief Definiuje klase timer i jej metody
 */

class timer
{
public:

struct timespec m_start;

struct timespec m_stop;

void start();

void stop();

unsigned int elapsed_us();

};


#endif