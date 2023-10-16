#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>

using namespace std;

int main() {
    const int numMonths = 12;
    vector<string> months = {"Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"};
    vector<double> sales(numMonths);

    double sum = 0.0;

    for (int i = 0; i < numMonths; i++) {
        cout << "Enter sales for " << months[i] << ": ";
        cin >> sales[i];
        sum += sales[i];
    }

    double averageSale = sum / numMonths;
    auto minSale = min_element(sales.begin(), sales.end());
    auto maxSale = max_element(sales.begin(), sales.end());

    cout << "Sales Report for 2022" << endl;
    cout << "Month\tSales" << endl;
    for (int i = 0; i < numMonths; i++) {
        cout << months[i] << "\t$" << fixed << setprecision(2) << sales[i] << endl;
    }

    cout << "Sales Summary" << endl;
    cout << "Min sales: $" << fixed << setprecision(2) << *minSale << " (" << months[minSale - sales.begin()] << ")" << endl;
    cout << "Max sales: $" << fixed << setprecision(2) << *maxSale << " (" << months[maxSale - sales.begin()] << ")" << endl;
    cout << "Avg sales: $" << fixed << setprecision(2) << averageSale << endl;

    cout << "6-Month Avg Report" << endl;
    cout << "Month\tAvg" << endl;
    for (int i = 0; i < numMonths; i++) {
        double movingAverage = 0.0;
        int count = min(i + 1, 6);
        for (int j = i; j > i - 6 && j >= 0; j--) {
            movingAverage += sales[j];
        }
        movingAverage /= count;
        cout << months[i] << " - " << months[i - (count - 1)] << "\t$" << fixed << setprecision(2) << movingAverage << endl;
    }

    cout << "Sales (High to Low)" << endl;
    cout << "Month\tSales" << endl;
    vector<pair<string, double>> sortedSales;
    for (int i = 0; i < numMonths; i++) {
        sortedSales.push_back({months[i], sales[i]});
    }
    sort(sortedSales.begin(), sortedSales.end(), [](const auto& a, const auto& b) {
        return a.second > b.second;
    });
    for (const auto& [month, sale] : sortedSales) {
        cout << month << "\t$" << fixed << setprecision(2) << sale << endl;
    }

    return 0;
}