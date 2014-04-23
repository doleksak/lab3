#include "timer.hh"

using namespace std;

/*!
 * \file
 * \brief Metody klasy timer
 *
 */

/*! \brief Rozpoczyna odliczanie czasu.
 * 
 */

void timer::start()
{
clock_gettime(CLOCK_MONOTONIC, &m_start);
}

/*! \brief Konczy odliczanie czasu.
 * 
 */

void timer::stop()
{
clock_gettime(CLOCK_MONOTONIC, &m_stop);
}

/*! \brief Zwraca roznice miedzy zakonczeniem i rozpoczeciem odliczania.
 * 
 */

unsigned int timer::elapsed_us()
{
return
((m_stop.tv_sec - m_start.tv_sec) * 1000000) +
(m_stop.tv_nsec - m_start.tv_nsec) / 1000;
}
