#pragma once
// @credits: https://github.com/ValveSoftware/source-sdk-2013/blob/master/sp/src/public/cdll_int.h

class IClientNetworkable;
using CreateClientClassFn = IClientNetworkable*(__cdecl*)(int, int);
using CreateEventFn = IClientNetworkable*(__cdecl*)();

struct RecvTable_t;
enum class EClassIndex;

// @credits: https://github.com/ValveSoftware/source-sdk-2013/blob/master/sp/src/public/client_class.h
class CBaseClient
{
public:
	CreateClientClassFn		pCreateFn;
	CreateEventFn			pCreateEventFn;
	char*					szNetworkName;
	RecvTable_t*			pRecvTable;
	CBaseClient*			pNext;
	EClassIndex				nClassID;
};

using CreateInterfaceFn = void*(__cdecl*)(const char*, int*);
using InstantiateInterfaceFn = void*(__cdecl*)(void);
using DemoCustomDataCallbackFn = void(__cdecl*)(unsigned char*, std::size_t);

class IGlobalVarsBase;
class IBaseClientDll
{
public:
	CBaseClient* GetAllClasses()
	{
		return MEM::CallVFunc<CBaseClient*>(this, 8);
	}

	bool DispatchUserMessage(int iMessageType, unsigned int a3, unsigned int uBytes, void* bfMessageData)
	{
		return MEM::CallVFunc<bool>(this, 38, iMessageType, a3, uBytes, bfMessageData);
	}
};
