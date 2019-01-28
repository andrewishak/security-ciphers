/*
Input
2 lines. The first is the Key with Length > 0 The second is the plain text with Length > 0 All inputs are Uppercase letters with no spaces or special characters.
EX:-
input=
KEYWORD
BALLOON
output=
CBIZSCES

*/#include <iostream>
#include <string>
#include <sstream>
#include <cmath>
#include <algorithm>

using namespace std;

int main()
{
	string enc_massage, key, s, out;
	s = "";
	out = "";
	cin >> key;
	cin >> enc_massage;
	int matrix[5][5] = { 0 };
	int alpha[26] = { 0 };
	alpha[9] = 1;
	int r1, r0, c1, c0, x, i = 0, j = 0;
	for (int i = 0; i < enc_massage.length(); i++)
	{
		if (enc_massage[i] == 'J')
			enc_massage[i] = 'I';
	}
	for (int i = 0; i < key.length(); i++)
	{
		if (key[i] == 'J')
			key[i] = 'I';
	}

	for (int k = 0;k < key.length();k++)
	{
		x = int(key[k]) - 65;
		if (alpha[x] == 0)
		{
			alpha[x] = 1;
			matrix[i][j] = x;
			j++;
			if (j == 5)
			{
				j = 0;
				i++;
			}
		}
	}

	for (int k = 0; k < 26; k++)
	{
		if (alpha[k] == 0)
		{
			matrix[i][j] = k;
			j++;
			if (j == 5)
			{
				j = 0;
				i++;
			}

		}

	}

	while (enc_massage.length()>0) {
		if (enc_massage.length() > 1)
		{

			if (enc_massage[0] == enc_massage[1])
			{
				if (enc_massage[0] == 'X')
				{
					s = enc_massage[0];
					s += "Q";
					enc_massage = enc_massage.substr(1, enc_massage.length() - 1);
				}
				else
				{
					s = enc_massage[0];
					s += "X";
					enc_massage = enc_massage.substr(1, enc_massage.length() - 1);
				}
			}
			else
			{
				s = enc_massage.substr(0, 2);
				enc_massage = enc_massage.substr(2, enc_massage.length() - 2);
			}
		}
		else
		{
			if (enc_massage[0] == 'X')
			{
				s = enc_massage[0];
				s += "Q";
				enc_massage = "";
			}
			else
			{
				s = enc_massage[0];
				s += "X";
				enc_massage = "";
			}
		}
		for (i = 0; i < 5; i++)
		{
			for (j = 0; j < 5; j++)
			{
				if ((s[0] - 65) == matrix[i][j])
				{
					r0 = i;
					c0 = j;
				}
				else if ((s[1] - 65) == matrix[i][j])
				{
					r1 = i;
					c1 = j;
				}
			}


		}
		if (r0 == r1)
		{
			out += char(65 + matrix[r0][(c0 + 1) % 5]);
			out += char(65 + matrix[r0][(c1 + 1) % 5]);
		}
		else if (c0 == c1)
		{
			out += char(65 + matrix[(r0 + 1) % 5][c0]);
			out += char(65 + matrix[(r1 + 1) % 5][c0]);
		}
		else
		{
			out += char(65 + matrix[r0][c1]);
			out += char(65 + matrix[r1][c0]);
		}

	}
	cout << out;
	system("pause");
}