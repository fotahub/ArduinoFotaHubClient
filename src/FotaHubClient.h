#ifndef FOTAHUBCLIENT_H
#define FOTAHUBCLIENT_H

#include "FotaHub.h"

// Library interface description
class FotaHubClientClass
{
  // User-accessible "public" interface
  public:
	void init(const char *productId, const char *productName, const FOTAUpdateClientConfig *pUpdateClientConfig);
	void run(void);
	void notifyNetworkStatusChange(NetworkAdapterStatus_t status);
  bool downloadFirmwareUpdate(FirmwareUpdateInfo_t *pUpdateInfo);
  bool applyFirmwareUpdate(FirmwareUpdateInfo_t *pUpdateInfo);
  bool confirmFirmwareUpdate(FirmwareUpdateInfo_t *pUpdateInfo);
  bool rollBackFirmwareUpdate(FirmwareUpdateInfo_t *pUpdateInfo);

  // Library-accessible "private" interface
  private:
};

extern FotaHubClientClass FotaHubClient;
#endif
