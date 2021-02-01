#ifndef DEMOFOTAUPDATEAGENT_H
#define DEMOFOTAUPDATEAGENT_H

#include <FOTAUpdateDefinitions.h>

// Application interface description
class DemoFOTAUpdateAgentClass
{
  // User-accessible "public" interface
  public:
	void init(const char *productId, const char *productName, const FOTAUpdateClientConfig *pUpdateClientConfig);
	void run(void);

	// Application-accessible "private" interface
  private:
};

extern DemoFOTAUpdateAgentClass DemoFOTAUpdateAgent;

#endif

