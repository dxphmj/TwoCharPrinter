
#ifndef			____INCLUDE_DOM____
#define			____INCLUDE_DOM____
#endif

#ifdef			__cplusplus
extern	"C" {
#define			_DOMEXP		FAR PASCAL
#else
#define			_DOMEXP		FAR PASCAL _export
#endif

#define			BON_FLAG			1
#define			BND_FLAG			2
short DM_Dom(char* neededMemPointer,short point_count, short nCurveDegree);

#ifdef			__cplusplus
}
#endif
