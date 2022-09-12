#include <iostream>
#include <cstring>
using namespace std;

struct box
{
    char maker[40];
    float height;
    float width;
    float length;
    float volume;
};
/*Display the value of each member*/
void Display_box(box printBox)
{
    cout << "maker: " << printBox.maker << endl;
    cout << "height: " << printBox.height << endl;
    cout << "width: " << printBox.width << endl;
    cout << "length: " << printBox.length << endl;
    cout << "volume: " << printBox.volume << endl;
}

void Cal_Volume(box *cal_box)
{
    float h = cal_box->height;
    float w = cal_box->width;
    float l = cal_box->length;
    cal_box->volume = h * w * l;
}

int main()
{
    box start;
    stpcpy(start.maker, "Jack Smith");
    start.height = 3.4;
    start.width = 4.5;
    start.length = 5.6;
    start.volume = 0;
    cout << "Before setting volume:" << endl;
    Display_box(start);
    Cal_Volume(&start);
    cout << "After setting volume:" << endl;
    Display_box(start);
    return 0;
}
