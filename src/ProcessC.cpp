//
// Created by jestemleon on 10.01.2021.
//

#include "ProcessC.h"
#include <allegro5/allegro5.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_color.h>
#include <iostream>
#include <cmath>
#include <cstdlib>

[[noreturn]] void ProcessC::operate(int stations) {
    data fromB{};
    log_message log{};

    bool first = true;
    float dane[10][3] = {{2,5,40}, {3,7,35}, {10, 17, 6}, {9, 2, 20}, {4, 1, 30}, {5, 8, 43}, {5,10,20}, {1,10,30},{10,10,30}, {5,5,4}};

        al_init();
        al_install_keyboard();
        al_init_primitives_addon();
//    ALLEGRO_TIMER* timer = al_create_timer(1.0 );
        ALLEGRO_EVENT_QUEUE* queue = al_create_event_queue();
        ALLEGRO_DISPLAY* disp = al_create_display(620, 480);
        ALLEGRO_FONT* font = al_create_builtin_font();

        al_register_event_source(queue, al_get_keyboard_event_source());
        al_register_event_source(queue, al_get_display_event_source(disp));
//    al_register_event_source(queue, al_get_timer_event_source(timer));

        bool redraw = true;
        ALLEGRO_EVENT event;

//    al_start_timer(timer);
        float max_temp = -1000;
        float min_temp = 1000;
        float min_x = 10000;
        float max_x = 0;
        float min_y = 10000;
        float max_y = 0;
        int current_x, current_y;
        int r,g,b;
        int max_temperature_x, max_temperature_y, min_temperature_x, min_temperature_y, step;
        float fr, fg, fb, tmp, tmp2, current_temperature_r, current_temperature_g, current_temperature_b, current_temperature = 0;


        for (int i = 0; i < 10; ++i) {
            if (dane[i][2] > max_temp)
                max_temp = dane[i][2];

            if (dane[i][2] < min_temp)
                min_temp = dane[i][2];

            if (dane[i][0] > max_x)
                max_x = dane[i][0];

            if (dane[i][0] < min_x)
                min_x = dane[i][0];

            if (dane[i][1] > max_y)
                max_y = dane[i][1];

            if (dane[i][1] < min_y)
                min_y = dane[i][1];

        }

        std::string s1 = std::to_string((int)max_temp);
        char const *max_temp_char = s1.c_str();  //use char const* as target type
        std::string s2 = std::to_string((int)min_temp);
        char const *min_temp_char = s2.c_str();  //use char const* as target type

        std::cout << max_temp << std::endl;
        std::cout << min_temp << std::endl;
        std::cout << max_x << std::endl;
        std::cout << min_x << std::endl;
        std::cout << max_y << std::endl;
        std::cout << min_y << std::endl;

        while(true)
        {
            log_message log{};

            shmBC.pop(&fromB);
            auto end = std::chrono::system_clock::now();

            log.start = fromB.timestamp;
            log.end = end;
            queueC.push(&log);

            al_wait_for_event(queue, &event);

//        if(event.type == ALLEGRO_EVENT_TIMER)
//            redraw = true;
//        else
            if(event.type == ALLEGRO_EVENT_DISPLAY_CLOSE)
                break;

            if(event.type == ALLEGRO_EVENT_KEY_DOWN)
            {
                first = false;
                al_clear_to_color(al_map_rgb(255, 255, 255));
                for (int w = 0; w < 620; w+=4) {
                    for (int h = 0; h < 480; h+=4) {
                        for (int i = 0; i < 10; ++i) {
                            current_x = ((dane[i][0]-min_x)*(620/(max_x-min_x)));
                            current_y = ((dane[i][1]-min_y)*(480/(max_y-min_y)));
                            if(current_y == h && current_x == w){
                                tmp = 1;

                            }else {
                                tmp = 1 /
                                      sqrt((current_x - w) * (current_x - w) + (current_y - h) * (current_y - h));
                            }
                            current_temperature += dane[i][2]*tmp;
                            tmp2+=tmp;
                            if (dane[i][2] == max_temp) {
                                max_temperature_x = current_x;
                                max_temperature_y = current_y;

                            } else if (dane[i][2] == min_temp) {
                                min_temperature_x = current_x;
                                min_temperature_y = current_y;

                            }

                        }

                        current_temperature/=tmp2;
//                        std::cout<<current_temperature<<std::endl;
                        current_temperature = ((current_temperature-min_temp)*(255/(max_temp-min_temp)));
//                        current_temperature = ((current_temperature-min_temp)*(255/(max_temp-min_temp)));
//                        current_temperature_r = ((current_temperature-min_temp)*(255/(max_temp-min_temp)));
//                        current_temperature_g = 110 - ((current_temperature-min_temp)*(110/(max_temp-min_temp)));
//                        current_temperature_b = 255 - ((current_temperature-min_temp)*(255/(max_temp-min_temp)));

//                        step = 20;
//                        current_temperature_r = floor(     (current_temperature-min_temp)*(1/(max_temp-min_temp)) * step) * 255/step;
//                        current_temperature_g = floor( 1 - (current_temperature-min_temp)*(1/(max_temp-min_temp)) * step) * 111/step;
//                        current_temperature_b = floor( 1 - (current_temperature-min_temp)*(1/(max_temp-min_temp)) * step) * 255/step;
//                        std::cout << current_temperature_r << "\n B: "<<current_temperature_b<<"\nG: "<< current_temperature_g<<std::endl;
//

//                        al_draw_filled_rectangle(w, h, w+4, h+4, al_map_rgb(current_temperature_r, current_temperature_g, current_temperature_b));
                        al_draw_filled_rectangle(w, h, w+4, h+4, al_map_rgb(current_temperature, 127, 0));
                        current_temperature = 0;
                        tmp2 = 0;
                    }


                }
                al_draw_text(font, al_map_rgb(0, 0, 0), max_temperature_x, max_temperature_y, ALLEGRO_ALIGN_CENTER,
                             max_temp_char);
                al_draw_text(font, al_map_rgb(0, 0, 0), min_temperature_x, min_temperature_y, ALLEGRO_ALIGN_CENTER,
                             min_temp_char);


            }


            al_flip_display();

            redraw = false;

        }

        al_destroy_font(font);
        al_destroy_display(disp);
//    al_destroy_timer(timer);
        al_destroy_event_queue(queue);



}


