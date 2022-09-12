#include "select_cities.h"

int main()
{
    string data;
    ifstream world_data("world_cities.csv");
    ofstream china_data;
    china_data.open("china_cities.csv");
    
    if (!world_data.is_open())
    {
        cout << "Error: fail to open input file" << endl;
        exit(1);
    }

    if (!china_data.is_open())
    {
        cout << "Error: fail to opening output file" << endl;
        exit(1);
    }

    // 读取数据
    while (getline(world_data, data))
    {
        if(judge_city_in_China(data) == 1) 
            china_data << data << endl;
    }

    world_data.close();
    china_data.close();
    return 0;
}