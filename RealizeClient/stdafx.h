// stdafx.h : ���� ��������� ���� ��������� �ʴ�
// ǥ�� �ý��� ���� ���� �� ������Ʈ ���� ���� ������
// ��� �ִ� ���� �����Դϴ�.
//

#pragma once

// TODO: ���α׷��� �ʿ��� �߰� ����� ���⿡�� �����մϴ�.
#include <thread>
#include <mutex>
#include <map>
#include <string>

using namespace std;

#ifdef WIN32
	#define WIN32_LEAN_AND_MEAN             // ���� ������ �ʴ� ������ Windows ������� �����մϴ�.
	#include <WinSock2.h>
	#pragma comment(lib, "ws2_32.lib")
	typedef int				socklen_t;
#else
	#include <sys/socket.h>
	#include <netinet/in.h>
	#include <netdb.h>
	#include <fcntl.h>
	#include <unistd.h>
	#include <sys/stat.h>
	#include <sys/types.h>
	#include <arpa/inet.h>
	#include <errno.h>
	typedef int				SOCKET;

	//#pragma region define win32 const variable in linux
	#define INVALID_SOCKET	-1
	#define SOCKET_ERROR	-1
	//#pragma endregion
#endif