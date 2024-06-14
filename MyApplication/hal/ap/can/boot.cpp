#include "boot.h"


uint16_t bootCmdReadVersion(cmd_t* p_cmd, boot_version_t *version, uint32_t timeout)
{
  uint16_t ret = CMD_OK;
  if (cmdSendCmdRxResp(p_cmd, BOOT_CMD_VERSION, NULL, 0, timeout) == true)
  {
    cmd_packet_t *p_packet = &p_cmd->packet;

    memset(version, 0, sizeof(boot_version_t));
    if (p_packet->err_code == CMD_OK)
    {
      if (p_packet->length == sizeof(boot_version_t))
      {
        memcpy(version, p_packet->data, p_packet->length);
      } 
      else
      {
        p_packet->err_code = ERR_CMD_RX_LENGTH;
      }    
    }
  } 

  ret = p_cmd->packet.err_code;

  return ret;
}

