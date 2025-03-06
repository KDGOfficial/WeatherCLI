#include <iostream>
#include <windows.h>
#include <vector>
#pragma comment(lib, "urlmon.lib")

using namespace std;

int main()
{
    const string baseURL = "https://sinoptik.ua/ru/pog���-";
    const string destFile = "weather2.html";

    // ���������� �������� �����
    if (S_OK == URLDownloadToFileA(NULL, baseURL.c_str(), destFile.c_str(), 0, NULL))
        cout << "Saved to " << destFile << "\n";
    else
    {
        cout << "Failed to download the file.\n";
        return 1;
    }

    // ������ ��� �������� ������
    vector<string> favoriteCities =
    {
        "kyiv", "odesa", "lviv", "dnipro", "kharkiv",
        "chernihiv", "vinnytsia", "zaporizhzhia", "ivano-frankivsk", "uzhhorod"
    };

    cout << "Fetching weather data...\n";

    // ����� ������ �������
    for (const auto& city : favoriteCities)
    {
        string filename = "weather_" + city + ".html";
        string url = baseURL + city;

        if (S_OK != URLDownloadToFileA(NULL, url.c_str(), filename.c_str(), 0, NULL))
            cout << "Failed to download weather data for " << city << "\n";
    }

    cout << "\nEnter city name: ";
    string userCity;
    cin >> userCity;

    string userFilename = "weather_" + userCity + ".html";
    string userURL = baseURL + userCity;

    // ���������� ������ �� ��������� ������
    if (S_OK == URLDownloadToFileA(NULL, userURL.c_str(), userFilename.c_str(), 0, NULL))
    {
        cout << "Saved to " << userFilename << "\n";
        ShellExecuteA(NULL, "open", userFilename.c_str(), NULL, NULL, SW_SHOWNORMAL);
    }
    else
        cout << "Failed to download weather data for " << userCity << "\n";

    return 0;
}
