#include "global.h"

int main()
{
	SetConsoleTitle(L"Serial Checker Made By _onez.01 << discord");
	std::vector<BYTE> ekData = Utils::GetEK();
	if (ekData.empty())
	{
		printf("Cannot get TPM data!\n");
		return EXIT_FAILURE;
	}

	printf("---------------------------------------------------------------------------------------\n");
	printf("BIOS\n");
	printf("---------------------------------------------------------------------------------------\n");
	system("wmic bios get serialnumber");
	system("wmic csproduct get uuid");
	printf("---------------------------------------------------------------------------------------\n");
	printf("CPU\n");
	printf("---------------------------------------------------------------------------------------\n");
	system("wmic cpu get serialnumber");
	system("wmic cpu get processorid");
	printf("---------------------------------------------------------------------------------------\n");
	printf("DISKDRIVE\n");
	printf("---------------------------------------------------------------------------------------\n");
	system("wmic diskdrive get serialnumber");
	printf("---------------------------------------------------------------------------------------\n");
	printf("BASEBOARD\n");
	printf("---------------------------------------------------------------------------------------\n");
	system("wmic baseboard get serialnumber");
	printf("---------------------------------------------------------------------------------------\n");
	printf("RAM\n");
	printf("---------------------------------------------------------------------------------------\n");
	system("wmic memorychip get serialnumber");
	printf("---------------------------------------------------------------------------------------\n");
	printf("GPU\n");
	printf("---------------------------------------------------------------------------------------\n");
	system("wmic PATH Win32_VideoController GET Description, PNPDeviceID");
	printf("---------------------------------------------------------------------------------------\n");
	printf("TPM\n");
	printf("---------------------------------------------------------------------------------------\n");
	printf("MD5:     %s\n", Utils::GetKeyHash(ekData, CALG_MD5).c_str());
	printf("SHA1:    %s\n", Utils::GetKeyHash(ekData, CALG_SHA1).c_str());
	printf("SHA256:  %s\n", Utils::GetKeyHash(ekData, CALG_SHA_256).c_str());
	printf("---------------------------------------------------------------------------------------\n");

	Sleep(10000);

	return EXIT_SUCCESS;
}