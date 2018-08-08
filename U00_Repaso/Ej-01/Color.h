#ifndef REPASO_COLOR_H
#define REPASO_COLOR_H


class Color {
private:
    int red;
    int green;
    int blue;
public:
    Color(){
        red = 0;
        green = 0;
        blue = 0;
    }
    Color(int r, int g, int b){
        red = r;
        green = g;
        blue = b;
    }

};


#endif //REPASO_COLOR_H
