#include <iostream>
#include <fstream>
#include <cstring>
#include <random>
#include <algorithm>
#include <cassert>
#include <vector>
#include <x86intrin.h>

#include "utils.h"
#include "core_workload.h"


#include <iostream>
#include <fstream>
#include <cstring>
#include <random>
#include <algorithm>
#include <cassert>
#include <vector>
#include <x86intrin.h>

string WorkloadName[] = {"random", "lognormal", "normal", "segment"};
enum WorkloadDist {RANDOM, LOGNORMAL, NORMAL, SEGMENT};

using namespace std;

int main(int argc, char ** argv) {

    // arg list: 
    // 1. Distribution: random, lognormal, normal, segment
    // 2. scale: total data count
    // 3. 


    WorkloadDist dist;
    if(strcmp(argv[1], "random") == 0) 
        dist = WorkloadDist::RANDOM;
    else if(strcmp(argv[1], "lognormal") == 0)
        dist = WorkloadDist::LOGNORMAL;
    else if(strcmp(argv[1], "normal") == 0)
        dist = WorkloadDist::NORMAL;
    else if(strcmp(argv[1], "segment") == 0)
        dist = WorkloadDist::SEGMENT;
    else 
        dist = WorkloadDist::RANDOM;

    int key_len = 16;

    uint64_t scale = atoi(argv[2]);
    std::vector<string> keys_write;

    if(dist == WorkloadDist::RANDOM){
        uint64_t key_min = 0;
        uint64_t key_max = scale * 100;

        string filenamew = WorkloadName[dist] + "_write_" + std::to_string(scale) + ".dat";
        if(!utils::file_exist(filenamew.c_str())) {
            remove(filenamew.c_str());
        }
        std::default_random_engine e;
        std::uniform_int_distribution<int> u(key_min,key_max);
        for(uint64_t i = 0; i < scale; i++) {
            
            int tmp = u(e);
            string tmp_str = std::to_string(tmp);
            string tmp_key = string(key_len - tmp_str.length(), '0') + tmp_str;
            keys_write.push_back(tmp_key);
        }
        srand((unsigned int)time(0));
        random_shuffle(keys_write.begin(),keys_write.end());
        ofstream foutr(filenamew);
        for(int i=0; i<keys_write.size(); i++){
            foutr<<keys_write[i]<<endl;
        }
        cout<<"outputfile " + filenamew << endl;
    }

    else if(dist == WorkloadDist::LOGNORMAL){
        uint64_t key_min = 0;
        uint64_t key_max = scale * 100;

        string filenamew = WorkloadName[dist] + "_write_" + std::to_string(scale) + ".dat";
        if(!utils::file_exist(filenamew.c_str())) {
            remove(filenamew.c_str());
        }
        std::default_random_engine e;
        std::lognormal_distribution<double> dist(0,2);
        for(uint64_t i = 0; i < scale; i++) {
            if(i%100000 == 0){
                cout<<"lognormal: "<<i<<" out of "<<scale<<endl;
            }

            uint64_t tmp_int = -1;

            do {
                std::mt19937 gen(utils::rand());
                double val = static_cast<double>(dist(gen));
                tmp_int = static_cast<uint64_t>(val * 10e14);
            } while(tmp_int > 10e16);
            // cout<<tmp_int<<endl;
            // uint64_t tmp_int = val;
            string tmp_str = std::to_string(tmp_int);
            string tmp_key;
            if(tmp_str.length()<key_len){
                tmp_key = string(key_len - tmp_str.length(), '0') + tmp_str;
            }
            else{
                tmp_key = tmp_str;
            }
            
            
            keys_write.push_back(tmp_key);
        }
        srand((unsigned int)time(0));
        random_shuffle(keys_write.begin(),keys_write.end());
        ofstream foutr(filenamew);
        for(int i=0; i<keys_write.size(); i++){
            foutr<<keys_write[i]<<endl;
        }
        cout<<"outputfile " + filenamew << endl;
    }

    else if(dist == WorkloadDist::NORMAL){
        uint64_t key_min = 0;
        uint64_t key_max = scale * 10;
        

        string filenamew = WorkloadName[dist] + "_write_" + std::to_string(scale) + ".dat";
        if(!utils::file_exist(filenamew.c_str())) {
            remove(filenamew.c_str());
        }
        std::default_random_engine e;
        std::normal_distribution<double> dist(key_max/2,key_max/8);
        for(uint64_t i = 0; i < scale; i++) {
            if(i%100000 == 0){
                cout<<"normal: "<<i<<" out of "<<scale<<endl;
            }
            
            std::mt19937 gen(utils::rand());
            double val = (double)dist(gen);
            while(val <= 0 || val > UINT64_MAX) {
                std::mt19937 gen(utils::rand());
                val = (double)dist(gen);
            }
            // cout<<val<<endl;
            // uint64_t tmp_int = val * 10e9;
            uint64_t tmp_int = val;
            // cout<<tmp_int<<endl;
            string tmp_str = std::to_string((uint64_t)std::round(tmp_int));
            // cout<<tmp_str<<endl;
            string tmp_key = string(key_len - tmp_str.length(), '0') + tmp_str;
            keys_write.push_back(tmp_key);
        }
        srand((unsigned int)time(0));
        random_shuffle(keys_write.begin(),keys_write.end());
        ofstream foutr(filenamew);
        for(int i=0; i<keys_write.size(); i++){
            foutr<<keys_write[i]<<endl;
        }
        cout<<"outputfile " + filenamew << endl;
    }

    else if(dist == WorkloadDist::SEGMENT){
        int seg_idx = 0;
        int tmp_count = 0;
        int seg_len = 10;
        string filenamew = WorkloadName[dist] + "_write_" + std::to_string(scale) + ".dat";
        for(int i=0; i<scale; i++){
            uint64_t tmp_key = i + 100 * seg_idx;
            // uint64_t tmp_key = i + 0 * seg_idx;
            tmp_count++;
            if(tmp_count == seg_len){
                tmp_count = 0;
                seg_idx ++;
            }
            // cout<<tmp_key;
            string key = to_string(tmp_key);
            // while(key.size()<key_len){
            //     // key = "0" + key;
            //     key = key + "0";
            // }
            // cout<<" "<<key<<endl;
            keys_write.push_back(key);
        }
        srand((unsigned int)time(0));
        random_shuffle(keys_write.begin(),keys_write.end());
        ofstream foutr(filenamew);
        for(int i=0; i<keys_write.size(); i++){
            foutr<<keys_write[i]<<endl;
        }
        cout<<"outputfile " + filenamew << endl;
    }


    return 0;
}