#include "stdafx.h"
#include "Function.h"

NS_REALIZE_BEGIN

string stringf(const char* format, ...)
{
	char* stringf_formatted_str; // ���������� ���˵� ���ڿ��� �����ϴ� ������
	char stringf_buffer[1024]; // stringf�� �⺻ ����

	va_list valist;

	va_start(valist, format);

	int stringf_sizeof_str = vsnprintf_s(NULL, 0, 0, format, valist);
	if(stringf_sizeof_str >= 1024) // ��� ���ڿ��� ���̰� 1024 �̻��� ��� �޸𸮸� ���� �Ҵ��մϴ�.
		stringf_formatted_str = new char[stringf_sizeof_str + 1];
	else
		stringf_formatted_str = stringf_buffer;

	vsprintf_s(stringf_formatted_str, stringf_sizeof_str >= 1024 ? stringf_sizeof_str : 1024, format, valist);

	string lpszResult(stringf_formatted_str);

	if(stringf_sizeof_str >= 1024) // ��� ���ڿ��� ���̰� 1024 �̻��� ��� �޸𸮸� �Ҵ������Ƿ� �������ݴϴ�.
		delete[] stringf_formatted_str;

	va_end(valist);

	return lpszResult;
}

char* getIPFromSocket(SOCKET socket)
{
	sockaddr_in socket_address;
	int namelen = sizeof(socket_address);

	getpeername(socket, reinterpret_cast<sockaddr*> (&socket_address), &namelen);

	return inet_ntoa(socket_address.sin_addr);
}

NS_REALIZE_END