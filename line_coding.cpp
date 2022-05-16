#include <bits/stdc++.h>
#include <graphics.h>
using namespace std;

void diagraminit(char* method){
    int gd = DETECT, gm, color;
    initgraph(&gd, &gm, "");

    setlinestyle(0, 0, 3);
    settextstyle(1,0,1);

    line(100,100,100,500);
    line(100,300,600,300);

    outtextxy(100, 90, "Amplitude");
    outtextxy(550, 310, "Time");
    outtextxy(300, 520, method);
    outtextxy(50, 450, "-V");
    outtextxy(70, 300, "0");
    outtextxy(50, 150, "+V");

}

void unipolar_NRZ(vector<int> bitStream){

    diagraminit("Unipolar_NRZ");
    int xStart = 100, yStart = 300, xEnd = 140, yEnd = 300, xBits = 115;

    char buffer1[16] = {0};
    itoa(bitStream[0], buffer1, 10);
    outtextxy(xBits, 270, buffer1);

    for(int i=1; i<bitStream.size(); i++){
        char buffer[16] = {0};
        itoa(bitStream[i], buffer, 10);
        outtextxy((xBits+(i*40)), 270, buffer);
    }

    setcolor(2);

    if(bitStream[0]==1){
        line(xStart,yStart-40,xEnd,yEnd-40);
        if(bitStream[1]==0){
            line(xEnd,yEnd-40,xEnd,yEnd);
        }
    }else if(bitStream[0]==0){
        line(xStart,yStart,xEnd,yEnd);
        if(bitStream[1]==1){
            line(xEnd,yEnd,xEnd,yEnd-40);
        }
    }

    for(int i=1; i<bitStream.size(); i++){
        if(bitStream[i]==1){
            line((xStart+(i*40)),yStart-40,(xEnd+(i*40)),yEnd-40);
            if(bitStream[i+1]==0){
                line((xEnd+(i*40)),yEnd-40,(xEnd+(i*40)),yEnd);
            }
        }else if(bitStream[i]==0){
            line((xStart+(i*40)),yStart,(xEnd+(i*40)),yEnd);
            if(bitStream[i+1]==1){
                line((xEnd+(i*40)),yEnd,(xEnd+(i*40)),yEnd-40);
            }
        }
    }

    getch();
    closegraph();

}

void polar_RZ(vector<int> bitStream){
    diagraminit("polar_RZ");

    int xStart = 100, yStart = 300, xEnd = 140, yEnd = 300, xBits = 115;

    char buffer1[16] = {0};
    itoa(bitStream[0], buffer1, 10);
    outtextxy(xBits, 210, buffer1);

    for(int i=1; i<bitStream.size(); i++){
        char buffer[16] = {0};
        itoa(bitStream[i], buffer, 10);
        outtextxy((xBits+(i*40)), 210, buffer);
    }

    setcolor(2);

    if(bitStream[0]==1){
        line(xStart,yStart-40,xEnd-20,yEnd-40);
        line(xEnd-20,yEnd-40,xEnd-20,yEnd);
        line(xEnd-20,yEnd,xEnd,yEnd);
    }else if(bitStream[0]==0){
        line(xStart,yStart+40,xEnd-20,yEnd+40);
        line(xEnd-20,yEnd+40,xEnd-20,yEnd);
        line(xEnd-20,yEnd,xEnd,yEnd);
    }

    for(int i=1; i<bitStream.size(); i++){
        if(bitStream[i]==1){
            line((xStart+(i*40)),yStart,(xStart+(i*40)),yEnd-40);
            line((xStart+(i*40)),yEnd-40,(xEnd-20+(i*40)),yEnd-40);
            line((xEnd-20+(i*40)),yEnd-40,(xEnd-20+(i*40)),yEnd);
            line((xEnd-20+(i*40)),yEnd,(xEnd+(i*40)),yEnd);
        }else if(bitStream[i]==0){
            line((xStart+(i*40)),yStart,(xStart+(i*40)),yEnd+40);
            line((xStart+(i*40)),yEnd+40,(xEnd-20+(i*40)),yEnd+40);
            line((xEnd-20+(i*40)),yEnd+40,(xEnd-20+(i*40)),yEnd);
            line((xEnd-20+(i*40)),yEnd,(xEnd+(i*40)),yEnd);
            }
    }

    getch();
    closegraph();

}

void polar_NRZ_L(vector<int> bitStream){
    diagraminit("polar_NRZ_L");

    int xStart = 100, yStart = 300, xEnd = 140, yEnd = 300, xBits = 115;

    char buffer1[16] = {0};
    itoa(bitStream[0], buffer1, 10);
    outtextxy(xBits, 270, buffer1);

    for(int i=1; i<bitStream.size(); i++){
        char buffer[16] = {0};
        itoa(bitStream[i], buffer, 10);
        outtextxy((xBits+(i*40)), 270, buffer);
    }

    setcolor(2);

    if(bitStream[0]==1){
        line(xStart,yStart-40,xStart,yEnd+40);
        line(xStart,yEnd+40,xEnd,yEnd+40);
        if(bitStream[1]==0){
            line(xEnd,yEnd+40,xEnd,yEnd-40);
        }
    }else if(bitStream[0]==0){
        line(xStart,yStart-40,xEnd,yEnd-40);
    }

    for(int i=1; i<bitStream.size(); i++){
        if(bitStream[i]==1){
            if(bitStream[i-1]==0){
                line((xStart+(i*40)),yStart-40,(xStart+(i*40)),yEnd+40);
            }
            line((xStart+(i*40)),yEnd+40,(xEnd+(i*40)),yEnd+40);
            if(bitStream[i+1]==0){
                line((xEnd+(i*40)),yEnd+40,(xEnd+(i*40)),yEnd-40);
            }
        }else if(bitStream[i]==0){
            line((xStart+(i*40)),yStart-40,(xEnd+(i*40)),yEnd-40);
        }
    }

    getch();
    closegraph();

}

void polar_NRZ_I(vector<int> bitStream){
    diagraminit("polar_NRZ_I");

    int xStart = 100, yStart = 300, xEnd = 140, yEnd = 300, xBits = 115;

    char buffer1[16] = {0};
    itoa(bitStream[0], buffer1, 10);
    outtextxy(xBits, 270, buffer1);

    for(int i=1; i<bitStream.size(); i++){
        char buffer[16] = {0};
        itoa(bitStream[i], buffer, 10);
        outtextxy((xBits+(i*40)), 270, buffer);
    }

    setcolor(2);

    int counter=0;
    if(bitStream[0]==1){
        line(xStart,yStart-40,xEnd,yEnd-40);
    }else if(bitStream[0]==0){
        line(xStart,yStart-40,xEnd,yEnd-40);
    }

    for(int i=1; i<bitStream.size(); i++){
        if(bitStream[i]==1){
            if(counter==0){
                line((xStart+(i*40)),yStart-40,(xStart+(i*40)),yEnd+40);
                line((xStart+(i*40)),yStart+40,(xEnd+(i*40)),yEnd+40);
                counter=1;
            }else if(counter==1){
                line((xStart+(i*40)),yStart+40,(xStart+(i*40)),yEnd-40);
                line((xStart+(i*40)),yStart-40,(xEnd+(i*40)),yEnd-40);
                counter=0;
            }
        }else if(bitStream[i]==0){
            if(counter==0){
                line((xStart+(i*40)),yStart-40,(xEnd+(i*40)),yEnd-40);
            }else if(counter==1){
                line((xStart+(i*40)),yStart+40,(xEnd+(i*40)),yEnd+40);
            }
        }
    }

    getch();
    closegraph();

}

void Manchester(vector<int> bitStream){
    diagraminit("Manchester");

    int xStart = 100, yStart = 300, xEnd = 140, yEnd = 300, xBits = 115;

    char buffer1[16] = {0};
    itoa(bitStream[0], buffer1, 10);
    outtextxy(xBits, 210, buffer1);

    for(int i=1; i<bitStream.size(); i++){
        char buffer[16] = {0};
        itoa(bitStream[i], buffer, 10);
        outtextxy((xBits+(i*40)), 210, buffer);
    }

    setcolor(2);

    if(bitStream[0]==1){
        line(xStart,yStart+40,xEnd-20,yEnd+40);
        line(xEnd-20,yEnd+40,xEnd-20,yEnd-40);
        line(xEnd-20,yEnd-40,xEnd,yEnd-40);
        if(bitStream[1]==1){
            line(xEnd,yEnd-40,xEnd,yEnd+40);
        }
    }else if(bitStream[0]==0){
        line(xStart,yStart-40,xEnd-20,yEnd-40);
        line(xEnd-20,yEnd-40,xEnd-20,yEnd+40);
        line(xEnd-20,yEnd+40,xEnd,yEnd+40);
        if(bitStream[1]==0){
            line(xEnd,yEnd+40,xEnd,yEnd-40);
        }
    }

    for(int i=1; i<bitStream.size(); i++){
        if(bitStream[i]==1){
            line((xStart+(i*40)),yStart+40,(xEnd-20+(i*40)),yEnd+40);
            line((xEnd-20+(i*40)),yEnd+40,(xEnd-20+(i*40)),yEnd-40);
            line((xEnd-20+(i*40)),yEnd-40,(xEnd+(i*40)),yEnd-40);
            if(bitStream[i+1]==1){
                line((xEnd+(i*40)),yEnd-40,(xEnd+(i*40)),yEnd+40);
            }
        }else if(bitStream[i]==0){
            line((xStart+(i*40)),yStart-40,(xEnd-20+(i*40)),yEnd-40);
            line((xEnd-20+(i*40)),yEnd-40,(xEnd-20+(i*40)),yEnd+40);
            line((xEnd-20+(i*40)),yEnd+40,(xEnd+(i*40)),yEnd+40);
            if(bitStream[i+1]==0){
                line((xEnd+(i*40)),yEnd+40,(xEnd+(i*40)),yEnd-40);
            }
        }
    }

    getch();
    closegraph();

}

void AMI(vector<int> bitStream){
    diagraminit("AMI");

    int xStart = 100, yStart = 300, xEnd = 140, yEnd = 300, xBits = 115;

    char buffer1[16] = {0};
    itoa(bitStream[0], buffer1, 10);
    outtextxy(xBits, 270, buffer1);

    for(int i=1; i<bitStream.size(); i++){
        char buffer[16] = {0};
        itoa(bitStream[i], buffer, 10);
        outtextxy((xBits+(i*40)), 270, buffer);
    }

    setcolor(2);

    int neighbour_1_Counter = 0;
    if(bitStream[0]==1){
        line(xStart,yStart-40,xEnd,yEnd-40);
        line(xEnd,yEnd-40,xEnd,yEnd);
        neighbour_1_Counter++;
    }else if(bitStream[0]==0){
        line(xStart,yStart,xEnd,yEnd);
    }

    for(int i=1; i<bitStream.size(); i++){
        if(bitStream[i]==1){
            if(neighbour_1_Counter==1){
                line((xStart+(i*40)),yStart,(xStart+(i*40)),yEnd+40);
                line((xStart+(i*40)),yEnd+40,(xEnd+(i*40)),yEnd+40);
                line((xEnd+(i*40)),yEnd+40,(xEnd+(i*40)),yEnd);
                neighbour_1_Counter=0;
            }else{
                line((xStart+(i*40)),yStart,(xStart+(i*40)),yEnd-40);
                line((xStart+(i*40)),yEnd-40,(xEnd+(i*40)),yEnd-40);
                line((xEnd+(i*40)),yEnd-40,(xEnd+(i*40)),yEnd);
                neighbour_1_Counter++;
            }
        }else if(bitStream[i]==0){
            line((xStart+(i*40)),yStart,(xEnd+(i*40)),yEnd);
        }
    }

    getch();
    closegraph();

}

int main(){
    //vector to store converted binary value
    vector<int> bitStream;
    int id = 67;

    // applying decimal to binary conversion formula
    for(int i=0; ; i++) {
        bitStream.push_back(id % 2);
        id = id / 2;
        if(id==0){
            break;
        }
    }

    for(int i=0; ; i++){
        if(bitStream.size()%4==0){
            break;
        }else{
            bitStream.push_back(0);
        }
    }

    reverse(bitStream.begin(), bitStream.end());


     for(int i=0; i<bitStream.size(); i++){
         cout<<bitStream[i]<<" ";
     }
     cout<<"\n"<<bitStream.size();

     unipolar_NRZ(bitStream);
     //polar_RZ(bitStream);
     //polar_NRZ_L(bitStream);
     //polar_NRZ_I(bitStream);
    //Manchester(bitStream);
    //AMI(bitStream);


    return 0;
}
