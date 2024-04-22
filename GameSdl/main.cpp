
#include "Common_Function.h"
#include "stdafx.h"
#include "MainObject.h"
#include "ThreatObject.h"
#include "ExplosionObject.h"
#include "HP.h"
#include "TextObject.h"
#include "SupportItem.h"
#include "Boss.h"
#include <iostream>
#include "time.h"
#include "ImpTime.h"

TTF_Font* g_font_ = NULL;
TTF_Font* g_font_menu = NULL;

std::string bkgn_array [] = {"image\\bk1.png", "image\\bk2.png", "image\\bk3.png", "image\\bk4.png"};

#define FRAMES_PER_SECOND 35

bool Init(){
    if(SDL_Init(SDL_INIT_EVERYTHING) == -1){
        return false;
    }

    g_screen = SDL_SetVideoMode(SCREEN_WIDTH, SCREEN_HEIGHT, SCREEN_BPP, SDL_SWSURFACE);

    if(g_screen == NULL) return false;

    if(Mix_OpenAudio(22050, MIX_DEFAULT_FORMAT, 2, 4096) == -1) return false;

    //Load file wav audio
    g_sound_bullet[0] = Mix_LoadWAV("laser.wav");
    g_sound_bullet[1] = Mix_LoadWAV("gun.wav");
    g_sound_exp[0] = Mix_LoadWAV("explosion.wav");
    g_sound_exp[1] = Mix_LoadWAV("main_explosion.wav");
    g_sound_bgr[0] = Mix_LoadWAV("musicgame.wav");
    g_sound_gold[0] = Mix_LoadWAV("gold_sound.wav");
    g_sound_choose[0] = Mix_LoadWAV("choose.wav");
    if(g_sound_bullet[0] == NULL || g_sound_bullet[1] == NULL || g_sound_exp[0] == NULL ||  g_sound_exp[1] == NULL || g_sound_bgr[0] == NULL || g_sound_gold[0] == NULL) return false;


    //Load score text
    if(TTF_Init() == -1) return false;
    g_font_ = TTF_OpenFont("game.ttf", 20);
    g_font_menu = TTF_OpenFont("game.ttf", 40);
    if(g_font_ == NULL || g_font_menu == NULL){
        return 0;
    }
    
    return true;
}



int main(int arc, char* argv[])
{
    bool is_move_screen = true;
    double bkgn_x = 0;
    bool is_quit = false;
    
    if(Init() == false){
        return 0;
    }

    srand ( time(NULL) );

again:
    int rand_bkgn = SDLCommonFunc::GetRandInSpace(0, 3);
    std::string s_bkgn = bkgn_array[rand_bkgn];
    g_bkground = SDLCommonFunc::LoadImg(s_bkgn);
    if(g_bkground == NULL){
        return 0;
    }

    //make main HP
    Health health;
    health.Init();

    //make time
    TextObject time;
    time.SetColor(TextObject::BLACK_TEXT);

    //make score
    TextObject score;
    score.SetColor(TextObject::BLACK_TEXT);


    //make text gold
    TextObject gold_text;
    gold_text.SetColor(TextObject::BLACK_TEXT);
    
    //make gold
    SupportItem gold;
     gold.Init();

    
    int dem = 0;

    
    //make Mainobject
    MainObject human_object;
    human_object.SetRect(POS_X_START_MAIN_OBJ,POS_Y_START_MAIN_OBJ);
    bool ret = human_object.LoadImg("c3.png");
    if(!ret){
        return 0;
    }

    //make explosion mainobject
    ExplosionObject exp_main;
    ret = exp_main.LoadImg("expmain.png");
    exp_main.set_clip();
    if(ret == false) return 0;

    //make explosion threatobject
    ExplosionObject exp_threats;
    ret = exp_threats.LoadImg("expmain.png");
    exp_threats.set_clip();
    if(ret == false) return 0;


    //make Threatobject
    ThreatObject* p_threats = new ThreatObject[THREAT];
    for(int i = 0; i < THREAT; i++){
        ThreatObject* p_threat = (p_threats + i);
        if(p_threat){
    bool res = p_threat->LoadImg("c2.png");
    if(res == false) return 0;


    
    int rand_y =   SDLCommonFunc::GetRandInSpace(0,  SCREEN_HEIGHT);

    p_threat->SetRect(SCREEN_WIDTH + i*800, rand_y-125);
 
    p_threat->set_x_val(SPEED_THREAT);

    BulletObject * p_bullet = new BulletObject();

       p_threat->InitBullet(p_bullet);

       


        }}

    //make BossObject
   BossObject* p_bosses = new BossObject[BOSS];
    for(int i = 0; i < BOSS; i++)
    {
        BossObject* p_boss = (p_bosses + i);
        if(p_boss)
        {
            bool res = p_boss->LoadImg("c4.png");
            if(res == false) 
                return 0;

            int rand_y_boss = SDLCommonFunc::GetRandInSpace(0, SCREEN_HEIGHT - UNDER_BOUND);
            p_boss->SetRect(SCREEN_WIDTH + i*800, rand_y_boss-125);
            p_boss->set_x_val(SPEED_BOSS);
            p_boss->set_y_val(SPEED_BOSS);
            BulletObject * p_bullet = new BulletObject();

            p_boss->InitBullet(p_bullet);
        }
     }
 
    
    int score_val = 0;
    int gold_num = 0;
    double slvc = 0;


    int menu = SDLCommonFunc::MakeMenu(g_screen, g_font_menu);
    if (menu == 1)
    {  
        is_quit = true;
    }
    else if (menu == 2)
    {
        int menu2 = SDLCommonFunc::MakeMenu2(g_screen, g_font_menu);
        if (menu2 == 0)
        {   
            is_quit = true;
        }
    }

    Mix_PlayChannelTimed(-1, g_sound_bgr[0], -1, -1);
    
    // doc hieu phan duoi day nhe, ky thuat fps
    // fps là biến quản lý kỹ thuật fps trong game
    // hiểu đơn giả là tạo ra sự cân bằng thời gian trong game
    // Mỗi vòng lặp while ở dưới có thể chạy với lượng thời gian khác nhau
    // lần 1: chạy hết 100 ms
    // lần 2: chạy hết 40 ms
    // lần 3: chạy hết 60 ms
    // Điều đó tạo ra sự chênh lệch thời gian và hiệu ứng hình ảnh ko đẹp
    // fps tạo ra một mức thời gian tối tiêu cho phép. ví dụ 80s.
    // Mọi vòng lặp dưới 80s sẽ được delay cho đên khi đủ 80s ới kết thúc.
    // Kỹ thuật này có thể xem chi tiết video trên youtbe
    ImpTimer fps;

    //ENTER GAME
    while(!is_quit){
        
          fps.start();
        while(SDL_PollEvent(&g_even)){
            if(g_even.type == SDL_QUIT){
                is_quit = true;
                break;
            }
            human_object.HandleInputAction(g_even, g_sound_bullet);
        } 
        
        
        if(is_move_screen == true){
        bkgn_x -= SPEED_SCREEN;
        if(bkgn_x <= -(WIDTH_BACKGROUND - SCREEN_WIDTH)){
            is_move_screen = false;
             
        }
        else{
        SDLCommonFunc::ApplySurface(g_bkground,g_screen,bkgn_x, 0);
        }
        }
        else{
            SDLCommonFunc::ApplySurface(g_bkground,g_screen,bkgn_x, 0);
             
            for(int i = 0; i < BOSS; i++){
                 BossObject* p_boss = (p_bosses + i);
                
            if(p_boss){
            p_boss->HandleMove(SCREEN_WIDTH, SCREEN_HEIGHT );
            p_boss->Show(g_screen);
            p_boss->MakeBullet(g_screen, SCREEN_WIDTH, SCREEN_HEIGHT);


           

      

            //Check collision threats bullet with main object
            bool is_col1 = false;
            std::vector<BulletObject*> bullet_arr = p_boss->GetBulletList();
            for(int b = 0; b < bullet_arr.size(); b++){
                BulletObject* p_bullet = bullet_arr.at(b);
                if(p_bullet){
                    is_col1 = SDLCommonFunc::IsCollision(p_bullet->GetRect(),human_object.GetRect());
                    if(is_col1 == true){
                        p_boss->ResetBullet(p_bullet);
                        break;
                    }
                }
            }
             

            //Check collision thr and main
            bool is_col2 = SDLCommonFunc::IsCollision(human_object.GetRect(), p_boss->GetRect());
            if(is_col2 || is_col1){
                for(int ex = 0; ex < 4; ex++){
                    int x_pos = (human_object.GetRect().x + human_object.GetRect().w*0.5)- EX_WIDTH*0.5;
                    int y_pos = (human_object.GetRect().y + human_object.GetRect().h*0.5)- EX_HEIGHT*0.5;

                    exp_main.set_frame(ex);
                    exp_main.SetRect(x_pos, y_pos);
                    exp_main.ShowEx(g_screen);

                    SDL_Delay(100);
                    //Update screen
                   if(SDL_Flip(g_screen) == -1) {
                       delete [] p_threats;
                       SDLCommonFunc::Cleanup();
                       SDL_Quit();
                       return 0;}
                }
                Mix_PlayChannel(-1, g_sound_exp[1], 0);


                if(health.GetNumber() > 1){
                    SDL_Delay(1500);
                    human_object.SetRect(POS_X_START_MAIN_OBJ, POS_Y_START_MAIN_OBJ);
                    health.Decrease();
                    health.Render(g_screen);

                    if(SDL_Flip(g_screen) == -1){
                        delete [] p_threats;
                        SDLCommonFunc::Cleanup();
                        SDL_Quit();
                        return 0;
                    }

                }
                else{
                   
                    int menu = SDLCommonFunc::MakeMenu3(g_screen, g_font_menu, score_val, gold_num);
                        if (menu == 0)
                        {  
                           is_quit = true;
                           continue;
                        }
                        else 
                        {

                                for (int i = 0; i < BOSS; i++)
                                {
                                    (p_bosses+i)->Free();
                                }

                                health.Free();
                                time.Free();
                                score.Free();
                                gold_text.Free();
                                gold.Free();
                                human_object.Free();
                                exp_main.Free();
                                exp_threats.Free();

                                goto again;
                        }
               
                }
               
            }

                //Check collision main bullet with threats.
            std::vector<BulletObject*> bullet_list = human_object.GetBulletList();
            for(int j = 0; j < bullet_list.size(); j++){
                BulletObject* p_bullet = bullet_list.at(j);
                if(p_bullet != NULL){
                    bool res_col = SDLCommonFunc::IsCollision(p_bullet->GetRect(), p_boss->GetRect());
                    if(res_col){
                        if(slvc > 20){
                            dem++;
                            std::cout << dem << " ";
                        score_val += 5;
                        if(dem == 2){
                   int menu_end = SDLCommonFunc::MakeMenu4(g_screen, g_font_menu , score_val, gold_num);
                        

                        if (menu_end == 0)
                        {  
                           is_quit = true;
                           continue;
                        }
                        else 
                        {

                                for (int i = 0; i < THREAT; i++)
                                {
                                    (p_threats+i)->Free();
                                }

                                health.Free();
                                time.Free();
                                score.Free();
                                gold_text.Free();
                                gold.Free();
                                human_object.Free();
                                exp_main.Free();
                                exp_threats.Free();

                                goto again;
                        }
                        
                        
                        
                        
                        
                        
                        
                        }
                        for(int t = 0; t < 4; t++){
                            int x_pos = p_bullet->GetRect().x - EX_WIDTH*0.5;
                            int y_pos = p_bullet->GetRect().y - EX_HEIGHT*0.5;

                            exp_threats.set_frame(t);
                            exp_threats.SetRect(x_pos, y_pos);
                            exp_threats.ShowEx(g_screen);

                            //Update screen
                            if(SDL_Flip(g_screen) == -1) return 0;

                        }

                        p_boss->Renew(SCREEN_WIDTH + i*VAL_OFFSET_START_POST_THREATS);
                        human_object.DestroyBullet(j);
                        Mix_PlayChannel(-1, g_sound_exp[0], 0);
                        slvc = 0;
                        }
                        else {
                            slvc += 0.18; 
                        for(int t = 0; t < 4; t++){
                            int x_pos = p_bullet->GetRect().x - EX_WIDTH*0.5;
                            int y_pos = p_bullet->GetRect().y - EX_HEIGHT*0.5;

                            exp_threats.set_frame(t);
                            exp_threats.SetRect(x_pos, y_pos);
                            exp_threats.ShowEx(g_screen);

                            //Update screen
                            if(SDL_Flip(g_screen) == -1) return 0;
                        }

                        }


                    }
                }
            }
          }
        }//
        }

        //Implement main
        human_object.HandleMove();
        human_object.Show(g_screen);
        human_object.MakeBullet(g_screen);
    
        //Show health
            health.Render(g_screen);


        // Implement threat object
        for(int i = 0; i < THREAT; i++){
            ThreatObject* p_threat = (p_threats + i);
            if(p_threat){
            p_threat->HandleMove(SCREEN_WIDTH, SCREEN_HEIGHT);
            p_threat->Show(g_screen);
            p_threat->MakeBullet(g_screen, SCREEN_WIDTH, SCREEN_HEIGHT);


           

      

            //Check collision threats bullet with main object
            bool is_col1 = false;
            std::vector<BulletObject*> bullet_arr = p_threat->GetBulletList();
            for(int b = 0; b < bullet_arr.size(); b++){
                BulletObject* p_bullet = bullet_arr.at(b);
                if(p_bullet){
                    is_col1 = SDLCommonFunc::IsCollision(p_bullet->GetRect(),human_object.GetRect());
                    if(is_col1 == true){
                        p_threat->ResetBullet(p_bullet);
                        break;
                    }
                }
            }
             

            //Check collision thr and main
            bool is_col2 = SDLCommonFunc::IsCollision(human_object.GetRect(), p_threat->GetRect());
            if(is_col2 || is_col1){
                for(int ex = 0; ex < 4; ex++){
                    int x_pos = (human_object.GetRect().x + human_object.GetRect().w*0.5)- EX_WIDTH*0.5;
                    int y_pos = (human_object.GetRect().y + human_object.GetRect().h*0.5)- EX_HEIGHT*0.5;

                    exp_main.set_frame(ex);
                    exp_main.SetRect(x_pos, y_pos);
                    exp_main.ShowEx(g_screen);

                    SDL_Delay(100);
                    //Update screen
                   if(SDL_Flip(g_screen) == -1) {
                       delete [] p_threats;
                       SDLCommonFunc::Cleanup();
                       SDL_Quit();
                       return 0;}
                }
                Mix_PlayChannel(-1, g_sound_exp[1], 0);


                if(health.GetNumber() > 1){
                    SDL_Delay(1500);
                    human_object.SetRect(POS_X_START_MAIN_OBJ, POS_Y_START_MAIN_OBJ);
                    health.Decrease();
                    health.Render(g_screen);

                    if(SDL_Flip(g_screen) == -1){
                        delete [] p_threats;
                        SDLCommonFunc::Cleanup();
                        SDL_Quit();
                        return 0;
                    }

                }
                else{
                   
                    int menu = SDLCommonFunc::MakeMenu3(g_screen, g_font_menu, score_val, gold_num);
                        if (menu == 0)
                        {  
                           is_quit = true;
                           continue;
                        }
                        else 
                        {

                                for (int i = 0; i < THREAT; i++)
                                {
                                    (p_threats+i)->Free();
                                }

                                health.Free();
                                time.Free();
                                score.Free();
                                gold_text.Free();
                                gold.Free();
                                human_object.Free();
                                exp_main.Free();
                                exp_threats.Free();

                                goto again;
                        }
               
                }
               
            }

                //Check collision main bullet with threats.
            std::vector<BulletObject*> bullet_list = human_object.GetBulletList();
            for(int j = 0; j < bullet_list.size(); j++){
                BulletObject* p_bullet = bullet_list.at(j);
                if(p_bullet != NULL){
                    bool res_col = SDLCommonFunc::IsCollision(p_bullet->GetRect(), p_threat->GetRect());
                    if(res_col){
                        score_val++;
                        for(int t = 0; t < 4; t++){
                            int x_pos = p_bullet->GetRect().x - EX_WIDTH*0.5;
                            int y_pos = p_bullet->GetRect().y - EX_HEIGHT*0.5;

                            exp_threats.set_frame(t);
                            exp_threats.SetRect(x_pos, y_pos);
                            exp_threats.ShowEx(g_screen);

                            //Update screen
                            if(SDL_Flip(g_screen) == -1) return 0;

                        }

                        p_threat->Renew(SCREEN_WIDTH + i*VAL_OFFSET_START_POST_THREATS);
                        human_object.DestroyBullet(j);
                        Mix_PlayChannel(-1, g_sound_exp[0], 0);
                    }
                }
            }
          }
        }//

        //Show gold 
        gold.Render(g_screen);
        bool is_co = SDLCommonFunc::IsCollision(human_object.GetRect(), gold.GetRect());
      


           
           if(is_co){
               Mix_PlayChannel(-1, g_sound_gold[0], 0);
               gold_num++;
               gold.Decrease();
               gold.Render(g_screen);
               if(gold.GetPosSize() == 0){
                   gold.Init();
                   gold.Render(g_screen);
               }}
           if(gold_num >= 30 ){
               health.Increase();
              health.Render(g_screen);
              gold_num = gold_num - 30;
           }
        

           
          

        //Show gold
           std::string val_str_gold = std::to_string(gold_num);
        std::string strGold("Gold :");
        strGold += val_str_gold;

        gold_text.SetText(strGold);
        gold_text.MakeText(g_font_, g_screen);
        gold_text.SetRect(30, 40);
        
        

        

        //Show time
        std::string str_time = "Time :";
        Uint32 time_val = SDL_GetTicks()/1000;
        std::string str_val = std::to_string(time_val);
        str_time += str_val;

        time.SetText(str_time);
        time.SetRect(30, 90);
        time.MakeText(g_font_, g_screen);

        
         //Show score 
        std::string val_str_score = std::to_string(score_val);
        std::string strScore("Score :");
        strScore += val_str_score;

        score.SetText(strScore);
        score.MakeText(g_font_, g_screen);
        score.SetRect(30, 65);
        

        //Update screen
        if(SDL_Flip(g_screen) == -1) return 0;


        // cân bằng thời gian cho mỗi vòng lặp game
        if (fps.get_ticks() < 1000 / FRAMES_PER_SECOND)
        {
            SDL_Delay((1000 / FRAMES_PER_SECOND) - fps.get_ticks());
        }
    }

    fps.stop();


    for (int i = 0; i < THREAT; i++)
    {
        (p_threats+i)->Free();
    }

    health.Free();
    time.Free();
    score.Free();
    gold_text.Free();
    gold.Free();
    human_object.Free();
    exp_main.Free();
    exp_threats.Free();

    SDLCommonFunc::Cleanup();
    SDL_Quit();

    




    return 0;

}
