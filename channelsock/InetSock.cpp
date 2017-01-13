#include "InetSock.h"
#include "UdpChannel.h"
#include <map>

using namespace std;
CInetSock::CInetSock(void)
{
	m_service =  new CServiceName("");
}

CInetSock::CInetSock(const char* location)
{
	m_service = new CServiceName(location);
}

CInetSock::CInetSock(CServiceName* service)
{
	m_service = service;
}

CInetSock::~CInetSock()
{
	if(m_service != NULL)
		delete m_service;
	m_service = NULL;
}

int CInetSock::CreateSocket()
{
	m_fd = socket(AF_INET,m_service->GetNChannel(),0);
	return m_fd;
}

int CInetSock::Getfd()
{
	return m_fd;
}


CChannel* CInetSock::GetChannel(int fd)
{
	if(m_chanelmap.find(fd) != m_chanelmap.end())
		return m_chanelmap[fd];
	return NULL;
}

CChannel* CInetSock::AddChannel(int fd,const CServiceName* service)
{
	if(m_chanelmap.find(fd) == m_chanelmap.end())
	{
		if(service->GetNChannel() == 1)
			m_chanelmap[fd] = new CChannel(fd);
		else
			m_chanelmap[fd] = new CUdpChannel(fd);
	}
	m_chanelmap[fd]->SetService(*service);
	return m_chanelmap[fd];
}
