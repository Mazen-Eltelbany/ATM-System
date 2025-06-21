#include <iostream>
#include <cmath>
#include <vector>
#include <ctime>
#include <string>
#include <cctype>
#include <fstream>
#include <iomanip>
typedef double db;
#define vs vector<string>
#define vi vector<int>
using namespace std;
const string clientfilename = "../cli.txt";
struct clients {
	string accnum;
	string pincode;
	string name;
	string phone;
	double balance=0;
	bool marktodelete = false;
};
clients currentclient;
void gobacktoatmmainmenu();
void login();
void printquickwithdrawscreen();
void printnormalwithdrawscreen();
enum enquickwithdrawop {
	en20 = 1,
	en50 = 2,
	en100 = 3,
	en200 = 4,
	en400 = 5,
	en600 = 6,
	en800 = 7,
	en1000 = 8,
	enexit = 9,
};
enum enprocessinmainmenu{
	enquickwithdraw = 1,
	ennormalwithdraw = 2,
	endeposit=3,
	encheckbalance = 4,
	enlogout = 5,
};
string  readaccnum() {
	string AC;
	cout << "Enter your account number: ";
	getline(cin >> ws, AC);
	return AC;
}
string readpincode() {
	string pin;
	cout << "Enter your pincode: ";
	getline(cin >> ws, pin);
	return pin;
}
short readquickwithdraw() {
	short choice = 0;
	do {
		cout << "Choose What to withdraw from[1] to [9] ? ";
		cin >> choice;
	} while (choice < 1 || choice > 9);
	return choice;
}
vector<string>splitastring(string s, string sep = "#//#") {
	vs ves;
	int pos = 0;
	string word = "";
	while ((pos = s.find(sep)) != string::npos)
	{
		word = s.substr(0, pos);
		if (word != " ") {
			ves.push_back(word);

		}
		s.erase(0, pos + sep.length());
	}
	if (s != " ") {
		ves.push_back(s);
	}
	return ves;
}
clients converlinetorecord(string line,string sep="#//#") {
	vector<string> vcl=splitastring(line);
	clients cl;
	cl.accnum = vcl[0];
	cl.pincode = vcl[1];
	cl.name = vcl[2];
	cl.phone = vcl[3];
	cl.balance = stod(vcl[4]);
	return cl;
}
string converrecordtoline(clients cl,string sep="#//#") {
	string line = cl.accnum + sep + cl.pincode + sep + cl.name + sep+cl.phone+sep + to_string(cl.balance);
	return line;
}
vector<clients>getclientsfromffile(string filename) {
	vector<clients>vcl;
	fstream file;
	file.open(filename, ios::in);
	if (file.is_open()) {
		string line;
		clients cl;
		while (getline(file, line)) {
			cl = converlinetorecord(line);
			vcl.push_back(cl);
		}
		file.close();
	}
	return vcl;
}
vector<clients> saveclientdatatofile(string filename, vector<clients>vcl) {
	fstream file;
	file.open(filename, ios::out);
	string dataline;
	if (file.is_open()) {
		for (clients cl : vcl) {
			if (cl.marktodelete == false) {
				dataline = converrecordtoline(cl);
				file << dataline << endl;
			}
		}
		file.close();
	}
	return vcl;
}
bool findclientbyaccnumandpincode(string accnum, string pincode, clients& cl) {
	vector<clients> clientslist = getclientsfromffile(clientfilename);
	for (clients c : clientslist) {
		if (c.accnum == accnum && c.pincode == pincode) {
			cl = c;
			return true;
		}
	}
	return false;
}
bool depositbalancetoclientbyaccnum(string accnum, double amount, vector<clients>vcl) {
	char Answer = 'n';     
	cout << "\n\nAre you sure you want perfrom this transaction? y/n ? ";
	cin >> Answer;
	if (tolower(Answer) == 'y') {
		for (clients& cl : vcl) {
			if (cl.accnum == accnum) {
				cl.balance += amount;
				saveclientdatatofile(clientfilename, vcl);
				cout << "\n\nDone Successfully. New balance is: " << cl.balance << endl;
				return true;
			}
		}
	}
	return false;
}
short getquickwithdrawamount(enquickwithdrawop e) {
	switch (e)
	{
	case enquickwithdrawop::en20:
		return 20;
		break;
	case enquickwithdrawop::en50:
		return 50;
		break;
	case enquickwithdrawop::en100:
		return 100;
		break;
	case enquickwithdrawop::en200:
		return 200;
		break;
	case enquickwithdrawop::en400:
		return 400;
		break;
	case enquickwithdrawop::en600:
		return 600;
		break;
	case enquickwithdrawop::en800:
		return 800;
		break;
	case enquickwithdrawop::en1000:
		return 1000;
		break;
	default:
		return 0;
	}
}
void preformquickwithdraw(short quickwithdrawoption) {
	if (quickwithdrawoption == 9) {
		return;
	}
	short withdrawamount = getquickwithdrawamount((enquickwithdrawop)quickwithdrawoption);
	if (withdrawamount > currentclient.balance) {
		cout << "\nThe amount exceeds your balance,make another choice.\n";
		cout << "press any key to continue...\n";
		system("pause");
		printquickwithdrawscreen();
		return;
	}
	vector<clients>vcl = getclientsfromffile(clientfilename);
	depositbalancetoclientbyaccnum(currentclient.accnum, -withdrawamount, vcl);
	currentclient.balance -= withdrawamount;
}
void printquickwithdrawscreen() {
	system("cls");
	cout << "====================================\n";
	cout << "\tQuick Withdraw\n";
	cout << "====================================\n";
	cout << "\t[1] 20";
	cout << "\t\t[2] 50\n";
	cout << "\t[3] 100";
	cout << "\t\t[4] 200\n";
	cout << "\t[5] 400";
	cout << "\t\t[6] 600\n";
	cout << "\t[7] 800";
	cout << "\t\t[8] 1000\n";
	cout << "\t[9] Exit\n";
	cout << "=====================================\n";
	cout << "Your Balance is : " << currentclient.balance << "\n";
	preformquickwithdraw(readquickwithdraw());
}
short readamountofwithdraw() {
	short amount = 0;
	cout << "Enter an amount multiple of 5's ? ";
	cin >> amount;
	while (amount % 5 != 0) {
		cout << "Enter an amount multiple of 5's ? ";
		cin >> amount;
	}
	return amount;
}
void preformnormalwithdrawoperation() {
	short amount = readamountofwithdraw();
	if (amount > currentclient.balance) {
		cout << "\nThe amount exceeds your balance,make another choice.\n";
		cout << "press any key to continue...\n";
		system("pause");
		printnormalwithdrawscreen();
		return;
	}
	vector<clients>vcl = getclientsfromffile(clientfilename);
	depositbalancetoclientbyaccnum(currentclient.accnum, -amount, vcl);
	currentclient.balance -= amount;
}
void printnormalwithdrawscreen() {
	system("cls");
	cout << "===========================================\n";
	cout << "\tNormal Withdraw Screen\n";
	cout << "===========================================\n";
	preformnormalwithdrawoperation();
}
double readdepositamount() {
	double amount = 0;
	cout << "\nEnter a Positive Deposit Amount? ";
	cin >> amount;
	while (amount<=0)
	{
		cout << "\nEnter a positive Deposit Amount? ";     
		cin >> amount;
	}
	return amount;
}
void preformdepositoperation() {
	double amount = readdepositamount();
	vector<clients>vcl = getclientsfromffile(clientfilename);
	depositbalancetoclientbyaccnum(currentclient.accnum, amount, vcl);
	currentclient.balance += amount;
}
void printdepositscreen() {
	system("cls");
	cout << "=====================================\n";
	cout << "\t\tDeposit\n";
	cout << "=====================================\n";
	preformdepositoperation();
}
void checkbalancescreen() {
	system("cls");
	cout << "==================================\n";
	cout << "\tCheck Balance Screen\n";
	cout << "==================================\n";
	cout << "Your Balance is: " << currentclient.balance << endl;
}
int readchoiceofmainmenu() {
	int choice=0;
	do {
		cout << "Choose what do you want to do from [1 to 5]? ";
		cin >> choice;
	} while (choice < 1 || choice > 5);
	return choice;
}
void operationonatmmainmenu(int choice) {
	switch (choice) {
	case enprocessinmainmenu::enquickwithdraw:
		printquickwithdrawscreen();
		gobacktoatmmainmenu();
		break;
	case enprocessinmainmenu::ennormalwithdraw:
		printnormalwithdrawscreen();
		gobacktoatmmainmenu();
		break;
	case enprocessinmainmenu::endeposit:
		printdepositscreen();
		gobacktoatmmainmenu();
		break;
	case enprocessinmainmenu::encheckbalance:
		checkbalancescreen();
		gobacktoatmmainmenu();
		break;
	case enprocessinmainmenu::enlogout:
		login();
		break;
	}
}
void atmmainmenu() {
	system("cls");
	cout << "====================================\n";
	cout << "\t\tATM Main Menu\n";
	cout << "====================================\n";
	cout << "\t[1] Quick Withdraw\n";
	cout << "\t[2] Normal Withdraw\n";
	cout << "\t[3] Deposit\n";
	cout << "\t[4] Check Balance\n";
	cout << "\t[5] Logout\n";
	cout << "====================================\n";
	operationonatmmainmenu(readchoiceofmainmenu());
}
void gobacktoatmmainmenu() {
	system("pause");
	cout << "Press any key to go back to ATM Main Menu...\n";
	atmmainmenu();
}
void loginscreen(){
	cout << "==================================\n";
	cout << "\t\tLogin\n";
	cout << "==================================\n";
}
bool findclient() {
	string accnum = readaccnum(), pincode = readpincode();
	if (findclientbyaccnumandpincode(accnum, pincode, currentclient)) {
		return true;
	}
	return false;
}
void login() {
	bool loginfailed = false;
	do {
		system("cls");
		loginscreen();
		if (loginfailed) {
			cout << "Invalid account number / pincode.\n";
		}
		loginfailed = !findclient();
	} while (loginfailed);
	atmmainmenu();
}
int main() {
	login();
	return 0;
}