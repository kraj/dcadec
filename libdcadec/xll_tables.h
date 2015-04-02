/*
 * This file is part of libdcadec.
 *
 * This library is free software; you can redistribute it and/or modify it
 * under the terms of the GNU Lesser General Public License as published by the
 * Free Software Foundation; either version 2.1 of the License, or (at your
 * option) any later version.
 *
 * This library is distributed in the hope that it will be useful, but WITHOUT
 * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
 * FITNESS FOR A PARTICULAR PURPOSE. See the GNU Lesser General Public License
 * for more details.
 *
 * You should have received a copy of the GNU Lesser General Public License
 * along with this library; if not, write to the Free Software Foundation,
 * Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA
 */

// Section 8.4.3: Look-up table of quantized reflection coefficients
static const uint16_t refl_coeff_table[128] = {
        0,  3070,  5110,  7140,  9156, 11154, 13132, 15085,
    17010, 18904, 20764, 22588, 24373, 26117, 27818, 29474,
    31085, 32648, 34164, 35631, 37049, 38418, 39738, 41008,
    42230, 43404, 44530, 45609, 46642, 47630, 48575, 49477,
    50337, 51157, 51937, 52681, 53387, 54059, 54697, 55302,
    55876, 56421, 56937, 57426, 57888, 58326, 58741, 59132,
    59502, 59852, 60182, 60494, 60789, 61066, 61328, 61576,
    61809, 62029, 62236, 62431, 62615, 62788, 62951, 63105,
    63250, 63386, 63514, 63635, 63749, 63855, 63956, 64051,
    64140, 64224, 64302, 64376, 64446, 64512, 64573, 64631,
    64686, 64737, 64785, 64830, 64873, 64913, 64950, 64986,
    65019, 65050, 65079, 65107, 65133, 65157, 65180, 65202,
    65222, 65241, 65259, 65275, 65291, 65306, 65320, 65333,
    65345, 65357, 65368, 65378, 65387, 65396, 65405, 65413,
    65420, 65427, 65434, 65440, 65446, 65451, 65456, 65461,
    65466, 65470, 65474, 65478, 65481, 65485, 65488, 65491
};

static const uint8_t ch_nbits[16] = {
    0, 1, 2, 2, 3, 3, 3, 3, 4, 4, 4, 4, 4, 4, 4, 4
};

static const uint8_t prim_dmix_nch[7] = {
    1, 2, 2, 3, 3, 4, 4
};

#define SCALE(x)    (INT64_C(x) << 10)

static const int64_t band_coeff_table0[] = {
    SCALE(868669), SCALE(-5931642), SCALE(-1228483)
};

static const int64_t band_coeff_table1[] = {
    SCALE(  -20577), SCALE( 122631), SCALE( -393647), SCALE( 904476),
    SCALE(-1696305), SCALE(2825313), SCALE(-4430736), SCALE(6791313)
};

static const int64_t band_coeff_table2[] = {
    SCALE(  41153), SCALE( -245210), SCALE( 785564), SCALE(-1788164),
    SCALE(3259333), SCALE(-5074941), SCALE(6928550), SCALE(-8204883)
};

#undef SCALE
