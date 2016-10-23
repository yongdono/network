/**
利用对应的地址或者传入的servicename 生成对应的一组sock

**/

#ifndef INETSOCK_H
#define INETSOCK_H

#include "socks.h"
#include "./ServiceName.h"
#include "Channel.h"
#include <map>
class CInetSock
{
public:
  CInetSock(void);
  CInetSock(char* location);
  CInetSock(CServiceName* service);
  int Getfd();
  virtual  CChannel* GetChannel(int fd);
  virtual CChannel* AddChannel(int fd,const CServiceName* service= NULL);
  virtual ~CInetSock();

  virtual int CreateSocket();
  virtual int Connect(CServiceName* server){return 0;};
  virtual int Accept(){ return 0;};
private:
  CServiceName* m_service;
  int m_fd;
  std::map<int,CChannel*> m_chanelmap;
};


#endif
