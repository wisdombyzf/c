#define _CRT_SECURE_NO_WARNINGS
//#include  <stdafx.h>
#include    <stdio.h> 
#include    <winsock.h> 
#include    <string.h> 
#pragma comment(lib, "ws2_32.lib") 

#define PORT 80
#define SIZE 512
#define MAX_SIZE 1024

void buildGETHeader(char* header, int size, char* host, char* res)
{
	memset(header, 0, size);
	strcat(header, "GET ");
	strcat(header, res);
	strcat(header, " HTTP/1.1\r\n");
	strcat(header, "HOST:");
	strcat(header, host);
	strcat(header, "\r\nConnection: Keep-Alive\r\n\r\n");

	return;
}

void buildPOSTHeader(char* header, int size, char* host, char* res)
{
	memset(header, 0, size);
	strcat(header, "POST ");
	strcat(header, res);
	strcat(header, " HTTP/1.1\r\n");
	strcat(header, "HOST:");
	strcat(header, host);
	strcat(header, "\r\nContent-Type: application/x-www-form-urlencoded\r\n");
	strcat(header, "Content-Length: 8\r\n");
	strcat(header, "Connection: Keep-Alive\r\n\r\n");
	strcat(header, "user=zf\r\n\r\n");

	return;
}

void sendData(SOCKET serverSocket, char* data)
{
	send(serverSocket, data, strlen(data), 0);
}

void getData(SOCKET serverSocket, char* data, int size)
{
	int num = 0;
	char buf[SIZE];

	memset(data, 0, MAX_SIZE);
	memset(buf, 0, SIZE);
	while (recv(serverSocket, buf, SIZE, 0)>0)
	{
		strcat(data, buf);
		memset(buf, 0, SIZE);
	}
	return;
}

void parseURL(char*url, char*& host, char*& res)
{
	char* p;
	int num = 0;

	p = url + 7;
	while (*p != '/' && *p != '\0')
	{
		p++;
	}
	if (strlen(p) != 0)
	{
		num = strlen(p) + 1;
		res = (char*)malloc(num);
		memset(res, 0, num);
		strcpy(res, p);
	}
	else
	{
		res = (char*)malloc(2);
		memset(res, 0, 2);
		res[0] = '/';
	}
	*p = '\0';
	host = url + 7;

	return;
}

void connectToHost(char* host, SOCKET& serverSocket, char* res)
{
	WSAData wsadata = { 0 };
	struct sockaddr_in addr;
	struct hostent* pHost;
	char header[SIZE], buf[MAX_SIZE];

	if (WSAStartup(MAKEWORD(2, 2), &wsadata))
	{
		printf("WSASartup failed!\n");
		system("pause");
		exit(-1);
	}
	serverSocket = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
	pHost = gethostbyname(host);
	addr.sin_family = AF_INET;
	addr.sin_addr.S_un.S_addr = *((unsigned long*)pHost->h_addr);
	addr.sin_port = htons(PORT);
	connect(serverSocket, (SOCKADDR*)&addr, sizeof(addr));
	printf("Connect to host OK!\n");

	return;
}



int myhttp(void)
{
	char url[100] = "http://cxyzf.cn/cpp.php";
	char *host, *res, header[SIZE], buf[MAX_SIZE];
	SOCKET serverSocket;

	parseURL(url, host, res);
	connectToHost(host, serverSocket, res);
	/*buildGETHeader(header,SIZE,host,res);
	sendData(serverSocket,header);
	getData(serverSocket,buf,MAX_SIZE);
	printf("%s\n",buf);*/
	buildPOSTHeader(header, SIZE, host, res);
	sendData(serverSocket, header);
	getData(serverSocket, buf, MAX_SIZE);
	printf("%s\n", buf);



	closesocket(serverSocket);
	//WSACleanup();
	system("pause");
	return 0;
}
