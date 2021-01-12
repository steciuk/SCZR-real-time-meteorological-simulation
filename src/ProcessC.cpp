//
// Created by jestemleon on 10.01.2021.
//

#include "ProcessC.h"
#include <allegro5/allegro5.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_primitives.h>
//#include <allegro5/allegro_color.h>
#include <iostream>
#include <cmath>
#include <cstdlib>
#include <cfloat>


[[noreturn]] void ProcessC::operate(int stations) {
    data fromB{};
    log_message log{};
    float dane[MAX_STATIONS][3]{};
    float dists[stations];
        al_init();
        al_init_primitives_addon();
        ALLEGRO_EVENT_QUEUE* queue = al_create_event_queue();
        al_set_new_display_flags(ALLEGRO_NOFRAME);
        ALLEGRO_DISPLAY* disp = al_create_display(620, 480);
        ALLEGRO_FONT* font = al_create_builtin_font();

        al_register_event_source(queue, al_get_display_event_source(disp));

        ALLEGRO_EVENT event;

        while(true)
        {
            log_message log{};
            shmBC.pop(&fromB);
            auto end = std::chrono::system_clock::now();

            float max_temp = -1000;
            float min_temp = 1000;
            float min_x = 0;
            float max_x = 20;
            float min_y = 0;
            float max_y = 20;
            int current_x, current_y;
            int max_temperature_x, max_temperature_y, min_temperature_x, min_temperature_y;
            float tmp, tmp2, current_temperature = 0;

            for(int i = 0; i < stations; i++) {
                dane[i][0] = fromB.coords[i][0];
                dane[i][1] = fromB.coords[i][1];
                dane[i][2] = fromB.coords[i][2];
            }

            for (int i = 0; i < stations; ++i) {
                if (dane[i][2] > max_temp)
                    max_temp = dane[i][2];

                if (dane[i][2] < min_temp)
                    min_temp = dane[i][2];

//                if (dane[i][0] > max_x)
//                    max_x = dane[i][0];

//                if (dane[i][0] < min_x)
//                    min_x = dane[i][0];
//
//                if (dane[i][1] > max_y)
//                    max_y = dane[i][1];

//                if (dane[i][1] < min_y)
//                    min_y = dane[i][1];
            }

            std::string s1 = std::to_string((int)max_temp);
            char const *max_temp_char = s1.c_str();  //use char const* as target type
            std::string s2 = std::to_string((int)min_temp);
            char const *min_temp_char = s2.c_str();  //use char const* as target type

            log.start = fromB.timestamp;
            log.end = end;
            queueC.push(&log);

            if(event.type == ALLEGRO_EVENT_DISPLAY_CLOSE)
                break;


            al_clear_to_color(al_map_rgb(255, 255, 255));
            for (int w = 0; w < 620; w+=4) {
                for (int h = 0; h < 480; h+=4) {
                     for (int i = 0; i < 10; ++i) {
                         current_x = ((dane[i][0]-min_x)*(620/(max_x-min_x)));
                         current_y = ((dane[i][1]-min_y)*(480/(max_y-min_y)));
                         dists[i] = abs((current_x - w) * (current_x - w)) + abs((current_y - h) * (current_y - h)) + FLT_EPSILON;


                         if (dane[i][2] == max_temp) {
                             max_temperature_x = current_x;
                             max_temperature_y = current_y;

                         } else if (dane[i][2] == min_temp) {
                             min_temperature_x = current_x;
                             min_temperature_y = current_y;

                         }

                     }
                        for (int i = 0; i < stations; ++i) {
                            float nom = 1 / dists[i];
                            float den = 0;
                            for(int j = 0; j < stations; ++j)
                                den += 1 / dists[j];

                            current_temperature += nom/den * dane[i][2];
                        }

                        float step = 20;
                        int current_temperature_r = floor(     (current_temperature-min_temp)*(1/(max_temp-min_temp)) * step) * 255/step;
                        int current_temperature_g = floor( (1 - (current_temperature-min_temp)*(1/(max_temp-min_temp))) * step) * 111/step;
                        int current_temperature_b = floor( (1 - (current_temperature-min_temp)*(1/(max_temp-min_temp))) * step) * 255/step;

                        al_draw_filled_rectangle(w, h, w+4, h+4, al_map_rgb(current_temperature_r, current_temperature_g, current_temperature_b));

                        current_temperature = 0;
                        tmp2 = 0;
                    }


                }
            for (int i = 0; i < stations; ++i) {
                current_x = ((dane[i][0]-min_x)*(620/(max_x-min_x)));
                current_y = ((dane[i][1]-min_y)*(480/(max_y-min_y)));
                std::string s3 = std::to_string((dane[i][2]));
                char const *temp_char = s3.c_str();  //use char const* as target type
                al_draw_text(font, al_map_rgb(0, 0, 0), current_x, current_y, ALLEGRO_ALIGN_CENTER,
                             temp_char);
            }
//                al_draw_text(font, al_map_rgb(0, 0, 0), max_temperature_x, max_temperature_y, ALLEGRO_ALIGN_CENTER,
//                             max_temp_char);
//                al_draw_text(font, al_map_rgb(0, 0, 0), min_temperature_x, min_temperature_y, ALLEGRO_ALIGN_CENTER,
//                             min_temp_char);





            al_flip_display();


        }

        al_destroy_font(font);
        al_destroy_display(disp);
        al_destroy_event_queue(queue);

}


