// SPDX-License-Identifier: MIT
#ifdef FEX_STANDALONE_CRT
double exp2(double);
double log2(double);
double remainder(double, double);
double remquo(double, double, int*);
long long strtoll(const char*, char**, int);
unsigned long long strtoull(const char*, char**, int);
long long strtoimax(const char*, char**, int);
unsigned long long strtoumax(const char*, char**, int);

double (*__imp_exp2)(double) = exp2;
double (*__imp_log2)(double) = log2;
double (*__imp_remainder)(double, double) = remainder;
double (*__imp_remquo)(double, double, int*) = remquo;
long long (*__imp_strtoll)(const char*, char**, int) = strtoll;
unsigned long long (*__imp_strtoull)(const char*, char**, int) = strtoull;
long long (*__imp_strtoimax)(const char*, char**, int) = strtoimax;
unsigned long long (*__imp_strtoumax)(const char*, char**, int) = strtoumax;
#endif
