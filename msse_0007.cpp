#include <iostream>
#include <string>
#include <fstream>
#include <algorithm>
#include "better_int_convert.h"
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

void getinputdata(msesid07 *litebulletcfg,int size)
{
    for (int i = 0; i < size; i++)
    {
        char temp;
        for (int lencount = 0; lencount < 4; lencount++)
        { 
            std::cin.get(temp);
            litebulletcfg[i].len[lencount]=uint8_t(temp);
        }
        for (int namebyidcount = 0; namebyidcount < 5; namebyidcount++)
        { 
            std::cin.get(temp);
            litebulletcfg[i].namebyid[namebyidcount]=uint8_t(temp);
        }
        for (int namecount = 0; namecount < 4; namecount++)
        { 
            std::cin.get(temp);
            litebulletcfg[i].lenname[namecount]=uint8_t(temp);
        }
        std::getline(std::cin,litebulletcfg[i].name,'\x00');
        for (int dist = 0; dist < 41; dist++)
        {
            std::cin.get(temp);
            litebulletcfg[i].dirname[dist]=uint8_t(temp);
        }
        for (int lendatacount = 0; lendatacount < 4; lendatacount++)
        {
            std::cin.get(temp);
            litebulletcfg[i].lendata[lendatacount]=uint8_t(temp);
        }
        std::getline(std::cin,litebulletcfg[i].data,'\0');
        std::transform((litebulletcfg[i].data).begin(), (litebulletcfg[i].data).end(), (litebulletcfg[i].data).begin(), ::tolower);
    }
}

void outputdata(msesid07 litebulletcfg[],uint8_t header[],int size=0){
    std::ofstream ofile;
    ofile.open("liteBulletCfg_mod.bytes",std::ios::binary);
    for (size_t i = 0; i < 140; i++)
        ofile<<char(header[i]);
    for (int i = 0; i < size; i++)
    {
        for (int lencount = 0; lencount < 4; lencount++)
        { 
            ofile<<char(litebulletcfg[i].len[lencount]);
        }
        for (int namebyidcount = 0; namebyidcount < 5; namebyidcount++)
        { 
            ofile<<char(litebulletcfg[i].namebyid[namebyidcount]);
        }
        for (int namecount = 0; namecount < 4; namecount++)
        { 
            ofile<<char(litebulletcfg[i].lenname[namecount]);
        }
        ofile<<litebulletcfg[i].name<<char(0x00);
        for (int dist = 0; dist < 41; dist++)
        {
            ofile<<char(litebulletcfg[i].dirname[dist]);
        }
        for (int lendatacount = 0; lendatacount < 4; lendatacount++)
        {
            ofile<<char(litebulletcfg[i].lendata[lendatacount]);
        }
        ofile<<litebulletcfg[i].data<<char(0x00);
    }
}

