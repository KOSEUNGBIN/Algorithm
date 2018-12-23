//
// Created by 고승빈 on 2018. 12. 23..
//

/*
You should use the standard input/output

in order to receive a score properly.

Do not use file input and output

Please be very careful.
*/

#include <iostream>
#include <string.h>
#include <string>
#include <cmath>
#include <stack>

using namespace std;

int Answer;

string HEX_TO_BITS[16] = {
        "0000", "0001", "0010", "0011", "0100", "0101", "0110", "0111", "1000", "1001", "1010", "1011", "1100", "1101",
        "1110", "1111"
};

char BIT_TO_HEX[16] = {
        '0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C', 'D', 'E', 'F'
};

char ALPHABET[45] = {
        '0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L',
        'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z', ' ', '$', '%', '*', '+', '-', '.', '/',
        ':'
};

string toBits(string hex) {
    const char *str = hex.c_str();
    string result = "";
    for (long idx = 0, len = strlen(str); idx < len; ++idx) {
        char ch = str[idx];
        if (ch >= 65) {
            result.append(HEX_TO_BITS[ch - 55]);

        } else {
            result.append(HEX_TO_BITS[ch - 48]);

        }


    }

    return result;
}

int checkType(string str, long *start) {
    int value;
    if (str[*start] == '1' && str[*start + 1] == '1' && str[*start + 2] == '1' && str[*start + 3] == '0') {
        value = 5;

    } else if (str[*start + 3] == '1') {
        value = 1; // number;

    } else if (str[*start + 2] == '1') {
        value = 2; // alphabet

    } else if (str[*start + 1] == '1') {
        value = 3; // 8bits

    } else if (str[*start] == '1') {
        value = 4; // Kanji

    } else {
        value = 5;

    }

    *start += 4;
    return value;

}

long countLength(string str, long *start, int len) {
    long result = 0;
    for (int idx = 0; idx < len; ++idx) {
        if (str[*start + idx] == '1') {
            result += pow(2, len - 1 - idx);

        }

    }

    *start += len;
    return result;
}

string toInteger(string str, long *start, int len) {
    long temp = 0;
    for (int idx = 0; idx < len; ++idx) {
        if (str[*start + idx] == '1') {
            temp += pow(2, len - 1 - idx);

        }

    }

    string result = "";
    stack<char> values;
    if (temp > 0) {
        while (temp > 0) {
            values.push((char) ((temp % 10) + 48));
            temp /= 10;

        }

    } else {
        values.push('0');

    }

    while (!values.empty()) {
        char value = values.top();
        result += value;
        values.pop();

    }

    *start += len;
    return result;

}

string decodeToInteger(string str, long *start, int *counts) {
    long count = countLength(str, start, 10);
    *counts += count;
    long mul = count / 3;
    long rest = count % 3;

    string result = "";
    for (int m = 0; m < mul; ++m) {
        result += toInteger(str, start, 10);

    }

    if (rest == 2) {
        result += toInteger(str, start, 7);

    } else if (rest == 1) {
        result += toInteger(str, start, 4);

    }

    return result;

}

string toAlphabet(string str, long *start, int len) {
    long temp = 0;
    for (int idx = 0; idx < len; ++idx) {
        if (str[*start + idx] == '1') {
            temp += pow(2, len - 1 - idx);

        }

    }

    string result = "";
    long a = 0;
    long b = 0;
    bool is = false;
    for (; a < 45; ++a) {
        for (b = 0; b < 45; ++b) {
            if (((a * 45) + b) == temp) {
                is = true;
                break;

            }

        }

        if (is) {
            break;

        }

    }

    result += ALPHABET[a];
    result += ALPHABET[b];

    *start += len;
    return result;

}

char toAlphabetRest(string str, long *start, int len) {
    long temp = 0;
    for (int idx = 0; idx < len; ++idx) {
        if (str[*start + idx] == '1') {
            temp += pow(2, len - 1 - idx);

        }

    }

    *start += len;
    return ALPHABET[temp];

}

string decodeToAlphabet(string str, long *start, int *counts) {
    long count = countLength(str, start, 9);
    *counts += count;
    long mul = count / 2;
    long rest = count % 2;

    string result = "";
    for (int m = 0; m < mul; ++m) {
        result += toAlphabet(str, start, 11);

    }

    if (rest == 1) {
        result += toAlphabetRest(str, start, 6);

    }

    return result;


}

char toHex(string str, long *start, int len) {
    long temp = 0;
    for (int idx = 0; idx < len; ++idx) {
        if (str[*start + idx] == '1') {
            temp += pow(2, len - 1 - idx);

        }

    }

    *start += len;
    return BIT_TO_HEX[temp];

}

string toAscii(string str, long *start, int len) {
    string result = "\\";
    char ch[2];
    int value = 0;
    for (int c = 0; c < 2; ++c) {
        ch[c] = toHex(str, start, 4);
        if (ch[c] >= 65) {
            value += (ch[c] - 55) * pow(16, 1 - c);

        } else {
            value += (ch[c] - 48) * pow(16, 1 - c);

        }

    }

    if (31 < value && value < 127) {
        if (value == 35 || value == 92) {
            result = "\\" + ((char) value);

        } else {
            result = (char) value;

        }

    } else {
        result += ch[0];
        result += ch[1];

    }

    return result;

}

string decodeToAscii(string str, long *start, int *counts) {
    long count = countLength(str, start, 8);
    *counts += count;
    string result = "";
    for (long c = 0; c < count; ++c) {
        result += toAscii(str, start, 8);

    }

    return result;

}

string toKanji(string str, long *start, int len) {
    string result = "#";
    char ch[4];
    ch[0] = str[*start];
    *start += 1;
    for (int c = 1; c < 4; ++c) {
        ch[c] = toHex(str, start, 4);

    }


    for (int c = 0; c < 4; ++c) {
        result += ch[c];

    }

    return result;

}

string decodeToKanji(string str, long *start, int *counts) {
    long count = countLength(str, start, 8);
    *counts += count;
    string result = "";
    for (long c = 0; c < count; ++c) {
        result += toKanji(str, start, 13);

    }

    return result;

}

string decode(string bits, int *counts) {
    long cur = 0;
    long end = bits.length();
    string result = "";
    while (cur < end) {
        int type = checkType(bits, &cur);
        if (type == 1) {
            result += decodeToInteger(bits, &cur, counts);

        } else if (type == 2) {
            result += decodeToAlphabet(bits, &cur, counts);

        } else if (type == 3) {
            result += decodeToAscii(bits, &cur, counts);

        } else if (type == 4) {
            result += decodeToKanji(bits, &cur, counts);

        } else {
            break;

        }

    }

    return result;

}

int main(int argc, char **argv) {
    int T, test_case;
    /*
       The freopen function below opens input.txt file in read only mode, and afterward,
       the program will read from input.txt file instead of standard(keyboard) input.
       To test your program, you may save input data in input.txt file,
       and use freopen function to read from the file when using cin function.
       You may remove the comment symbols(//) in the below statement and use it.
       Use #include<cstdio> or #include <stdio.h> to use the function in your program.
       But before submission, you must remove the freopen function or rewrite comment symbols(//).
     */

    // freopen("input.txt", "r", stdin);

    cin >> T;
    for (test_case = 0; test_case < T; test_case++) {

        Answer = 0;
        /////////////////////////////////////////////////////////////////////////////////////////////
        string input;
        cin >> input;
        string bits = toBits(input);
        string result = decode(bits, &Answer);

        // Print the answer to standard output(screen).
        cout << "Case #" << test_case + 1 << endl;
        cout << Answer << " " << result << endl;

    }

    return 0;//Your program should return 0 on normal termination.
}

// 00111001110
// 11100111001
// 11100111001

// 0001 0000001000 0001111011  0111001000  1001110
// 0010 000000101  00111001110 11100111001 000010
// 0100 00000011   01000101    00000010    10100011
// 0000 000000     11101100    00010001    11101100


// 1000 00000010 1101010111100 0001101000101
// 0000 00000011101100000100011110110000010001111011000001000111101100000100011110110000010001111011000001000111101100

// 0001 0000001000 0001111011  0111001000  1001110
// 0010 000000101  00111001110 11100111001 000010
// 0100 00000011   01000101    10010010    10100011
// 0000 000000     11101100    00010001    11101100

