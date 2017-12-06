#include <iostream>     // std::cout
#include <fstream>      // std::ifstream
#include <string>
#include <sstream>
#include <list>
#include <stdio.h>
#include <vector>
#include <stdlib.h>

using std::string;

int main() {


	  char filename1[] = "Sala10_p2_u1.txt";
	  std::ifstream arq1(filename1);
	  std::list<string> temp1;
	  std::list<string> u5;
	  std::list<string> u10;
	  std::list<string> u15;
	  std::list<string> u20;
	  std::list<string> u50;
	  std::list<string> u100;
	  std::ofstream myfile5;
	  std::ofstream myfile10;
	  std::ofstream myfile15;
	  std::ofstream myfile20;
	  std::ofstream myfile50;
	  std::ofstream myfile100;
	  double rss1;
	  double rss2;
	  double rss3;
	  std::vector<double> rssia;
	  std::vector<double> rssib;
	  std::vector<double> rssic;

	  myfile5.open ("Sala10_p2_u5.txt");
	  myfile10.open ("Sala10_p2_u10.txt");
	  myfile15.open ("Sala10_p2_u15.txt");
	  myfile20.open ("Sala10_p2_u20.txt");
	  myfile50.open ("Sala10_p2_u50.txt");
	  myfile100.open ("Sala10_p2_u100.txt");




	    if (not arq1.is_open()) {
	        std::cout << "Arq1 nao pode ser aberto" ;
	        return 0;
	    }

	    std::string linha;

	    int i =0;
	    int j = 0;
	    int k;
	    while (getline(arq1, linha)) {
	        // processa linha
	        std::stringstream ss(linha);
	         while(getline(ss, linha, ',')){
	              // You now have separate entites here
	    	if(i==0){
	    		rss1 = atoi(linha.c_str());
		    	rssia.push_back(rss1);
	    		//std::cout << "A" <<  rss1 << std::endl;;
	    		i++;
	    	}
	    	else if(i==1){
	    		rss2 = atoi(linha.c_str());
	    		rssib.push_back(rss2);
	    		//std::cout << "B" << rss2 << std::endl;;
	    		i++;
	        }
    		else if(i==2){
    			rss3 = atoi(linha.c_str());
    			rssic.push_back(rss3);
	    		//std::cout << "C" << rss3 << std::endl;
	        	i++;
        	}
    		else{
    			j++;
	        	i=0;
	        	if(j>=5){
	        		 //std::cout << rssic.size() << std::endl;
	        		 //std::cout << (rssic[rssic.size()-1]+rssic[rssic.size()-2]+rssic[rssic.size()-3]+rssic[rssic.size()-4]+rssic[rssic.size()-5])/5 << std::endl;
	        		 rss1 = 0;
	        		 for(k=1;k<6;k++){
	        		  rss1 = rss1 + rssia[rssia.size()-k]/5;
	        		 }
	        		 rss2 = 0;
	        		 for(k=1;k<6;k++){
	        		  rss2 = rss2 + rssib[rssib.size()-k]/5;
	        		 }
	        		 rss3 = 0;
	        		 for(k=1;k<6;k++){
	        		  rss3 = rss3 + rssic[rssic.size()-k]/5;
	        		 }
	        		 myfile5 << rss1 << "," << rss2 << "," << rss3 << "," << "Sala10" ;
	        	     myfile5 << "\n";
	        	}
	        	if(j>=10){
	        		 //std::cout << rssic.size() << std::endl;
	        		 //std::cout << (rssic[rssic.size()-1]+rssic[rssic.size()-2]+rssic[rssic.size()-3]+rssic[rssic.size()-4]+rssic[rssic.size()-5])/5 << std::endl;
	        		 rss1 = 0;
	        		 for(k=1;k<11;k++){
	        		  rss1 = rss1 + rssia[rssia.size()-k]/10;
	        		 }
	        		 rss2 = 0;
	        		 for(k=1;k<11;k++){
	        		  rss2 = rss2 + rssib[rssib.size()-k]/10;
	        		 }
	        		 rss3 = 0;
	        		 for(k=1;k<11;k++){
	        		  rss3 = rss3 + rssic[rssic.size()-k]/10;
	        		 }
	        		 myfile10 << rss1 << "," << rss2 << "," << rss3 << "," << "Sala10" ;
	        	     myfile10 << "\n";
	        	}
	        	if(j>=15){
	        		 //std::cout << rssic.size() << std::endl;
	        		 //std::cout << (rssic[rssic.size()-1]+rssic[rssic.size()-2]+rssic[rssic.size()-3]+rssic[rssic.size()-4]+rssic[rssic.size()-5])/5 << std::endl;
	        		 rss1 = 0;
	        		 for(k=1;k<16;k++){
	        		  rss1 = rss1 + rssia[rssia.size()-k]/15;
	        		 }
	        		 rss2 = 0;
	        		 for(k=1;k<16;k++){
	        		  rss2 = rss2 + rssib[rssib.size()-k]/15;
	        		 }
	        		 rss3 = 0;
	        		 for(k=1;k<16;k++){
	        		  rss3 = rss3 + rssic[rssic.size()-k]/15;
	        		 }
	        		 myfile15 << rss1 << "," << rss2 << "," << rss3 << "," << "Sala10" ;
	        	     myfile15 << "\n";
	        	}
	        	if(j>=20){
	        		 //std::cout << rssic.size() << std::endl;
	        		 //std::cout << (rssic[rssic.size()-1]+rssic[rssic.size()-2]+rssic[rssic.size()-3]+rssic[rssic.size()-4]+rssic[rssic.size()-5])/5 << std::endl;
	        		 rss1 = 0;
	        		 for(k=1;k<21;k++){
	        		  rss1 = rss1 + rssia[rssia.size()-k]/20;
	        		 }
	        		 rss2 = 0;
	        		 for(k=1;k<21;k++){
	        		  rss2 = rss2 + rssib[rssib.size()-k]/20;
	        		 }
	        		 rss3 = 0;
	        		 for(k=1;k<21;k++){
	        		  rss3 = rss3 + rssic[rssic.size()-k]/20;
	        		 }
	        		 myfile20 << rss1 << "," << rss2 << "," << rss3 << "," << "Sala10" ;
	        	     myfile20 << "\n";
	        	}
	        	if(j>=50){
	        		 //std::cout << rssic.size() << std::endl;
	        		 //std::cout << (rssic[rssic.size()-1]+rssic[rssic.size()-2]+rssic[rssic.size()-3]+rssic[rssic.size()-4]+rssic[rssic.size()-5])/5 << std::endl;
	        		 rss1 = 0;
	        		 for(k=1;k<51;k++){
	        		  rss1 = rss1 + rssia[rssia.size()-k]/50;
	        		 }
	        		 rss2 = 0;
	        		 for(k=1;k<51;k++){
	        		  rss2 = rss2 + rssib[rssib.size()-k]/50;
	        		 }
	        		 rss3 = 0;
	        		 for(k=1;k<51;k++){
	        		  rss3 = rss3 + rssic[rssic.size()-k]/50;
	        		 }
	        		 myfile50 << rss1 << "," << rss2 << "," << rss3 << "," << "Sala10" ;
	        	     myfile50 << "\n";
	        	}
	        	if(j>=100){
	        		 //std::cout << rssic.size() << std::endl;
	        		 //std::cout << (rssic[rssic.size()-1]+rssic[rssic.size()-2]+rssic[rssic.size()-3]+rssic[rssic.size()-4]+rssic[rssic.size()-5])/5 << std::endl;
	        		 rss1 = 0;
	        		 for(k=1;k<101;k++){
	        		  rss1 = rss1 + rssia[rssia.size()-k]/100;
	        		 }
	        		 rss2 = 0;
	        		 for(k=1;k<101;k++){
	        		  rss2 = rss2 + rssib[rssib.size()-k]/100;
	        		 }
	        		 rss3 = 0;
	        		 for(k=1;k<101;k++){
	        		  rss3 = rss3 + rssic[rssic.size()-k]/100;
	        		 }
	        		 myfile100 << rss1 << "," << rss2 << "," << rss3 << "," << "Sala10" ;
	        	     myfile100 << "\n";
	        	}
    		}
	      }
	    }



		  myfile5.close();
		  myfile10.close();
		  myfile15.close();
		  myfile20.close();
		  myfile50.close();
		  myfile100.close();



		  std::cout << "Terminado";
		  std::cout << "\n";

}
