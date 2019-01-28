/*
The input consists of 3 lines. The first line contains the length of the key L(0 < L ≤ 104) L is guaranteed to be a perfect square. The second line contains L numbers X(0 ≤ X ≤ 109) which represent the key. You can use these numbers to form the key matrix of Hill Cipher. The last line contains the plaintext to encrypt. It is a single string that consists of at most 100 characters. Each character is a capital English alphabetical character.
EX:_
input=
4
7 8 11 11
SHORT
output=
APADFU
*/
#include <iostream>
#include <string>
#include <sstream>
#include <cmath>

using namespace std;

int main()
{
	string enc_massage, out, s;
	int key_length, x = 0;
	out = "";
	cin >> key_length;
	key_length = sqrt(key_length);
	long **key;
	key = new long*[key_length];
	for (int i = 0; i < key_length; i++)
		key[i] = new long[key_length];

	for (int i = 0; i < key_length; i++)
	{
		for (int j = 0; j < key_length; j++)
		{
			cin >> key[i][j];
		}

	}
	cin >> enc_massage;
	int num_x = key_length - (enc_massage.length() % key_length);
	for (int i = 0; i < num_x; i++)
	{
		enc_massage += "X";
	}
	
	for (int k = 0; k < enc_massage.length(); k += key_length)
	{
		s = enc_massage.substr(k, key_length);
		for (int i = 0; i < key_length; i++)
		{
			for (int j = 0; j < key_length; j++)
				x += (key[i][j] % 26) * ((int(s[j]) - 65) % 26);
			out += char(x % 26 + 65);
			x = 0;
		}
	}

	cout << out;
		system("pause");
}