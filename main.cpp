#include <iostream>
#include <vector>
#include "Figure.h"



int main() {
    std::vector<Figure*> v;
    int opt = 0, index = 0;
    Dot tmp_center;
    double tmp_area;

    while (opt != -1) {
        std::cout << "Choose option (-2 for man, -1 to close)" << '\n';
        std::cin >> opt;
        switch (opt) {
            case -1:
                for (auto & figure: v) {
                    delete figure;
                }
                break;
            case -2:
                std::cout << "Option 1: add octagon. Defined by 8 points (x then y coordinate for each)\n"
                << "Option 2: add Triangle (3 points)\n"
                << "Option 3: add square (2 points from ends of a diagonal line)\n"
                << "Option 4: print all figures\n"
                << "Option 5: count and print centers of all figures\n"
                << "Option 6: count and print areas of all figures\n"
                << "Option 7: print all available info about all figures\n"
                << "Option 8: count and print summary area of all figures\n"
                << "Option 9: erase figure from vector by it`s index (starts from 1)\n";
                break;
            case 1:
                v.push_back(new Octagon(std::cin));
                break;
            case 2:
                v.push_back(new Triangle(std::cin));
                break;
            case 3:
                v.push_back(new Square(std::cin));
                break;
            case 4:
                for (size_t i = 0; i < v.size(); ++i) {
                    std::cout << '\t' << i+1 << ':' << std::endl;
                    v[i]->PrintOut(std::cout);
                }
                break;
            case 5:
                for (size_t i = 0; i < v.size(); ++i) {
                    std::cout << '\t' << i+1 << ':' << std::endl;
                    tmp_center = v[i]->Center();
                    std::cout << tmp_center << std::endl;
                }
                break;
            case 6:
                for (size_t i = 0; i < v.size(); ++i) {
                    std::cout << '\t' << i+1 << ':' << std::endl;
                    tmp_area = v[i]->Area();
                    std::cout << tmp_area << std::endl;
                }
                break;
            case 7:
                for (size_t i = 0; i < v.size(); ++i) {
                    std::cout << '\t' << i+1 << ':' << std::endl;
                    tmp_area = v[i]->Area();
                    tmp_center = v[i]->Center();
                    std::cout << "Angle coordinates:\t";
                    v[i]->PrintOut(std::cout);
                    std::cout << "Center:\t\t\t" << tmp_center << '\n' << "Area:\t\t\t" << tmp_area << '\n';
                }
                break;
            case 8:
                tmp_area = 0;
                for (auto & figure : v) {
                    tmp_area += figure->Area();
                }
                std::cout << "Summary area: " << tmp_area << std::endl;
                break;
            case 9:
                std::cout << "choose index of a figure you want to delete (from 1 to " << v.size() << "): ";
                std::cin >> index;
                delete v[index-1];
                v.erase(v.begin()+index-1);
                break;
            default:
                std::cout << "Sorry, there is no such option" << '\n';
                break;
        }
    }
    return 0;
}