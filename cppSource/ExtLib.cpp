#ifdef EXPORT_API
#undef EXPORT_API

using namespace std;

void EXT_LIB_InternalFunc()
{
    //do somethin inside
}

EXPORT_API int EXT_LIB_GetNum()
{
  return 29310;
}

EXPORT_API void EXT_LIB_PassingVector(float* pnts, float* floatArray, float* val)
{

  int id = 0;
  int dis = 0;
  for(int i=0; i<=20; ++i){

    pnts[id++] = -id;
    pnts[id++] = -id-1000;
    pnts[id++] = -id-2000;

    pnts[id++] = id;
    pnts[id++] = id+1000;
    pnts[id++] = id+2000;

    floatArray[dis++] = id*id;
    floatArray[dis++] = id*2;

  }

  *val = 20151006;
}
