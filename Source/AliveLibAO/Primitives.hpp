#pragma once

#include "Primitives_common.hpp"
#include "FunctionFwd.hpp"

START_NS_AO

EXPORT void CC Init_SetTPage_495FB0(Prim_SetTPage* pPrim, int /*notUsed1*/, int /*notUsed2*/, int tpage);
EXPORT int CC PSX_getTPage_4965D0(char tp, char abr, int x, __int16 y);

EXPORT void CC Poly_Set_Blending_498A00(PrimHeader* pPrim, int bBlending);

EXPORT int CC PSX_getClut_496840(int x, int y);

EXPORT void CC Poly_Set_SemiTrans_498A40(PrimHeader* pPrim, int bSemiTrans);

void CC Sprt_Init(Prim_Sprt* pPrim);

END_NS_AO
