/*
Input
The input consists of 2 lines. The first line consists of a string that contains the key which consists of only English capital letters and its length is less than 10000 characters. It contains at least 1 character. The second line consists of another string that contains the plaintext which consists of only English capital letters and its length is less than 10000 characters. It contains at least one character. The length of the key is guaranteed to be less than or equal to the length of the plaintext.
EX:-
input= 
TEST
CORRECT
output=
Vigenere: VSJKXGL
Vernam: 170A0106110607
One-Time Pad: NO*/
#include <iostream>
#include <string>
#include <sstream>
using namespace std;
int main()
{

	string enc_message, key, n_key, ver, vig, pad;
	cin >> key;
	cin >> enc_message;
	vig = enc_message;
	ver = "";
	int repeat_key = enc_message.length() / key.length();
	int x;
	stringstream s;
	for (int i = 0;i < repeat_key;i++)
		n_key += key;

	n_key += key.substr(0, enc_message.length() % key.length());
	for (int i = 0;i < enc_message.length();i++)
	{
		vig[i] = char((int(enc_message[i]) + int(n_key[i]) - 130) % 26 + 65);

		x = int(enc_message[i] ^ n_key[i]);
		if (x<16)
			s << '0';
		s << hex << x;
	}
	ver = s.str();
	for (int i = 0;i < ver.length();i++)
		ver[i] = toupper(ver[i]);
	if (key.length() == enc_message.length())
		pad = "YES";
	else
		pad = "NO";

	cout << "Vigenere: " << vig << '\n' << "Vernam: " << ver << '\n' << "One-Time Pad: " << pad;
	system("pause");
}