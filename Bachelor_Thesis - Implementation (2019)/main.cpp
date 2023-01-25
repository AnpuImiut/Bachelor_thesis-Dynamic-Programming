#include <iostream>

#define M_PI acos(-1)
#include"interface.h"

void PNG_Test()
{
    int i;
    int y;

    pngwriter png(300,300,0,"PngOut/test.png");

    for(i = 1; i <= 300;++i)
    {
        y = 150+100*sin((double)i*9/300.0);

        png.plot(i,y, 0.0, 0.0, 1.0);
    }

    png.close();
}

void graph_test()
{
    // Prepare data.
    int n = 5000;
    std::vector<double> x(n), y(n), z(n), w(n,2);
    for(int i=0; i<n; ++i) {
        x.at(i) = i*i;
        y.at(i) = sin(2*M_PI*i/360.0);
        z.at(i) = log(i);
    }

    // Set the size of output image = 1200x780 pixels
    // plt::figure_size(1024, 768);
    // Plot line from given x and y data. Color is selected automatically.
    plt::plot(x, y);
    // Plot a red dashed line from given x and y data.
    plt::plot(x, w,"r--");
    // Plot a line whose name will show up as "log(x)" in the legend.
    plt::named_plot("log(x)", x, z);

    // Set x-axis to interval [0,1000000]
    plt::xlim(0, 1000*1000);
    // Enable legend.
    plt::legend();
    // Save the image (file format is determined by the extension)
    plt::save("./basic.png");
}

int main()
{
    Interface inf;
    inf.run();
//    int n = 1000;
//    LogSDfkt test(n,499);
//    while(true)
//    {
//        int input;
//        std::cin>> input;
//        if(input == -1)
//            break;
//        std::cout<< test.berechne(0,input) << "\n";
//    }
}
