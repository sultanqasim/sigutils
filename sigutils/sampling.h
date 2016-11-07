/*

  Copyright (C) 2016 Gonzalo José Carracedo Carballal

  This program is free software: you can redistribute it and/or modify
  it under the terms of the GNU Lesser General Public License as
  published by the Free Software Foundation, either version 3 of the
  License, or (at your option) any later version.

  This program is distributed in the hope that it will be useful, but
  WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
  GNU Lesser General Public License for more details.

  You should have received a copy of the GNU Lesser General Public
  License along with this program.  If not, see
  <http://www.gnu.org/licenses/>

*/

#ifndef _SIGUTILS_SAMPLING_H
#define _SIGUTILS_SAMPLING_H

#include "types.h"

#ifndef PI
#define PI 3.141592653589793238462643
#endif

/*
 * Conventions used for frequency representation
 * ---------------------------------------------
 * SAMPLING FREQUENCY (fs): How many samples are taken per second, in Hz.
 *
 * RELATIVE FREQUENCY (frel): Represents the frequency of a discretized signal,
 * ranging from 0 (constant signal) to 1 (a signal that flips sign on each
 * time step).
 *
 * ABSOLUTE FREQUENCY (freq): Represents the actual frequency of the signal,
 * in Hz. It is defined as:
 *
 *   freq = frel * fs / 2.
 *
 * RELATIVE ANGULAR FREQUENCY (omrel): Represents how many radians are added
 * to the signal phase in each time step. It is defined as:
 *
 *   omrel = PI * frel
 *
 * as the flipping sign signal's phase increments in 180 degrees on each
 * time step.
 */

#define SU_ABS2REL_FREQ(fs, freq) (2 * (SUFLOAT) (freq) / (SUFLOAT) (fs))
#define SU_REL2ABS_FREQ(fs, frel) ((SUFLOAT) (fs) * (SUFLOAT) (frel) / 2)

#define SU_REL2ANG_FREQ(freq) (PI * (freq))
#define SU_ANG2REL_FREQ(omrel) ((omrel) / (PI))

#define SU_T2N(fs, t) ((unsigned int) floor((t) * (SUFLOAT) (fs)))
#define SU_N2T(fs, n) ((unsigned int) floor((n) / (SUFLOAT) (fs)))

#endif /* _SIGUTILS_SAMPLING_H */