//2_player.cpp
#include<iostream>
#include<SFML/Graphics.hpp>
#include<cmath>
#include<string>
using namespace std;
using namespace sf;
bool game_over=false;
int winner=0;
bool check(int b[15][15],int x,int y,int c) {
    int cnt=0;
    for(int i=0;i<15;i++) {
        if(b[x][i]==c) cnt++; else cnt=0;
        if(cnt>=5) return true;
}
    cnt=0;
    for(int i=0;i<15;i++) {
        if(b[i][y]==c) cnt++; else cnt=0;
        if(cnt>=5) return true;
}
    cnt=0;
    int sx=x-min(x,y),sy=y-min(x,y);
    while(sx<15&&sy<15) {
        if(b[sx][sy]==c) cnt++; else cnt=0;
        if(cnt>=5) return true;
        sx++; sy++;
}
    cnt=0;
    int d=min(x,14-y);
    sx=x-d; sy=y+d;
    while(sx<15&&sy>=0) {
        if(b[sx][sy]==c) cnt++; else cnt=0;
        if(cnt>=5) return true;
        sx++; sy--;
} return false;
}
int main() {
    RenderWindow window(VideoMode(600,600),"2 Player Gomoku");
    window.setFramerateLimit(60);
    const int SIZE=15;
    const int CELL=36;
    const int OFFSET=30;
    int board[SIZE][SIZE]={0};
    int player=1;
    Color bgColor(240,224,206);
    while(window.isOpen()) {
    Event e;
    while(window.pollEvent(e)) {
        if(e.type==Event::Closed) {
            window.close();
} 
if(e.type==Event::KeyPressed) {
    if(e.key.code==Keyboard::Escape)
        window.close();
}
if(e.type==Event::MouseButtonPressed&&e.mouseButton.button==Mouse::Left) {
    if(game_over) continue;
    int mx=e.mouseButton.x;
    int my=e.mouseButton.y;
    int x=(mx-OFFSET+CELL/2)/CELL;
    int y=(my-OFFSET+CELL/2)/CELL;
    if(x>=0&&x<SIZE&&y>=0&&y<SIZE&&board[x][y]==0) {
        board[x][y]=player;
        if(check(board,x,y,player)) {
            game_over=true;
            winner=player;
}
        player=(player==1)?2:1;
}
}
} window.clear(bgColor);
for(int i=0;i<=SIZE;++i) {
    Vertex lineH[]={
        Vertex(Vector2f(OFFSET,OFFSET+i*CELL),Color::Black),
        Vertex(Vector2f(OFFSET+SIZE*CELL,OFFSET+i*CELL),Color::Black)
}; window.draw(lineH,2,Lines);
    Vertex lineV[]={
        Vertex(Vector2f(OFFSET+i*CELL,OFFSET),Color::Black),
        Vertex(Vector2f(OFFSET+i*CELL,OFFSET+SIZE*CELL),Color::Black)
}; window.draw(lineV,2,Lines);
}
for(int i=0;i<SIZE;++i) {
    for(int j=0;j<SIZE;++j) {
        if(board[i][j]!=0) {
            CircleShape piece(CELL/2-2);
            piece.setPosition(
                OFFSET+i*CELL-CELL/2+1,
                OFFSET+j*CELL-CELL/2-1
); piece.setFillColor(board[i][j]==1?Color::Black:Color::White);
window.draw(piece);
}
}
} 
if(game_over) {
    RectangleShape bg(Vector2f(600,600));
    bg.setFillColor(Color::White);
    Font font;
    font.loadFromFile("/usr/share/fonts/truetype/dejavu/DejaVuSans.ttf");
    Text go1("YOU WIN!",font,100);
    go1.setFillColor(Color::Yellow);
    go1.setPosition(70,150);
    string str=winner==1?"Black Wins":"White Wins";
    Text go2(str,font,30);
    go2.setFillColor(Color::Red);
    go2.setPosition(220,300);
    window.draw(bg);
    window.draw(go1);
    window.draw(go2);
}
window.display();
} return 0;
}
