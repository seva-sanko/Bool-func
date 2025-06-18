#pragma once
#include <iostream>
#include <string>
#include <vector>

struct data {
	char name;
	data* False;
	data* True;

	data(const char s) {
		name = s;
		False = nullptr;
		True = nullptr;
	}
	void AddTrue(data* d) {
		data* buf = this;
		while (buf->True != nullptr) {
			buf = buf->True;
		}
		buf->True = d;
	}

	void AddFalse(data* d) {
		data* buf = this;
		while (buf->False != nullptr) {
			buf = buf->False;
		}
		buf->False = d;
	}
};

class BulIst
{
	std::vector<bool> X{0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1};
	std::vector<bool> Y{0, 0, 0, 0, 1, 1, 1, 1, 0, 0, 0, 0, 1, 1, 1, 1};
	std::vector<bool> Z{0, 0, 1, 1, 0, 0, 1, 1, 0, 0, 1, 1, 0, 0, 1, 1};
	std::vector<bool> H{0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1};
	//std::vector<bool> F{0, 0, 1, 1, 0, 1, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1};
	std::vector<bool> F;
	std::string f;
	data* BDR;
	data* BDR_F;
	data* BDR_T;
	std::string SDNF;
	std::string SKNF;
	std::vector <std::vector<bool>> Zhegalkin;
	std::vector <int> Alpha_index;
	std::string Zhegalkin_str = "F = ";
	std::string Zhegalkin_str2 = "F = ";

public:
	BulIst();
	void PrintIst();
	void Print_SDNF();
	void Print_SKNF();
	void Print_Zhegalkin();
	void Search_SDNF(std::string s);
	void SearchBDR(std::string s);
	void Search_Zhegalkin(std::string s);
	void VisualizeBDR(data* node, int level);
	std::vector<bool> convertToBool(std::string& f);
};


