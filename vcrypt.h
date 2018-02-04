#ifndef VCRYPT_H
#define VCRYPT_H

#include <stdlib.h>
#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

void vcrypt_1_1_256(const char* input, char* output, uint32_t n);
void vcrypt_1_1_256_sp(const char* input, char* output, char* scratchpad, uint32_t n);

#ifdef __cplusplus
}
#endif

#endif
