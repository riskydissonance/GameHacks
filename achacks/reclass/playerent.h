#pragma once

#include <maths/vector.h>
#include <cstdint>


// Created with ReClass.NET 1.2 by KN4CK3R
/*

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
    int32_t SecondaryRecoilVelocity; //0x0184
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
    int8_t Firing; //0x0224
    char Name[16]; //0x0225
    char pad_0235[247]; //0x0235
    int32_t Team; //0x032C
    char pad_0330[8]; //0x0330
    int8_t Fly; //0x0338
    char pad_0339[59]; //0x0339
    class inventory* Inventory; //0x0374
}; //Size: 0x0378

*/

// Created with ReClass.NET 1.2 by KN4CK3R

class playerent
{
public:
	void *N0000004F; //0x0000
	Vector3 HeadPosition; //0x0004
	Vector3 HeadVelocity; //0x0010
	int32_t XIntVelocity; //0x001C
	int32_t YIntVelocity; //0x0020
	int32_t ZIntVelocity; //0x0024
	Vector3 BodyPosition; //0x0028
	Vector3 Facing; //0x0034
	char pad_0040[29]; //0x0040
	bool Grounded; //0x005D
	char pad_005E[7]; //0x005E
	bool Static; //0x0065
	char pad_0066[14]; //0x0066
	int8_t ForwardBackward; //0x0074
	int8_t LeftRight; //0x0075
	int8_t PlayerState; //0x0076
	int8_t Invisible; //0x0077
	float CrouchVelocity; //0x0078
	char pad_007C[4]; //0x007C
	bool LeftPressed; //0x0080
	bool RightPressed; //0x0081
	bool ForwardPressed; //0x0082
	bool BackwardPressed; //0x0083
	char pad_0084[104]; //0x0084
	int32_t Health; //0x00EC
	int32_t Armour; //0x00F0
	char pad_00F4[12]; //0x00F4
	int32_t Akimbo; //0x0100
	char pad_0104[4]; //0x0104
	int32_t SecondaryAmmoReserve; //0x0108
	char pad_010C[16]; //0x010C
	int32_t PrimaryAmmoReserve; //0x011C
	char pad_0120[4]; //0x0120
	int32_t AkimboAmmoReserve; //0x0124
	char pad_0128[4]; //0x0128
	int32_t SecondaryAmmo; //0x012C
	char pad_0130[16]; //0x0130
	int32_t PrimaryAmmo; //0x0140
	int32_t NumberOfGrenades; //0x0144
	int32_t AkimboAmmo; //0x0148
	int32_t KnifeRecoilVelocity; //0x014C
	int32_t PistolRecoilVelocity; //0x0150
	char pad_0154[16]; //0x0154
	int32_t PrimaryRecoilVelocity; //0x0164
	int32_t GrenadeRecoilVelocity; //0x0168
	char pad_016C[4]; //0x016C
	int32_t KnifeSwipes; //0x0170
	int32_t SecondaryShotsFired; //0x0174
	char pad_0178[16]; //0x0178
	int32_t PrimaryShotsFired; //0x0188
	int32_t GrenadesThrown; //0x018C
	char pad_0190[72]; //0x0190
	int32_t Respawns; //0x01D8
	int32_t KillsThisLife; //0x01DC
	int32_t FlagScore; //0x01E0
	int32_t Deaths; //0x01E4
	int32_t Teamkills; //0x01E8
	char pad_01EC[24]; //0x01EC
	bool Firing; //0x0204
	char Name[16]; //0x0205
	char pad_0215[247]; //0x0215
	int32_t Team; //0x030C
	int32_t WeaponChanging; //0x0310
	char pad_0314[8]; //0x0314
	int8_t Fly; //0x031C
	int8_t N000004EB; //0x031D
	char pad_031E[1]; //0x031E
	bool MiniMapOff; //0x031F
	char pad_0320[3412]; //0x0320
}; //Size: 0x1074

class inventory {
public:
    char pad_0000[8]; //0x0000
    class playerent* Owner; //0x0008
    class weapon* CurrentWeapon; //0x000C
    char pad_0010[1012]; //0x0010
}; //Size: 0x0404

class weapon {
public:
    char pad_0000[260]; //0x0000
    int16_t N00000736; //0x0104
    int16_t N000008FF; //0x0106
    int16_t N00000737; //0x0108
    int16_t N00000901; //0x010A
    int16_t N00000738; //0x010C
    int16_t N00000903; //0x010E
    int16_t N00000739; //0x0110
    int16_t N00000905; //0x0112
    int16_t N0000073A; //0x0114
    int16_t Kickback; //0x0116
    int16_t MagSize; //0x0118
    int16_t N00000909; //0x011A
    int16_t N0000073C; //0x011C
    int16_t N0000090B; //0x011E
    int16_t Recoil1; //0x0120
    int16_t Recoil2; //0x0122
    int16_t N0000073E; //0x0124
    int16_t N0000090F; //0x0126
    int16_t Spread; //0x0128
}; //Size: 0x012A
