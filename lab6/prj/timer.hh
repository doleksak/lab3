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

/*! \brief Klasa timer mierzy i pozwala wyswietlic czas wykonywania programu
 * 
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