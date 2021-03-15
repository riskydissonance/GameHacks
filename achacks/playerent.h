#pragma once

#include <cstdint>

struct Vector3
{
    float x;
    float y;
    float z;
};

// playerent generated from REClass.NET
class playerent
{
public:
    char pad_0000[4]; //0x0000
    Vector3 HeadPosition; //0x0004
    Vector3 Velocity; //0x0010
    char pad_001C[24]; //0x001C
    Vector3 BodyPosition; //0x0034
    Vector3 Facing; //0x0040
    char pad_004C[172]; //0x004C
    int32_t Health; //0x00F8
    char pad_00FC[24]; //0x00FC
    int32_t SecondaryAmmoReserve; //0x0114
    char pad_0118[16]; //0x0118
    int32_t PrimaryAmmoReserve; //0x0128
    char pad_012C[16]; //0x012C
    int32_t SecondaryAmmo; //0x013C
    char pad_0140[16]; //0x0140
    int32_t PrimaryAmmo; //0x0150
    char pad_0154[76]; //0x0154
    int32_t ShotsFired; //0x01A0
    char pad_01A4[129]; //0x01A4
    char N000002BC[16]; //0x0225
    char pad_0235[1653]; //0x0235
}; //Size: 0x08AA

class N00000281
{
public:
    char pad_0000[4]; //0x0000
}; //Size: 0x0004
