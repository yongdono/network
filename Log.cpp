#include "Log.h"
#include <cerrno>
#include <cstring>
using namespace std;



CLog* CLog::g_Log = NULL;

CLog* CLog::GetInstance()
{
  if(g_Log == NULL)
  {
    return g_Log = new CLog();
  }
  else
    return g_Log;
}

CLog::CLog()
{
  ;
}
CLog:: ~CLog()
{
  delete g_Log;
  g_Log = NULL;
}

void CLog::Printerrno(int error)
{
    #ifdef WINDOWS

    #else
    cout<<error<<"\t"<<strerror(error)<<endl;
    #endif // WINDOWS

}
