#define /bin/python

"""
Description: Script to create animations in a format that represents
             RGB values in a 32 bit unsigned integer.

Author:      Robin von Berg (inf104426)
"""

import sys

FRAME_AMOUNT = 38
VALUES_PER_FRAME = 19

# Used to correct linear color transitions to look linear/smooth.
GAMMA = [
    0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
    0,   0,   0,   0,   0,   0,   0,   0,   0,   1,   1,   1,   1,   1,   1,
    1,   1,   1,   1,   1,   1,   2,   2,   2,   2,   2,   2,   2,   2,   3,
    3,   3,   3,   3,   3,   4,   4,   4,   4,   5,   5,   5,   5,   5,   6,
    6,   6,   6,   7,   7,   7,   8,   8,   8,   9,   9,   9,   10,  10,  10,
    11,  11,  11,  12,  12,  13,  13,  13,  14,  14,  15,  15,  16,  16,  17,
    17,  18,  18,  19,  19,  20,  20,  21,  21,  22,  22,  23,  24,  24,  25,
    25,  26,  27,  27,  28,  29,  29,  30,  31,  31,  32,  33,  34,  34,  35,
    36,  37,  38,  38,  39,  40,  41,  42,  42,  43,  44,  45,  46,  47,  48,
    49,  50,  51,  52,  53,  54,  55,  56,  57,  58,  59,  60,  61,  62,  63,
    64,  65,  66,  68,  69,  70,  71,  72,  73,  75,  76,  77,  78,  80,  81,
    82,  84,  85,  86,  88,  89,  90,  92,  93,  94,  96,  97,  99,  100, 102,
    103, 105, 106, 108, 109, 111, 112, 114, 115, 117, 119, 120, 122, 124, 125,
    127, 129, 130, 132, 134, 136, 137, 139, 141, 143, 145, 146, 148, 150, 152,
    154, 156, 158, 160, 162, 164, 166, 168, 170, 172, 174, 176, 178, 180, 182,
    184, 186, 188, 191, 193, 195, 197, 199, 202, 204, 206, 209, 211, 213, 215,
    218, 220, 223, 225, 227, 230, 232, 235, 237, 240, 242, 245, 247, 250, 252,
    255]


def gamma_correction(c):
    return (GAMMA[c[0]], GAMMA[c[1]], GAMMA[c[2]])

# Concatenate 8bit RGB values.
def to_single_val(c):
    return c[0] << 16 | c[1] << 8 | c[2]

def print_color(c):
    sys.stdout.write(str(to_single_val(gamma_correction(c))))
    sys.stdout.write(", ")


def line_up(base_color):
    color8th = (int(base_color[0] / 8), int(base_color[1] / 8), int(base_color[2] / 8))
    color6th = (int(base_color[0] / 6), int(base_color[1] / 6), int(base_color[2] / 6))
    color5th = (int(base_color[0] / 5), int(base_color[1] / 5), int(base_color[2] / 5))
    color4th = (int(base_color[0] / 4), int(base_color[1] / 4), int(base_color[2] / 4))
    color2th = (int(base_color[0] / 2), int(base_color[1] / 2), int(base_color[2] / 2))


    for led in range(VALUES_PER_FRAME):
        print_color(color6th)
    sys.stdout.write("\n")

    for led in range(VALUES_PER_FRAME):
        print_color(color5th)
    sys.stdout.write("\n")

    for led in range(VALUES_PER_FRAME):
        print_color(color4th)
    sys.stdout.write("\n")

    for frame in range(FRAME_AMOUNT):
        for led in range(VALUES_PER_FRAME):
            led_in_focus = int(((FRAME_AMOUNT - 1) - frame) / 2)
            distance = abs(led - led_in_focus)

            if distance > 7: distance = 4
            elif distance > 3: distance = 3
            factor = 4 - distance

            color = ( 
                color2th[0] + color8th[0] * factor, 
                color2th[1] + color8th[1] * factor, 
                color2th[2] + color8th[2] * factor 
            )
            
            print_color(color)
        sys.stdout.write("\n")

    for led in range(VALUES_PER_FRAME):
        print_color(color4th)
    sys.stdout.write("\n")

    for led in range(VALUES_PER_FRAME):
        print_color(color5th)
    sys.stdout.write("\n")

    for led in range(VALUES_PER_FRAME):
        print_color(color6th)
    sys.stdout.write("\n")

if __name__ == "__main__":
    base_color = (0, 0, 255)
    line_up(base_color)