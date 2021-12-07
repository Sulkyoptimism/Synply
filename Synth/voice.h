#pragma once
#include <stdint.h>
#include <vector>
#include "helper.h"
//
//struct voice_params {
//    bool active;
//    bool flagged;
//    int id;
//    int note;
//    float detune;
//    int mode;
//    float pulse_width;
//    double phase_position;
//    int phase_int;
//    double lfo_rate;
//    double lfo_phase_pos;
//    int lfo_phase_int;
//    float mod_factor;
//    double amplitude_factor;
//    double envelope_cursor = 0;
//    double current_amp;
//    int16_t sample[64];
//};
enum wave_type { SINE = 0, SQUARE = 1, TRI = 2, SAW = 3 };

namespace DSP {
    const  double pi = 3.14159265358979323846;
    const  double chromatic_ratio = 1.059463094359295264562;
}

class voice
{
public:
    //general
    static double sample_rate;
    static int table_length;
    static int16_t* sine_wave_table;
    static int16_t* saw_wave_table;

    //voice
    bool active;
    bool flagged;
    std::string parent_id;
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
    double amplitude_factor;    //a volume control
    /// <summary>
    /// ///////////////
    /// </summary>

    double envelope_cursor;
    double current_amp;

    bool key_pressed;

    int16_t sample[64];

    voice_params default_params;
    // amplitude smoothing
    double envelope_data[4] = { 1.0f, 0.5f, 0.5f, 0.0f }; // ADSR amp range 0.0-1.0
    double envelope_speed_scale = 1; // set envelope speed 1-8
    double envelope_increment_base = 0; // this will be set in init_data based on current samplingrate.
    double target_amp = 0;
    double smoothing_amp_speed = 0.01;
    double smoothing_enabled = true;

    voice(double sample_rate, int table_length);
    void init_voice(std::string parent_id, voice_params vp);
    void hot_load_voice(voice_params vp);
    int update_LFO_pos(double freq);
    void write_samples(long length);
    int16_t get_sample_from_table(int phase_int, int synthwave_mode, float pulse_width);
    double update_envelope();
    double get_envelope_amp_by_node(int base_node, double cursor);
    void key_press(int note, bool b, bool poly_over);
    void flag();

    static bool is_init;
    static void init_data();
    static void delete_data();
    static int16_t* build_sine_table( int wave_length);
    static void build_saw_table(int16_t* data, int wave_length);
    static int16_t square_from_sine(int index, float pulse_width);
    static int16_t triangle_from_sin(int index);
    static double get_pitch(double note);

    ~voice();

private:
};

