#include<stdio.h>
#include<winsock.h>

#pragma comment(lib,"ws2_32.lib")

int main()
{

	/*�����������*/
	char Sendbuf[100];            /*�������ݵĻ�����*/
	char Receivebuf[100];         /*��*/
	int Sendlen;                  /*�������ݵĳ���*/
	int Receivelen;               /*��*/
	int Lenth;                    /*SOCKADDR�Ĵ�С*/
	SOCKET socket_server;          /*����������׽���*/
	SOCKET socket_receive;        /*�������������׽���*/
	SOCKADDR_IN Server_add;       /*��������ַ��Ϣ�ṹ���壩*/
	SOCKADDR_IN Client_add;       /*�ͻ��˵�ַ��Ϣ�ṹ���壩*/
	WORD wVersionRequested;       /*WORD���� unsigned short   */
	WSADATA wsaData;              /*��汾��Ϣ�ṹ(�ǽṹ��)*/
	int error;                    /*��ʾ����*/



	/*��ʼ���׽��ֿ�*/
	wVersionRequested = MAKEWORD(2, 2);     /*MAKEWORD�ǽ������ֽ���ϳ�һ���֣�ǰ���Ǹ��ֽڣ������ǵ��ֽڣ���ʾ2.2�汾*/
	error = WSAStartup(wVersionRequested, &wsaData); /*�����׽��ֿ⣬��ʼ��Ws2����32.dll��̬���ӿ�*/
	if (error!=0)
	{
		printf("�����׽���ʧ�ܣ�");
		return 0;
	}
	if (LOBYTE(wsaData.wVersion)!=2||
		HIBYTE(wsaData.wVersion)!=2)         /*�ж�������صİ汾���Ƿ����Ҫ��*/
	{
		WSACleanup();                /*�����ϣ��ر��׽��ֿ�*/
		return 0;
	}


	/*�������ӵ�ַ*/
	Server_add.sin_family = AF_INET;         /*�����ַ������AF_INET����ֻ�������������ֽ�˳��*/
	Server_add.sin_addr.S_un.S_addr = htonl(INADDR_ANY);  /*������ַ���ǵ�ת���������ֽ�˳��*/
	Server_add.sin_port = htons(5000);       /*�˿ںţ��ǵ�ת���������ֽ�˳��*/


	/*�����׽���*/
	socket_server = socket(AF_INET, SOCK_STREAM, 0);   /*SOCK_STREAM��ʾ��ʽ�׽���tcp*/


	/*���׽��ֵ����ص�ĳ����ַ�Ͷ˿���*/
	if (bind(socket_server,(SOCKADDR*)&Server_add,sizeof(SOCKADDR))==SOCKET_ERROR)
	{
		printf("��ʧ�ܣ�\n");                           /*ʵ�ְ󶨵�ͬʱ�����ж�*/
		return 0;
	}


	/*���ü���ģʽ*/
	if (listen(socket_server,5)<0)
	{
		printf("����ʧ�ܣ�\n");
		return 0;
	}


	/*��������*/
	Lenth = sizeof(SOCKADDR);
	socket_receive = accept(socket_server, (SOCKADDR*)&Client_add, &Lenth);
	if (socket_receive == SOCKET_ERROR)
	{
		printf("����ʧ�ܣ�");
		return 0;
	}


	/*��������*/
	while (1)                      /*����ѭ��*/
	{
		/*��������*/
		Receivelen = recv(socket_receive, Receivebuf, 100, 0);
		if (Receivelen < 0)
		{
			printf("��������ʧ�ܣ������˳�");
			break;
		}
		else
		{
			printf("Client say��%s\n", Receivebuf);
		}


		/*��������*/
		printf("please enter message:");
		scanf_s("%s", Sendbuf, 100);
		Sendlen = send(socket_receive, Sendbuf, 100, 0);
		if (Sendlen < 0)
		{
			printf("����ʧ�ܣ��˳�����");
			return 0;
		}
	}

	/*�ͷ��׽��֣��رն�̬��*/
	closesocket(socket_receive);
	closesocket(socket_server);
	WSACleanup();
	return 0;
}