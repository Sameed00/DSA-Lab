#include <iostream>
using namespace std;

int main(){
    
    int m, i, j;
    
    float **data;
    int *readings;
    float *avgdays;
    
    cout << "enter number of days: ";
    cin >> m;
    
    readings = new int[m];
    data = new float*[m];
    avgdays = new float[m];
    
    for (i = 0; i < m; i++){
        cout << "enter number of readings for day " << i + 1 << ": ";
        cin >> readings[i];
        data[i] = new float[readings[i]];
    }
    
    for (i = 0; i < m; i++){
        for (j = 0; j < readings[i]; j++){
            cout << "enter temp for day " << i + 1 << " reading " << j + 1 << ": ";
            cin >> data[i][j];
        }
    }
    
    cout << "printing data for all days." << endl;
    
    float total = 0.0;
    
    for (i = 0; i < m; i++){
        for (j = 0; j < readings[i]; j++){
            total = total + data[i][j];
            cout << " " << data[i][j] << " ";
        }
        avgdays[i] = total / readings[i];
        total = 0.0;
        cout << endl;
    }
    
    float high = 0, low = 999;
    int hindex, lindex;
    
    for (i = 0; i < m; i++){
        if (avgdays[i] > high){
            high = avgdays[i];
            hindex = i;
        }
        if (avgdays[i] < low){
            low = avgdays[i];
            lindex = i;
        }
    }
    
    cout << "hottest day was day " << hindex + 1 << " with avg temp of: " << high << "c" << endl;
    cout << "coldest day was day " << lindex + 1 << " with avg temp of: " << low << "c" << endl;
    
    for (i = 0; i < m; i++){
        delete[] data[i];
    }
    
    delete[] data;
    delete[] readings;
    delete[] avgdays;
}
