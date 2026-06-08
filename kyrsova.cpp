#include <SFML/Graphics.hpp>
#include <iostream>

using namespace sf;
int main(){
  int option;
  std::cout<<"Мурзик:   Гра підтримує два варіанти гри: консольний та графіний. Виберіть, який саме ви хочете використовувати."<<"\n"<<"Введіть 1, якщо бажаєте консольний."<<"\n"<<"Введіть 2, якщо бажаєте графічний. "<<"\n"<< "Введіть 3, якщо бажаєте завершити роботу."<<"\n";
  std::cin>>option;
  if (option == 1){
  long long n, m;
  std::cout<<"\n"<< "Мурзик:    Я одну з квіткових клумб зробив у вигляді шахової дошки розмірами m на n, у кожній клітинці якої росте якась квітка. Інколи на цю клумбу я виводжу напрогулянку Анфісу (так, не дивуйтесь, ми дійсно друзі). Анфіса, починаючи завжди з верхнього лівого кута переміщується по клумбі до правого нижнього і збирає квіти, причому таким чином, щоб щоразу проходити по новому маршруту, а я на виході вручаю їй шматочок сиру." ;
  std::cout << "\n"<< "N: ";
  std::cin >> n;
  std::cout <<"\n"<< "M: ";
  std::cin >> m;
  std::cout<<"\n"<<"Анфіса:     Порахуй, яка найбільша кількість шматочків сиру дістанеться мені, якщо я весь час намагатимусь зберегти якнайбільше квітів. При кожному своєму переміщенні я обов'язково маю зібрати як мінiмум одну квітку.";
  long long mn;
  std::cin>>mn;
  int false_index = 0;
  for (int false_index = 0; false_index < 5; false_index++) {
  if(mn != 1+(m-1)*(n-1)){
    std::cout<<"Мурзик:     Неправильно!""\n""Анфіса: Ой, не хвилюйся! Перечитай умову ще раз і спробуй знову) я впевнена, що ти все зможеш!";
  } else {
    std::cout<<"Мурзик:     Правильно! Найбільша кількість шматочків сиру при заданому розмірі дорівнює "<<mn<<"\n"<<"Анфіса:     Ура! Вітаю! В тебе все вийшло)";
    return 0;
  }
  std::cout<<"\n"<<"Мурзик:     Ще одна спроба. Відповідь: ";
  std::cin>>mn;
}
  std::cout<<"\n"<<"Мурзик:     Підсказка: формула, за якою ти маєш порахувати кількість сиру виглядає так: cheese = 1+(m-1)(n-1)""\n""Анфіса:     Проста формула, правда? Спробуй підставити свої числа в неї і порахувати"<<"\n"; 
  std::cin>>mn;
  if (mn != 1+(m-1)*(n-1)) {
    std::cout<<"Мурзик:     Невірно, ви програли. (правильна відповідь: "<<mn<<")";
    std::cout<<"\n"<<"Анфіса:     Мені так шкода, що в тебе не вийшло... Нічого, просто перезапути гру і спробуй знову";
    return 0;
  }
  std::cout<<"Мурзик:     Правильно!";
  return 0;
  /*1+(m-1)(n-1)*/
  }
  else if (option == 2){
  long long m,n,mn;
  float cellSize = 60.f;
  float offsetTop = 70.f;
  int i =0;

  std::cout<<"Мурзик:    Я одну з квіткових клумб зробив у вигляді шахової дошки розмірами m на n"<<"\n";
  std::cout<<"M: ";
  std::cin>>m;
  std::cout<<"N: ";
  std::cin>>n;
    RenderWindow window (VideoMode({1500, 800}), "Anfisa and flowers");
    sf::Font font;
    if (!font.openFromFile("c:\\WINDOWS\\Fonts\\CENSCBK.TTF"))
    {
    std::cout<<"error";
    return 0;
    }
    sf::Font font_B;
    if (!font_B.openFromFile("c:\\WINDOWS\\Fonts\\SCHLBKB.TTF"))
    {
    std::cout<<"error";
    return 0;
    }

Text text1 (font);
text1.setString("Anfisa and flowers");
text1.setCharacterSize(50);
text1.setFillColor(Color(255, 255, 255));
text1.setPosition({500, 30});

RectangleShape square_for_headline({500, 70});
square_for_headline.setFillColor(Color(39, 77, 34));
square_for_headline.setOutlineThickness(2);
square_for_headline.setOutlineColor(Color(39, 77, 34));
square_for_headline.setPosition({480, 30});

Text text2 (font);
text2.setString("     Murzyk made one of the flower beds in the form of a chessboard measuring m by n, ""\n""in each cell of which a flower grows. Sometimes he leads to this flower bed ""\n""Anfisa's walk (yes, don't be surprised, they are really friends). Anfisa, always ""\n""starting from the upper left corner, moves along the flower bed to the lower ""\n""right corner and collects flowers, ""\n""in such a way as to pass along a new route each time, and Murzik ""\n""hands her a piece of cheese on the way out. ""\n""     Calculate the maximum number of pieces of cheese Anfisa will get if she ""\n""always tries to save as many flowers as possible. ""\n""Anfisa must collect at least one flower every time she moves.");
text2.setCharacterSize(20);
text2.setFillColor(Color(0, 0, 0));
text2.setPosition({700, 130});

Text text_N (font);
text_N.setString("N:");
text_N.setCharacterSize(25);
text_N.setFillColor(Color(0, 0, 0));
text_N.setPosition({700, 430});

Text num_N (font);
num_N.setString(std::to_string(n));
num_N.setCharacterSize(25);
num_N.setFillColor(Color(0, 0, 0));
num_N.setPosition({750, 430});

Text num_M (font);
num_M.setString(std::to_string(m));
num_M.setCharacterSize(25);
num_M.setFillColor(Color(0, 0, 0));
num_M.setPosition({750, 530});

RectangleShape square_for_N({500, 40});
square_for_N.setFillColor(Color(255, 255, 255));
square_for_N.setOutlineThickness(2);
square_for_N.setOutlineColor(Color(255, 255, 255));
square_for_N.setPosition({740, 425});

Text text_M (font);
text_M.setString("M:");
text_M.setCharacterSize(25);
text_M.setFillColor(Color(0, 0, 0));
text_M.setPosition({700, 530});

RectangleShape square_for_M({500, 40});
square_for_M.setFillColor(Color(255, 255, 255));
square_for_M.setOutlineThickness(2);
square_for_M.setOutlineColor(Color(255, 255, 255));
square_for_M.setPosition({740, 525});

Text text_rez (font_B);
text_rez.setString("Rezult:");
text_rez.setCharacterSize(35);
text_rez.setFillColor(Color(0, 0, 0));
text_rez.setPosition({700, 695});

RectangleShape square_for_rez({500, 40});
square_for_rez.setFillColor(Color(255, 255, 255));
square_for_rez.setOutlineThickness(2);
square_for_rez.setOutlineColor(Color(255, 255, 255));
square_for_rez.setPosition({850, 695});

Texture texture_Myrsik;
texture_Myrsik.loadFromFile("C:\\C++\\kyrsova\\Myrsik.png");
Texture texture_Anfisa;
texture_Anfisa.loadFromFile("C:\\C++\\kyrsova\\Anfisa.png");

Sprite sprite1(texture_Myrsik);
sprite1.setTexture(texture_Myrsik);
sprite1.setScale({0.2f, 0.2f});
sprite1.setPosition({70, 620});

Sprite sprite2(texture_Anfisa);
sprite2.setTexture(texture_Anfisa);
sprite2.setScale({0.4f, 0.4f});
sprite2.setPosition({350, 570});

Text winningText(font);
winningText.setString("Wow! you so smart! ""\n"" Thanks for your efforts)""\n"" Now I now how much cheese I ""\n"" can get!");
winningText.setCharacterSize(20);
winningText.setFillColor(Color(0, 0, 0));
winningText.setPosition({330, 400}); 

RectangleShape winningsquare_1({300, 150});
winningsquare_1.setFillColor(Color(255, 255, 255));
winningsquare_1.setOutlineThickness(2);
winningsquare_1.setOutlineColor(Color(255, 255, 255));
winningsquare_1.setPosition({320, 400});

Text winningText_2(font);
winningText_2.setString("Corect! ""\n"" I hope you anderstand the ""\n"" solution to the problem ""\n"" now. If you want to ""\n"" try again, just restart ""\n"" the program and enter new ""\n"" values of m and n.");
winningText_2.setCharacterSize(20);
winningText_2.setFillColor(Color(0, 0, 0));
winningText_2.setPosition({40, 400}); 

RectangleShape winningsquare_2({280, 200});
winningsquare_2.setFillColor(Color(255, 255, 255));
winningsquare_2.setOutlineThickness(2);
winningsquare_2.setOutlineColor(Color(255, 255, 255));
winningsquare_2.setPosition({30, 400});

Text losingText(font);
losingText.setString("Oh, it`s okay! Just try again!");
losingText.setCharacterSize(20);
losingText.setFillColor(Color(0, 0, 0));
losingText.setPosition({330, 460});

RectangleShape losingsquare_1({300, 70});
losingsquare_1.setFillColor(Color(255, 255, 255));
losingsquare_1.setOutlineThickness(2);
losingsquare_1.setOutlineColor(Color(255, 255, 255));
losingsquare_1.setPosition({320, 450});

Text losingText_2(font);
losingText_2.setString("Try to use this formula:""\n"" cheese = 1+(m-1)(n-1)""\n"" to calculate the answer.");
losingText_2.setCharacterSize(20);
losingText_2.setFillColor(Color(0, 0, 0));
losingText_2.setPosition({40, 460});

RectangleShape losingsquare_2({280, 130});
losingsquare_2.setFillColor(Color(255, 255, 255));
losingsquare_2.setOutlineThickness(2);
losingsquare_2.setOutlineColor(Color(255, 255, 255));
losingsquare_2.setPosition({30, 450});

std::string inputRez="";
std::string input = "";
Text displayText(font_B);
displayText.setCharacterSize(35);
displayText.setFillColor(Color(0, 0, 0));
displayText.setPosition({860, 695});

   while (window.isOpen()){
    while (const std::optional event = window.pollEvent()){
      if (const auto* textEvent = event->getIf<Event::TextEntered>()) {
             if (textEvent->unicode >= '0' && textEvent->unicode <= '9') {
                inputRez += static_cast<char>(textEvent->unicode);
            }
            if(textEvent->unicode == 13){
              input = inputRez;
              inputRez = "";
              i ++;
            }
            displayText.setString(inputRez);
        }
        if (event->is<Event::Closed>()){
            window.close();
        }
    }

    window.clear(Color(119, 196, 110));

if (m <= 5 && n <= 5) {
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            RectangleShape square({cellSize, cellSize});
            square.setFillColor(Color(119, 196, 110));
            square.setOutlineThickness(2);
            square.setOutlineColor(Color(0, 0, 0));
            square.setPosition({20.f + j * cellSize, offsetTop + i * cellSize});

            window.draw(square);
        }
    }
}
else {
  for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            RectangleShape square({cellSize, cellSize});
            square.setFillColor(Color(119, 196, 110));
            square.setOutlineThickness(2);
            square.setOutlineColor(Color(0, 0, 0));
            square.setPosition({20.f + j * cellSize, offsetTop + i * cellSize});

            window.draw(square);
        }
    }
}
if (i>=1){
if (input == std::to_string(1+(m-1)*(n-1))){
  window.draw(winningsquare_1);
  window.draw(winningsquare_2);
  window.draw(winningText);
  window.draw(winningText_2);

} else{

    if (input != std::to_string(1+(m-1)*(n-1))){
          window.draw(losingsquare_1);
      window.draw(losingsquare_2);
      window.draw(losingText);
      window.draw(losingText_2);
    }
  }
}

window.draw(square_for_headline);
window.draw(square_for_N);
window.draw(square_for_M);
window.draw(sprite1);
window.draw(sprite2);
window.draw(square_for_rez);
window.draw(num_N);
window.draw(num_M);
window.draw(text1);
window.draw(text_N);
window.draw(text_M);
window.draw(text2);
window.draw(text_rez);
window.draw(displayText);
window.display();
    }}
  if (option == 3){
    std::cout<<"\n"<<"Анфіса:   Дуже шкода, що ти не захотів допомогти мені... Сподіваюсь, ти скоро передумаєш і запустиш гру знову";
    return 0;
  }}