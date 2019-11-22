#include "Types.h"

#pragma once

void AesEncyption(LPBYTE lpbState, LPCBYTE lpbKey);

// shift row
void ShiftRow(LPBYTE lpbState);

// add the subkey to the state
void KeyAdd(LPBYTE lpbState, LPCBYTE lpbKey, int iRount);

void AesDecryption(LPBYTE lpbState, LPCBYTE lpbKey);

void ByteSub(LPBYTE lpbState);

void InvByteSub(LPBYTE lpbState);

void InvShiftRow(LPBYTE lpbState);

void MixColumn(LPBYTE lpbState);

void InvMixColumn(LPBYTE lpbState);

void coef_mult(BYTE a[], BYTE b[], BYTE d[]);

BYTE GFMult(BYTE bFac1, BYTE bFac2);