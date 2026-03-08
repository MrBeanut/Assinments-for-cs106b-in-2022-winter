#include "Plotter.h"
#include "strlib.h"
using namespace std;

void runPlotterScript(istream &input) {
    PenStyle style{1, "black"}; // 初始化笔的属性
    double x0, y0, x1, y1;
    x0 = 0;
    y0 = 0;
    int penState = 0;//0代表不在纸上，1代表在纸上
    for (string line; getline(input, line);) {
        Vector<string> name_of_result = stringSplit(line, " ");
        string tmp = toLowerCase(name_of_result[0]);
        if (tmp == "pencolor") {
            style.color = name_of_result[1];
        }
        else if (tmp == "penwidth") {
            style.width = stringToReal(name_of_result[1]);
        }
        else if(tmp == "pendown")
        {
            penState = 1;
        }
        else if(tmp == "penup")
        {
            penState = 0;
        }
        else if(tmp == "moveabs")
        {

                x1 =stringToReal( name_of_result[1]);
                y1 =stringToReal( name_of_result[2]);
                if(penState)  drawLine(x0,y0,x1,y1,style);
                x0 = x1;//更新当前位置
                y0 = y1;
        }
        else if(tmp == "moverel")
        {
            x1 = stringToReal(name_of_result[1]) + x0;//更新目的地
            y1 = stringToReal(name_of_result[2]) + y0;
            if(penState)
            {
                drawLine(x0,y0,x1,y1,style);
            }
            x0 = x1;
            y0 = y1;
        }
    }
}
