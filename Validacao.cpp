#include <iostream>     // std::cout
#include <fstream>      // std::ifstream
#include <string>
#include <sstream>
#include <list>
#include <stdio.h>


using std::string;

int main() {


	  char filename1[] = "GW1_Sala10_P1.csv";
	  char filename2[] = "GW2_Sala10_P1.csv";
	  char filename3[] = "GW3_Sala10_P1.csv";



	  std::ifstream arq1(filename1);
	  std::ifstream arq2(filename2);
	  std::ifstream arq3(filename3);
	  std::list<string> temp1;
	  std::list<string> temp2;
	  std::list<string> temp3;
	  std::list<string> final;
	  std::ofstream myfile;

	  myfile.open ("Sala10_p1_u1.txt");

	    if (not arq1.is_open()) {
	        std::cout << "Arq1 nao pode ser aberto" ;
	        return 0;
	    }

	    std::string linha;
	    while (getline(arq1, linha)) {
	        // processa linha
	    	temp1.push_back(linha);
	        }

	    if (not arq2.is_open()) {
	        std::cout << "Arq2 nao pode ser aberto" ;
	        return 0;
	    }


	    while (getline(arq2, linha)) {
	        // processa linha
	    	temp2.push_back(linha);
	        }


	    if (not arq3.is_open()) {
	        std::cout << "Arq3 nao pode ser aberto" ;
	        return 0;
	    }
	    while (getline(arq3, linha)) {
	        // processa linha
	    	temp3.push_back(linha);
	        }

	    std::string str1;
	    std::string str2;
	    std::string str3;
	    std::string rss1;
	    std::string rss2;
	    std::string rss3;
	    std::list<string>::iterator it1;
	    std::list<string>::iterator it2;
	    std::list<string>::iterator it3;
	    for (it1=temp1.begin(); it1!=temp1.end(); ++it1){
	    	linha = *it1;
	    	str1 = linha.substr(linha.length()-25,8);
	    	if(linha.length()==71){
	    		rss1 = linha.substr(linha.length()-47,3);
	    	}
	    	else{
	    		rss1 = linha.substr(linha.length()-48,4);
	    	}
	    	//std::cout << linha;
	    	//std::cout << '\n';
	    		for (it2=temp2.begin(); it2!=temp2.end(); ++it2){
	    	    	linha = *it2;
	    	    	str2 = linha.substr(linha.length()-25,8);
	    	    	if(linha.length()==71){
	    	    		rss2 = linha.substr(linha.length()-47,3);
	    	    	}
	    	    	else{
	    	    		rss2 = linha.substr(linha.length()-48,4);
	    	    	}
	    	    	if(str1.compare(str2)==0){
	    	    		for (it3=temp3.begin(); it3!=temp3.end(); ++it3){
	    	    	    	linha = *it3;
	    	    	    	str3 = linha.substr(linha.length()-25,8);
	    	    	    	if(linha.length()==71){
	    	    	    		rss3 = linha.substr(linha.length()-47,3);
	    	    	    	}
	    	    	    	else{
	    	    	    		rss3 = linha.substr(linha.length()-48,4);
	    	    	    	}

	    	    	    	if(str1.compare(str3)==0){
	    	    	    	    myfile << rss1 << "," << rss2 << "," << rss3 << "," << "Sala10" ;
	    	    	    	    myfile << "\n";
	    	    	    	}
	    	    	}
	    		    linha.clear();
	    		}
	    	linha.clear();
	    }
	    }

		  myfile.close();
		  std::cout << "Terminado u1";
		  std::cout << "\n";

}
