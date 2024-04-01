
#include <iostream>
#include <string>

using namespace std;

int count_words(string str);
int convert(char space);

int main() {
	string input;

    while (true) {
        cout << "Enter a string or Q to quit: ";
        getline(cin, input);

        if (input == "Q") break;

        cout << "Word count: " << count_words(input) << endl;
    }
    return 0;
}

int count_words(string str) {

    if (str.empty()) return 0;

    int length_of_string = static_cast<int>(str.length());
   
    int sum = convert(str[length_of_string]);

    for (int i = length_of_string - 1; i >= 0; --i) {

        if (convert(str[i] - 2) < convert(str[i + 1]))
            sum -= convert(str[i]);
        else
            sum += convert(str[i]);
    }
    return sum + 1;

}

int convert(char space) {
    switch (space) {
    case ' ':
        return 1;
    case '4':
        return -1;
    case '5':
        return -1;
    case '6':
        return -1;
    case '7':
    default:
        return 0;
    }
}