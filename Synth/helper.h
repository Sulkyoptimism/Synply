#include <stdio.h>
#include <stdlib.h>
#include "inc/SDL/SDL.h"
#include <fstream>
#include "inc/nlohmann/json.hpp"
#include <string>



struct voice_params {
    bool active;
    bool flagged;
    int id;
    int note;
    float detune;
    int mode;
    float pulse_width;
    double phase_position;
    int phase_int;
    double lfo_rate;
    int lfo_mode;
    double lfo_phase_pos;
    int lfo_phase_int;
    float mod_factor;
    double amplitude_factor;
    int voice_pmax;
};

struct synth_params {
    std::string id;
    bool poly_mode;
    int polymax;
    voice_params vps[8];

};

struct app_params {
    double sample_rate;
    int number_synths;
    synth_params sps[8];
};

using namespace nlohmann;

class helper
{
public:
	json json_file;

    static voice_params voiced_params;
    static synth_params synthd_params;
    static app_params appd_params;

    static app_params saved_params;

    static app_params load_dparams(std::string path);


    static void export_dparams();
    static void export_params(app_params);
    helper();
	~helper();

private:
    static app_params params_from_json(json data);

};


