#include <iostream>
#include <string>
#include <curl/curl.h>
#include "json.hpp"
using namespace std;


using json = nlohmann::json;
using namespace std;

/* Callback function for CURL */
size_t WriteCallback(void* contents, size_t size, size_t nmemb, string* output) {
    size_t totalSize = size * nmemb;
    output->append((char*)contents, totalSize);
    return totalSize;
}

int main() {
    CURL* curl;
    CURLcode res;
    string readBuffer;

    string apiKey = "YOUR_API_KEY";
    string city = "Delhi";

    string url = "https://api.openweathermap.org/data/3.0/onecall?lat={lat}&lon={lon}&exclude={part}&appid={API key}" +
                 city + "&appid=" + apiKey + "&units=metric";

    curl = curl_easy_init();
    if (curl) {
        curl_easy_setopt(curl, CURLOPT_URL, url.c_str());
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, &readBuffer);

        res = curl_easy_perform(curl);
        curl_easy_cleanup(curl);
    }

    // Parse JSON
    json data = json::parse(readBuffer);

    double temperature = data["main"]["temp"];
    int humidity = data["main"]["humidity"];

    cout << "City: " << city << endl;
    cout << "Temperature: " << temperature << " °C" << endl;
    cout << "Humidity: " << humidity << " %" << endl;

    return 0;
}