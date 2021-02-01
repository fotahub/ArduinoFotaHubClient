#ifndef FOTAUPDATEDEFINITIONS_H
#define FOTAUPDATEDEFINITIONS_H

#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>
#include "TLSDefinitions.h"

#ifdef __cplusplus
extern "C" {
#endif

#define BINARY_KIND_DEFAULT 0

#define BINARY_NAME_DEFAULT NULL

#define PARTITION_IDX_NONE -1

#define PARTITION_IDX_1 0

#define PARTITION_IDX_2 1

#define PARTITION_IDX_3 2

#define FIRMWARE_UPDATE_DOWNLOAD_TIMEOUT_DEFAULT 10000

#define MAX_FIRMWARE_UPDATE_DOWNLOAD_RETRY_COUNT_DEFAULT 2

#define MAX_FIRMWARE_UPDATE_DOWNLOAD_DATA_RATE_DEGRESSION_DELTA 2

enum FOTAUpdateVerificationAlgorithm {
  FOTA_UPDATE_VERIFICATION_ALGORITHM_NONE,
  FOTA_UPDATE_VERIFICATION_ALGORITHM_MD5,
  FOTA_UPDATE_VERIFICATION_ALGORITHM_SHA1,
  FOTA_UPDATE_VERIFICATION_ALGORITHM_SHA256,
  FOTA_UPDATE_VERIFICATION_ALGORITHM_SHA384,
  FOTA_UPDATE_VERIFICATION_ALGORITHM_SHA512,
  FOTA_UPDATE_VERIFICATION_ALGORITHM_RSA2048
};
typedef enum FOTAUpdateVerificationAlgorithm FOTAUpdateVerificationAlgorithm_t;

enum FOTAUpdateStatus {
  FOTA_UPDATE_STATUS_NONE,
  FOTA_UPDATE_STATUS_DOWNLOAD_SUCCEEDED,
  FOTA_UPDATE_STATUS_DOWNLOAD_FAILED,
  FOTA_UPDATE_STATUS_DOWNLOAD_TIMEOUT,
  FOTA_UPDATE_STATUS_TOO_MANY_UPDATE_REQUESTS,
  FOTA_UPDATE_STATUS_UNSUPPORTED_UPDATE_VERIFICATION_ALGORITHM,
  FOTA_UPDATE_STATUS_UPDATE_VERIFICATION_FAILED,
  FOTA_UPDATE_STATUS_IO_ERROR,
  FOTA_UPDATE_STATUS_ACTIVATION_SUCCEEDED,
  FOTA_UPDATE_STATUS_ACTIVATION_FAILED,
  FOTA_UPDATE_STATUS_REVERSION_SUCCEEDED,
  FOTA_UPDATE_STATUS_REVERSION_FAILED,
  FOTA_UPDATE_STATUS_CONNECTIVITY_UNAVAILABLE
};
typedef enum FOTAUpdateStatus FOTAUpdateStatus_t;

struct FOTAUpdateClientConfig {
  bool authenticateUpdateServer;
  TLSMaxFragmentLength_t maxUpdateDownloadFragmentLength;
  uint8_t maxUpdateDownloadDataRate;
  uint16_t updateDownloadTimeoutInterval;
  uint8_t maxUpdateDownloadRetryCount;
};
typedef struct FOTAUpdateClientConfig FOTAUpdateClientConfig_t;

struct FOTAProductInfo {
  char const *id;
  char const *name;
};
typedef struct FOTAProductInfo FOTAProductInfo_t;

struct FirmwareUpdateInfo {
  uint8_t binaryKind;
  char const *binaryName;
  char const *version;
  int8_t partitionIdx;
};
typedef struct FirmwareUpdateInfo FirmwareUpdateInfo_t;

extern size_t getVerificationDataSize(FOTAUpdateVerificationAlgorithm_t algorithm);

extern FOTAUpdateClientConfig_t const FOTA_UPDATE_CLIENT_DEFAULT_CONFIG;

#ifdef __cplusplus
} /* extern "C" */
#endif

#endif
