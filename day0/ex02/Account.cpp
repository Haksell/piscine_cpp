#include "Account.hpp"
#include <ctime>
#include <iomanip>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

class variant {
public:
	variant(const std::string& str) : type(STRING), str(str) {}
	variant(int n) : type(INT), n(n) {}

	bool operator==(const variant& v) const {
		if (this->type == STRING)
			return v.type == STRING && this->str == v.str;
		else
			return v.type == INT && this->n == v.n;
	}

	std::string to_string() const {
		std::stringstream ss;
		switch (type) {
		case STRING:
			ss << str;
			break;
		case INT:
			ss << n;
			break;
		}
		return ss.str();
	}

private:
	enum Type { STRING, INT };

	Type type;
	std::string str;
	int n;
};

std::ostream& operator<<(std::ostream& os, const variant& v) {
	os << v.to_string();
	return os;
}

typedef std::pair<std::string, variant> logpair_t;
typedef std::vector<logpair_t> logpairs_t;

static void displayTimestamp() {
	std::time_t t = std::time(0);
	std::tm* now = std::localtime(&t);
	std::cout << '[' << (now->tm_year + 1900) << std::setfill('0') << std::setw(2)
			  << (now->tm_mon + 1) << std::setfill('0') << std::setw(2) << now->tm_mday << '_'
			  << std::setfill('0') << std::setw(2) << now->tm_hour << std::setfill('0')
			  << std::setw(2) << now->tm_min << std::setfill('0') << std::setw(2) << now->tm_sec
			  << "] ";
}

static void logLine(logpairs_t pairs) {
	displayTimestamp();
	for (size_t i = 0; i < pairs.size(); ++i) {
		if (i != 0)
			std::cout << ';';
		std::cout << pairs[i].first;
		if (!(pairs[i].second == variant(-1)))
			std::cout << ':' << pairs[i].second;
	}
	std::cout << '\n';
}

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

Account::Account(int initial_deposit) {
	this->_accountIndex = Account::_nbAccounts;
	this->_amount = initial_deposit;
	this->_nbDeposits = 0;
	this->_nbWithdrawals = 0;
	++Account::_nbAccounts;
	Account::_totalAmount += initial_deposit;
	logpairs_t pairs;
	pairs.push_back(std::make_pair("index", this->_accountIndex));
	pairs.push_back(std::make_pair("amount", this->_amount));
	pairs.push_back(std::make_pair("created", -1));
	logLine(pairs);
}

Account::Account() {
	this->_accountIndex = Account::_nbAccounts;
	this->_amount = 0;
	this->_nbDeposits = 0;
	this->_nbWithdrawals = 0;
	++Account::_nbAccounts;
}

Account::~Account() {
	logpairs_t pairs;
	pairs.push_back(std::make_pair("index", this->_accountIndex));
	pairs.push_back(std::make_pair("amount", this->_amount));
	pairs.push_back(std::make_pair("closed", -1));
	logLine(pairs);
}

int Account::getNbAccounts() { return Account::_nbAccounts; }
int Account::getTotalAmount() { return Account::_totalAmount; }
int Account::getNbDeposits() { return Account::_totalNbDeposits; }
int Account::getNbWithdrawals() { return Account::_totalNbWithdrawals; }

void Account::displayAccountsInfos() {
	logpairs_t pairs;
	pairs.push_back(std::make_pair("accounts", Account::_nbAccounts));
	pairs.push_back(std::make_pair("total", Account::_totalAmount));
	pairs.push_back(std::make_pair("deposits", Account::_totalNbDeposits));
	pairs.push_back(std::make_pair("withdrawals", Account::_totalNbWithdrawals));
	logLine(pairs);
}

void Account::makeDeposit(int deposit) {
	Account::_totalAmount += deposit;
	++Account::_totalNbDeposits;
	this->_amount += deposit;
	++this->_nbDeposits;
	logpairs_t pairs;
	pairs.push_back(std::make_pair("index", this->_accountIndex));
	pairs.push_back(std::make_pair("p_amount", this->_amount - deposit));
	pairs.push_back(std::make_pair("deposit", deposit));
	pairs.push_back(std::make_pair("amount", this->_amount));
	pairs.push_back(std::make_pair("nb_deposits", this->_nbDeposits));
	logLine(pairs);
}

bool Account::makeWithdrawal(int withdrawal) {
	logpairs_t pairs;
	pairs.push_back(std::make_pair("index", this->_accountIndex));
	pairs.push_back(std::make_pair("p_amount", this->_amount));
	if (withdrawal > this->_amount) {
		pairs.push_back(std::make_pair("withdrawal", variant("refused")));
		logLine(pairs);
		return false;
	} else {
		Account::_totalAmount -= withdrawal;
		++Account::_totalNbWithdrawals;
		this->_amount -= withdrawal;
		++this->_nbWithdrawals;
		pairs.push_back(std::make_pair("withdrawal", withdrawal));
		pairs.push_back(std::make_pair("amount", this->_amount));
		pairs.push_back(std::make_pair("nb_withdrawals", this->_nbWithdrawals));
		logLine(pairs);
		return true;
	}
}

int Account::checkAmount() const { return this->_amount; }

void Account::displayStatus() const {
	logpairs_t pairs;
	pairs.push_back(std::make_pair("index", this->_accountIndex));
	pairs.push_back(std::make_pair("amount", this->_amount));
	pairs.push_back(std::make_pair("deposits", this->_nbDeposits));
	pairs.push_back(std::make_pair("withdrawals", this->_nbWithdrawals));
	logLine(pairs);
}

void Account::_displayTimestamp() { displayTimestamp(); }
