#include <iostream>
#include <vector>
using namespace std;

vector<vector<vector<string>>>cube(6,vector<vector<string>>(3,vector<string>(3)));
vector<string> colors = {"white","blue","orange","green","red","yellow"};
vector<string> colors2 = {"W","B","O","G","R","Y"};
int getOppositeFace(int face) {
    switch(face) {
        case 0: return 5; // Up -> Down
        case 1: return 3; // Front -> Back
        case 2: return 4; // Right -> Left
        case 3: return 1; // Back -> Front
        case 4: return 2; // Left -> Right
        case 5: return 0; // Down -> Up
        default: return -1; // invalid
    }
}
void rotateCW(int sideNo){
    //first corners
    string temp = cube[sideNo][0][0];
    cube[sideNo][0][0] = cube[sideNo][2][0];
    cube[sideNo][2][0] = cube[sideNo][2][2];
    cube[sideNo][2][2] = cube[sideNo][0][2];
    cube[sideNo][0][2] = temp;
    //then edges
    temp = cube[sideNo][0][1];
    cube[sideNo][0][1] = cube[sideNo][1][0];
    cube[sideNo][1][0] = cube[sideNo][2][1];
    cube[sideNo][2][1] = cube[sideNo][1][2];
    cube[sideNo][1][2] = temp;

}
void rotateCCW(int sideNo){
    int t = 3;
    while(t--){
        rotateCW(sideNo);
    }
}
void M() {
    cout<<"Executing M()..."<<endl;
    vector<string> tempUp = {cube[0][0][1], cube[0][1][1], cube[0][2][1]}; // middle column of Up face
    cube[0][0][1] = cube[3][2][1];
    cube[0][1][1] = cube[3][1][1];
    cube[0][2][1] = cube[3][0][1];
    // Move Down face middle column (5) to Back face middle column (3)
    cube[3][0][1] = cube[5][2][1];
    cube[3][1][1] = cube[5][1][1];
    cube[3][2][1] = cube[5][0][1];
    // Move Front face middle column (1) to Down face middle column (5)
    cube[5][0][1] = cube[1][0][1];
    cube[5][1][1] = cube[1][1][1];
    cube[5][2][1] = cube[1][2][1];
    // Move saved Up face middle column (tempUp) to Front face middle column (1)
    cube[1][0][1] = tempUp[0];
    cube[1][1][1] = tempUp[1];
    cube[1][2][1] = tempUp[2];
}
void R(){
    cout<<"Executing R()..."<<endl;
    vector<string> tempUp = {cube[0][0][2], cube[0][1][2], cube[0][2][2]}; // right column of Up face
    cube[0][0][2] = cube[3][2][2];
    cube[0][1][2] = cube[3][1][2];
    cube[0][2][2] = cube[3][0][2];
    // Move Down face right column (5) to Back face right column (3)
    cube[3][0][2] = cube[5][2][2];
    cube[3][1][2] = cube[5][1][2];
    cube[3][2][2] = cube[5][0][2];
    // Move Front face right column (1) to Down face right column (5)
    cube[5][0][2] = cube[1][0][2];
    cube[5][1][2] = cube[1][1][2];
    cube[5][2][2] = cube[1][2][2];
    // Move saved Up face right column (tempUp) to Front face right column (1)
    cube[1][0][2] = tempUp[0];
    cube[1][1][2] = tempUp[1];
    cube[1][2][2] = tempUp[2];
    rotateCW(4);

}
void L(){
    cout<<"Executing L()..."<<endl;
    vector<string> tempUp = {cube[5][0][0], cube[5][1][0], cube[5][2][0]}; // left column of up face
    //Move Back Face(3) to Up face(5)
    cube[5][0][0] = cube[3][2][2];
    cube[5][1][0] = cube[3][1][2];
    cube[5][2][0] = cube[3][0][2];
    //Move Back 
    cube[3][0][2] = cube[5][2][2];
    cube[3][1][2] = cube[5][1][2];
    cube[3][2][2] = cube[5][0][2];
    // Move Front face right column (1) to Down face right column (5)
    cube[5][0][2] = cube[1][0][2];
    cube[5][1][2] = cube[1][1][2];
    cube[5][2][2] = cube[1][2][2];
    // Move saved Up face right column (tempUp) to Front face right column (1)
    cube[1][0][2] = tempUp[0];
    cube[1][1][2] = tempUp[1];
    cube[1][2][2] = tempUp[2];
    rotateCW(2);
}
void U(){
    cout<<"Executing U()..."<<endl;
    vector<string> temp = {cube[2][0][0], cube[2][0][1], cube[2][0][2]}; // Upper row of left face
    //Move upper row of back face to left face
    cube[2][0][0] = cube[3][0][0];
    cube[2][0][1] = cube[3][0][1];
    cube[2][0][2] = cube[3][0][2];
    //Move Right Upper row to Back Upper row
    cube[3][0][0] = cube[4][0][0];
    cube[3][0][1] = cube[4][0][1];
    cube[3][0][2] = cube[4][0][2];
    // Move front Upper Row to Right Upper Row
    cube[4][0][0] = cube[1][0][0];
    cube[4][0][1] = cube[1][0][1];
    cube[4][0][2] = cube[1][0][2];
    // Move saved Up face right column (tempUp) to Front face right column (1)
    cube[1][0][0] = temp[0];
    cube[1][0][1] = temp[1];
    cube[1][0][2] = temp[2];
    rotateCCW(5);
}
void showCube(){
    cout<<"Showing Cube..."<<endl;
    for(int i = 0;i<6;i++){
        for(int j = 0;j<3;j++){
            for(int k = 0;k<3;k++){
                cout<<cube[i][j][k]<<" ";
            }
            cout<<endl;
        }
        cout<<endl;
    }
    cout<<"Cube Shown"<<endl;
    cout<<"-- -- --"<<endl;
}
void resetCube(){
    cout<<"Resetting Cube..."<<endl;
    for(int i = 0;i<6;i++){
        for(int j = 0;j<9;j++){
            cube[i][j/3][j%3] = colors2[i];
        }
    }
    cout<<"Cube Reset"<<endl;
}
void resetCubeCheckered() {
    cout << "Resetting Cube to Checkered Pattern with Opposite Face Colors..." << endl;
    for (int i = 0; i < 6; i++) {
        int opp = getOppositeFace(i);
        for (int r = 0; r < 3; r++) {
            for (int c = 0; c < 3; c++) {
                if ((r + c) % 2 == 0) {
                    cube[i][r][c] = colors2[i];       // main face color
                } else {
                    cube[i][r][c] = colors2[opp];    // opposite face color
                }
            }
        }
    }
    cout << "Cube Reset to Checkered Opposite Face Pattern" << endl;
}
int main(){
    resetCubeCheckered();
    showCube();
    M();
    showCube();
    R();
    showCube();
    return 0;
}