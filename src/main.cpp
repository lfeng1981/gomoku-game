//main.cpp
#include<iostream>
#include<SFML/Graphics.hpp>
#include<cstdlib>
using namespace std;
using namespace sf;
int main() {
    RenderWindow window(VideoMode(800,600),"Gomoku Laucher");
    window.setFramerateLimit(60);
    Font font;
    font.loadFromFile("/usr/share/fonts/truetype/dejavu/DejaVuSans.ttf");
    Text title("Welcome to Gomoku!",font,50);
    title.setFillColor(Color::White);
    title.setPosition(150,80);
    RectangleShape btn2P(Vector2f(220,60));
    btn2P.setFillColor(Color::Blue);
    btn2P.setPosition(190,250);
    btn2P.setOutlineThickness(5);
    btn2P.setOutlineColor(Color::White);
    Text txt2P("2 Player",font,28);
    txt2P.setString("2 Player");
    txt2P.setFillColor(Color::White);
    txt2P.setPosition(230,260);
    RectangleShape btnAI(Vector2f(220,60)); 
    btnAI.setFillColor(Color::Green);
    btnAI.setPosition(390,250);
    btnAI.setOutlineThickness(5);
    btnAI.setOutlineColor(Color::White);
    Text txtAI("VS AI",font,28);
    txtAI.setString("VS AI");
    txtAI.setFillColor(Color::White);
    txtAI.setPosition(470,265);
    while(window.isOpen()) {
    Event e;
    while(window.pollEvent(e)) {
        if(e.type==Event::Closed) {
            window.close();
}       if(e.type==Event::MouseButtonPressed) {
            Vector2i mousePos=Mouse::getPosition(window);
            if(mousePos.x>=190&&mousePos.x<=410&&mousePos.y>=250&&mousePos.y<=310) {
            system("./2_player &");
} if(mousePos.x>=390&&mousePos.x<=610&&mousePos.y>=250&&mousePos.y<=310) {
            system("./VS_AI &");
}
}
} window.clear(); window.draw(title); window.draw(btn2P); window.draw(txt2P);
  window.draw(btnAI); window.draw(txtAI); window.display();
}
    return 0;
}
