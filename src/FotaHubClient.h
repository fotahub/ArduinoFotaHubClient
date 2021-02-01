#ifndef FOTAHUBCLIENT_H
#define FOTAHUBCLIENT_H

#include "FotaHub.h"
#include <HashWrapper.h>
#include <HttpClientWrapper.h>
#include <InternalStorageWrapper.h>
#include <LibPrintf.h>

// Library interface description
class FotaHubClientClass
{
  // User-accessible "public" interface
  public:
	void init(const char *productId, const char *productName, const FOTAUpdateClientConfig *pUpdateClientConfig);
	void run(void);
	void notifyNetworkStatusChange(NetworkAdapterStatus status);
  bool downloadFirmwareUpdate(FirmwareUpdateInfo_t *pUpdateInfo);
  bool activateFirmwareUpdate(FirmwareUpdateInfo_t *pUpdateInfo);
  bool confirmFirmwareUpdate(FirmwareUpdateInfo_t *pUpdateInfo);
  bool revertFirmwareUpdate(FirmwareUpdateInfo_t *pUpdateInfo);

  // Library-accessible "private" interface
  private:
};

extern FotaHubClientClass FotaHubClient;

#endif

