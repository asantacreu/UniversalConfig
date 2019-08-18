
#include "uConfig.h"

#include <fstream>



void UConfig::LoadConfigFile(std::string filePath){
    std::ifstream input(filePath);
    while(input){
        std::string key;
        std::string value;
        std::getline(input, key, '=');
        std::getline(input, value, '\n');

        strings[key] = value;
    }
    input.close();
}



void UConfig::Save(){

}



void UConfig::SetString(std::string key, std::string value){

}




std::string UConfig::GetString(std::string key) const{
    return strings.find(key)->second;
}