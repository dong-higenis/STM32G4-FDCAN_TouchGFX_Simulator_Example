#ifndef CMD_CAN_H_
#define CMD_CAN_H_

#ifdef __cplusplus
 extern "C" {
#endif

#include <stdint.h>

typedef enum CanCmdType
{
  CMD_CAN_OPEN        = 0x0110,
  CMD_CAN_CLOSE       = 0x0111,
  CMD_CAN_DATA        = 0x0112,
  CMD_CAN_ERR_INFO    = 0x0113,
  CMD_CAN_SET_FILTER  = 0x0114,
  CMD_CAN_GET_FILTER  = 0x0115
} CanCmdType_t;

typedef enum CanBitRate
{
  CAM_BIT_RATE_100K   = 0,
  CAM_BIT_RATE_125K   = 1,
  CAM_BIT_RATE_250K   = 2,
  CAM_BIT_RATE_500K   = 3,
  CAM_BIT_RATE_1M     = 4,
  CAM_BIT_RATE_2M     = 5,
  CAM_BIT_RATE_4M     = 6,
  CAM_BIT_RATE_5M     = 7
} CanBitRate_t;

typedef enum CanMode
{
  CAN_MODE_NORMAL     = 0,
  CAN_MODE_MONITOR    = 1,
  CAN_MODE_LOOPBACK   = 2
} CanMode_t;

typedef enum CanFrame
{
  CAN_FRAME_CLASSIC   = 0,
  CAN_FRAME_FD_NO_BRS = 1,
  CAN_FRAME_FD_BRS    = 2
} CanFrame_t;

typedef enum CanIdType
{
    CAN_ID_TYPE_STD   = 0,
    CAN_ID_TYPE_EXT   = 1
} CanIdType_t;

typedef struct
{
  uint8_t mode;
  uint8_t frame;
  uint8_t baud;
  uint8_t baudData;
} can_open_cfg_t;

#pragma pack(push, 1)
typedef struct
{
  uint16_t timestamp;
  uint8_t frame;
  uint8_t id_type;
  uint8_t dlc;
  uint32_t id;
  uint8_t len;
} can_pakcet_header_t;

typedef struct
{
  can_pakcet_header_t header;
  uint8_t data[64];
} can_packet_t;

typedef struct
{
  uint8_t type;
  uint8_t id_type;
  uint32_t id1;
  uint32_t id2;
} cmd_can_filter_t;
#pragma pack(pop)


uint16_t canCmdOpen(cmd_t *p_cmd, can_open_cfg_t* p_cfg);
uint16_t canCmdClose(cmd_t *p_cmd);
uint16_t canCmdGetFilter(cmd_t *p_cmd, cmd_can_filter_t* filter);
uint16_t canCmdSetFilter(cmd_t *p_cmd, cmd_can_filter_t* filter);

bool canCmdSendData(cmd_t *p_cmd, uint32_t id, uint8_t* dat, uint8_t len);

#ifdef __cplusplus
 }
#endif

#endif
