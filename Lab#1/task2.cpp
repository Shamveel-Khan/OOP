#include <iostream>
using namespace std;

int main() {
    int choice;
    int start = 1;
    int aqi1[4][28] = {0};
    int aqi2Averages[4][4] = {0};
    float aqi1Averages[4]={0};
    while (start) {
        cout << "enter your choice\n0.for Exit\n1.weekly AQI tracker\n2.critical polution days\n";
        cin >> choice;
        switch (choice) {
            case 0:
                start = 0;
                break;
            case 1: {
                int highest1 = 0;
                float highest1f = 0.0;
                for (int i = 0; i < 4; i++) {
                    for (int j = 0; j < 7; j++) {
                        cout << "for city " << i + 1 << " on day # " << j + 1 << ": ";
                        cin >> aqi1[i][j];
                    }
                }
                float aqi1Averages[4];
                for (int i = 0; i < 4; i++) {
                    int sum1 = 0;
                    for (int j = 0; j < 7; j++) {
                        sum1 += aqi1[i][j];
                    }
                    aqi1Averages[i] = (float)sum1 / 7.0;
                }
                for (int i = 0; i < 4; i++) {
                    if (highest1f < aqi1Averages[i]) {
                        highest1 = i + 1;
                        highest1f = aqi1Averages[i];
                    }
                    cout << "the average for city# " << i + 1 << ": " << aqi1Averages[i] << endl;
                }
                cout << "highest Aqi was " << highest1f << " for city# " << highest1 << endl;
            }
            break;
            case 2:
                for (int i = 0; i < 4; i++) {
                    cout << "for city# " << i + 1 << " " << endl;
                    for (int j = 0; j < 7; j++) {
                        if (aqi1[i][j] >= 150) {
                            cout << "day# " << j + 1 << endl;
                        }
                    }
                    cout << endl;
                }
                break;
            case 3:
                for (int i = 0; i < 4; i++) {
                    cout << "for city# " << i + 1 << " ";
                    for (int j = 0; j < 7; j++) {
                        if (aqi1[i][j] >= 50) {
                            cout << " * ";
                        }
                    }
                    cout << endl;
                }
                break;
            case 4: {
                int city = 0;
                for (int i = 0; i < 4; i++) {
                    cout << "enter for city# " << i + 1 << " ";
                    for (int j = 7; j < 28; j++) {
                        cout << "enter for day# " << j + 1 << " ";
                        cin >> aqi1[i][j];
                    }
                    cout << endl;
                }
                for (int i = 0; i < 4; i++) {
                    int sum2 = 0;
                    int k = 0;
                    for (int j = 0; j < 28; j++) {
                        sum2 += aqi1[i][j];
                        if ((j + 1) % 7 == 0) {
                            aqi2Averages[i][k++] = sum2 / 7;
                            sum2 = 0;
                        }
                    }
                }
                int diff = 0;
                for (int i = 0; i < 4; i++) {
                    if (diff < (aqi2Averages[i][0] - aqi2Averages[i][3])) {
                        diff = aqi2Averages[i][0] - aqi2Averages[i][3];
                        city = i + 1;
                    }
                }
                cout << "the largest drop was for: " << city << endl;
                break;
            }
            case 5: {
                int max = -1;
                int min = 1000;
                cout << "WEEEKLY AVERAGES:" << endl;
                for (int i = 0; i < 4; i++) {
                    cout << "for city# " << i + 1 << endl;
                    for (int j = 0; j < 4; j++) {
                        cout << "week# " << j + 1 << " " << aqi2Averages[i][j] << endl;
                    }
                    cout << endl;
                }
                for (int i = 0; i < 4; i++) {
                    for (int j = 0; j < 28; j++) {
                        if (aqi1[i][j] >= 150) {
                            cout << "for city # " << i + 1 << " day# " << j + 1 << endl;
                        }
                        if (max < aqi1[i][j]) {
                            max = aqi1[i][j];
                        }
                        if (min > aqi1[i][j]) {
                            min = aqi1[i][j];
                        }
                    }
                }
                cout << "the highest aqi ever was: " << max << endl;
                cout << "the lowest aqi ever was: " << min << endl;
                break;
            }
        }
    }
}
