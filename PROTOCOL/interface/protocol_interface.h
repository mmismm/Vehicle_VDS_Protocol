/**********************************************************************
Copyright:		YiXiong AUTO S&T Co., Ltd.
Description:	�������ӿں���
History:
	<author>	<time>		<desc>
DEMO Version: V2.1 2017.3.30
************************************************************************/


#ifndef _INTERFACE_H
#define _INTERFACE_H


#include "protocol_define.h"

#ifdef __cplusplus
extern "C" {
#endif


#ifdef WIN32
#ifdef PROTOCOL_DLL_EXPORTS
#	define PROTOCOL_API __declspec(dllexport)
#else
#	define PROTOCOL_API __declspec(dllimport)
#endif
#else
#	define PROTOCOL_API
#endif


	// ****************************************************************************
	typedef int ( *SEND_CMD_CALLBACK )( const byte*, int ); // ��������ص�����ָ��
	SEND_CMD_CALLBACK send_cmd;
	PROTOCOL_API void regist_send_cmd_callback( SEND_CMD_CALLBACK send_cmd_callback ); // ע�ᷢ������ص�����

	typedef int ( *RECEIVE_CMD_CALLBACK )( byte*, int nLen, int nTimeOut ); // ��������ص�����ָ��
	RECEIVE_CMD_CALLBACK receive_cmd;
	PROTOCOL_API void regist_receive_cmd_callback( RECEIVE_CMD_CALLBACK receive_cmd_callback ); // ע���������ص�����

	typedef int ( *RECEIVE_ALL_CMD_CALLBACK )( byte*, int nLen, int nTimeOut ); // ���մ�֡ͷ����ص�����ָ��
	RECEIVE_ALL_CMD_CALLBACK receive_all_cmd;
	PROTOCOL_API void regist_receive_all_cmd_callback( RECEIVE_ALL_CMD_CALLBACK receive_all_cmd_callback ); // ע���������ص�����

	typedef void ( *TIME_DELAY )( int ); //��ʱ�ص�����ָ��
	TIME_DELAY time_delay_ms;
	PROTOCOL_API void regist_time_delay( TIME_DELAY time_delay_callback ); // ע����ʱ�ص�����

	// ����VCI
	PROTOCOL_API int setting_vci( void* pIn, void* pOut );

	// ����ECU
	PROTOCOL_API int active_ECU( void* pIn, void* pOut );

	// �����빦��
	PROTOCOL_API int read_current_Dtc( void* pIn, void* pOut );
	PROTOCOL_API int read_history_Dtc( void* pIn, void* pOut );
	PROTOCOL_API int clear_Dtc( void* pIn, void* pOut );

	// ����֡����
	PROTOCOL_API int read_freeze_frame_DTC( void* pIn, void* pOut );
	PROTOCOL_API int read_freeze_frame_DS( void* pIn, void* pOut );

	// ��������
	PROTOCOL_API int read_data_stream( void* pIn, void* pOut );
	PROTOCOL_API int enter_read_data_stream( void* pIn, void* pOut );
	PROTOCOL_API int quit_read_data_stream( void* pIn, void* pOut );

	// ���汾��Ϣ
	PROTOCOL_API int read_Ecu_information( void* pIn, void* pOut );

	// ִ��������
	PROTOCOL_API int actuator_test( void* pIn, void* pOut );

	// ���⹦��
	PROTOCOL_API int special_function( void* pIn, void* pOut );

	// �˳�ϵͳ
	PROTOCOL_API int quit_system( void* pIn, void* pOut );

	//��ȡ��������
	PROTOCOL_API int init_config_from_xml( int iConfigType, void* pIn );

	//��ȡ���⹦������
	PROTOCOL_API int special_config_function( void* pIn, void* pOut );

	//�ȴ����а�ťȡ��
	PROTOCOL_API void cancelWaitDlg(void* pIn, void* pOut);

	//ɨ��ECU�汾
	PROTOCOL_API void process_ECU_version(void* pIn, void* pOut);
	
	//����VDI�Զ��������
	PROTOCOL_API int XML_to_VDI(void* pIn, void* pOut);

	//�Զ�ɨ��ʱ��ȡϵͳ�Ĺ��������
	PROTOCOL_API int read_dtc( void* pIn, void* pOut );

	//ֹͣ���� �˺�����λִ��XML��CALLPROTOCOL֮ǰ���ô˺������˺�������protocol������ֹͣ��
	PROTOCOL_API   void stopCallProtocol(void* pIn, void* pOut); 

#undef PROTOCOL_API

#ifdef __cplusplus
}
#endif

#endif/* _INTERFACE_H */
