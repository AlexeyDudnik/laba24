#include <iostream>
#include <vector>
#include <deque>
#include <string>
#include <algorithm>
#include <fstream>
using namespace std;
class Bank {
	string name;
	double summ;
	string type;
	double bet;
public:
	Bank(string name, double summ, string type, double bet) : name(name), summ(summ), type(type), bet(bet) {}
	friend ostream& operator<<(ostream& os, const Bank& dt) {
		os << "Name: " << dt.name << ", Sum: " << dt.summ << ", Type: " << dt.type << ", Bet: " << dt.bet;
		return os;
	}
	bool operator<(const Bank& o) const {
		return summ < o.summ;
	}
};
int main()
{
	vector <Bank> bank;
	ifstream infile("input.txt");
	string name, type;
	double summ, bet;
	while (infile >> name >> summ >> type >> bet) {
		bank.emplace_back(name, summ, type, bet);
	}
	sort(bank.begin(), bank.end());
	for (const auto& bank : bank) {
		cout << bank << endl;
	}
	deque <Bank> c_bank;
	copy(bank.begin(), bank.end(), back_inserter(c_bank));
	ofstream outfile("output.txt");
	for (const auto& c_bank : c_bank) {
		cout << c_bank << endl;
	}
}
