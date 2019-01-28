/*Input
The input consists of 2 lines. 
The first line is just a number N ( 0 ≤ N ≤ 99999999999 ) which represents the key that is also the number of right shifts. 
The second line is a string which represents the plain text. 
It consists of only capital English letters. i.e: Each character of the string is between A-Z inclusive. No spaces, no special characters and no small letters.

Ex:-
input= 
3
HACKINGZEBRAS
output = 
KDFNLQJCHEUDV
*/
#include <iostream>
#include <string>
using namespace std;
int main()
{
	int x;
	long long key;
	string enc_message, dec_message;
	cin >> key;
	key = key % 26;
	cin >> enc_message;
	for (int i = 0;i < enc_message.length();i++)
	{
		x = int(enc_message[i]) + key;
		x = (x - 65) % 26 + 65;

		enc_message[i] = char(x);
	}
	cout << enc_message;
	system("pause");
}