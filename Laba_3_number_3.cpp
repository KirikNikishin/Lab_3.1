// Laba_3_number_3.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//Выведите строки, содержащие двоичную запись числа, кратного 3
#include <fstream>
#include <regex>
#include <iterator>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

vector<int> Searching(std::sregex_iterator words_begin, std::sregex_iterator words_end) {

    std::vector<int> count_arr;
    for (std::sregex_iterator i = words_begin; i != words_end; ++i) {
        std::smatch match = *i;
        std::string match_str = match.str();
        int size_ = sizeof(match_str) / sizeof(match_str[0]);
        int power = 0;
        int count = 0;
        //std::cout << match_str << std::endl;
        for (int i = match_str.length() - 1; i >= 0; i--) {
            if (match_str[i] == '1') {
                count += pow(2, power);
            }
            power += 1;
        }
        if (count != 0 and match_str != "0" and count % 3==0) {
            count_arr.push_back(count);
        }
    }
    return count_arr;
}
int main()
{
    std::string s[7] = { "11110_1111120202002_11011", "dhsjkzxzhjxj11110zcnjnk11", "Lorem 111 Ipsum", "1001 nights", "14-th century and 100001 deaths", "<html><head><title>Bank</title><head><body><button type = \"button\ class = \"button\">+1111</button><button type = \"button\ class = \"button\">110</button></body></html>", "11011_158_12_18_12B_11111_11"}; //"11110_1111120202002_11011";
    std::regex words_regex("[0-1]+");
    for (int i = 0; i < sizeof(s)/sizeof(s[0]); i++) {
        std::sregex_iterator words_begin =
            std::sregex_iterator(s[i].begin(), s[i].end(), words_regex);
        std::sregex_iterator words_end = std::sregex_iterator();
        vector <int> arr = Searching(words_begin, words_end);
        if (arr.size() != 0) {
            cout << s[i] << endl;
        }
    }
    
}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
