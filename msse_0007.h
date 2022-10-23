#include <iostream>
#include <string>
#include <algorithm>
#include "header_tree.h"
#include "tools/common.h"
//header == 07
struct msesid07{
        uint16_t len[5];
        uint8_t lenname[6],namebyid[6];
        std::string name;
        uint8_t dirname[42];
        uint16_t lendata[5];
        std::string data;
};

void getinputdata(msesid07 *object,int size)
{
    for (int i = 0; i < size; i++)
    {
        char temp;
        for (int lencount = 0; lencount < 4; lencount++)
        { 
            std::cin.get(temp);
            object[i].len[lencount]=uint8_t(temp);
        }
        for (int namebyidcount = 0; namebyidcount < 5; namebyidcount++)
        { 
            std::cin.get(temp);
            object[i].namebyid[namebyidcount]=uint8_t(temp);
        }
        for (int namecount = 0; namecount < 4; namecount++)
        { 
            std::cin.get(temp);
            object[i].lenname[namecount]=uint8_t(temp);
        }
        std::getline(std::cin,object[i].name,'\x00');
        for (int dist = 0; dist < 41; dist++)
        {
            std::cin.get(temp);
            object[i].dirname[dist]=uint8_t(temp);
        }
        for (int lendatacount = 0; lendatacount < 4; lendatacount++)
        {
            std::cin.get(temp);
            object[i].lendata[lendatacount]=uint8_t(temp);
        }
        std::getline(std::cin,object[i].data,'\0');
        std::transform((object[i].data).begin(), (object[i].data).end(), (object[i].data).begin(), ::tolower);
    }
}

void outputdata(msesid07 object[],uint8_t header[],int size=0){
    for (size_t i = 0; i < 140; i++)
        std::cout<<char(header[i]);
    for (int i = 0; i < size; i++)
    {
        for (int lencount = 0; lencount < 4; lencount++)
        { 
            std::cout<<char(object[i].len[lencount]);
        }
        for (int namebyidcount = 0; namebyidcount < 5; namebyidcount++)
        { 
            std::cout<<char(object[i].namebyid[namebyidcount]);
        }
        for (int namecount = 0; namecount < 4; namecount++)
        { 
            std::cout<<char(object[i].lenname[namecount]);
        }
        std::cout<<object[i].name<<char(0x00);
        for (int dist = 0; dist < 41; dist++)
        {
            std::cout<<char(object[i].dirname[dist]);
        }
        for (int lendatacount = 0; lendatacount < 4; lendatacount++)
        {
            std::cout<<char(object[i].lendata[lendatacount]);
        }
        std::cout<<object[i].data<<char(0x00);
    }
}

