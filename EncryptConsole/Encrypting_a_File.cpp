#include "Encrypting_a_File.h"
int _tmain(int argc, _TCHAR* argv[])
{
    if (argc < 3)
    {
        _tprintf(TEXT("Usage: <example.exe> <source file> ")
            TEXT("<destination file> | <password>\n"));
        _tprintf(TEXT("<password> is optional.\n"));
        _tprintf(TEXT("Press any key to exit."));
        _gettch();
        return 1;
    }

    LPTSTR pszSource = argv[1];
    LPTSTR pszDestination = argv[2];
    LPTSTR pszPassword = NULL;

    if (argc >= 4)
    {
        pszPassword = argv[3];
    }

    //---------------------------------------------------------------
    // Call EncryptFile to do the actual encryption.
    if (MyEncryptFile(pszSource, pszDestination, pszPassword))
    {
        _tprintf(
            TEXT("Encryption of the file %s was successful. \n"),
            pszSource);
        _tprintf(
            TEXT("The encrypted data is in file %s.\n"),
            pszDestination);
    }
    else
    {
        MyHandleError(
            (LPTSTR)TEXT("Error encrypting file!\n"),
            GetLastError());
    }

    return 0;
}

