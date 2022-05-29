#include<stdio.h>
#include<winsock.h>
#pragma comment(lib,"ws2_32.lib")

int main()
{
	/*�����������*/
	char Sendbuf[100];
	char Receivebuf[100];
	int Sendlen;
	int Receivelen;
	SOCKET socket_send;
	SOCKADDR_IN Server_add;
	WORD wVersionRequested;
	WSADATA wsaData;
	int error;


	/*��ʼ���׽��ֿ�*/
	wVersionRequested = MAKEWORD(2, 2);     /*MAKEWORD�ǽ������ֽ���ϳ�һ���֣�ǰ���Ǹ��ֽڣ������ǵ��ֽڣ���ʾ2.2�汾*/
	error = WSAStartup(wVersionRequested, &wsaData); /*�����׽��ֿ⣬��ʼ��Ws2����32.dll��̬���ӿ�*/
	if (error != 0)
	{
		printf("�����׽���ʧ�ܣ�");
		return 0;
	}
	if (LOBYTE(wsaData.wVersion) != 2 ||
		HIBYTE(wsaData.wVersion) != 2)         /*�ж�������صİ汾���Ƿ����Ҫ��*/
	{
		WSACleanup();                /*�����ϣ��ر��׽��ֿ�*/
		return 0;
	}


	/*���÷�������ַ*/
	Server_add.sin_family = AF_INET;
	Server_add.sin_addr.S_un.S_addr = inet_addr("192.168.0.103");   /*���ַ�����ʾ�ĵ�ַת���޷��ų���������*/
	Server_add.sin_port = htons(5000);

	/*���ӷ�����*/
	socket_send = socket(AF_INET, SOCK_STREAM, 0);    /*�ͻ��˴����׽��֣�������Ҫ�󶨣�ֻ����������������Ӽ���*/


	/*�����������ӵ��׽���*/
	if (connect(socket_send,(SOCKADDR*)&Server_add,sizeof(SOCKADDR))==SOCKET_ERROR)
	{
		printf("����ʧ�ܣ�");
		return 0;
	}


	/*��������*/
	while (1)
	{
		/*��������*/
		printf("please enter message:");
		scanf_s("%s", Sendbuf,100);
		Sendlen = send(socket_send, Sendbuf, 100, 0);
		if (Sendlen<0)
		{
			printf("����ʧ�ܣ�");
		}


		/*��������*/
		Receivelen = recv(socket_send, Receivebuf, 100, 0);
		if(Receivelen<0)
		{
			printf("����ʧ�ܣ��˳�����");
			break;
		}
		else
		{
			printf("Server say:%s\n", Receivebuf);
		}
	}

	/*�ͷ��׽���*/
	closesocket(socket_send);
	WSACleanup();
	return 0;
}