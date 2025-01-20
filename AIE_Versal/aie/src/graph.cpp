#include <iostream>
#include <fstream>
#include "graph.hpp"
#include "common.h"

simpleGraph vmul_graph;

#if defined(__AIESIM__) || defined(__X86SIM__)
int main(int argc, char **argv)
{
    vmul_graph.init();
#ifdef STREAM
    vmul_graph.run(2);
#else
    vmul_graph.run(1);
#endif
    vmul_graph.end();
    std::ifstream golden_file, aie_file;
    std::cout << "HEYOU" << std::endl;
    golden_file.open("../data/golden.txt");
    if (golden_file.fail())
    {
        std::cerr << "Error opening golden file." << std::endl;
        golden_file.close();
        return -1;
    }
    for(auto cu = 0; cu < PE; cu++){
#if defined(__X86SIM__)
        aie_file.open("x86simulator_output/output"+std::to_string(cu)+".txt");
#else
        aie_file.open("aiesimulator_output/outpu"+std::to_string(cu)+".txt");
#endif
        if (aie_file.fail())
        {
            std::cerr << "Error opening produced file with PE "<< cu << "cu." << std::endl;
            return -1;
        }

        std::string line_golden, line_aie;
        bool match = true;
        while (getline(golden_file, line_golden))
        {
            getline(aie_file, line_aie);
            if (aie_file.eof())
            {
                std::cerr << "AI Engine results are too short to match golden result with PE "<< cu << "cu." << std::endl;
                break;
            }
            while (line_aie[0] == 'T')
                getline(aie_file, line_aie);
            if (std::stoi(line_golden) != std::stoi(line_aie))
            {
                match = false;
                break;
            }
        }
        if (!aie_file.eof())
        {
            getline(aie_file, line_aie);
            if (!aie_file.eof())
                std::cerr << "AI Engine results are too long to match golden result with PE "<< cu << "cu." << std::endl;
        }
        if (match)
            std::cout << "AI Engine results match golden result with PE "<< cu << "cu." << std::endl;
        else
            std::cout << "AI Engine results DO NOT match golden result with PE "<< cu << "cu." << std::endl;

        golden_file.close();
        aie_file.close();
    }
    return 0;
}
#endif