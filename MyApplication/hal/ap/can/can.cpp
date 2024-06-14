#include "bsp.h"
#include "cmd.h"
#include "can.h"

#define DEFAULT_CAN_CMD_TIMEOUT (500)

static bool isCanOpen = false;

uint16_t canCmdOpen(cmd_t *p_cmd, can_open_cfg_t* p_cfg)
{
  uint16_t ret = CMD_OK;

  if (cmdSendCmdRxResp(p_cmd, CMD_CAN_OPEN, (uint8_t*)p_cfg, sizeof(can_open_cfg_t), DEFAULT_CAN_CMD_TIMEOUT) == true)
  {
    cmd_packet_t *p_packet = &p_cmd->packet;
    if (p_packet->err_code == CMD_OK)
    {
      isCanOpen = true;
    }
  } 
  ret = p_cmd->packet.err_code;
  return ret;
}

uint16_t canCmdClose(cmd_t *p_cmd)
{
  uint16_t ret = CMD_OK;

  if (cmdSendCmdRxResp(p_cmd, CMD_CAN_CLOSE, 0, 0, DEFAULT_CAN_CMD_TIMEOUT) == true)
  {
    cmd_packet_t *p_packet = &p_cmd->packet;
    if (p_packet->err_code == CMD_OK)
    {
      isCanOpen = false;
    }
  } 
  ret = p_cmd->packet.err_code;
  return ret;
}

bool canCmdSendData(cmd_t *p_cmd, uint32_t id, uint8_t* dat, uint8_t len)
{  
    can_packet_t pkt;
    pkt.header.timestamp = (uint16_t)millis();
    pkt.header.frame = CAN_FRAME_CLASSIC;
    pkt.header.id_type = CAN_ID_TYPE_STD;
    pkt.header.id = id;
    pkt.header.len = pkt.header.dlc = len;
    for(uint8_t i=0;i<len;i++)
    {
      pkt.data[i] = dat[i];
    }
    return cmdSend(p_cmd, PKT_TYPE_CAN, CMD_CAN_DATA, OK, (uint8_t*)&pkt, sizeof(can_pakcet_header_t) + len);
}

uint16_t canCmdGetFilter(cmd_t *p_cmd, cmd_can_filter_t* filter)
{  
  uint16_t ret = CMD_OK;
  if(p_cmd == NULL || filter == NULL)
  {
    return ERR_CMD_INVALID_PARM;
  }
  if (cmdSendCmdRxResp(p_cmd, CMD_CAN_GET_FILTER, 0, 0, DEFAULT_CAN_CMD_TIMEOUT) == true)
  {
    cmd_packet_t *p_packet = &p_cmd->packet;
    if (p_packet->err_code == CMD_OK)
    {
      memcpy(filter, p_packet->data, sizeof(cmd_can_filter_t));      
    }
  } 
  ret = p_cmd->packet.err_code;
  return ret;
}

uint16_t canCmdSetFilter(cmd_t *p_cmd, cmd_can_filter_t* filter)
{   
  uint16_t ret = CMD_OK;
  if(p_cmd == NULL || filter == NULL)
  {
    return ERR_CMD_INVALID_PARM;
  }
  if (cmdSendCmdRxResp(p_cmd, CMD_CAN_SET_FILTER, (uint8_t*)filter, sizeof(cmd_can_filter_t), DEFAULT_CAN_CMD_TIMEOUT) == true)
  {
    cmd_packet_t *p_packet = &p_cmd->packet;
    if (p_packet->err_code == CMD_OK)
    {
    }
  } 
  ret = p_cmd->packet.err_code;
  return ret;
}