#include <iostream>
#include "J1939.H" 
#include "ECanVci.H"
using namespace std;

#pragma comment (lib,"j1939.lib")
#pragma comment (lib,"ECanVci.lib")

J1939_MESSAGE Msg;
ECan MYCAN;

int main()
{
	char data[100];
	J1939_Initialization(TRUE);
	// �ȴ���ַ������ʱ
	while (J1939_Flags.WaitingForAddressClaimContention)
		J1939_Poll(5);
	//��ַ�Ѿ������ã��豸�ѹ��ص������ϣ�
	while (1)
	{
		/*��ȡTP�������ݵ�data����*/
		while (J1939_TP_RX_Message(data, sizeof(data)) == RC_SUCCESS)
			J1939_Poll(5);
		Sleep(10);//10����ľ�ȷ��ʱ
		J1939_Poll(20);
	}
}
//int main()
//{
//	J1939_Initialization(TRUE);
//	//�ȴ���ַ��ʱ
//	while (J1939_Flags.WaitingForAddressClaimContention)
//		J1939_Poll(5);
//	//���е����˵����ַ�Ѿ������ã��豸�ѹ��ص������ϣ�
//	while (1)
//	{
//		/***********************��������***************************/
//		Msg.Mxe.DataPage = 0;
//		Msg.Mxe.Priority = J1939_CONTROL_PRIORITY;
//		Msg.Mxe.DestinationAddress = 0x0f;
//		Msg.Mxe.DataLength = 8;
//		Msg.Mxe.PDUFormat = 0xfe;
//		Msg.Mxe.Data[0] = 1;
//		Msg.Mxe.Data[1] = 2;
//		Msg.Mxe.Data[2] = 3;
//		Msg.Mxe.Data[3] = 4;
//		Msg.Mxe.Data[4] = 5;
//		Msg.Mxe.Data[5] = 6;
//		Msg.Mxe.Data[6] = 7;
//		Msg.Mxe.Data[7] = 8;
//		while (J1939_EnqueueMessage(&Msg) != RC_SUCCESS)
//			J1939_Poll(5);
//		/***********************�����������*************************/
//		while (RXQueueCount > 0)
//		{
//			J1939_DequeueMessage(&Msg);
//		}
//		J1939_Poll(20);
//	  }
//}