#include "bsp.h"
#include "ap.h"
#include "uart.h"
#include "cmd_uart.h"
#include "cmd.h"
#include "boot.h"
#include "can.h"
#include "err_code.h"

static cmd_t cmd_can;
static cmd_driver_t cmd_driver;

void apInit(void)
{   
  bool ret = false;
  char port_name[128] = "COM10";
  uartSetPortName(HW_UART_CH_MAIN, port_name);
  
  cmdUartInitDriver(&cmd_driver, HW_UART_CH_MAIN, 600);
  cmdInit(&cmd_can, &cmd_driver);

  ret = cmdOpen(&cmd_can);
  if(!ret)
  {    
    logPrintf("uartOpen() %s Fail\n", port_name);
    return;
  } 
  
  boot_version_t version;
  can_open_cfg_t can_open_cfg;
  can_open_cfg.mode = CAN_MODE_NORMAL;
  can_open_cfg.frame = CAN_FRAME_CLASSIC;
  can_open_cfg.baud = CAM_BIT_RATE_500K;
  can_open_cfg.baudData = 0;
  if(bootCmdReadVersion(&cmd_can, &version, 500) != OK)
  { 
    logPrintf("read version failed: %d\r\n", cmd_can.packet.err_code);
    return;      
  }
  logPrintf("read version boot: %s: firm: %s: update: %s\r\n", version.boot.version_str, version.firm.version_str, version.update.version_str);
  if(canCmdOpen(&cmd_can, &can_open_cfg) == OK)
  {
      logPrintf("CAN Open success\r\n");          
  }
}

void apMain(void)
{
  if (cmdReceivePacket(&cmd_can) == true)
  {
    if(cmd_can.packet.cmd == CMD_CAN_DATA)
    {
      can_packet_t pkt;

      memcpy(&pkt.header, cmd_can.packet.data, sizeof(can_pakcet_header_t));
      memcpy(&pkt.data, &cmd_can.packet.data[sizeof(can_pakcet_header_t)], pkt.header.dlc);
      logPrintf("[%d]frm: %d, type: %d, dlc: %d, id: %x, len: %d, data: ", pkt.header.timestamp, pkt.header.frame, pkt.header.id_type, pkt.header.dlc, pkt.header.id, pkt.header.len);
      for(uint8_t i=0;i<pkt.header.dlc;i++)
      {
        logPrintf("%02x ", pkt.data[i]);
      }
      logPrintf("\r\n");      
    }
  }
}

void apSend(uint32_t id, uint8_t* dat, uint8_t len)
{
  canCmdSendData(&cmd_can, id, dat, len);
}
