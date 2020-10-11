#include <iostream>
#include <iomanip>
#include <sstream>
#include <string>

using namespace std;

#include <openssl/sha.h>
string sha256(const string str)
{
    unsigned char hash[SHA256_DIGEST_LENGTH];
    SHA256_CTX sha256;
    SHA256_Init(&sha256);
    SHA256_Update(&sha256, str.c_str(), str.size());
    SHA256_Final(hash, &sha256);
    stringstream ss;
    for(int i = 0; i < SHA256_DIGEST_LENGTH; i++)
    {
        ss << hex << setw(2) << setfill('0') << (int)hash[i];
    }
    return ss.str();
}

int main() {
  string f;
  f=sha256("f");
   cout<<f<<endl;
    cout << sha256("1234567890_2") << endl;
    
    return 0;
}