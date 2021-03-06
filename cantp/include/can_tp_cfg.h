/**********************************************************************************************************************
*  COPYRIGHT
*  -------------------------------------------------------------------------------------------------------------------
*  \verbatim
*  Copyright (c) 2013 by XXX.                                              All rights reserved.
*
*                This software is copyright protected and proprietary to XXX.
*                XXX grants to you only those rights as set out in the license conditions.
*                All other rights remain with XXX.
*  \endverbatim
*  -------------------------------------------------------------------------------------------------------------------
*  FILE DESCRIPTION
*  -------------------------------------------------------------------------------------------------------------------
*         File:  XXX.h
*    Component:  -
*       Module:  -
*    Generator:  -
*
*  Description:  Provision of XXX
*
*  -------------------------------------------------------------------------------------------------------------------
*  MISRA VIOLATIONS
*  -------------------------------------------------------------------------------------------------------------------
*
*
*********************************************************************************************************************/

/**********************************************************************************************************************
*  AUTHOR IDENTITY
*  -------------------------------------------------------------------------------------------------------------------
*  Name                          Initials      Company
*  -------------------------------------------------------------------------------------------------------------------
*  Joachim Kalmbach              Jk            Vector Informatik
*  -------------------------------------------------------------------------------------------------------------------
*  REVISION HISTORY
*  -------------------------------------------------------------------------------------------------------------------
*  Version   Date        Author  Change Id     Description
*  -------------------------------------------------------------------------------------------------------------------
*  01.00.00  2007-08-01  Jk                    Initial creation

*********************************************************************************************************************/


#ifndef _CAN_TP_CFG_H_
#define _CAN_TP_CFG_H_
/**********************************************************************************************************************
* INCLUDES
*********************************************************************************************************************/
#include "std_types.h"

/**********************************************************************************************************************
*  GLOBAL CONSTANT MACROS
*********************************************************************************************************************/

#define   WIN32_DEBUG


/*if defined, This CANTP can be used to run on CANFD drivers.*/
#define   CANTP_FLEX_DATA_RATE_SUPPORTED   

#define   CANTP_CAN_FRAME_PADDING

#define   CANTP_STATIC_CHANNELS_NUM         1




//#define   CANTP_CAN_FRAME_OPTIM

/**********************************************************************************************************************
*  GLOBAL FUNCTION MACROS
*********************************************************************************************************************/

/**********************************************************************************************************************
*  GLOBAL DATA TYPES AND STRUCTURES
*********************************************************************************************************************/

typedef struct
{
	U8* pdu_data_ptr;  // payload data(without protocol information)
	U8  data_len;     //payload length of the first frame or single frame
}ul_pdu_info_type;

typedef  S16   ms_timer_type;

typedef U8  (*ul_request_rx_buffer_func_type)( U32, U32* );
typedef U8  (*ul_copy_rx_data_func_type)(const U8*, U32,U32* remain_buf_size_ptr);
typedef void (*ul_rx_indication_func_type)(U8);
typedef U8  (*ul_copy_tx_data_func_type)(U8*, U32, U32*);
typedef void(*ul_tx_confirmation_func_type)(U8);

typedef struct
{
	U16   main_func_period;   /*period unit: ms*/

}cantp_general_cfg_type;

typedef struct
{
	U8									channel_id;

	U8									TX_DL;    //CAN_TX_DL
	U8                                  ext_addr_flag;

	ms_timer_type                       A_TO;     //Timeout value for CAN frame transmission.
	ms_timer_type                       BS_TO;    //Timeout value of waiting time for next flow control frame.
	ms_timer_type                       CR_TO;    //Timeout value of waiting time for nett consecutive  frame.


	ul_request_rx_buffer_func_type        req_rx_buf_func;
	ul_copy_rx_data_func_type             copy_rx_data_func;
	ul_rx_indication_func_type            rx_indication_func;
	ul_copy_tx_data_func_type                copy_tx_data_func;
	ul_tx_confirmation_func_type          tx_confirmation_func;
	//FUNC* ul_start_of_reception
	//FUNC* ul_copy_rx_data
	//FUNC* ul_copy_tx_data
	//FUNC* ul_rx_indication
	//FUNC* ul_tx_confirmation

	U32   can_id;
}cantp_channel_cfg_type;

/**********************************************************************************************************************
*  GLOBAL DATA PROTOTYPES
*********************************************************************************************************************/

/**********************************************************************************************************************
*  GLOBAL FUNCTION PROTOTYPES
*********************************************************************************************************************/


/**********************************************************************************************************************
*  END OF FILE:
*********************************************************************************************************************/

#endif
