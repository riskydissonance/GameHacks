#pragma once

#include <cstdint>

struct Vector3 {
    float x;
    float y;
    float z;
};

// Created with ReClass.NET 1.2 by KN4CK3R

class playerent {
public:
    char pad_0000[4]; //0x0000
    Vector3 HeadPosition; //0x0004
    Vector3 HeadVelocity; //0x0010
    int32_t XIntVelocity; //0x001C
    int32_t YIntVelocity; //0x0020
    int32_t ZIntVelocity; //0x0024
    Vector3 BodyVelocity; //0x0028
    Vector3 BodyPosition; //0x0034
    Vector3 Facing; //0x0040
    int32_t FiringSomething; //0x004C
    float N00000365; //0x0050
    int16_t JumpSomething; //0x0054
    char pad_0056[2]; //0x0056
    float N00000058; //0x0058
    float N00000368; //0x005C
    float N00000369; //0x0060
    float N0000005A; //0x0064
    int8_t Unknown; //0x0068
    int8_t Grounded; //0x0069
    char pad_006A[2]; //0x006A
    int8_t Crouched; //0x006C
    int8_t N00000454; //0x006D
    int8_t Crouched2; //0x006E
    char pad_006F[1]; //0x006F
    int8_t StoodStill; //0x0070
    char pad_0071[3]; //0x0071
    int32_t IntDistanceJumped; //0x0074
    float FloatDistanceJumped; //0x0078
    char pad_007C[4]; //0x007C
    int8_t ForwardBackward; //0x0080
    int8_t LeftRight; //0x0081
    int8_t PlayerState; //0x0082
    int8_t Invisible; //0x0083
    float CrouchVelocity; //0x0084
    char pad_0088[4]; //0x0088
    int8_t LeftPressed; //0x008C
    int8_t RightPressed; //0x008D
    int8_t ForwardPressed; //0x008E
    int8_t BackwardPressed; //0x008F
    char pad_0090[12]; //0x0090
    char* N0000052B; //0x009C
    char pad_00A0[16]; //0x00A0
    char* N0000047D; //0x00B0
    char pad_00B4[52]; //0x00B4
    void* N00000488; //0x00E8
    void* N0000049D; //0x00EC
    char pad_00F0[4]; //0x00F0
    void* N0000044F; //0x00F4
    int32_t Health; //0x00F8
    int32_t Armour; //0x00FC
    char pad_0100[12]; //0x0100
    int32_t Akimbo; //0x010C
    char pad_0110[4]; //0x0110
    int32_t SecondaryAmmoReserve; //0x0114
    char pad_0118[16]; //0x0118
    int32_t PrimaryAmmoReserve; //0x0128
    char pad_012C[8]; //0x012C
    int32_t AkimboAmmoReserve; //0x0134
    char pad_0138[4]; //0x0138
    int32_t SecondaryAmmo; //0x013C
    char pad_0140[16]; //0x0140
    int32_t PrimaryAmmo; //0x0150
    char pad_0154[4]; //0x0154
    int32_t NumberOfGrenades; //0x0158
    int32_t AkimboAmmo; //0x015C
    int32_t KnifeRecoilVelocity; //0x0160
    int32_t PistolRecoilVelocity; //0x0164
    char pad_0168[16]; //0x0168
    int32_t PrimaryRecoilVelocity; //0x0178
    char pad_017C[4]; //0x017C
    int32_t GrenadeRecoilVelocity; //0x0180
    int32_t SeondaryRecoilVelocity; //0x0184
    int32_t KnifeSwipes; //0x0188
    int32_t SecondaryShotsFired; //0x018C
    char pad_0190[16]; //0x0190
    int32_t PrimaryShotsFired; //0x01A0
    char pad_01A4[4]; //0x01A4
    int32_t GrenadesThrown; //0x01A8
    int32_t AkimboShotsFired; //0x01AC
    char pad_01B0[40]; //0x01B0
    int32_t Alive; //0x01D8
    int32_t Alive2; //0x01DC
    char pad_01E0[24]; //0x01E0
    int32_t Deaths; //0x01F8
    int32_t KillsThisLife; //0x01FC
    char pad_0200[4]; //0x0200
    int32_t Deaths2; //0x0204
    char pad_0208[4]; //0x0208
    int32_t Alive3; //0x020C
    int32_t TotalRecoil; //0x0210
    int32_t DistanceTravelled; //0x0214
    int32_t TotalDamage; //0x0218
    char pad_021C[8]; //0x021C
    int8_t AutomaticFiring; //0x0224
    char Name[16]; //0x0225
    char pad_0235[259]; //0x0235
    int8_t Fly; //0x0338
    char pad_0339[1589]; //0x0339
}; //Size: 0x096E
