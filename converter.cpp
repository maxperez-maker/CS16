#include <iostream> // for cin, cout, endl
#include <cstdlib>  // for exit()
#include <cmath>    // for pow() function ONLY
using namespace std;

int bin2d(string binstring);
string dec2bh(string sdec, char bh);

int main (int argc, char *argv[] ) {
    
    if(argc != 3){
        cerr << "Usage: converter <options: d2b, d2h, b2d> <value>";
        exit(0);
    }

    string str1 = argv[2];
    string str2 = argv[1];
    
    if(str2 == "d2b"){
        cout << "The value in binary is: " << dec2bh(str1 , 'b')<< endl;
    }
    else if(str2 == "d2h"){
        cout << "The value in hexadecimal is: " << dec2bh(str1 , 'h')<< endl;
    }
    else if(str2 == "b2d"){
        if(bin2d(str1) == -1){
            cerr << "Binary value contains non-binary digits." << endl;
        }
        else{
        cout << "The value in decimal is: " << bin2d(str1)<< endl;
        }
    }
    else{
        cerr << "Usage: converter <options: d2b, d2h, b2d> <value>";
        exit(0);
    }
    return 0;
}

int bin2d(string binstring){
    int sum = 0;
    
    for( int i = 0 ; i < binstring.size() ; i++){
        if(binstring[i] != '1' && binstring[i] != '0'){
         return -1;
        }
        else if(binstring[i] == '1'){
            sum += pow(2 , binstring.size() - (i + 1));
        }
    }
    return sum;
}

string dec2bh(string sdec, char bh){
    int n = stoi(sdec);
    if(bh == 'b'){
        if(n == 0){ 
        return "0";
        }

        string Bin = "";

        while (n > 0) {
            int remainder = n % 2;
            Bin = char(48 + remainder) + Bin;
            n /= 2;
        }

        return Bin;
}
    else if(bh == 'h'){
        if(n == 0){ 
        return "0";
        }

        string Hex = "";

        while( n > 0){
            int remainder = n % 16;
            if(remainder < 10){
                Hex = char(48 + remainder) + Hex;
                n /= 16;
            }
            else{
                Hex = char(65 + (remainder - 10)) + Hex;
                n /= 16;
            }
        }
        return Hex;
}
    else{
        return "";
    }
}
