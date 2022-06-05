#include <SFML/Graphics.hpp>
#include <iostream>

#include <strstream>
#define JUMP_FORCE 4.8
#define JUMP_ACC 0.08

using namespace sf;

sf::View camera;

enum State
{
    GAMEOVER,
    GAMEISON,
    PAUSE
};

int main()
{
    // sf::Text  hp_text;
    // std::stringstream str;
    //  str << 100;
    //  hp_text.setString(str);
    RenderWindow window(VideoMode(760, 400), "SFML works!");

    camera.reset(sf::FloatRect(0, 0, 760, 400));

    Font font;
    font.loadFromFile("res/comic.ttf");

    Text game_over_text;
    game_over_text.setFont(font);
    game_over_text.setCharacterSize(80);
    game_over_text.setFillColor(Color::Red);
    game_over_text.setString("GAME OVER!!!");

    sf::Image image[8];
    for (int i = 0; i < 8; ++i)
    {
        String str = std::to_string(i+1);
        str.insert(str.getSize(), ".png");
        if (!image[i].loadFromFile(String("res/")+str))
            return 1;
    }

    sf::Image jump_image;
    jump_image.loadFromFile("res/9.png");
    Texture k;
    k.loadFromImage(jump_image);

    float hpfloat;
    hpfloat = 7.5;

    /// 8888888888888888888888888888888888888888888888888888888888888888888888888888888888888888888888888888888888888

    sf::Image hp_full;
    hp_full.loadFromFile("res/hp8.png");
    Texture hp_8;
    hp_8.loadFromImage(hp_full);
    Sprite hp8;
    hp8.setTexture(hp_8);
    // hp8.setPosition(sf::Vector2f(window.getSize().x-60,0));

    /// 77777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777
    sf::Image hp_7;
    hp_7.loadFromFile("res/hp7.png");
    Texture hp__7;
    hp__7.loadFromImage(hp_7);
    Sprite hp7;
    hp7.setTexture(hp__7);
    // hp7.setPosition(sf::Vector2f(window.getSize().x-60,0));

    /// 66666666666666666666666666666666666666666666666666666666666666666666666666666666666666666666666666666666666666
    sf::Image hp_6;
    hp_6.loadFromFile("res/hp6.png");
    Texture hp__6;
    hp__6.loadFromImage(hp_6);
    Sprite hp6;
    hp6.setTexture(hp__6);
    // hp6.setPosition(sf::Vector2f(window.getSize().x-60,0));

    /// 5555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555
    sf::Image hp_5;
    hp_5.loadFromFile("res/hp5.png");
    Texture hp__5;
    hp__5.loadFromImage(hp_5);
    Sprite hp5;
    hp5.setTexture(hp__5);
    /// hp5.setPosition(sf::Vector2f(window.getSize().x-60,0));

    /// 444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444
    sf::Image hp_4;
    hp_4.loadFromFile("res/hp4.png");
    Texture hp__4;
    hp__4.loadFromImage(hp_4);
    Sprite hp4;
    hp4.setTexture(hp__4);
    /// hp4.setPosition(sf::Vector2f(window.getSize().x-60,0));

    /// 333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333
    sf::Image hp_3;
    hp_3.loadFromFile("res/hp3.png");
    Texture hp__3;
    hp__3.loadFromImage(hp_3);
    Sprite hp3;
    hp3.setTexture(hp__3);
    /// hp3.setPosition(sf::Vector2f(window.getSize().x-60,0));
    /// 2222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222
    sf::Image hp_2;
    hp_2.loadFromFile("res/hp2.png");
    Texture hp__2;
    hp__2.loadFromImage(hp_2);
    Sprite hp2;
    hp2.setTexture(hp__2);
    /// hp2.setPosition(sf::Vector2f(window.getSize().x-60,0));

    /// 111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111
    sf::Image hp_1;
    hp_1.loadFromFile("res/hp1.png");
    Texture hp__1;
    hp__1.loadFromImage(hp_1);
    Sprite hp1;
    hp1.setTexture(hp__1);
    /// hp1.setPosition(sf::Vector2f(window.getSize().x-60,0));

    std::vector<sf::Sprite> hp;

    hp.push_back(hp1);
    hp.push_back(hp2);
    hp.push_back(hp3);
    hp.push_back(hp4);
    hp.push_back(hp5);
    hp.push_back(hp6);
    hp.push_back(hp7);
    hp.push_back(hp8);

    Texture t[8];
    for (int i = 0; i < 8; ++i)
        t[i].loadFromImage(image[i]); /// в кадрах 2 3 и 9 обрезается рука

    Texture f; //////////////////////////////////////////////////////////////
    f.loadFromFile("res/fon1.png");
    // Sprite f;
    // f.setTexture(fon);
    // f.setPosition(-window.getSize().x/2,-window.getSize().y/2);

    Sprite s;
    s.setPosition(sf::Vector2f(window.getSize().x / 2, window.getSize().y / 2));

    Sprite d;
    d.setTexture(f);
    d.setTextureRect(IntRect(0, 0, 760 * 90, 400 * 2));
    d.setPosition(sf::Vector2f(-390, -200));

    // sf::RectangleShape fon;////////////////////////////////////////////////////////////////////////////////////////////////
    // fon.setFillColor(sf::Color::Cyan);
    // fon.setSize(sf::Vector2f(100*window.getSize().x,100*window.getSize().y));
    // fon.setPosition(/*-window.getSize().x/2, -window.getSize().y/2*/0,0);

    sf::RectangleShape ground;
    ground.setFillColor(sf::Color::Green);
    ground.setSize(sf::Vector2f(100 * window.getSize().x, 100 * window.getSize().y));
    ground.setPosition(-ground.getSize().x / 2, 4 * window.getSize().y / 5);

    sf::RectangleShape limits;
    limits.setFillColor(sf::Color::Red);
    limits.setSize(sf::Vector2f(35, window.getSize().y));
    int r;
    r = 0 - window.getSize().y / 5;
    // std::cout << r << std::endl;
    limits.setPosition(-35, r /*+(window.getSize().y/2*/);

    // bool sprite_hp_1_is_visible=true,sprite_hp_2_is_visible=true,sprite_hp_3_is_visible=true,sprite_hp_4_is_visible=true;
    // bool sprite_hp_5_is_visible=true,sprite_hp_6_is_visible=true,sprite_hp_7_is_visible=true,sprite_hp_8_is_visible=true;
    bool sprite_is_visible[8];
    float run = 0;
    float speed = 350;
    int alfa = (int)s.getPosition().x;
    int view = 1; // 1/ 1 - means to right and -1 to left accordingly
    bool jumping = false, fall = false;
    float jump_force = -4.8;
    sf::Clock clock;
    float delay = 0;
    clock.restart();
    float jump_acceleration = JUMP_ACC;
    bool double_jump = false;
    // bool m_pressed=false;
    float current_vertical_speed = 0.f;
    float current_vertical_acceleration = 3.11f;
    int hp_s = 7;

    std::vector<Sprite> rockk;
    std::vector<float> rocks_velocity;
    sf::Image rock;
    if (!rock.loadFromFile("res/rock.png"))
        std::cout << "SAD";
    Texture rock_;
    rock_.loadFromImage(rock); /// ГЛАВНАЯ ЧАСТЬ
                               ///////////////wa1/1///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

    State state = GAMEISON;
    float diff = 1.1f;
    Clock attack_time;
    int last_attack = 1000; // attack each second

    while (window.isOpen())
    { ///////////////////////////////////////////////////////////////////////////////////////////////////////////////

        /// if ( wjumping == true || jumping == true) jump_acceleration += 0.01;
        delay = clock.restart().asSeconds(); /// asSeconds();
        // std::cout << fall <<  double_jump << " " <<   s.getPosition().x << " " << s.getPosition().y << std::endl;
        Event event;

        while (window.pollEvent(event))
        {
            std::cout << "EVENT!" << std::endl;
            if (event.type == Event::Closed)
                window.close();
            if (event.type == Event::KeyPressed)
            {
                if (Keyboard::isKeyPressed(Keyboard::Enter))
                {
                    if (state == GAMEOVER)
                    {
                        hpfloat = 7.5;
                        hp_s = 7;
                        state = GAMEISON;
                    }
                    else if (state == GAMEISON)
                        state = PAUSE;
                    else if (state == PAUSE)
                        state = GAMEISON;
                }

                if (Keyboard::isKeyPressed(Keyboard::H))
                {
                    hp_s = (++hp_s) % 8;
                    //--hpfloat;
                }
                if (Keyboard::isKeyPressed(Keyboard::A))
                {
                    Sprite rocks;
                    rocks.setTexture(rock_);
                    // rocks.setColor(sf::Color::Red);
                    rocks.setTextureRect(sf::IntRect(0, 0, 40, 40));
                    rocks.setPosition(rand() % ((int)s.getPosition().x + window.getSize().x / 2) + (int)s.getPosition().x - window.getSize().x / 2, 0); /// падение камней рядом с игроком
                                                                                                                                                        // rocks.setScale(2,2);
                                                                                                                                                        // rocks.setRotation((float)((float)(rand()%1000)/1000.f));
                    rockk.push_back(rocks);
                    rocks_velocity.push_back(0.f);

                    /*   Sprite rock;

                       rock.setSize(sf::Vector2f(25,25));
                       rock.setFillColor(sf::Color::Red);
                       rock.setPosition(rand()%window.getSize().x , 0);
                       rock.setRotation((float)((float)(rand()%1000)/1000.f));
                       rocks.push_back(rock);
                       rocks_velocity.push_back(0.f);*/
                    std::cout << "AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA";
                }
            }
        }

        if (state == GAMEISON)
        {
            /*if (diff > 1.f)
                diff -= 0.4f;
            else if (diff < 1.f)
                diff += 0.4f;
            s.setScale(1.f, diff);
        */
            if (attack_time.getElapsedTime().asMilliseconds() > last_attack)
            {
                attack_time.restart();
                Sprite rocks;
                rocks.setTexture(rock_);
                // rocks.setColor(sf::Color::Red);
                rocks.setTextureRect(sf::IntRect(0, 0, 40, 40));
                rocks.setPosition(rand() % ((int)s.getPosition().x + window.getSize().x / 2) + (int)s.getPosition().x - window.getSize().x / 2, 0); /// падение камней рядом с игроком
                                                                                                                                                    // rocks.setScale(2,2);
                                                                                                                                                    // rocks.setRotation((float)((float)(rand()%1000)/1000.f));
                rockk.push_back(rocks);
                rocks_velocity.push_back(0.f);
            }
            std::cout << "GAMEEE" << std::endl;
            camera.setCenter(s.getPosition());

            if (run > 8.f)
                run = 0.f;

            if (run < 0.f)
                run = 7.9f;
            ///вычитание хп
            if (speed > 500)
            {
                hpfloat -= 1;
                hp_s = hpfloat;
            }
            for (int i = 0; i < rockk.size(); ++i)
            {
                if (s.getGlobalBounds().intersects(rockk[i].getGlobalBounds()))
                {
                    hpfloat -= 1;
                    rockk.erase(rockk.begin() + i);
                    // hpfloat-=0.01;
                    hp_s = hpfloat;
                }
                if (rockk[i].getPosition().y == s.getPosition().y)
                {
                    std::cout << "fmnbhyugtvygbhunjmnihubygvfdcrxcfvgbh" << std::endl;
                }
            }
            if (s.getPosition().y > 400)
            {
                hpfloat -= 0.02;
                hp_s = hpfloat;
            }
            std::cout << "                 " << hpfloat << std::endl;

            /*for (int i=0;i<9;++i){//////////////////////////////////////////////////////////////////////////////////////
              if (hpfloat<8-i){
                      hp.pop_back();
                      hp.resize();
              }
              if (hpfloat>=8-i){
                  i=8;
              }
            }*/
            /*if(hpfloat<8){
                hp_s=7;//sprite_hp_8_is_visible=false;
            }
            if(hpfloat<7){
                hp_s=6;//sprite_hp_7_is_visible=false;
            }
            if(hpfloat<6){
                hp_s=5;//sprite_hp_6_is_visible=false;
            }
            if(hpfloat<5){
                hp_s=4;//sprite_hp_5_is_visible=false;
            }
            if(hpfloat<4){
                hp_s=3;//sprite_hp_4_is_visible=false;
            }
            if(hpfloat<3){
                hp_s=2;//sprite_hp_3_is_visible=false;
            }
            if(hpfloat<2){
                hp_s=1;//sprite_hp_2_is_visible=false;
            }
            if(hpfloat<1){
                hp_s=0;//sprite_hp_1_is_visible=false;
            }*/
            if (hpfloat < 0.02)
            {
                std::cout << "GAME OVER" << std::endl;
                state = GAMEOVER;
                continue;
            }
            ///видимость спратов сердечек. не работает то что закомменчено

            // for (int i=8;i>0;--i){
            //  if(hpfloat<i-1) sprite_is_visible[i-1]=false;
            //}

            if (jumping == true || fall == true)
                s.setTexture(k);
            else
                s.setTexture(t[int(run)]);

            s.setTextureRect(IntRect(207, 25, 217, 425));
            s.setOrigin(217 / 2, 425 / 2);
            s.setScale(view * (1 / 5.f), 1 / 5.f);

            if (s.getGlobalBounds().intersects(limits.getGlobalBounds()))
            {
                s.move(7, 0);
            }

            if (!s.getGlobalBounds().intersects(ground.getGlobalBounds())) //????????????????????????????????????????????????
            {
                current_vertical_speed += current_vertical_acceleration;
                s.move(0, current_vertical_speed * delay);
            }
            else
            {
                current_vertical_speed = 0.f;
                fall = false;
                double_jump = false;
            }

            /// ROCK

            for (int i = 0; i < rockk.size(); ++i)
            {
                rocks_velocity[i] += current_vertical_acceleration;
                rockk[i].move(0, rocks_velocity[i] * delay);
            }
            /*  std::vector<RectangleShape>::iterator it = rocks.begin();
              std::vector<float>::iterator it_v = rocks_velocity.begin();
              for (int i =0 ; it!= rocks.end(); ++it, ++it_v){
                  if (!(*it).getGlobalBounds().intersects(ground.getGlobalBounds()))//????????????????????????????????????????????????
                  {
                      (*it_v) += current_vertical_acceleration;
                      (*it).move (0,(*it_v)*delay);
                  }
                  else
                  {
                      it = rocks.erase(it);
                      it_v = rocks_velocity.erase(it_v);
                  }


              }
              */
            if (jumping == true)
            {
                s.move(0, jump_force);
                jump_force += jump_acceleration;
                if (jump_force > 0)
                {
                    jumping = false;
                    fall = true;
                    jump_force = -JUMP_FORCE;
                    //                    jump_acceleration = JUMP_ACC;
                }
            }
            if (Keyboard::isKeyPressed(Keyboard::Escape))
            {
                break;
            }
            if (fall == false && jumping == false && Keyboard::isKeyPressed(Keyboard::Space))
            {
                if (!jumping)
                {
                    jumping = true;
                    s.move(0, -2);
                }
            }
            else if (Keyboard::isKeyPressed(Keyboard::Space) && double_jump == false && fall == true)
            {
                jump_force = -JUMP_FORCE;
                s.move(0, -3);
                jumping = true;
                fall = false;
                double_jump = true;
                camera.setCenter(s.getPosition().x, s.getPosition().y);
            }

            if (Keyboard::isKeyPressed(Keyboard::Right))
            {
                if (view < 0)
                    view = 1;
                if (Keyboard::isKeyPressed(Keyboard::M))
                { ///////////////////////////////////
                    speed = 485;
                    std::cout << speed << std::endl;
                }
                if (!Keyboard::isKeyPressed(Keyboard::M))
                { ///////////////////////////////////
                    speed = 350;
                    std::cout << speed << std::endl;
                }
                s.move(speed * delay, 0);
                run += 0.05;
                camera.setCenter(s.getPosition().x, s.getPosition().y);
            }
            if (Keyboard::isKeyPressed(Keyboard::Left))
            {
                if (Keyboard::isKeyPressed(Keyboard::M))
                { ///////////////////////////////////
                    speed = 485;
                    std::cout << speed << std::endl;
                }
                if (!Keyboard::isKeyPressed(Keyboard::M))
                { ///////////////////////////////////
                    speed = 350;
                    std::cout << speed << std::endl;
                }
                if (view > 0)
                    view = -1;
                s.move(-speed * delay, 0);
                run += 0.05;
                camera.setCenter(s.getPosition().x, s.getPosition().y);
            }
            if (Keyboard::isKeyPressed(Keyboard::H))
            {
                hp_s = (++hp_s) % 8;
                // std::cout << hp_s << std::endl << hp << std::endl;
            }

            /*            if(Keyboard::isKeyPressed(Keyboard::Up)){
                            s.move(0,-0.1);
                             run += speed;
                        }
                        if(Keyboard::isKeyPressed(Keyboard::Down)){
                            s.move(0,0.1);
                             run += speed;
                        }
            */

            window.setView(camera);
            window.clear();
            window.draw(d);
            window.draw(s);
            window.draw(ground);
            window.draw(limits);
            for (int i = 0; i < rockk.size(); ++i)
            {
                // std::cout << rocks[i].getPosition().x << "CCCCCCCCCCCCCCCCC";
                window.draw(rockk[i]);
            }
            hp[hp_s].setPosition(sf::Vector2f(300, -200) + s.getPosition());
            window.draw(hp[hp_s]); /// можно написать [hp_s-1] и заменить начальные значения hp и hp_s на 7 но тогда

            /// сердечки будут отображаться слева сверху около стены и перестанут бегать за девочкой
            //    window.draw(game_over_text);
            window.display();
        }
        if (state == GAMEOVER)
        {
            game_over_text.setPosition(s.getPosition() - Vector2f(150, 0));
            window.clear(Color::Black);
            window.draw(game_over_text);
            window.display();
        }
    }
    // window.draw(game_over_text);
    // window.display();
    return 0;
}
