/*
    Hello World
    Copyright (C) 2022 butztill

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <https://www.gnu.org/licenses/>.
*/

#include <iostream>
#include <fstream>
#include <regex>
using namespace std;
int runningon()
{

    ifstream lsbrelease;
    lsbrelease.open("/etc/lsb-release");
    string lsbout;
    string parsed;

    if (lsbrelease.is_open()){
        lsbrelease >> lsbout;
        regex regex1("DISTRIB_ID=\"(.*)\"");
        smatch matches;
        regex_search(lsbout, matches, regex1);
        parsed = matches.str(1);
        cout << "You use " << parsed << " btw.\n";
        lsbrelease.close();
    } else {
        cout << "error: file could not be opened.\n";
        return EXIT_FAILURE;
    }
    return EXIT_SUCCESS;
}
int helloworld()
{
    cout << "I will add 1 to your input."
         << endl
         << "Please input a number:"
         << endl;
    int a;
    cin >> a;
    a = a+1;
    cout << "The result is " << a << ".\n";
    if (a > 10) {
        cout << "What you entered is greater than 10.";
    } else {
        cout << "What you entered is not greater than 10.";
    }
    return EXIT_SUCCESS;
}
int main(void)
{
    int choice;

    do{
        cout << "1. runningon\n"
             << "2. helloworld\n"
             << "3. exit\n";
        cin >> choice;

            switch(choice) {
                case 1:
                    runningon();
                    break;
                case 2:
                    helloworld();
                case 3:
                    cout << "\nexiting.\n";
                default:
                    return 0;
            }
    } while(choice !=3);
    return EXIT_SUCCESS;
}
