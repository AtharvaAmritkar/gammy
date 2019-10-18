/**
 * Copyright (C) 2019 Francesco Fusco. All rights reserved.
 * License: https://github.com/Fushko/gammy#license
 */

#ifndef UTILS_H
#define UTILS_H
#include <string>
#include <array>

constexpr int   min_temp_kelvin = 2000,
                max_temp_kelvin = 6500,
                temp_arr_entries = 46,
                temp_mult = 60, //min: 3
                temp_steps = temp_arr_entries * 3;

/*Color ramp by Ingo Thies, from Redshift
**https://github.com/jonls/redshift/blob/master/README-colorramp
*/
constexpr std::array<double, temp_steps> ingo_thies_table =
{
    1.00000000,  0.54360078,  0.08679949, /* 2000K */
    1.00000000,  0.56618736,  0.14065513,
    1.00000000,  0.58734976,  0.18362641,
    1.00000000,  0.60724493,  0.22137978,
    1.00000000,  0.62600248,  0.25591950,
    1.00000000,  0.64373109,  0.28819679,
    1.00000000,  0.66052319,  0.31873863,
    1.00000000,  0.67645822,  0.34786758,
    1.00000000,  0.69160518,  0.37579588,
    1.00000000,  0.70602449,  0.40267128,
    1.00000000,  0.71976951,  0.42860152,
    1.00000000,  0.73288760,  0.45366838,
    1.00000000,  0.74542112,  0.47793608,
    1.00000000,  0.75740814,  0.50145662,
    1.00000000,  0.76888303,  0.52427322,
    1.00000000,  0.77987699,  0.54642268,
    1.00000000,  0.79041843,  0.56793692,
    1.00000000,  0.80053332,  0.58884417,
    1.00000000,  0.81024551,  0.60916971,
    1.00000000,  0.81957693,  0.62893653,
    1.00000000,  0.82854786,  0.64816570,
    1.00000000,  0.83717703,  0.66687674,
    1.00000000,  0.84548188,  0.68508786,
    1.00000000,  0.85347859,  0.70281616,
    1.00000000,  0.86118227,  0.72007777,
    1.00000000,  0.86860704,  0.73688797,
    1.00000000,  0.87576611,  0.75326132,
    1.00000000,  0.88267187,  0.76921169,
    1.00000000,  0.88933596,  0.78475236,
    1.00000000,  0.89576933,  0.79989606,
    1.00000000,  0.90198230,  0.81465502,
    1.00000000,  0.90963069,  0.82838210,
    1.00000000,  0.91710889,  0.84190889,
    1.00000000,  0.92441842,  0.85523742,
    1.00000000,  0.93156127,  0.86836903,
    1.00000000,  0.93853986,  0.88130458,
    1.00000000,  0.94535695,  0.89404470,
    1.00000000,  0.95201559,  0.90658983,
    1.00000000,  0.95851906,  0.91894041,
    1.00000000,  0.96487079,  0.93109690,
    1.00000000,  0.97107439,  0.94305985,
    1.00000000,  0.97713351,  0.95482993,
    1.00000000,  0.98305189,  0.96640795,
    1.00000000,  0.98883326,  0.97779486,
    1.00000000,  0.99448139,  0.98899179,
    1.00000000,  1.00000000,  1.00000000 /* 6500K */
};

/** Config*/
constexpr int cfg_count = 9;
constexpr std::array<const char*, cfg_count> cfg_str =
{
    "minBrightness=",
    "maxBrightness=",
    "offset=",
    "temp=",
    "speed=",
    "threshold=",
    "updateRate=",
    "auto=",
    "toggleLimit="
};
extern std::array<int, cfg_count> cfg;
enum {
    MinBr,
    MaxBr,
    Offset,
    Temp,
    Speed,
    Threshold,
    Polling_rate,
    isAuto,
    toggleLimit
};
/****/

int calcBrightness(uint8_t* buf, uint64_t screen_res);

void readConfig();
void saveConfig();

template <class T>
T convertToRange(T old_val, int old_min, int old_max, int new_min, int new_max)
{
    T val = (((old_val - old_min) * (new_max - new_min)) / old_max - old_min) + new_min;

    return val;
}
#ifdef _WIN32

void getGDISnapshot(uint8_t* buf, uint64_t w, uint64_t h);
void setGDIBrightness(unsigned short brightness, int temp);

void checkInstance();
void checkGammaRange();
void toggleRegkey(bool);

std::wstring getExecutablePath(bool add_cfg);
#else
std::string getHomePath(bool add_cfg);
#endif

#endif // UTILS_H
