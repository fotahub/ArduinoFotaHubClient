#ifndef TLSDEFINITIONS_H
#define TLSDEFINITIONS_H

#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#ifdef __cplusplus
extern "C" {
#endif

enum TLSMaxFragmentLength {
  TLS_MAX_FRAGMENT_LENGTH_DISABLED = 0,
  TLS_MAX_FRAGMENT_LENGTH_512 = 512,
  TLS_MAX_FRAGMENT_LENGTH_1024 = 1024,
  TLS_MAX_FRAGMENT_LENGTH_2048 = 2048,
  TLS_MAX_FRAGMENT_LENGTH_4096 = 4096
};
typedef enum TLSMaxFragmentLength TLSMaxFragmentLength_t;

#define TLS_DEFAULT_FRAGMENT_LENGTH 16384

#define TLS_MAX_DATA_RATE_NONE 0

#ifdef __cplusplus
} /* extern "C" */
#endif

#endif
