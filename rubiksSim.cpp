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
// Basic Rotations
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
// Existing Functions
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
void Mprime(){
    M();M();M();
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
void Rprime(){
    R();R();R();
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
void Lprime(){
    L();L();L();
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
void Uprime(){
    U();U();U();
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
// Front Face Moves
void F() {
    cout << "Executing F()..." << endl;
    vector<string> tempUp = {cube[0][2][0], cube[0][2][1], cube[0][2][2]}; // bottom row of Up face
    // Move Left face (2) to Up face
    cube[0][2][0] = cube[2][2][2];
    cube[0][2][1] = cube[2][1][2];
    cube[0][2][2] = cube[2][0][2];
    // Move Down face (5) to Left face
    cube[2][0][2] = cube[5][0][0];
    cube[2][1][2] = cube[5][0][1];
    cube[2][2][2] = cube[5][0][2];
    // Move Right face (4) to Down face
    cube[5][0][0] = cube[4][2][0];
    cube[5][0][1] = cube[4][1][0];
    cube[5][0][2] = cube[4][0][0];
    // Move saved temp (Up face row) to Right face
    cube[4][0][0] = tempUp[0];
    cube[4][1][0] = tempUp[1];
    cube[4][2][0] = tempUp[2];
    rotateCW(1);
}
void Fprime() {
    F(); F(); F();
}

// Back Face Moves
void B() {
    cout << "Executing B()..." << endl;
    vector<string> tempUp = {cube[0][0][2], cube[0][0][1], cube[0][0][0]}; // top row of Up face (reversed)
    // Move Right face to Up face
    cube[0][0][2] = cube[4][2][2];
    cube[0][0][1] = cube[4][1][2];
    cube[0][0][0] = cube[4][0][2];
    // Move Down face to Right face
    cube[4][0][2] = cube[5][2][2];
    cube[4][1][2] = cube[5][2][1];
    cube[4][2][2] = cube[5][2][0];
    // Move Left face to Down face
    cube[5][2][2] = cube[2][2][0];
    cube[5][2][1] = cube[2][1][0];
    cube[5][2][0] = cube[2][0][0];
    // Move saved temp to Left face
    cube[2][0][0] = tempUp[2];
    cube[2][1][0] = tempUp[1];
    cube[2][2][0] = tempUp[0];
    rotateCW(3);
}
void Bprime() {
    B(); B(); B();
}

// Down Face Moves 
void D() {
    cout << "Executing D()..." << endl;
    vector<string> tempFront = {cube[1][2][0], cube[1][2][1], cube[1][2][2]}; // bottom row of Front face
    // Move Left face to Front face
    cube[1][2][0] = cube[2][2][0];
    cube[1][2][1] = cube[2][2][1];
    cube[1][2][2] = cube[2][2][2];
    // Move Back face to Left face
    cube[2][2][0] = cube[3][2][0];
    cube[2][2][1] = cube[3][2][1];
    cube[2][2][2] = cube[3][2][2];
    // Move Right face to Back face
    cube[3][2][0] = cube[4][2][0];
    cube[3][2][1] = cube[4][2][1];
    cube[3][2][2] = cube[4][2][2];
    // Move saved temp to Right face
    cube[4][2][0] = tempFront[0];
    cube[4][2][1] = tempFront[1];
    cube[4][2][2] = tempFront[2];
    rotateCW(5);
}
void Dprime() {
    D(); D(); D();
}

// Middle Slice Moves (second layer)
void E() {
    cout << "Executing E()..." << endl;
    vector<string> tempFront = {cube[1][1][0], cube[1][1][1], cube[1][1][2]}; // middle row of Front face
    // Move Left face to Front face
    cube[1][1][0] = cube[2][1][0];
    cube[1][1][1] = cube[2][1][1];
    cube[1][1][2] = cube[2][1][2];
    // Move Back face to Left face
    cube[2][1][0] = cube[3][1][0];
    cube[2][1][1] = cube[3][1][1];
    cube[2][1][2] = cube[3][1][2];
    // Move Right face to Back face
    cube[3][1][0] = cube[4][1][0];
    cube[3][1][1] = cube[4][1][1];
    cube[3][1][2] = cube[4][1][2];
    // Move saved temp to Right face
    cube[4][1][0] = tempFront[0];
    cube[4][1][1] = tempFront[1];
    cube[4][1][2] = tempFront[2];
}

void Eprime() {
    E(); E(); E();
}

// S
void S() {
    cout << "Executing S()..." << endl;
    vector<string> tempUp = {cube[0][1][0], cube[0][1][1], cube[0][1][2]}; // middle row of Up face
    // Move Left face to Up face
    cube[0][1][0] = cube[2][2][1];
    cube[0][1][1] = cube[2][1][1];
    cube[0][1][2] = cube[2][0][1];
    // Move Down face to Left face
    cube[2][0][1] = cube[5][1][0];
    cube[2][1][1] = cube[5][1][1];
    cube[2][2][1] = cube[5][1][2];
    // Move Right face to Down face
    cube[5][1][0] = cube[4][2][1];
    cube[5][1][1] = cube[4][1][1];
    cube[5][1][2] = cube[4][0][1];
    // Move saved temp to Right face
    cube[4][0][1] = tempUp[2];
    cube[4][1][1] = tempUp[1];
    cube[4][2][1] = tempUp[0];
}

void Sprime() {
    S(); S(); S();
}

// xyz
void x() {
    R();
    Lprime();
    Mprime();
}

void xprime() {
    Rprime();
    L();
    M();
}

void y() {
    U();
    Dprime();
    Eprime();
}

void yprime() {
    Uprime();
    D();
    E();
}

void z() {
    F();
    Bprime();
    S();
}

void zprime() {
    Fprime();
    B();
    Sprime();
}
//Cube functions
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
    
    cout << "\nTesting fundamental cube moves:\n";
    
    F();
    showCube();
    B();
    showCube();
    D();
    showCube();
    R();
    showCube();
    L();
    showCube();
    U();
    showCube();
    M();
    showCube();
    E();
    showCube();
    S();
    showCube();
    
    return 0;
}