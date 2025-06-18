#include "BulIst.h"
#include <regex>


std::vector<bool> BulIst::convertToBool(std::string& f) {
    for (char bit : f) {
        if (bit == '0')
            F.push_back(false);
        else if (bit == '1')
            F.push_back(true);
    }
    return F;
}

BulIst::BulIst()
{
    std::regex BulSTR("^[0-1]{16}$");
    std::cout << " Введите исходную булеву функцию (строка должна состоять из 16 символов '0' и '1')" << std::endl;
    while (true) {
        std::cin >> f;
        if (regex_match(f, BulSTR)) {
            //std::cout << "Исходная функция: " << f << std::endl;
            break;
        }
        else
            std::cout << "Некорректный ввод, строка должна содержать 16 цифр по значению равным только 0 и 1" << std::endl;
            std::cout << "|              |" << std::endl;
    }
    F = convertToBool(f);
    BDR = new data('x');
    data* BDR_yF = new data('y');
    data* BDR_yT = new data('y');
    BDR->AddFalse(BDR_yF);
    BDR->AddTrue(BDR_yT);

    data* BDR_z0 = new data('z');
    data* BDR_z1 = new data('z');
    data* BDR_z2 = new data('z');
    data* BDR_z3 = new data('z');

    BDR_yF->AddFalse(BDR_z3);
    BDR_yF->AddTrue(BDR_z2);

    BDR_yT->AddFalse(BDR_z1);
    BDR_yT->AddTrue(BDR_z0);

    data* BDR_h0 = new data('h');
    data* BDR_h1 = new data('h');
    data* BDR_h2 = new data('h');
    data* BDR_h3 = new data('h');
    data* BDR_h4 = new data('h');
    data* BDR_h5 = new data('h');
    data* BDR_h6 = new data('h');
    data* BDR_h7 = new data('h');

    BDR_z0->AddFalse(BDR_h1);
    BDR_z0->AddTrue(BDR_h0);

    BDR_z1->AddFalse(BDR_h3);
    BDR_z1->AddTrue(BDR_h2);

    BDR_z2->AddFalse(BDR_h5);
    BDR_z2->AddTrue(BDR_h4);

    BDR_z3->AddFalse(BDR_h7);
    BDR_z3->AddTrue(BDR_h6);

    BDR_F = new data('0');
    BDR_T = new data('1');

    for (int i = 15; i >= 0; ) {

        if (F[i] == 1) {
            BDR_h0->AddTrue(BDR_T);
            i--;
        }
        else {
            BDR_h0->AddTrue(BDR_F);
            i--;
        }
        if (F[i] == 1) {
            BDR_h0->AddFalse(BDR_T);
            i--;
        }
        else {
            BDR_h0->AddFalse(BDR_F);
            i--;
        }



        if (F[i] == 1) {
            BDR_h1->AddTrue(BDR_T);
            i--;
        }
        else {
            BDR_h1->AddTrue(BDR_F);
            i--;
        }
        if (F[i] == 1) {
            BDR_h1->AddFalse(BDR_T);
            i--;
        }
        else {
            BDR_h1->AddFalse(BDR_F);
            i--;
        }



        if (F[i] == 1) {
            BDR_h2->AddTrue(BDR_T);
            i--;
        }
        else {
            BDR_h2->AddTrue(BDR_F);
            i--;
        }
        if (F[i] == 1) {
            BDR_h2->AddFalse(BDR_T);
            i--;
        }
        else {
            BDR_h2->AddFalse(BDR_F);
            i--;
        }



        if (F[i] == 1) {
            BDR_h3->AddTrue(BDR_T);
            i--;
        }
        else {
            BDR_h3->AddTrue(BDR_F);
            i--;
        }
        if (F[i] == 1) {
            BDR_h3->AddFalse(BDR_T);
            i--;
        }
        else {
            BDR_h3->AddFalse(BDR_F);
            i--;
        }


        if (F[i] == 1) {
            BDR_h4->AddTrue(BDR_T);
            i--;
        }
        else {
            BDR_h4->AddTrue(BDR_F);
            i--;
        }
        if (F[i] == 1) {
            BDR_h4->AddFalse(BDR_T);
            i--;
        }
        else {
            BDR_h4->AddFalse(BDR_F);
            i--;
        }



        if (F[i] == 1) {
            BDR_h5->AddTrue(BDR_T);
            i--;
        }
        else {
            BDR_h5->AddTrue(BDR_F);
            i--;
        }
        if (F[i] == 1) {
            BDR_h5->AddFalse(BDR_T);
            i--;
        }
        else {
            BDR_h5->AddFalse(BDR_F);
            i--;
        }


        if (F[i] == 1) {
            BDR_h6->AddTrue(BDR_T);
            i--;
        }
        else {
            BDR_h6->AddTrue(BDR_F);
            i--;
        }
        if (F[i] == 1) {
            BDR_h6->AddFalse(BDR_T);
            i--;
        }
        else {
            BDR_h6->AddFalse(BDR_F);
            i--;
        }


        if (F[i] == 1) {
            BDR_h7->AddTrue(BDR_T);
            i--;
        }
        else {
            BDR_h7->AddTrue(BDR_F);
            i--;
        }
       if (F[i] == 1) {
            BDR_h7->AddFalse(BDR_T);
            i--;
       }
       else {
           BDR_h7->AddFalse(BDR_F);
           i--;
       }


    }

    SDNF = "СДНФ(f) = ";
    SKNF = "СКНФ(f) = ";

    for (int i = 0; i < 16; i++) {
        if (F[i] == 1) {
            SDNF += X[i] == 1 ? "x " : "!x ";
            SDNF += Y[i] == 1 ? "y " : "!y ";
            SDNF += Z[i] == 1 ? "z " : "!z ";
            SDNF += H[i] == 1 ? "h " : "!h ";
            SDNF += "  V  ";
        }
        else {
            SKNF += "(";
            SKNF += X[i] == 0 ? "x" : "!x";
            SKNF += " V ";
            SKNF += Y[i] == 0 ? "y" : "!y";
            SKNF += " V ";
            SKNF += Z[i] == 0 ? "z" : "!z";
            SKNF += " V ";
            SKNF += H[i] == 0 ? "h" : "!h";
            SKNF += ")";
        }
    }
    if (SDNF.length() >= 3) {
        SDNF.erase(SDNF.length() - 3);
    }
    SDNF += "\0";
    SKNF += "\0";


    for (int i = 16; i > 0; i--) {
        std::vector<bool> buf(i);
        Zhegalkin.push_back(buf);
    }
    for (int i = 0; i < 16; i++) {
        Zhegalkin[0][i] = F[i];
    }
    for (int i = 1; i < 16; i++) {
        for (int j = 0; j < Zhegalkin[i].size(); j++) {
            Zhegalkin[i][j] = Zhegalkin[i - 1][j] == Zhegalkin[i - 1][j + 1] ? 0 : 1;
        }
    }

    Alpha_index.push_back(0);
    Alpha_index.push_back(1);
    Alpha_index.push_back(2);
    Alpha_index.push_back(3);
    Alpha_index.push_back(4);
    Alpha_index.push_back(5);
    Alpha_index.push_back(6);
    Alpha_index.push_back(7);
    Alpha_index.push_back(8);
    Alpha_index.push_back(9);
    Alpha_index.push_back(10);
    Alpha_index.push_back(11);
    Alpha_index.push_back(12);
    Alpha_index.push_back(13);
    Alpha_index.push_back(14);
    Alpha_index.push_back(15);


    for (int i = 0; i < 16; i++) {
        if (Zhegalkin[i][0] == 1) {
            //Zhegalkin_str += "&_";
            if (i == 0) {
                Zhegalkin_str += "1";
            }
            //Zhegalkin_str += std::to_string(Alpha_index[i]);
            Zhegalkin_str += " ";
            Zhegalkin_str += X[i] == 1 ? "x" : "";
            Zhegalkin_str += Y[i] == 1 ? "y" : "";
            Zhegalkin_str += Z[i] == 1 ? "z" : "";
            Zhegalkin_str += H[i] == 1 ? "h" : "";
            Zhegalkin_str += i < 16 ? " + " : "\0";
            Zhegalkin_str2 += X[i] == 1 ? "x" : "!x";
            Zhegalkin_str2 += Y[i] == 1 ? "y" : "!y";
            Zhegalkin_str2 += Z[i] == 1 ? "z" : "!z";
            Zhegalkin_str2 += H[i] == 1 ? "h" : "!h";
            Zhegalkin_str2 += i < 16 ? " + " : "\0";
        }
    }
    if (Zhegalkin_str.length() >= 3) {
        Zhegalkin_str.erase(Zhegalkin_str.length() - 2);
        Zhegalkin_str2.erase(Zhegalkin_str2.length() - 2);
    }
 
}


void BulIst::PrintIst() {
    std::cout << "  ~             Таблица истинности: " << std::endl;
    std::cout << "  ~              -------------- " << std::endl;
    std::cout << "  ~              | x y z h | f |" << std::endl;
    std::cout << "  ~              |-------------|\n";
    for (int i = 0; i < 16; i++) {
        std::cout << "  ~              | " << X[i] << " " << Y[i] << " " << Z[i] << " " << H[i] << " | " << F[i] << " |" << std::endl;
    }
    std::cout << "  ~              |-------------| " << std::endl;
}

void BulIst::VisualizeBDR(data* node, int level) {
    if (node != nullptr) {
        VisualizeBDR(node->True, level + 1);
        for (int i = 0; i < level; i++) {
            std::cout << "    ";
        }
        std::cout << "            " << node->name << std::endl;
        VisualizeBDR(node->False, level + 1);
    }
}

void BulIst::SearchBDR(std::string s) {
    data* buf = this->BDR;
    std::string bdr = "Решение: X";
    int answer = 0;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == '0') {
            buf = buf->False;
            if (i == 0) {
                bdr += " --f--> Y";
            }
            else if (i == 1) {
                bdr += " --f--> Z";
            }
            else if (i == 2) {
                bdr += " --f--> H";
            }
            else{
                if (buf == BDR_F) {
                    bdr += " --f--> 0";
                    answer = 0;
                }
                else {
                    bdr += " --f--> 1";
                    answer = 1;
                }
            }
            
        }
        if (s[i] == '1') {
            buf = buf->True;
            if (i == 0) {
                bdr += " --t--> Y";
            }
            else if (i == 1) {
                bdr += " --t--> Z";
            }
            else if (i == 2) {
                bdr += " --t--> H";
            }
            else {
                if (buf == BDR_F) {
                    bdr += " --t--> 0";
                    answer = 0;
                }
                else {
                    bdr += " --t--> 1";
                    answer = 1;
                }
            }
        }
    }
    std::cout << bdr << std::endl;
    std::cout << "    Ответ: " << answer << std::endl;
    std::cout << std::endl;
    std::cout << std::endl;
    std::cout << "Построение БДР: " << std::endl;
    VisualizeBDR(BDR, 0);

}

void BulIst::Print_SDNF() {
    std::cout << std::endl << SDNF << std::endl;
}

void BulIst::Print_SKNF() {
    std::cout << std::endl << SKNF << std::endl;
}

void BulIst::Search_SDNF(std::string s) {
    std::string s_out = "";
    for (int i = 0; i < 4; i++) {
        s_out += s[i] == '0' ? "1" : "0";
    }

    std::cout << " x = " << s[0] << "; y = " << s[1] << "; z = " << s[2] << "; h = " << s[3] << std::endl;

    std::string buf = "";
    for (int i = 0; SDNF[i] != '\0'; i++) {
        buf += SDNF[i] == 'x' ? SDNF[i - 1] == '!' ? std::string(1, s_out[0]) : std::string(1, s[0]) : "";
        buf += SDNF[i] == 'y' ? SDNF[i - 1] == '!' ? std::string(1, s_out[1]) : std::string(1, s[1]) : "";
        buf += SDNF[i] == 'z' ? SDNF[i - 1] == '!' ? std::string(1, s_out[2]) : std::string(1, s[2]) : "";
        buf += SDNF[i] == 'h' ? SDNF[i - 1] == '!' ? std::string(1, s_out[3]) : std::string(1, s[3]) : "";
        buf += SDNF[i] == 'V' ? "+" : "";
        buf += SDNF[i + 1] == '\0' ? "\0" : "";
    }

    std::cout << std::endl << " СДНФ(f) = " << buf;

    std::vector<int> result;
    int iterator = 5;
    std::string str = "";
    for (int j = 0; iterator > 2; iterator--) {
        for (int i = 0; i < buf.size() && buf[i] != '\0'; i += iterator) {
            str += buf[i] == '1' ? buf[i + 1] == '1' ? "1" : "0" : "0";
            str += buf.substr(i + 2, iterator - 3);// buf.substr(i + 2, 3), i + 2 - это 
            //начальный индекс, и iterator - 3 - это количество символов для включения. 
            str += "+";
        }
        if (str.length() >= 1) {
            str.erase(str.length() - 1);
        }
        std::cout << " = " << str;
        buf = str;
        str = "";
    }

    bool res = false;

    for (char c : buf) {
        if (c == '1') {
            res = true;
            break;
        }
    }
    std::cout << " = " << (res ? 1 : 0) << std::endl;
    std::cout << "   Ответ: " << res << std::endl;


}

void BulIst::Print_Zhegalkin() {
    std::string s = " ";
    std::cout << "                Полином Жегалкина" << std::endl;
    std::cout << "                -----------------" << std::endl;
    for (int i = 0; i < 16; i++) {
        std::cout << "&_" << Alpha_index[i] << '\t' << s;
        s += " ";
        for (int j = 0; j < Zhegalkin[i].size(); j++) {
            std::cout << Zhegalkin[i][j] << " ";
        }
        std::cout << std::endl;
    }
    std::cout << std::endl << Zhegalkin_str << std::endl;
}
    
void BulIst::Search_Zhegalkin(std::string s) {
    int result = 0;
    for (int i = 0; i < 16; i++) {
        if (Zhegalkin[i][0] == 1) {
            bool termResult = true;
            termResult &= X[i] == 1 ? s[0] == '1' : s[0] == '0';
            termResult &= Y[i] == 1 ? s[1] == '1' : s[1] == '0';
            termResult &= Z[i] == 1 ? s[2] == '1' : s[2] == '0';
            termResult &= H[i] == 1 ? s[3] == '1' : s[3] == '0';
            result ^= termResult;
        }
    }
    std::cout << " x = " << s[0] << "; y = " << s[1] << "; z = " << s[2] << "; h = " << s[3] <<std::endl << std::endl;
    std::cout << Zhegalkin_str2 << " = " << result << std::endl;
    std::cout << "    Ответ: " << result << std::endl;
}