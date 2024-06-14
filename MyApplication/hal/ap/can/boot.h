#ifndef CMD_BOOT_H_
#define CMD_BOOT_H_

#ifdef __cplusplus
 extern "C" {
#endif

#include <stdint.h>
#include "cmd.h"
#include "def.h"

#define BOOT_CMD_VERSION                0x0001

uint16_t bootCmdReadVersion(cmd_t* p_cmd, boot_version_t *version, uint32_t timeout);

#ifdef __cplusplus
 }
#endif

#endif
