#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

class CurrencyConverter {
public:
    CurrencyConverter() {
        countries = {
            {"United States", "USD"}, {"China", "CNY"}, {"Japan", "JPY"}, {"Germany", "EUR"}, 
            {"India", "INR"}, {"United Kingdom", "GBP"}, {"France", "EUR"}, {"Italy", "EUR"},
            {"Canada", "CAD"}, {"South Korea", "KRW"}, {"Australia", "AUD"}, {"Brazil", "BRL"},
            {"Russia", "RUB"}, {"Spain", "EUR"}, {"Mexico", "MXN"}, {"Indonesia", "IDR"},
            {"Netherlands", "EUR"}, {"Saudi Arabia", "SAR"}, {"Turkey", "TRY"}, {"Switzerland", "CHF"},
            {"Taiwan", "TWD"}, {"Sweden", "SEK"}, {"Poland", "PLN"}, {"Belgium", "EUR"},
            {"Argentina", "ARS"}, {"Thailand", "THB"}, {"Nigeria", "NGN"}, {"South Africa", "ZAR"},
            {"Egypt", "EGP"}, {"Pakistan", "PKR"}, {"Chile", "CLP"}, {"Malaysia", "MYR"},
            {"Vietnam", "VND"}, {"United Arab Emirates", "AED"}, {"Hong Kong", "HKD"}, {"Israel", "ILS"},
            {"Singapore", "SGD"}, {"Norway", "NOK"}, {"Ireland", "EUR"}, {"Colombia", "COP"},
            {"Philippines", "PHP"}, {"Bangladesh", "BDT"}, {"Peru", "PEN"}, {"Nepal", "NPR"}
        };

        exchangeRates = {
            {"USD", 84.29}, {"CNY", 11.74}, {"JPY", 0.55}, {"EUR", 90.50}, {"INR", 1.0},
            {"GBP", 108.69}, {"CAD", 60.48}, {"KRW", 67.74}, {"AUD", 55.50}, {"BRL", 14.67},
            {"RUB", 1.13}, {"MXN", 4.15}, {"IDR", 0.0060}, {"SAR", 23.60}, {"TRY", 4.89},
            {"CHF", 96.22}, {"TWD", 2.56}, {"SEK", 9.16}, {"PLN", 20.33}, {"ARS", 0.085},
            {"THB", 2.46}, {"NGN", 0.0079}, {"ZAR", 4.35}, {"EGP", 2.72}, {"PKR", 1.86},
            {"CLP", 0.12}, {"MYR", 19.14}, {"VND", 0.0035}, {"AED", 22.93}, {"HKD", 10.83},
            {"ILS", 28.59}, {"SGD", 62.34}, {"NOK", 8.90}, {"COP", 0.022}, {"PHP", 1.43},
            {"BDT", 0.86}, {"PEN", 0.28}, {"NPR", 0.625}
        };
    }

    void findCurrencyCodeByCountry(const string &countryName) {
        if (countries.find(countryName) != countries.end()) {
            cout << "The currency code for " << countryName << " is: " << countries[countryName] << endl;
        } else {
            cout << "Country not found!" << endl;
        }
    }

    void displayExchangeRate(const string &fromCurrency, const string &toCurrency) {
        if (exchangeRates.find(fromCurrency) != exchangeRates.end() && exchangeRates.find(toCurrency) != exchangeRates.end()) {
            double rateFrom = exchangeRates[fromCurrency];
            double rateTo = exchangeRates[toCurrency];
            double exchangeRate = rateFrom / rateTo;
            cout << "Exchange rate from " << fromCurrency << " to " << toCurrency << " is: " << exchangeRate << endl;
        } else {
            cout << "Currency not found!" << endl;
        }
    }

    void convertCurrency(const string &fromCurrency, const string &toCurrency, double amount) {
        if (exchangeRates.find(fromCurrency) != exchangeRates.end() && exchangeRates.find(toCurrency) != exchangeRates.end()) {
            double rateFrom = exchangeRates[fromCurrency];
            double rateTo = exchangeRates[toCurrency];
            double exchangeRate = rateFrom / rateTo;
            double result = amount * exchangeRate;
            cout << amount << " " << fromCurrency << " is " << result << " " << toCurrency << endl;
        } else {
            cout << "Currency not found!" << endl;
        }
    }

private:
    unordered_map<string, string> countries;
    unordered_map<string, double> exchangeRates;
};

int main() {
    CurrencyConverter converter;
    string countryName, fromCurrency, toCurrency;
    double amount;
    
    cout << "Welcome to the Currency Converter!" << endl;

    while (true) {
        cout << "\nSelect an option:\n";
        cout << "1. Find currency code by country name\n";
        cout << "2. View exchange rate between two currencies\n";
        cout << "3. Convert currency\n";
        cout << "4. Exit\n";
        
        int choice;
        cin >> choice;

        if (choice == 1) {
            cout << "Enter country name: ";
            cin.ignore(); 
            getline(cin, countryName);
            converter.findCurrencyCodeByCountry(countryName);
        } else if (choice == 2) {
            cout << "Enter source currency code: ";
            cin >> fromCurrency;
            cout << "Enter target currency code: ";
            cin >> toCurrency;
            converter.displayExchangeRate(fromCurrency, toCurrency);
        } else if (choice == 3) {
            cout << "Enter source currency code: ";
            cin >> fromCurrency;
            cout << "Enter target currency code: ";
            cin >> toCurrency;
            cout << "Enter amount to convert: ";
            cin >> amount;
            converter.convertCurrency(fromCurrency, toCurrency, amount);
        } else if (choice == 4) {
            break; 
        } else {
            cout << "Invalid choice! Please try again.\n";
        }
    }
    return 0;
}