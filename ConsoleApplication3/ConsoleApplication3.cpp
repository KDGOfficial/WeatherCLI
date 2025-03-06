#include <iostream>
#include <windows.h>
#pragma comment(lib, "urlmon.lib")

using namespace std;

int main()
{
    const char* srcURL = "https://sinoptik.ua/";
    const char* destFile = "weather.html";

    if (S_OK == URLDownloadToFileA(NULL, srcURL, destFile, 0, NULL))
        cout << "\n[+] \u0424\u0430\u0439\u043b \u0437\u0430\u0432\u0430\u043d\u0442\u0430\u0436\u0435\u043d\u043e: " << destFile << "\n";
    else
    {
        cout << "\n[-] \u041f\u043e\u043c\u0438\u043b\u043a\u0430 \u043f\u0440\u0438 \u0437\u0430\u0432\u0430\u043d\u0442\u0430\u0436\u0435\u043d\u043d\u0456!\n";
        return 1;
    }

    FILE* f;
    fopen_s(&f, destFile, "r+");

    if (!f)
    {
        cout << "\n[-] \u041f\u043e\u043c\u0438\u043b\u043a\u0430 \u043f\u0440\u0438 \u0432\u0456\u0434\u043a\u0440\u0438\u0442\u0442\u0456 \u0444\u0430\u0439\u043b\u0443!\n";
        return 1;
    }

    char text[200];
    while (fgets(text, sizeof(text) - 1, f))
    {
        AnsiToOem(text, text);
        cout << text;
    }

    fclose(f);

    cout << "\n[+] \u0412\u0456\u0434\u043a\u0440\u0438\u0432\u0430\u044e \u0444\u0430\u0439\u043b...\n";
    ShellExecuteA(NULL, "open", destFile, NULL, NULL, SW_SHOWNORMAL);
    return 0;
}
