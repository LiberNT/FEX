// SPDX-License-Identifier: MIT
#define _SECIMP
#define _CRTIMP
#include <cstdlib>
#include <cstdint>
#include <cmath>
#include <cstring>
#include "../Priv.h"

#ifndef __REACTOS__
long double tanl(long double X) {
  return tan(static_cast<double>(X));
}

long double sinl(long double X) {
  return sin(static_cast<double>(X));
}

long double cosl(long double X) {
  return cos(static_cast<double>(X));
}
#endif

long double exp2l(long double N) {
  return exp2(static_cast<double>(N));
}

long double log2l(long double N) {
  return log2(static_cast<double>(N));
}

#ifndef __REACTOS__
long double atan2l(long double X, long double Y) {
  return atan2(static_cast<double>(X), static_cast<double>(Y));
}
#endif

#ifdef FEX_STANDALONE_CRT
DLLEXPORT_FUNC(short, _dclass, (double X)) {
  uint64_t Bits;
  memcpy(&Bits, &X, sizeof(Bits));
  const uint64_t Exponent = (Bits >> 52) & 0x7FF;
  const uint64_t Mantissa = Bits & ((1ULL << 52) - 1);
  if (Exponent == 0x7FF) {
    return Mantissa ? FP_NAN : FP_INFINITE;
  }
  if (Exponent == 0) {
    return Mantissa ? FP_SUBNORMAL : FP_ZERO;
  }
  return FP_NORMAL;
}

DLLEXPORT_FUNC(int, _dsign, (double X)) {
  uint64_t Bits;
  memcpy(&Bits, &X, sizeof(Bits));
  return (Bits >> 63) ? 0x8000 : 0;
}
#endif
