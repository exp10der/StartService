#include <Windows.h>
#include <iostream>
#include <string>

int main()
{
	int error = 0;
	SC_HANDLE scm_handle = OpenSCManager(0,
		0,
		SC_MANAGER_ALL_ACCESS);


	SC_HANDLE service_handle = OpenService(scm_handle,
		L"WlanSvc",
		/*
		* NOTE: Для теста получения ошибки
		* SERVICE_QUERY_CONFIG);
		*/
		SERVICE_ALL_ACCESS);



	bool flagErr = false;
	flagErr = StartService(service_handle, 0, 0);

	if (!flagErr)
	{
		error = GetLastError();
	}


	std::cout << ((flagErr == true) ? "Service Started" : "GetLastError = " + std::to_string(error));


	CloseServiceHandle(service_handle);
	CloseServiceHandle(scm_handle);

	return 0;
}