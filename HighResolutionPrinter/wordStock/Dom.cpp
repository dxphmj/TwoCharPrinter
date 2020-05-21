 
#define		____MODIGLYF_IS_EXPORTED____
#include		<math.h>
#include		"Dom.h"
#define			LEFT_Y_SIGN			( 1)		// 1 or -1
#define			UP_X_SIGN			(-1)		// 1 or -1.
#define			MAX_MEMSIZE			((long)64*1016)
char *		D_pmem;
static long		D_memAddr,trns_memAddr;

		/*_____________________Make Glyph to be Domains_______________________
		  ____________________Modified 1995.12.14.Beijing_____________________
		  COMMENTS:
		  		The main function of this module is DM_Dom(),which get data
		  	and memory from its parameter "* mem".The parameter pnum is 
		  	the point count of the glyph to be disposed.Size of mem is 1016*
		  	64 bytes.
		  		Data brought by mem is in the format as following:If p is an
		  	ON-Point(p is the terminal point of a lineSection or 3-ordered 
		  	Bezier Curve or 2-ordered Spline), bit_0 of the typeFlag of p 
		  	(which be denoted as typeFlag(p) following) will be set to 1.If
		  	p is the end_point of a contour,the bit_1 of typeFlag(p) will be
		  	set to 1.Other bits should be set to 0.
		  		(X(p),Y(p),typeFlag(p)) with this order and the order of p 
		  	itself and with data type "int" be used by "mem" in the parameter.
		  	Let pxyc = (short int *)&mem[0],(pxyc[0],pxyc[1],pxyc[2]) is (X(0),
		  	Y(0),typeFlag(0));(pxyc[3],pxyc[4],pxyc[5]) is (X(1),Y(1),typeFlag(1)),
		  	...,and so on.
		  		Return Value is the point count of new disposed outline if the
		  	Value is greater than 0; If return 0,error had accured.In any case,
		  	the data saved in mem had been destroied.
		  												Commented By Gzj.
		  ____________________________________________________________________*/


#define			MAX_DXYVALUE		120
#define			BON_FLAG			1
#define			BND_FLAG			2
#define			BNOINTER_FLAG		4
#define			BUSED_FLAG			8

#define			MAX_XXXX			1024
#define			MAX_YYYY			1024

#define			D_ptx(_xyc,_p)		_xyc[((_p)<<1)+(_p)+0]	// be used by xyc in DM_
#define			D_pty(_xyc,_p)		_xyc[((_p)<<1)+(_p)+1]
#define			D_ptc(_xyc,_p)		_xyc[((_p)<<1)+(_p)+2]

#define			c_ptx(_xyc,_p)		_xyc[((_p)<<2)+0]		// be used by nxyc in DM_
#define			c_pty(_xyc,_p)		_xyc[((_p)<<2)+1]
#define			c_ptc(_xyc,_p)		_xyc[((_p)<<2)+2]
#define			c_ptr(_xyc,_p)		_xyc[((_p)<<2)+3]


#define			D_Abs(x)			( ((x)>=0)   ? (x) : (-(x)) )
#define			D_Max(x,y)			( ((x)>=(y)) ? (x) : (y) )
#define			D_Min(x,y)			( ((x)<=(y)) ? (x) : (y) )

#define			BRP_FLAG			0		//repeative Bezier.
#define			BLN_FLAG			1
#define			BSP_FLAG			2
#define			BBZ_FLAG			3

static short	nStaticCurveDegree;//			BBZ_FLAG
#define			BZ_SIZE				258
long *		bzxy;

typedef struct
{
	short 	pn;
	char 	cc;
	short	fz;
	short 	fm;
} D_RECD;

typedef struct
{
	short 	fz0,fm0;
	short	fz1,fm1;
	short	pn0,pn1;
	unsigned char	flg;		// Select-Flag.
	
	//___Coordis and fz. Where fm be the same as above fm0.
	short	x_in,x_fz;
	short	y_in,y_fz;

} D_INTERPNT;
// Comment on D_INTERPNT.flg: flg = (c1<<6)+(c2<<4) + (d1<<2)+d2.
// Where,c1,c2 is the flags of pn0(fz0/fm0),d1,d2 for pn1(fz1/fm1).
// if s=fz0/fm0,c1=s-,c2=s+;Similar to fz1/fm1.
// s- is the left Select_Flag of s.s+ for right side.this flg is
// valuates by Scanning.

typedef struct
{
	short 	m_x0,m_y0;
	short   m_x1,m_y1;
	short	m_x2,m_y2;
	short	m_x3,m_y3;
	short	flg;
} D_BEZIER;

typedef struct
{
	short 	m_x0,m_y0;
	short   m_x1,m_y1;
} D_RECT;

typedef struct
{
	short	x0,y0,x1,y1;
	short   pn;
	char	sn;
} D_SCANDATA;

typedef struct
{
	short 	xy0,xy1;
	short	yx0,yx1;
	short 	fz0,fm0;
	short	fz1,fm1;
	
	//InterPnts coordis.
	short	it_xy0,it_fz0,it_fm0;
	short	it_xy1,it_fz1,it_fm1;
} D_SCANXY;

typedef struct
{
	short	pn;		// order number in D_itpt.
	short	ap;		// anti_order number 
	char	flg;	// flg_bit[0] is 0,1 in D_itpt[].pn0,1 for pn;
					// flg_bit[1] is for ap.
} D_ANTIPODE;


typedef struct
{
	short 	in;
	short	fz;
	short 	fm;
} D_FSH;

typedef struct
{
	char 	c180,c90;
	long    fz,fm;

} D_CORNER;

typedef struct
{
	short			p0;
	unsigned char	c_fz0,c_fm0;
	short			n_fz0,n_fm0;
	
	short			p1;
	unsigned char	c_fz1,c_fm1;
	short			n_fz1,n_fm1;
	
	short			ipx,ipy;		// InterPoint coordis.
	char			flg_xy;			//x bit[0]; y bit[1].
} D_MAPANTI;

D_INTERPNT * 	D_itpt;
D_ANTIPODE *		D_anti;
D_MAPANTI   *	D_map;

//______________________Part_1:Simple Functions___________________________
//________________________________________________________________________

char D_FSHGreater(short fz0,short fm0,   short fz1,short fm1)
// Where, fm0>0,fm1>0; if fz0/fm0>fz1/fm1,return 1,
// if equal return 0,less,return -1.
{
	long	h0 = fz0 * (long) fm1;
	long	h1 = fz1 * (long) fm0;
	
	if(h0>h1)
	{
		return 1;
	}
	if(h0<h1)
	{
		return -1;
	}
return 0;
}

char D_GreaterLongFSH(unsigned char c_fz0, unsigned char c_fm0,
                      short         n_fz0, short         n_fm0,
                      unsigned char c_fz1, unsigned char c_fm1,
                      short         n_fz1, short         n_fm1)
// The real values of the number = (c_fz0 + (n_fz0/n_fm0)/c_fm0)
// and so on.Where,fm>0,0<=fz<=fm.
{
	char    rt_value;
	
	////ASSERT(c_fm0 == c_fm1);
	////ASSERT(n_fz0 <= n_fm0);
	////ASSERT(n_fz1 <= n_fm1);
	
	if(n_fz0 == n_fm0)
	{
		n_fz0 = 0;
		n_fm0 = 1;
		c_fz0++;
	}
	if(n_fz1 == n_fm1)
	{
		n_fz1 = 0;
		n_fm1 = 1;
		c_fz1++;
	}
	
	////ASSERT(c_fz0 <= c_fm0);
	////ASSERT(c_fz1 <= c_fm1);

	if(c_fz0 > c_fz1)
	{
		return 1;
	}
	if(c_fz0 < c_fz1)
	{
		return -1;
	}
	rt_value = D_FSHGreater(n_fz0,n_fm0, n_fz1,n_fm1);

return rt_value;
}

void D_GetFSH(long fz, long fm, long tm, D_FSH* fs)//fm>0.
// Where fm>0 and (fz*tm) not exceed 31 bits.
// Make (fz/fm)*tm be the form: integer + fz/fm 
// with 0<=fz<fm.Transfered by fs.
{
	long	b = fz * tm;
	long	a = D_Abs(b);
	
	fs[0].in = (short)(a/fm);
	fs[0].fz = (short)(a%fm);
	fs[0].fm = (short)fm;
	
	if(b<0)
	{
		fs[0].in = -fs[0].in;
		if(fs[0].fz)
		{
			fs[0].fz = (short)(fm - fs[0].fz);
			fs[0].in -= 1;
		}
	}
return;
}

void D_SimplifyInterPnt(D_INTERPNT* itpt)
{
		if(itpt[0].fz0==0)
		{
			itpt[0].fm0 = 1;
		}
		if(itpt[0].fz1 == 0)
		{
		 	itpt[0].fm1 = 1;
		}
		if(itpt[0].fz0 == itpt[0].fm0)
		{
		 	itpt[0].fz0 = 1;
		 	itpt[0].fm0 = 1;
		}
		if(itpt[0].fz1 == itpt[0].fm1)
		{
		 	itpt[0].fz1 = 1;
		 	itpt[0].fm1 = 1;
		}
		if(itpt[0].fm0<0)
		{
			itpt[0].fz0 = -itpt[0].fz0;
			itpt[0].fm0 = -itpt[0].fm0;
		}
		if(itpt[0].fm1<0)
		{
			itpt[0].fz1 = -itpt[0].fz1;
			itpt[0].fm1 = -itpt[0].fm1;
		}
return;				
}

void D_GetBetweenValue(D_SCANXY* pscn_xy,D_FSH* fs)
// Get a FSH value between n0 + r0/fm0 and n1 + r1/fm1
// in the functions.Where,fm0,fm1>0 and not exceed 15
// bits;The fm of the returned FSH not exceed 16 bits,
// This be used in D_Greater(),where long z,m be used
// to transform fs[] to "unsigned short".
{
	D_SCANXY 	sx = pscn_xy[0];
	short 		dxy = (sx.it_xy1-sx.it_xy0);
	short		n0,n1,r0,r1,fm0,fm1;
	short		min_n,max_n;
	
	n0 	= sx.it_xy0;
	r0 	= sx.it_fz0;
	n1 	= sx.it_xy1;
	r1 	= sx.it_fz1;
	fm0 = sx.it_fm0;
	fm1 = sx.it_fm1;
	
	if(n0==n1)		// Now,there must be r0/fm0 < r1/fm1.
	{
		////ASSERT(D_FSHGreater(r0,fm0,  r1,fm1));
		fs[0].in = n0;
		fs[0].fz = r0 + r1;
		fs[0].fm = fm0 + fm1;
		return;
	}
	
	// Now,n0!=n1.
	min_n = D_Min(n0,n1);
	max_n = D_Max(n0,n1);
	if(D_Abs(n1-n0)==1)
	{
		fs[0].in  = min_n;
		if(D_FSHGreater(r0,fm0, r1,fm1)==1)
		{
	 		fs[0].fz = r0  + 1;
	 		fs[0].fm = fm0 + 1;
	 		return;
		}
	
		fs[0].fz = r1  + 1;
		fs[0].fm = fm1 + 1;
	return;
	}
	
	//Now,max_n-min_n>=2.
	fs[0].in = min_n + (max_n - min_n)/2;
	fs[0].fz = 1;
	fs[0].fm = 2;

return;
}

char D_Sgn(short x)
{
	if(x>0)
	{
		return 1;
	}
	if(x<0)
	{
		return -1;
	}
return 0;
}

short C_Be(short * xyc,short p)
{
	while(1)
	{
		p--;
		if(p<0) return 0;
		if(c_ptc(xyc,p) & BND_FLAG)
		{
			p++;
			return p;
		}
	}
return 0;
}

short C_Nd(short * xyc,short p)
{
	while(1)
		{
		if(c_ptc(xyc,p) & BND_FLAG)
			return p;
		p++;
		}
return 0;
}

short C_Next(short * xyc,short p)
{
	if(!(c_ptc(xyc,p) & BND_FLAG))
	{
		return p+1;
	}
return C_Be(xyc,p);
}

short D_Be(short * xyc,short p)
{
	while(1)
	{
		p--;
		if(p<0) return 0;
		if(D_ptc(xyc,p) & BND_FLAG)
		{
			p++;
			return p;
		}
	}
return 0;
}

short D_Nd(short * xyc,short p)
{
	while(1)
		{
		if(D_ptc(xyc,p) & BND_FLAG)
			return p;
		p++;
		}
return 0;
}

short D_Next(short * xyc,short p)
{
	if(!(D_ptc(xyc,p) & BND_FLAG))
	{
		return p+1;
	}
return D_Be(xyc,p);
}

short D_NextOn(short * xyc, short p)
{
	
	while(1)
	{
		p = D_Next(xyc,p);
		if(D_ptc(xyc,p) & BON_FLAG)
		return p;
	}

return p;
}

void D_GetBezier(short * xyc, short p, D_BEZIER* bz)
{
	short 	p0 = p,p1,p2,p3;
	
	p1 = D_Next(xyc,p0);
	
	bz[0].m_x0 = D_ptx(xyc,p0);
	bz[0].m_y0 = D_pty(xyc,p0);
	bz[0].m_x1 = D_ptx(xyc,p1);
	bz[0].m_y1 = D_pty(xyc,p1);
	
	
	if(D_ptc(xyc,p1) & BON_FLAG)
	{
		bz[0].flg = BLN_FLAG;
		return;
	}
	
	bz[0].flg = nStaticCurveDegree;
	p2 = D_Next(xyc,p1);
	bz[0].m_x2 = D_ptx(xyc,p2);
	bz[0].m_y2 = D_pty(xyc,p2);
	if(nStaticCurveDegree == BSP_FLAG)
	{
		return;
	}
	
	p3 = D_Next(xyc,p2);
	bz[0].m_x3 = D_ptx(xyc,p3);
	bz[0].m_y3 = D_pty(xyc,p3);

return;
}

void D_GetBBox(short * xyc,short pnum, D_RECT* rc)
{
	short 	x0,y0,x1,y1;
	short 	p;
	
	if(pnum<=0)
	{
		rc[0].m_x0 = 0;
		rc[0].m_y0 = 0;
		rc[0].m_x1 = 0;
		rc[0].m_y1 = 0;
		return;
	}
	
	x0 = D_ptx(xyc,0);
	y0 = D_pty(xyc,0);
	x1 = x0;
	y1 = y0;
	
	for(p=1;p<pnum;p++)
	{
		if(D_ptx(xyc,p) < x0)		x0	=	D_ptx(xyc,p);
		if(D_ptx(xyc,p) > x1)		x1	=	D_ptx(xyc,p);
		if(D_pty(xyc,p) < y0)		y0	=	D_pty(xyc,p);
		if(D_pty(xyc,p)	> y1)		y1	=	D_pty(xyc,p);
	}
	
	rc[0].m_x0 = x0;
	rc[0].m_y0 = y0;
	rc[0].m_x1 = x1;
	rc[0].m_y1 = y1;
return;
}

//________________________Part_2: Bezier Functions_______________________
//_______________________________________________________________________
void D_FJBz2(D_BEZIER* 		bz,
             unsigned char 	c_fz0,
             unsigned char 	c_fm0,
             short			n_fz0,
             short			n_fm0,
			 unsigned char	c_fz1,
			 unsigned char	c_fm1,
			 short			n_fz1,
			 short			n_fm1,
			 short			_x0,
			 short			_y0,
			 short			_x1,
			 short			_y1,
			 char			use_xy0,
			 char			use_xy1)
{
	short   x0 = bz[0].m_x0, y0 = bz[0].m_y0;
	short	x1 = bz[0].m_x1, y1 = bz[0].m_y1;
	short	x2 = bz[0].m_x2, y2 = bz[0].m_y2;
	double 	s1,s2,t1,t2,dt;
	double 	ddtr[4][2];
	double  s,t;
	
	s = (c_fz0 + (double)n_fz0/n_fm0)/c_fm0;
	t = (c_fz1 + (double)n_fz1/n_fm1)/c_fm1;

	dt=t-s;
	s1=s;s2=s1*s;
	t1=t;t2=t1*t;

	x2 -= x1;
	y2 -= y1;
	x1 -= x0;
	y1 -= y0;
	
	x2 -= x1;
	y2 -= y1;

	ddtr[0][0] = x0+2*x1*s1+x2*s2;
	ddtr[0][1] = y0+2*y1*s1+y2*s2;
	ddtr[2][0] = x0+2*x1*t1+x2*t2;
	ddtr[2][1] = y0+2*y1*t1+y2*t2;
	if(use_xy0 & 1)
	{
		ddtr[0][0] = _x0;
	}
	if(use_xy0 & 2)
	{
		ddtr[0][1] = _y0;
	}
	if(use_xy1 & 1)
	{
		ddtr[2][0] = _x1;
	}
	if(use_xy1 & 2)
	{
		ddtr[2][1] = _y1;
	}

	ddtr[1][0] = ddtr[0][0]+(x1+x2*s1)*dt;
	ddtr[1][1] = ddtr[0][1]+(y1+y2*s1)*dt;

	bz[0].m_x0 = _x0 ;//(short)(ddtr[0][0]+0.5);
	bz[0].m_y0 = _y0; //(short)(ddtr[0][1]+0.5);
	bz[0].m_x1 = (short)(ddtr[1][0]+0.5);
	bz[0].m_y1 = (short)(ddtr[1][1]+0.5);
	bz[0].m_x2 = _x1; //(short)(ddtr[2][0]+0.5);
	bz[0].m_y2 = _y1; //(short)(ddtr[2][1]+0.5);

return;
}

void D_FJBz3(D_BEZIER* 		bz,
             unsigned char 	c_fz0,
             unsigned char 	c_fm0,
             short			n_fz0,
             short			n_fm0,
			 unsigned char	c_fz1,
			 unsigned char	c_fm1,
			 short			n_fz1,
			 short			n_fm1,
			 short			_x0,
			 short			_y0,
			 short			_x1,
			 short			_y1,
			 char			use_xy0,
			 char			use_xy1)
{
	short   x0 = bz[0].m_x0, y0 = bz[0].m_y0;
	short	x1 = bz[0].m_x1, y1 = bz[0].m_y1;
	short	x2 = bz[0].m_x2, y2 = bz[0].m_y2;
	short	x3 = bz[0].m_x3, y3 = bz[0].m_y3;
	double 	s1,s2,s3,t1,t2,t3,dt;
	double 	ddtr[4][2];
	double  s,t;
	
	s = (c_fz0 + (double)n_fz0/n_fm0)/c_fm0;
	t = (c_fz1 + (double)n_fz1/n_fm1)/c_fm1;

	dt=t-s;
	s1=s;s2=s1*s;s3=s2*s;
	t1=t;t2=t1*t;t3=t2*t;

	x3 -= x2;
	y3 -= y2;
	x2 -= x1;
	y2 -= y1;
	x1 -= x0;
	y1 -= y0;
	
	x3 -= x2;
	y3 -= y2;
	x2 -= x1;
	y2 -= y1;

	x3 -= x2;
	y3 -= y2;

	ddtr[0][0] = x0+x1*s1*3+x2*s2*3+x3*s3;
	ddtr[0][1] = y0+y1*s1*3+y2*s2*3+y3*s3;
	ddtr[3][0] = x0+3*x1*t1+3*x2*t2+x3*t3;
	ddtr[3][1] = y0+3*y1*t1+3*y2*t2+y3*t3;
	if(0)
	{
	if(use_xy0 & 1)
	{
		ddtr[0][0] = _x0;
	}
	if(use_xy0 & 2)
	{
		ddtr[0][1] = _y0;
	}
	if(use_xy1 & 1)
	{
		ddtr[3][0] = _x1;
	}
	if(use_xy1 & 2)
	{
		ddtr[3][1] = _y1;
	}
	}

	ddtr[1][0] = ddtr[0][0]+(x1+2*x2*s1+x3*s2)*dt;
	ddtr[1][1] = ddtr[0][1]+(y1+2*y2*s1+y3*s2)*dt;
	ddtr[2][0] = ddtr[3][0]-(x1+2*x2*t1+x3*t2)*dt;
	ddtr[2][1] = ddtr[3][1]-(y1+2*y2*t1+y3*t2)*dt;

	bz[0].m_x0 = _x0; //(short)(ddtr[0][0]+0.5);
	bz[0].m_y0 = _y0; //(short)(ddtr[0][1]+0.5);
	bz[0].m_x1 = (short)(ddtr[1][0]+0.5);
	bz[0].m_y1 = (short)(ddtr[1][1]+0.5);
	bz[0].m_x2 = (short)(ddtr[2][0]+0.5);
	bz[0].m_y2 = (short)(ddtr[2][1]+0.5);
	bz[0].m_x3 = _x1; //(short)(ddtr[3][0]+0.5);
	bz[0].m_y3 = _y1; //(short)(ddtr[3][1]+0.5);

return;
}

void D_FJBezier(D_BEZIER* 		bz,
                unsigned char 	c_fz0,
                unsigned char 	c_fm0,
                short			n_fz0,
                short			n_fm0,
	            unsigned char	c_fz1,
	            unsigned char	c_fm1,
	            short			n_fz1,
	            short			n_fm1,
	            short			x0,
	            short			y0,
	            short			x1,
	            short			y1,
	            char			use_xy0,
	            char			use_xy1)
// Comment: bz[] transfering the divided new Bezier.
// (c_fz0/c_fm0) + (n_fz0/n_fm0)/c_fm0 is the first
// parameter value t0.Similar to t1. (x0,y0) is the 
// coordis of P(t0),(x1,y1) is P(t1).Bezier can be 
// Line_Section,2-ordered Bezier Curve,or 3-Ordered
// Bezier Curve by bz[0].flg.
{
	short	m_x0 = bz[0].m_x0, m_y0 = bz[0].m_y0,
	        m_x1 = bz[0].m_x1, m_y1 = bz[0].m_y1,
	        m_x2 = bz[0].m_x2, m_y2 = bz[0].m_y2,
	        m_x3 = bz[0].m_x3, m_y3 = bz[0].m_y3;
	
	switch(bz[0].flg)
	{
		case BLN_FLAG:
			bz[0].m_x0 = x0;
			bz[0].m_y0 = y0;
			bz[0].m_x1 = x1;
			bz[0].m_y1 = y1;
			bz[0].flg = BLN_FLAG;
			break;
		case BSP_FLAG:
			D_FJBz2(bz,c_fz0,c_fm0,n_fz0,n_fm0,
			           c_fz1,c_fm1,n_fz1,n_fm1,
			           x0,y0,x1,y1,use_xy0,use_xy1);
			bz[0].flg = BSP_FLAG;
			break;
		case BBZ_FLAG:
			D_FJBz3(bz,c_fz0,c_fm0,n_fz0,n_fm0,
			           c_fz1,c_fm1,n_fz1,n_fm1,
			           x0,y0,x1,y1,use_xy0,use_xy1);
			bz[0].flg = BBZ_FLAG;
			break;
		default:
			break;
	}
return;
}
	            
short D_SaveBezier(D_BEZIER 	bz,
                   short * 	xyc,
                   short		num)
{
	switch(bz.flg)
	{
		case BLN_FLAG:
			D_ptx(xyc,num) = bz.m_x0;
			D_pty(xyc,num) = bz.m_y0;
			D_ptc(xyc,num) = BON_FLAG;
			num++;
			break;
		case BSP_FLAG:
			D_ptx(xyc,num) = bz.m_x0;
			D_pty(xyc,num) = bz.m_y0;
			D_ptc(xyc,num) = BON_FLAG;
			num++;
			D_ptx(xyc,num) = bz.m_x1;
			D_pty(xyc,num) = bz.m_y1;
			D_ptc(xyc,num) = 0;
			num++;
			break;
		case BBZ_FLAG:
			D_ptx(xyc,num) = bz.m_x0;
			D_pty(xyc,num) = bz.m_y0;
			D_ptc(xyc,num) = BON_FLAG;
			num++;
			D_ptx(xyc,num) = bz.m_x1;
			D_pty(xyc,num) = bz.m_y1;
			D_ptc(xyc,num) = 0;
			num++;
			D_ptx(xyc,num) = bz.m_x2;
			D_pty(xyc,num) = bz.m_y2;
			D_ptc(xyc,num) = 0;
			num++;
			break;
		default:
			break;
	}
return num;
}

short D_Bz2(short x0,short y0,short x1,short y1,
            short x2,short y2)
{	
	long 	a0 	= 	x0,		b0 	=	y0,
	        a1	=	x1,		b1	=	y1,
	        a2	=	x2,		b2	=	y2;
	short 	c2,d2;
	short 	tm,tm2,shtm,halfTm;
	short 	i,k;
	
	a2	-=	a1;	
	b2	-=	b1;  
	a1	-=	a0;
	b1	-=	b0;
	a2	-=	a1;
	b2	-=	b1;
	a1	+=	a1;
	b1	+=	b1;
	
	c2	=	(short)a2;
	d2	=	(short)b2;
	d2	=	D_Abs(d2);
	c2	=	D_Abs(c2);
	c2	=	D_Max(c2,d2);
	
	tm	=	1;
	c2	=	(c2>>3);
	while(c2)
	{
		tm++;
		c2	=	(c2>>2);
	}
	
	if(tm>6) 	tm = 6;
	
	shtm	=	(1<<tm);
	tm2		=	(tm+tm);
	
	a0	=	(a0<<tm2); 
	b0	=	(b0<<tm2);
	a1	=	(a1<<tm);
	b1	=	(b1<<tm);
	
	bzxy[0]	=	a0;
	bzxy[1]	=	b0;
	bzxy[2]	=	a0+a1+a2;
	bzxy[3]	=	b0+b1+b2;
	
	c2=(short)(a2+a2);
	d2=(short)(b2+b2);
	k=4;
	for(i=2;i<shtm;i++)
		{
		bzxy[k]	=	bzxy[k-2]+bzxy[k-2]-bzxy[k-4]+c2;
		k++;
		bzxy[k]	=	bzxy[k-2]+bzxy[k-2]-bzxy[k-4]+d2;
		k++;
		}
	k=0;
	halfTm=(shtm<<(tm-1));
	for(i=0;i<shtm;i++)
		{
		bzxy[k]=((bzxy[k]+halfTm)>>tm2);
		k++;
		bzxy[k]=((bzxy[k]+halfTm)>>tm2);
		k++;
		}
	bzxy[k]=x2;k++;
	bzxy[k]=y2;k++;
return (shtm);
}

short D_Bz3(short x0,short y0, short x1,short y1,
	        short x2,short y2, short x3,short y3)
{
	short		m_x0 = x0,	m_y0 = y0,
	            m_x1 = x1,  m_y1 = y1,
	            m_x2 = x2,  m_y2 = y2,
	            m_x3 = x3,  m_y3 = y3;
	short		i,u2,u3,v2,v3,fm,tm,shtm;
	short		x=x3,y=y3;
	short		bzxyl;
	long int 	u,v,w,_half;
	long int 	a0,b0,a1,b1,a2,b2,a3,b3;
	long int 	c3x,c3y;
		
	x3	-=	x2;
	y3	-=	y2; 
	x2	-=	x1;
	y2	-=	y1; 
	x1	-=	x0;
	y1	-=	y0;
	
	x3	-=	x2;
	y3	-=	y2; 
	x2	-=	x1;
	y2	-=	y1;
	x3	-=	x2;
	y3	-=	y2;
	
	u2	=	D_Abs(x2);
	v2	=	D_Abs(y2);
	u3	=	D_Abs(x2+x3);
	v3	=	D_Abs(y2+y3);
	fm  =   D_Max(u2,u3);
	fm	=	D_Max(fm,v2);
	fm	=	D_Max(fm,v3);
	
	tm=1;
	if(fm>=4)		tm++;
	if(fm>=16) 		tm++;
	if(fm>=64) 		tm++;
	if(fm>=256) 	tm++;
	if(fm>=1024) 	tm++;
	if(tm>5) 		tm=5;
	
	if(tm<2)				// tm = 1.
	{
		bzxy[0] = m_x0;
		bzxy[1] = m_y0;
		x  = m_x1 + m_x2;
		x += (x<<1);
		y  = m_y1 + m_y2;
		y += (y<<1);
		bzxy[2] = ((m_x0 + x + m_x3 + 4)>>3);
		bzxy[3] = ((m_y0 + y + m_y3 + 4)>>3);
		bzxy[4] = m_x3;
		bzxy[5] = m_y3;
		return 2;
	}

	a0	=	x0;
	b0	=	y0;
	a1	=	x1;
	b1	=	y1;
	a2	=	x2;
	b2	=	y2;
	a3	=	x3;
	b3	=	y3;
	
	if(x1<0) 
	{
		a1=-a1;
	}
	if(y1<0) 
	{
		b1=-b1;
	}
	if(x2<0) 
	{
		a2=-a2;
	}
	if(y2<0) 
	{
		b2=-b2;
	}
	
	fm=tm;                
		a2=(a2<<fm);b2=(b2<<fm);
	fm=fm+tm;
		a1=(a1<<fm);b1=(b1<<fm);
	fm=fm+tm;
		a0=(a0<<fm);b0=(b0<<fm);
	if(x1<0) 
	{
		a1=-a1;
	}
	if(y1<0) 
	{
		b1=-b1;
	}
	if(x2<0) 
	{
		a2=-a2;
	}
	if(y2<0) 
	{
		b2=-b2;
	}
	
	a1 	+=	(a1+a1);
	b1	+=	(b1+b1);
	a2	+=	(a2+a2);
	b2	+=	(b2+b2);
	c3x	 =	a3;
	c3x	+=	c3x;
	c3x	+=	(c3x+c3x);
	c3y	 =	b3;
	c3y	+=	c3y;
	c3y	+=	(c3y+c3y);
	u	=	(a0-a1+a2-a3);
	v	=	(b0-b1+b2-b3);
	
	bzxyl=0;
	bzxy[bzxyl]	=	a0;					bzxyl++;        
	bzxy[bzxyl]	=	b0;					bzxyl++;
	bzxy[bzxyl]	=	a0+a1+a2+a3;		bzxyl++;
	bzxy[bzxyl]	=	b0+b1+b2+b3;		bzxyl++;
		
		w		=	bzxy[bzxyl-2]-bzxy[bzxyl-4];
		w		=	w+w+w;
		w		=	w+u+c3x;
	bzxy[bzxyl]	=	w;					bzxyl++;
		w		=	bzxy[bzxyl-2]-bzxy[bzxyl-4];
		w		=	w+w+w;
		w		=	w+v+c3y;
	bzxy[bzxyl]	=	w;					bzxyl++;

	shtm=(1<<tm);
	for(i=3;i<shtm;i++)
	{
		w		=	bzxy[bzxyl-2]-bzxy[bzxyl-4];
		w		=	w+w+w;
		w		=	w+bzxy[bzxyl-6]+c3x;
	bzxy[bzxyl]	=	w;					bzxyl++;
		w		=	bzxy[bzxyl-2]-bzxy[bzxyl-4];
		w		=	w+w+w;
		w		=	w+bzxy[bzxyl-6]+c3y;
	bzxy[bzxyl]	=	w;					bzxyl++;
	}
	tm			+=	(tm+tm);
	fm			 =	tm-1;
	_half		 =	(1<<fm);
	
	for(i=0;i<bzxyl;i++)
	{
		bzxy[i]	 =	((bzxy[i]+_half)>>tm);
	}
	bzxy[bzxyl]	 	=	x;
	bzxy[bzxyl+1]	=	y;

return (shtm);
}

short D_Bezier(D_BEZIER* bz)
{
	short 	pn;
	short   xy[BZ_SIZE];
	short	p,q,r,i,len,len1,fm;
	long	fz;
	short	x0,y0,x1,y1;
	short	dx,dy,half;
	
	switch(bz[0].flg)
	{
		case BLN_FLAG:
			bzxy[0] = bz[0].m_x0;
			bzxy[1] = bz[0].m_y0;
			bzxy[2] = bz[0].m_x1;
			bzxy[3] = bz[0].m_y1;
			pn = 1;
			break;
		case BSP_FLAG:
			pn = D_Bz2( bz[0].m_x0,	bz[0].m_y0,
			            bz[0].m_x1,	bz[0].m_y1,
			            bz[0].m_x2, bz[0].m_y2 );
			break;
		case BBZ_FLAG:
			pn = D_Bz3( bz[0].m_x0,	bz[0].m_y0,
			            bz[0].m_x1,	bz[0].m_y1,
			            bz[0].m_x2, bz[0].m_y2,
			            bz[0].m_x3, bz[0].m_y3 );
			break;
		default:
			pn = 0;
			break;
	}

	// now, to make all lines length<128.
	// Get maximum length.
	len	= 0;
	q	= 0;
	for(i=0;i<pn;i++)
	{
		len1 = (short)D_Max(D_Abs(bzxy[q+2]-bzxy[q]),D_Abs(bzxy[q+3]-bzxy[q+1]));
		if(len1 > len)
		len = len1;
		q++;q++;
	}
	
	fm = (len/MAX_DXYVALUE) + 1;
	
	if(fm==1)
	{
		return pn;
	}
	
	if( (fm*pn) >= 128)
	{
		return -1;
	}
	
	// Cut Lines.
	half = (fm>>1);
	q = 0;
	r = 0;
	for(p=0;p<pn;p++)
	{
		x0 = (short)bzxy[q];		q++;
		y0 = (short)bzxy[q];		q++;
		x1 = (short)bzxy[q];
		y1 = (short)bzxy[q+1];
		dx = x1-x0;
		dy = y1-y0;		
		for(i=0;i<fm;i++)
		{
			fz = i;
			xy[r] = (short)(x0 + (fz*dx+half)/fm);		r++;
			xy[r] = (short)(y0 + (fz*dy+half)/fm);		r++;
		}
		
	}
	xy[r]   = (short)bzxy[pn+pn];
	xy[r+1] = (short)bzxy[pn+pn+1];
	
	for(i=0;i<=r+1;)
	{
		bzxy[i] = xy[i];
		i++;
	}
	pn = r/2;

return pn;
}

//______________________Part_3: Important Functions_________________________
//__________________________________________________________________________

short D_TrnsBzToLn(short * xyc,short pnum,short * nxyc)
// Transform all Bezier curves to be lineSections.
// if return 0,memSize too small;else return 1.
{
	short		be,nd,w,i,p,q,pn;
	long		ad     = D_memAddr;
	long		max_ad;
	D_BEZIER	bz;
	short		nptn;
	short		fz,fm;
	
	max_ad = (long)sizeof(long) * BZ_SIZE+64;
	bzxy   = (long *)&D_pmem[MAX_MEMSIZE - max_ad];
	max_ad = MAX_MEMSIZE - max_ad - 64;
	
	nptn = 0;
	for(w=0;w<pnum;w++)
	{
		be = w;
		nd = D_Nd(xyc,w);
		w  = nd;
		for(i=be;i<=nd;i++)
		if(D_ptc(xyc,i) & BON_FLAG)
		{
			D_GetBezier(xyc,i,&bz);
			pn = D_Bezier(&bz);
				if(pn<0)
				{
					return 0;
				}
			fm = pn;
			q  = 0;
			for(p=0;p<pn;p++)
			{
				if(ad >= max_ad)
				{
					return 0;
				}
				c_ptx(nxyc,nptn) = (short)bzxy[q];	q++;
				c_pty(nxyc,nptn) = (short)bzxy[q];	q++;
				c_ptc(nxyc,nptn) = BON_FLAG;
				c_ptr(nxyc,nptn) = i;
				fz = p;
				c_ptc(nxyc,nptn) += ((unsigned short)fz<<9) + ((unsigned short)fm<<2);
				nptn++;
				ad += 8;
			}
		}
		c_ptc(nxyc,nptn-1) |= BND_FLAG;
	}

return nptn;
}


short D_Elimi(short * xyc,short num)
// Elimilate repeative points on the new
// outline combinated by lineSections.
// If error,return 0; else return 1.
{
	char * 	flg = (char *)&D_pmem[D_memAddr];
	short       w,i,p,be,nd;

	if(D_memAddr + num >= MAX_MEMSIZE)
	{
		return 0;
	}
	
	for(w=0;w<num;w++)
	{
		flg[w] = 1;					// if(flg[w]),xyc(w) will be elimilated.
	}
	
	for(w=0;w<num;w++)
	{
		be = w;
		nd = C_Nd(xyc,w);
		w  = nd;
		for(i=be;i<=nd;i++)
		{
			p = C_Next(xyc,i);
			if(c_ptx(xyc,i) == c_ptx(xyc,p) &&
			   c_pty(xyc,i) == c_pty(xyc,p))
			{
				flg[i] = 0;
			}
		}
	}
	
	p = 0;
	for(w=0;w<num;w++)
	{
		be = w;
		nd = C_Nd(xyc,w);
		w  = nd;
		for(i=be;i<=nd;i++)
		if(flg[i])
		{
			c_ptx(xyc,p) = c_ptx(xyc,i);
			c_pty(xyc,p) = c_pty(xyc,i);
			c_ptc(xyc,p) = c_ptc(xyc,i);
			c_ptr(xyc,p) = c_ptr(xyc,i);
				if(i==nd)
				{
					c_ptc(xyc,p) -= (c_ptc(xyc,i) & BND_FLAG);
				}
			p++;
		}
		c_ptc(xyc,p-1) |= BND_FLAG;
	}
	num = p;

return num;
}

short D_Get1InterPnt(short * xyc, short p0, short rp0,
                     short x1,short y1,short x2,short y2,
                     short p1,short pn)
// By the preDisposing of MAX_DXY, fz,fm can be represented 
// in integers not exceed 15 bits.
{
	short 		x3,y3,x4,y4;
	char 		s;
	short 		tmp_xy;
	short 		max_x12,max_x34,min_x12,min_x34;
	short 		max_y12,max_y34,min_y12,min_y34;
	short		min_max_x, max_min_x,
				min_max_y, max_min_y;	
	short 		dx12,dy12,dx34,dy34;
	long		h12_3,h12_4,  
	    		h34_1,h34_2,
	    		det;
	short		same_contour;
	short		same_xy;
	short		rp1;
	short		fz0,fz1,fm;
	short		jx0,jy0,jx1,jy1;
	D_FSH		fs;

	trns_memAddr = 0;
	same_contour = 0;
	rp1 = C_Next(xyc,p1);
	x3 	=	c_ptx(xyc,p1);
	y3	=	c_pty(xyc,p1);
	x4	=	c_ptx(xyc,rp1);
	y4	=	c_pty(xyc,rp1);
	
	
		if(x1==x2 && y1==y2)
		{
			return (pn);
		}
		if(x3==x4 && y3==y4)
		{
			return (pn);
		}
	
	max_x12	=	D_Max(x1,x2);
	min_x34	=	D_Min(x3,x4);
		if(max_x12<min_x34)
		{
			return pn;
		}
	max_y12	=	D_Max(y1,y2);
	min_y34	=	D_Min(y3,y4);
		if(max_y12<min_y34)
		{
			return pn;
		}
	min_x12	=	D_Min(x1,x2);
	max_x34	=	D_Max(x3,x4);
    	if(min_x12 > max_x34)
    	{
    		return pn;
    	}
	min_y12 =	D_Min(y1,y2);
	max_y34	=	D_Max(y3,y4);
		if(min_y12 > max_y34)
		{
			return pn;
		}
	
	if(rp0 == p1 || rp1 == p0)
	{
		same_contour = 1;
	}
	
	dx12		=	x2-x1;	
	dy12		=	y2-y1;
	dx34		=	x4-x3;
	dy34		=	y4-y3;
	h12_3	=	(long)dx12*(y3-y1)-(long)dy12*(x3-x1);
	h12_4	=	(long)dx12*(y4-y1)-(long)dy12*(x4-x1);
	if(h12_3>0 && h12_4>0)
	{
		return (pn);
	}
	if(h12_3<0 && h12_4<0)
	{
		return (pn);
	}
	
	h34_1	=	(long)dx34*(y1-y3)-(long)dy34*(x1-x3);
	h34_2	=	(long)dx34*(y2-y3)-(long)dy34*(x2-x3);
	if(h34_1>0 && h34_2>0)
	{
		return (pn);
	}
	if(h34_1<0 && h34_2<0)
	{
		return (pn);
	}
	
	det	=	h12_4  -  h12_3;
		s=0;
		if(D_Abs(dx12)<D_Abs(dy12))
		{
			s = 1;
		}
	
	if(det == 0) //parallel
	{
		max_min_x 				= 	D_Max(min_x12,min_x34);
		max_min_y 				= 	D_Max(min_y12,min_y34);
		min_max_x 				= 	D_Min(max_x12,max_x34);
		min_max_y 				= 	D_Min(max_y12,max_y34);
		jx0						=	max_min_x;
		jy0						=	max_min_y;
		jx1						=	min_max_x;
		jy1						=	min_max_y;
		if(dx12<0)
		{
			tmp_xy 				= 	jx0;
			jx0 				=	jx1;
			jx1					= 	tmp_xy;
		}
		
		if(dy12<0)
		{
			tmp_xy				=	jy0;
			jy0					=	jy1;
			jy1					=	tmp_xy;
		}
		same_xy = 0;
		if(jx0 == jx1 && jy0 == jy1)
		{
			same_xy = 1;
		}
		if(same_contour && same_xy)
		{
			return pn;
		}
	
		if(s==0)
		{
			D_itpt[pn].fz0 = jx0 - x1;
			D_itpt[pn].fm0 = dx12;
			D_itpt[pn].fz1 = jx0 - x3;
			D_itpt[pn].fm1 = dx34;
		}
		if(s==1)
		{
			D_itpt[pn].fz0 = jy0 - y1;
			D_itpt[pn].fm0 = dy12;
			D_itpt[pn].fz1 = jy0 - y3;
			D_itpt[pn].fm1 = dy34;
		}
		D_itpt[pn].pn0 = p0;
		D_itpt[pn].pn1 = p1;
		D_itpt[pn].x_in = jx0;
		D_itpt[pn].y_in = jy0;
		D_itpt[pn].x_fz = 0;
		D_itpt[pn].y_fz = 0;
		D_SimplifyInterPnt(&D_itpt[pn]);	// Simplify fz0(1),fm0(1)
		pn++;
		trns_memAddr += sizeof(D_INTERPNT);
		if(same_xy)
		{
			return (pn);
		}
		if(s==0)
		{
			D_itpt[pn].fz0 = jx1 - x1;
			D_itpt[pn].fm0 = dx12;
			D_itpt[pn].fz1 = jx1 - x3;
			D_itpt[pn].fm1 = dx34;
		}
		if(s==1)
		{
			D_itpt[pn].fz0 = jy1 - y1;
			D_itpt[pn].fm0 = dy12;
			D_itpt[pn].fz1 = jy1 - y3;
			D_itpt[pn].fm1 = dy34;
		}
		D_itpt[pn].pn0 = p0;
		D_itpt[pn].pn1 = p1;
		D_itpt[pn].x_in = jx1;
		D_itpt[pn].y_in = jy1;
		D_itpt[pn].x_fz = 0;
		D_itpt[pn].y_fz = 0;
		D_SimplifyInterPnt(&D_itpt[pn]);	// Simplify fz0(1),fm0(1)
	    pn++;
		trns_memAddr += sizeof(D_INTERPNT);
		return (pn);
	}
	
	if(same_contour)
	{
		return pn;
	}
	// The General Circumference.
	// By the presumption of MAX_DXYBITS,
	// following conversion is rational.
	fz0 = (short)((long)(x3-x1)*dy34 - (long)(y3-y1)*dx34);
	fz1 = (short)((long)(x3-x1)*dy12 - (long)(y3-y1)*dx12);
	fm  = (short)det;
	
	D_itpt[pn].fz0 = fz0;
	D_itpt[pn].fz1 = fz1;
	D_itpt[pn].fm0 = fm;
	D_itpt[pn].fm1 = fm;
	D_itpt[pn].pn0 = p0;
	D_itpt[pn].pn1 = p1;
	D_SimplifyInterPnt(&D_itpt[pn]);		// Simplify fz0(1),fm0(1)
		D_GetFSH(D_itpt[pn].fz0,D_itpt[pn].fm0,dx12,&fs);
		D_itpt[pn].x_in = x1 + fs.in;
		D_itpt[pn].x_fz = fs.fz;
		D_GetFSH(D_itpt[pn].fz0,D_itpt[pn].fm0,dy12,&fs);
		D_itpt[pn].y_in = y1 + fs.in;
		D_itpt[pn].y_fz = fs.fz;
	pn++;
	trns_memAddr += sizeof(D_INTERPNT);
return (pn);
}

short D_GetAllInterPnts(short * xyc, short num,short m_dx,short m_dy)
{
	short  		pn=0;
	short       u,v,cc;
	long		ad = D_memAddr;
	long		max_ad = MAX_MEMSIZE - (long)sizeof(D_INTERPNT)*4-num-4;
	short		ru;
	short		x1,y1,x2,y2;
	unsigned char *	flg = (unsigned char *)&D_pmem[max_ad-4];
	short		x[9],y[9],xy_num = 8,i,j;
	short		dx = m_dx/xy_num,
	            dy = m_dy/xy_num;

	if(max_ad<ad)
	{
		return -1;						// Actually,only flg cann't be used.
	}
		
	x[0] = 0;
	y[0] = 0;
	for(i=1;i<xy_num;i++)
	{
		x[i] = x[i-1] + dx;
		y[i] = y[i-1] + dy;
	}
	x[xy_num] = MAX_XXXX;
	y[xy_num] = MAX_YYYY;
		
	for(i=0;i<num;i++)
	{
		flg[i] = 0;
	}

	for(u=0;u<num;u++)
	{
		v = C_Next(xyc,u);
		x1 = c_ptx(xyc,u);
		y1 = c_pty(xyc,u);
		x2 = c_ptx(xyc,v);
		y2 = c_pty(xyc,v);
		for(i=0;i<xy_num;i++)
		for(j=0;j<xy_num;j++)
		if(x1>=x[i] && x1<x[i+1] &&
		   x2>=x[i] && x2<x[i+1] &&
		   y1>=y[j] && y1<y[j+1] &&
		   y2>=y[j] && y2<y[j+1])
		{
			flg[u] = (unsigned char)(i*xy_num+j) + 1;
			break;
		}
	}

	for(u=0;u<num;u++)
	{
		ru = C_Next(xyc,u);
		x1 = c_ptx(xyc,u);
		y1 = c_pty(xyc,u);
		x2 = c_ptx(xyc,ru);
		y2 = c_pty(xyc,ru);
		for(v=u+1;v<num;v++)
		{
			cc = 1;
			if(flg[u] && flg[v] && flg[u]!=flg[v])
			{
				cc = 0;
			}
			if(ad>=max_ad)
			{
				return -1;
			}
			if(cc)
			{
				pn = D_Get1InterPnt(xyc,u,ru,x1,y1,x2,y2,v,pn);
				ad += trns_memAddr;
			}
		}
	}

return pn;
}

short D_Greater(short 				in,
                short 				__fz,
                short 				__fm,
                D_SCANDATA *		m_scn,
                short 				pb,
                short 				ps)
// If return 1: V(pb) > V(ps); if return -1,V(pb)<V(ps);
// If return 0,equal.
{
	short 	x0,y0,x1,y1,dx,dy;
	short   u0,v0,u1,v1,du,dv;
	long	m  = (unsigned short)__fm;
	long	z  = (unsigned short)__fz;
	short	max_x,min_x,max_u,min_u;
	long	hx0,hx1,sv_hx0,sv_hx1,hh0,hh1;
	short	sgn_dv,sgn_dy,sgn;
	short	det,fz0;
	D_FSH	m_fsh;
	
	x0	=	m_scn[pb].x0;
	y0	=	m_scn[pb].y0;
	x1	=	m_scn[pb].x1;
	y1	=	m_scn[pb].y1;
	dx	=	x1 - x0;
	dy	=	y1 - y0;
	
	u0	=	m_scn[ps].x0;
	v0	=	m_scn[ps].y0;
	u1	=	m_scn[ps].x1;
	v1	=	m_scn[ps].y1;
	du	=	u1 - u0;
	dv	=	v1 - v0;

//_____________Special Simple Cases_____________
	
	max_x = D_Max(x0,x1);
	min_u = D_Min(u0,u1);
	if(max_x < min_u)
	{
		return -1;
	}
	
	min_x = D_Min(x0,x1);
	max_u = D_Max(u0,u1);
	if(min_x > max_u)
	{
		return 1;
	}
	
	if(min_x == max_x)		//x0 == x1
	if(min_u == max_u)		//u0 == u1
	{
		if(x0>u0)
		{
			return 1;
		}
		if(x0<u0)
		{
			return -1;
		}
		return 0;
	}
	
	// hx0 = x0 - (u0 + du/dv*(y0-v0))
	// hx1 = x1 - (u0 + du/dv*(y1-v0))
	// sgn_dv = D_Sgn(dv);
	sgn_dv = D_Sgn(dv);
	hx0  = dv * (long)(x0-u0) - du * (long)(y0-v0);
	hx1  = dv * (long)(x1-u0) - du * (long)(y1-v0);
	sv_hx0 = hx0;
	sv_hx1 = hx1;
	hx0 *= sgn_dv;
	hx1 *= sgn_dv;
	
	if(hx0 == 0)
	{
		if(hx1 > 0)
		{
			return 1;
		}
		if(hx1 < 0)
		{
			return -1;
		}
		return 0;
	}
	
	// now hx0!=0.
	if(hx1 == 0)
	{
		if(hx0 > 0)
		{
			return 1;
		}
		return -1;
	}
	
	// now,hx0!=0 and hx1!=0.
	if(hx0>0 && hx1>0)
	{
		return 1;
	}
	if(hx0<0 && hx1<0)
	{
		return -1;
	}
	
	// Now,hx0!=0 && hx1!=0 && hx0 hx1 with different signs.
	// So,there must be 1 and only one interpoint. We calculate
	// the y_coordinate of this interpoint following(Considering
	// abs(dx,dy,du,dv)<=MAX_DXYVALUE,not exceed 7-bits.
	det = (short)(sv_hx1 - sv_hx0);		//dx*dv-dy*du.
	fz0 = (short)((long)(u0-x0)*dv - (long)(v0-y0)*du);
	if(det<0)
	{
		det = -det;
		fz0 = -fz0;
	}
	
	// Now,det>0 and 0<=fz0<det,for y0<inter_y<y1.We will compare
	// m_fsh.in + m_fsh.fz/det with in + fz/fm.
	D_GetFSH(fz0,det,dy,&m_fsh);
	m_fsh.in += y0;
	sgn_dy = D_Sgn(dy);
	sgn    = D_Sgn(in-m_fsh.in);
	if(sgn==0)
	{
		hh0  = z * m_fsh.fm;
		hh1  = m * m_fsh.fz;
		if(hh0>hh1)
		{
			sgn = 1;
		}
		if(hh0<hh1)
		{
			sgn = -1;
		}
		if(hh0 == hh1)
		{
		 	sgn = 0;
		}
	}
	
	if(sgn == 0)					// While interpoint_y == in + fz/fm,
	{								// the x coordis of them must be equal.
		return 0;
	}
	
	if(sgn == sgn_dy)				// return value is sign of hx1
	{
		if(hx1>0)
		{
			return 1;	
		}
		return -1;
	}
	
	// Now,return sign of hx0.	
	if(hx0>0)
	{
		return 1;
	}

return -1;
}

char D_SelectFlag(D_SCANDATA * m_scn, short cn,char sn)
{
	short 	sum = 0;
	short	w;
	
	for(w=0;w<cn;w++)
	{
		sum += m_scn[w].sn;
	}
	if(m_scn[cn].sn == sn && sum==0)
	{
		return 1;
	}
	if(m_scn[cn].sn == -sn && sum == sn)
	{
		return 1;
	}

return 0;
}

char  D_Scan1(short 			cp, 
              short * 		xyc, 	
              short 			num,
			  short 			scn_dir,  	
			  D_SCANXY* 		scn_xy,
			  D_SCANDATA * 	m_scn,
			  long 				max_scan_num)
// return scn_flg; if scn_flg==1,select; 
// 0: not select; -1: error.
{
	short		in,fz,fm;
	short 		w,p,i,x0,y0,x1,y1,scn_num,pn;
	char		macro_sn,sn;
	short		ccc,mp;
	short		great_flag;
	D_FSH		fs;
	char		rt_value;
	short		stop_x = D_Max(scn_xy[0].yx0,scn_xy[0].yx1)+1;
	
	
	D_GetBetweenValue(scn_xy,&fs);

//	scn_xy[0].it_xy0, scn_xy[0].it_xy1,
//	                  scn_xy[0].it_fz0, scn_xy[0].it_fm0,
//	                  scn_xy[0].it_fz1, scn_xy[0].it_fm1,&fs);
	in = fs.in;
	fz = fs.fz;
	fm = fs.fm;

		if(D_Min(scn_xy[0].xy0,scn_xy[0].xy1) > in || 
		   D_Max(scn_xy[0].xy0,scn_xy[0].xy1) <= in)
		{
			return -1;						// cp will not be taken following.
		}

		scn_num = 0;
		for(w=0;w<num;w++)
		{
			if(scn_num >= max_scan_num)
			{
				return -1;
			}
			p  = C_Next(xyc,w);
			x0 = c_ptx(xyc,w);
			y0 = c_pty(xyc,w);
			x1 = c_ptx(xyc,p);
			y1 = c_pty(xyc,p);

			if(scn_dir == 0) // Hor
			if(D_Min(x0,x1) < stop_x)
			if(D_Min(y0,y1) <= in && D_Max(y0,y1)>in)
			{
				m_scn[scn_num].x0 	= x0;
				m_scn[scn_num].y0 	= y0;
				m_scn[scn_num].x1 	= x1;
				m_scn[scn_num].y1 	= y1;
				m_scn[scn_num].sn	= D_Sgn(y1-y0);
				m_scn[scn_num].pn   = w;
				scn_num++;
			}
			if(scn_dir == 1) // Vir,transform to be Hor formally.
			if(D_Min(y0,y1) < stop_x)
			if(D_Min(x0,x1) <= in && D_Max(x0,x1)>in)
			{
				m_scn[scn_num].x0	= y0;
				m_scn[scn_num].y0	= x0;
				m_scn[scn_num].x1   = y1;
				m_scn[scn_num].y1	= x1;
				m_scn[scn_num].sn   = D_Sgn(x1-x0);
				m_scn[scn_num].pn   = w;
				scn_num++;
			}
		}
	//___________Order m_scn by formal y_values__________
	macro_sn = LEFT_Y_SIGN;
	if(scn_dir == 1)
	{
		macro_sn = UP_X_SIGN;
	}
	
	for(w=0;w<scn_num;w++)
	{
		p = w;
		for(i=w+1;i<scn_num;i++)
		{
			great_flag = D_Greater(in,fz,fm,m_scn,p,i);
		    if(great_flag == 1)
		    {
		    	p = i;
		    }
		    if(great_flag == 0)
		    {
		    	if(m_scn[i].sn == m_scn[p].sn)
		      	if(m_scn[i].pn<m_scn[p].pn)
				{
					p = i;
				}
				if(m_scn[i].sn == -m_scn[p].sn)
				if(m_scn[i].sn == macro_sn)
				{
					p = i;
				}
			}
		}
		x0 			= m_scn[w].x0;
		y0 			= m_scn[w].y0;
		x1 			= m_scn[w].x1;
		y1 			= m_scn[w].y1;
		pn 			= m_scn[w].pn;
		sn 			= m_scn[w].sn;
		
		m_scn[w].x0	= m_scn[p].x0;
		m_scn[w].y0	= m_scn[p].y0;
		m_scn[w].x1	= m_scn[p].x1;
		m_scn[w].y1	= m_scn[p].y1;
		m_scn[w].pn	= m_scn[p].pn;
		m_scn[w].sn	= m_scn[p].sn;
		
		m_scn[p].x0	= x0;
		m_scn[p].y0	= y0;
		m_scn[p].x1	= x1;
		m_scn[p].y1	= y1;
		m_scn[p].pn	= pn;
		m_scn[p].sn	= sn;
	}

	// To Decide the Select-Flag of cp.
	
	ccc = -1;
	for(i=0;i<scn_num;i++)
	if(m_scn[i].pn == cp)
	{
		ccc = i;
		break;
	}
	////ASSERT(ccc!=-1);
	rt_value = D_SelectFlag(m_scn,ccc,macro_sn);
	if(rt_value == 0)
	{
		return 0;
	}
	
		mp = -1;
		if(m_scn[ccc].sn == macro_sn) // Left side.
		{
			for(i=ccc+1;i<scn_num;i++)
			if(m_scn[i].sn == -macro_sn && D_SelectFlag(m_scn,i,macro_sn))
			{
				mp = i;
				break;
			}
		}
		if(m_scn[ccc].sn == -macro_sn) // Right side.
		{
			for(i=ccc-1;i>=0;i--)
			if(m_scn[i].sn == macro_sn && D_SelectFlag(m_scn,i,macro_sn))
			{
				mp = i;
				break;
			}
		}
		//ASSERT(mp!=-1);
		
		if(mp!=-1)
		{
			if(D_Greater(in,fz,fm,m_scn,ccc,mp)==0)
			rt_value = 0;
		}

return rt_value;
}

void D_SetLeftFlag(D_INTERPNT * ip, 
				   short pp, 				// ip[pp] be set.
				   short cc, 				// if(cc==0),ip[pp].pn0 be set.else pn1.
				   unsigned char flg)
{
		flg 	= 	(flg<<2);
		if(cc)
		{
			flg	=	(flg<<4);
		}
		ip[pp].flg += flg;
return;
}

void D_SetRghtFlag(D_INTERPNT * ip, 
				   short pp, 				// ip[pp] be set.
				   short cc, 				// if(cc==0),ip[pp].pn0 be set.else pn1.
				   unsigned char flg)
{
		if(cc)
		{
			flg	=	(flg<<4);
		}
		ip[pp].flg += flg;
return;
}


void D_SetSomeLeftRghtFlags(D_INTERPNT * ip,
              D_RECD     * m_rd,
              short      recd_num,
              short		 cp,
              unsigned   char flag,
              short		 left_rght)
{
	short 	i;
	short	fz=m_rd[cp].fz, fm=m_rd[cp].fm;
	
	for(i=cp-1;i>=0;i--)
	{
		if(D_FSHGreater(fz,fm, m_rd[i].fz,m_rd[i].fm)==0)
		{
			if(left_rght == 0) 	// Left
			D_SetLeftFlag(ip,m_rd[i].pn,m_rd[i].cc,flag);
			else				//Right.
			D_SetRghtFlag(ip,m_rd[i].pn,m_rd[i].cc,flag);
		}
		else
		break;
	}
	for(i=cp;i<recd_num;i++)
	{
		if(D_FSHGreater(fz,fm,m_rd[i].fz,m_rd[i].fm)==0)
		{
			if(left_rght == 0) 	// Left
			D_SetLeftFlag(ip,m_rd[i].pn,m_rd[i].cc,flag);
			else				//Right.
			D_SetRghtFlag(ip,m_rd[i].pn,m_rd[i].cc,flag);
		}
		else
		break;
	}
return;
}

unsigned char D_GetLeftFlag(
                   D_INTERPNT * ip, 
				   short pp, 				// get ip[pp] .
				   short cc) 				// if(cc==0),to get ip[pp].pn0,else pn1.
{
	unsigned char flg;		
		
		flg 	= 	ip[pp].flg;
		if(cc)
		{
			flg = (flg>>4);
		}
		else
		{
			flg = (flg & 15);
		}
		flg = (flg>>2);
		
return flg;
}

unsigned char D_GetRghtFlag(
                   D_INTERPNT * ip, 
				   short pp,
				   short cc)
// Similar to D_GetLeftFlag.
{
	unsigned char flg;
	
		flg		=	ip[pp].flg;
		
		if(cc)
		{
			flg	=	(flg>>4);
		}
		else
		{
			flg =   (flg & 15);
		}
		flg = (flg & 3);
return flg;
}

short D_ScanAllInterPnts(short * xyc, 		short num,
                        D_INTERPNT * ip,		short ipn)
// The destination of Scanning is to valuate 
// D_itpt[].flg.if return 0,error; else return 1.
{
	long				ad	  = D_memAddr,
	                    ad0   = D_memAddr;
	D_RECD     *		m_rd;
	D_SCANDATA *		m_scn;
	short				w,i,n,p,k,fz,fm,pn; 
	char 				cc;
	short				size0 = sizeof(D_RECD);
	long				max_scan_num;
	D_SCANXY			scn_xy;
	short				x0,y0,x1,y1;
	short				fz0,fm0,fz1,fm1;
	short				it_xy0,it_fz0,it_fm0,
	                    it_xy1,it_fz1,it_fm1,it;
	short				scn_dir; 					//0: hor; 1: vir.
	char				scn_flg;
	unsigned char		left_flag,rght_flag;

	for(i=0;i<ipn;i++)
	{
		if(ip[i].fm0<0)
		{
			ip[i].fm0 = -ip[i].fm0;
			ip[i].fz0 = -ip[i].fz0;
		}
		if(ip[i].fm1<0)
		{
			ip[i].fm1 = -ip[i].fm1;
			ip[i].fz1 = -ip[i].fz1;
		}
		if(ip[i].fz0<0 || ip[i].fz0>ip[i].fm0 || ip[i].fm0==0)
		{
			return 0;
		}
		if(ip[i].fz1<0 || ip[i].fz1>ip[i].fm1 || ip[i].fm1==0)
		{
			return 0;
		}
		if(ip[i].pn0 <0 || ip[i].pn0 >= num ||
		   ip[i].pn1 <0 || ip[i].pn1 >= num)
		{
			return 0;
		}
 	}
 	for(i=0;i<ipn;i++)
 	{
 		ip[i].flg = 0;
 	}

	m_rd = (D_RECD *)&D_pmem[ad0];
	for(w=0;w<num;w++)
	{
 		x0 = c_ptx(xyc,w);
 		y0 = c_pty(xyc,w);
 		i  = C_Next(xyc,w);
 		x1 = c_ptx(xyc,i);
 		y1 = c_pty(xyc,i);
 		if(x0 == x1  &&  y0 == y1)
 		{
			return 0;		// This is impossible for D_Elimi().
		}
		scn_dir = 0;	// Hor.
		scn_xy.yx0 = x0;
		scn_xy.yx1 = x1;
		if(D_Abs(y1-y0)<D_Abs(x1-x0))
		{
			scn_dir = 1; // Vir.
			scn_xy.yx0 = y0;
			scn_xy.yx1 = y1;
			y0 = x0;
		 	y1 = x1;
		 }
		scn_xy.xy0 = y0;
		scn_xy.xy1 = y1;
		
		//______Get m_itpt[] for w______
		 
		n = 0;
		for(i=0;i<ipn;i++)
		{
			if(ad+64>=MAX_MEMSIZE)
			{
				return 0;
			}
			if(ip[i].pn0 == w)
			{
				m_rd[n].pn = i;
				m_rd[n].cc = 0;
				m_rd[n].fz = ip[i].fz0;
				m_rd[n].fm = ip[i].fm0;
				n++;
				ad  += size0;
			}
			if(ip[i].pn1 == w)
			{
				m_rd[n].pn = i;
				m_rd[n].cc = 1;
				m_rd[n].fz = ip[i].fz1;
				m_rd[n].fm = ip[i].fm1;
				n++;
				ad  += size0;
			}
		}
		if(n)	
		{//_____________________Dispose w_______________________________________
		 	for(k=0;k<n;k++)			// Order by fz/fm.
		 	{
		 		p = k;
		 		for(i=k+1;i<n;i++)
		 		{
		 			if(D_FSHGreater(m_rd[p].fz,m_rd[p].fm,
		 			                m_rd[i].fz,m_rd[i].fm) == 1)
		 			{
		 				p = i;
		 			}
		 		}
				fz 			= m_rd[k].fz;
				fm 			= m_rd[k].fm;
				pn 			= m_rd[k].pn;
				cc 			= m_rd[k].cc;
						
				m_rd[k].fz 	= m_rd[p].fz;
				m_rd[k].fm 	= m_rd[p].fm;
				m_rd[k].pn	= m_rd[p].pn;
				m_rd[k].cc	= m_rd[p].cc;
						
				m_rd[p].fz	= fz;
				m_rd[p].fm	= fm;
				m_rd[p].pn	= pn;
				m_rd[p].cc	= cc;
		 	}
		 	
		 	ad = ad0 + (long)sizeof(D_RECD) * n;
		 	m_scn = (D_SCANDATA *)&D_pmem[ad];
		 	max_scan_num = (MAX_MEMSIZE-ad-64)/sizeof(D_SCANDATA);
		 	
			fz0 = 0;
			fm0 = 1;
			it_xy0 = y0;
			it_fz0 = 0;
			it_fm0 = 1;
			for(k=0;k<=n;k++)
			{	
		 		// Calculate scn_xy,which make 
		 		// (scn_xy.fz/scn_xy.fm) not 
		 		// be integer.
		 		// Now,scn_xy should between xy0,xy1.
		 		// where,xy0 = m_rd[k].fz/fm,xy1=m_rd[k+1].fz/fm;
		 		if(k<n)
		 		{
		 			fz1 = m_rd[k].fz;
		 			fm1 = m_rd[k].fm;
		 			it     = m_rd[k].pn;
		 			if(scn_dir==0) // take y_coordi
		 			{
		 				it_xy1 = ip[it].y_in;
		 				it_fz1 = ip[it].y_fz;
		 				it_fm1 = ip[it].fm0;
		 			}
		 			else
		 			{
		 			 	it_xy1 = ip[it].x_in;
		 			 	it_fz1 = ip[it].x_fz;
		 			 	it_fm1 = ip[it].fm0;
		 			}
		 		}
		 		if(k==n)
		 		{
		 			fz1 = 1;
		 			fm1 = 1; 
		 			it_xy1 = y1;
		 			it_fz1 = 0;
		 			it_fm1 = 1;
		 		}
		 		if(D_FSHGreater(fz0,fm0,fz1,fm1)==-1)
		 		{
		 			scn_xy.fz0 = fz0;
		 			scn_xy.fm0 = fm0;
		 			scn_xy.fz1 = fz1;
		 			scn_xy.fm1 = fm1;
		 			scn_xy.it_xy0 = it_xy0;
		 			scn_xy.it_fz0 = it_fz0;
		 			scn_xy.it_fm0 = it_fm0;
		 			scn_xy.it_xy1 = it_xy1;
		 			scn_xy.it_fz1 = it_fz1;
		 			scn_xy.it_fm1 = it_fm1;
		 			scn_flg = D_Scan1(w,
		 			                  xyc,num,
		 			                  scn_dir,&scn_xy,
		 			                  m_scn,
		 			                  max_scan_num);
		 			//scn_flg==1,select; 0: not select; -1: error.
		 			if(scn_flg<0)
		 			{
		 				return 0;
		 			}
		 		  //________Value ip[].flg by m_scn_______ 
						// Right Flag belongs to k-1.
						// Left  Flag belongs to k.
						// Every Flag takes 2_bits.
					left_flag 	= (1 + (unsigned char)scn_flg);
		 		  	rght_flag 	= (1 + (unsigned char)scn_flg);
		 		  	if(k<n)		// Set Left_flags by k.
		 		  	{
		 		  		D_SetSomeLeftRghtFlags(ip,m_rd,n,k,left_flag,0);
		 		  	}
		 		  	if(k>0)		// Set Right_Flag by k-1.
		 		  	{
		 		  		D_SetSomeLeftRghtFlags(ip,m_rd,n,k-1,rght_flag,1);
		 		  	}
		 		  //_______________________________________
		 			
		 		}
		 		fz0 = fz1;
		 		fm0 = fm1;
		 		it_xy0 = it_xy1;
		 		it_fz0 = it_fz1;
		 		it_fm0 = it_fm1;
		 	}
		}//______________end of disposing w____________________________
	}
return 1;
}

short D_SameInterXY(short p0,  char f0,
				    short p1,  char f1,
				    D_INTERPNT * ip)
{
	short 	x_in0 = ip[p0].x_in,
		    x_fz0 = ip[p0].x_fz;
	short	y_in0 = ip[p0].y_in,
	        y_fz0 = ip[p0].y_fz;
	short	x_in1 = ip[p1].x_in,
	        x_fz1 = ip[p1].x_fz;
	short	y_in1 = ip[p1].y_in,
	        y_fz1 = ip[p1].y_fz;
	short	fm0   = ip[p0].fm0;
	short	fm1   = ip[p1].fm0;
	
	if(x_in0 != x_in1)								return 0;
	if(y_in0 != y_in1)								return 0;
	
	if(D_FSHGreater(x_fz0,fm0, x_fz1,fm1)!=0)		return 0;
	if(D_FSHGreater(y_fz0,fm0, y_fz1,fm1)!=0)	    return 0;

return 1;
}

void D_Corner(short dx0, short dy0,			// The first vector.
              short dx1, short dy1,
              D_CORNER* cnr)
{
	long	im,vm;		//Inner_Multiple and Vector_Multiple.
	long	h;
	
	im = dx0 * (long) dx1 + dy0 * (long)dy1;
	vm = dx0 * (long) dy1 - dy0 * (long)dx1;
	
	cnr[0].c180 = 0;
	cnr[0].c90  = 0;
	cnr[0].fz   = 0;
	cnr[0].fm   = 1;
	
	if(vm==0)	//0 or 180
	{
		if(im>0)	// 0.
		{
			return;
		}
		if(im<0)
		{
			cnr[0].c180 = 1;
			return;
		}
		
		////ASSERT(im);
		if(im==0) //error.		
		{
			////m__pDC->TextOut(100,100,"Error in D_Corner()!");
			return;
		}
	}
	if(im==0)	//90 or 270.
	{
		if(vm>0)
		{
			cnr[0].c90 = 1;
			return;
		}
		if(vm<0)
		{
			cnr[0].c180 = 1;
			cnr[0].c90  = 1;
			return;
		}
		return;
	}
	
	if(vm<0)	// >=180.
	{
		cnr[0].c180 = 1;
		// Cal siny,cosy,where y = x-180.
		// sin(y) = sin(x-180) = -sinx.
		// cos(y) = cos(x-180) = -cosx.
		im = -im;
		vm = -vm;
	}
	
	// Now, x<180.
	if(im<0)		//>=90.
	{
		cnr[0].c90 = 1;
		// sin(y) = sin(x-90) = -cos(x);
		// cos(y) = cos(x-90) =  sin(x);
		h  = vm;
		vm = -im;
		im =  h;
	}
	// Now,cnr>=0 && cnr<90.we cal tg(x) = vm/im;
	cnr[0].fz = vm;
	cnr[0].fm = im;

return;
}

char D_GreaterCorner(D_CORNER cn0, D_CORNER cn1)
{
	char 	sn;
	long	h0,h1;
	char	ANTI_CLOCK = LEFT_Y_SIGN * UP_X_SIGN;
	
	sn = D_Sgn(cn0.c180 - cn1.c180);
	if(sn)
	{
		sn *= ANTI_CLOCK;
		return sn;
	}
	
	sn = D_Sgn(cn0.c90 - cn1.c90);
	if(sn)
	{
		sn *= ANTI_CLOCK;
		return sn;
	}
	
	h0 = cn0.fz * (long) cn1.fm;
	h1 = cn0.fm * (long) cn1.fz;
	
	if(h0>h1)
	{
		return ANTI_CLOCK;
	}
	if(h0<h1)
	{
		return -ANTI_CLOCK;
	}

return 0;
}

char D_AntiExist(D_INTERPNT * 	ip,
                 short 				w,
                 char 				flag_01,
                 short 				anti_num)
{
	char  	g_01;
	short 	i,p0_0,p0_1;
	
	
	for(i=0;i<anti_num;i++)
	{
		g_01 = (char)(D_anti[i].flg & 1);
		if(flag_01 == 0)
		{
			p0_0 = ip[w].pn0;
		}
		else
		{
			p0_0 = ip[w].pn1;
		}
		
		p0_1 = D_anti[i].pn;
		if(g_01 == 0)
		{
			p0_1 = ip[p0_1].pn0;
		}
		else
		{
			p0_1 = ip[p0_1].pn1;
		}
		if(p0_0 == p0_1)
		{
			if(D_SameInterXY(w,flag_01,D_anti[i].pn, g_01,ip))
			{
				return 1;
			}
		}
	}

return 0;
}

short D_Get1Antipode(short				pp,
                     char				flag_01,
                     short				anti_num,
                     short * 		xyc,
                     D_INTERPNT *	ip,
                     short				ipn)
//if(Error),return -1; else,return new anti_num.
{
	short		w;
	short		max_rdn  = 200;
	short		rd[200];
	short		rdn=0;
	char		fi;
	short		dx0,dy0,dx1,dy1;
	short		cp,dp,rp,p;
	D_CORNER	cnr,cmr;
	char		greater_cc;
	
	D_anti[anti_num].flg = flag_01;
	D_anti[anti_num].pn  = pp;
	
	for(w=0;w<ipn;w++)	// all ip[],with interXY as ip[pp] and with Flag(p+)==Select.
	for(fi=0;fi<2;fi++)
	if(D_GetRghtFlag(ip,w,fi)>1)
	if(D_SameInterXY(pp,flag_01,w,fi,ip))
	{
		if(rdn>=max_rdn)
		{
			return -1;
		}
		rd[rdn] = ((unsigned short)w<<1) + (unsigned short)fi;
		rdn++;
	}
	if(rdn==0)
	{
		return -1;
	}
	
	if(rdn==1)
	{
		D_anti[anti_num].flg += ((char)(rd[0] & 1)<<1);
		D_anti[anti_num].ap   = ((short)(rd[0]>>1));
		anti_num ++;
		return anti_num;
	}
	
	//___Now,rdn>1,We get the smallest member recorded in ____
	//___rd[] By the Macro definition ANTI_CLOCK_______
	if(flag_01 == 0)
	{
		cp	=	ip[pp].pn0;
	}
	else
	{
		cp	=	ip[pp].pn1;
	}
	rp	=  	C_Next(xyc,cp);
	dx0 = 	c_ptx(xyc,cp) - c_ptx(xyc,rp);
	dy0 = 	c_pty(xyc,cp) - c_pty(xyc,rp);


	p  = 0;
	fi = (char)(rd[p] & 1);
	cp = (short)(rd[p]>>1);
	if(fi==0)
	{
		cp = ip[cp].pn0;
	}
	else
	{
		cp = ip[cp].pn1;
	}
	rp = C_Next(xyc,cp);
	dx1 = c_ptx(xyc,rp) - c_ptx(xyc,cp);
	dy1 = c_pty(xyc,rp) - c_pty(xyc,cp);
	D_Corner(dx0,dy0,dx1,dy1,&cnr);
	for(w=1;w<rdn;w++)
	{
		fi = (char)(rd[w] & 1);
		dp = (short)(rd[w]>>1);
		if(fi==0)
		{
			dp = ip[dp].pn0;
		}
		else
		{
			dp = ip[dp].pn1;
		}
		rp = C_Next(xyc,dp);
		dx1 = c_ptx(xyc,rp) - c_ptx(xyc,dp);
		dy1 = c_pty(xyc,rp) - c_pty(xyc,dp);
		D_Corner(dx0,dy0,dx1,dy1,&cmr);
		greater_cc = D_GreaterCorner(cnr,cmr);		// USE ANTI_CLOCK.
		if( greater_cc == 1 || 
		   (greater_cc == 0 && dp<cp) )
		{

////if(!greater_cc)
////{
////m__pDC->TextOut(200,200,"SameCorner()!");
////}
			cp	= dp;
			cnr = cmr;
			p   = w;
		}
	}
	D_anti[anti_num].flg += ((char)(rd[p] & 1)<<1);
	D_anti[anti_num].ap   = ((short)(rd[p]>>1));
	anti_num ++;

return anti_num;
}

short D_GetAllAntipodes(short *			xyc,
						D_INTERPNT * 	ip, 
                        short 				ipn,
                        long				max_anti_num)
// If return -1,error;else,return the count of antipodes
// generated in this function. Only those interPnt which
// have Flag(p-) = Selected be considered.
{
	short 		anti_num = 0;
	short		w;
	char		flag_01;
	for(w=0;w<ipn;w++)
	{
		flag_01 = 0;
		if(D_GetLeftFlag(ip,w,flag_01)>1)
		if(!D_AntiExist(ip,w,flag_01,anti_num))
		{
			if(anti_num>=max_anti_num)
			{
				return -1;
			}
			anti_num = 	D_Get1Antipode(w,flag_01,anti_num,xyc,ip,ipn);
			if(anti_num<0)
			{
				return -1;
			}
		}
		flag_01 = 1;
		if(D_GetLeftFlag(ip,w,flag_01)>1)
		if(!D_AntiExist(ip,w,flag_01,anti_num))
		{
			if(anti_num>=max_anti_num)
			{
				return -1;
			}
			anti_num = 	D_Get1Antipode(w,flag_01,anti_num,xyc,ip,ipn);
			if(anti_num<0)
			{
				return -1;
			}
		}
	}
return anti_num;
}


//_______________________D_MapAntipodes()_______________________________

void D_BeforeMapping(short * 		xyc,  	short xycn,
                     short * 		nxyc, 	short nxycn,
                     D_INTERPNT *	ip,		short ipn)
{
	short	w,be,nd;
	short	cc,i,p0;
	
	for(i=0;i<xycn;i++)
	{
		be = i;
		nd = D_Nd(xyc,i);
		i  = nd;
		D_ptc(xyc,nd) -= (D_ptc(xyc,nd) & BNOINTER_FLAG);
	}
	
	for(w=0;w<nxycn;w++)
	{
		be = w;
		nd = C_Nd(nxyc,w);
		w  = nd;
		cc = 0;
		for(i=0;i<ipn;i++)
		if( (ip[i].pn0 >= be && ip[i].pn0 <= nd) ||
		    (ip[i].pn1 >= be && ip[i].pn1 <= nd) )
		{
			cc = 1;
			break;
		}
		if(!cc)
		{
			p0 = c_ptr(nxyc,be);
			p0 = D_Nd(xyc,p0);
			D_ptc(xyc,p0)  |= BNOINTER_FLAG;
		}
	}
return;
}

short D_MapAntipode(short *		xyc0,
					short * 		xyc,
	          	    D_INTERPNT *	ip,	short ipn,
	          		D_ANTIPODE * at,	short atn)
// If return -1,error; else return the count of mapped_antipode.
{
	long	max_map_num = (MAX_MEMSIZE - 64 - D_memAddr)/sizeof(D_MAPANTI);
	short			w,p0,p1,r0,r1;
	char			f0,f1;
	short			x0,y0;
	unsigned char 	fz,fm;
	short			hlf;
	
		if(max_map_num < atn)
		{
			return -1;
		}

	for(w=0;w<atn;w++)
	{
		f0 = (at[w].flg & 1);
		f1 = ((at[w].flg & 2)>>1);
		p0 = at[w].pn;
		p1 = at[w].ap;
		
		if(f0==0)
		{
			D_map[w].p0		=	ip[p0].pn0;
			D_map[w].n_fz0	=	ip[p0].fz0;
			D_map[w].n_fm0	=	ip[p0].fm0;
		}
		else
		{
			D_map[w].p0		=	ip[p0].pn1;
			D_map[w].n_fz0	=	ip[p0].fz1;
			D_map[w].n_fm0	=	ip[p0].fm1;
		}
		hlf = (short)( ((long)ip[p0].fm0 + 1)>>1 );
		x0 = ip[p0].x_in;
			if(ip[p0].x_fz >= hlf) x0++;
		y0 = ip[p0].y_in;
			if(ip[p0].y_fz >= hlf) y0++;
		p0 = D_map[w].p0;
		fz  = (unsigned char)( (unsigned short)c_ptc(xyc,p0)>>9);
		fm  = (unsigned char)( ((unsigned short)c_ptc(xyc,p0)>>2) & 127);
		D_map[w].p0 = c_ptr(xyc,p0);
		D_map[w].c_fz0 = fz;
		D_map[w].c_fm0 = fm;
		
		if(f1==0)
		{
			D_map[w].p1		=	ip[p1].pn0;
			D_map[w].n_fz1	=	ip[p1].fz0;
			D_map[w].n_fm1	=	ip[p1].fm0;
		}
		else
		{
			D_map[w].p1		=	ip[p1].pn1;
			D_map[w].n_fz1	=	ip[p1].fz1;
			D_map[w].n_fm1	=	ip[p1].fm1;
		}
		p1 = D_map[w].p1;
		fz  = (unsigned char)( (unsigned short)c_ptc(xyc,p1)>>9);
		fm  = (unsigned char)( ((unsigned short)c_ptc(xyc,p1)>>2) & 127);
		D_map[w].p1 = c_ptr(xyc,p1);
		D_map[w].c_fz1 = fz;
		D_map[w].c_fm1 = fm;
		
		// For horizontal and virtial lines,the coordis needed to 
		// adjust.
		p0 = D_map[w].p0;
		p1 = D_map[w].p1;
		r0 = D_Next(xyc0,p0);		
		r1 = D_Next(xyc0,p1);
		D_map[w].flg_xy = 0;
		if(D_ptx(xyc0,p0) == D_ptx(xyc0,r0))		//Virtical
		{
			if(D_ptc(xyc0,r0) & BON_FLAG)			//Line
			{
				x0 = D_ptx(xyc0,p0);
				D_map[w].flg_xy |= 1;
			}
		}
		else if(D_ptx(xyc0,p1) == D_ptx(xyc0,r1))	//Vir
		{
			if(D_ptc(xyc0,r1) & BON_FLAG)			//Line
			{
				x0 = D_ptx(xyc0,p1);
				D_map[w].flg_xy |= 1;
			}
		}
		
		if(D_pty(xyc0,p0) == D_pty(xyc0,r0))		//Hor
		{
			if(D_ptc(xyc0,r0) & BON_FLAG)			//Line
			{
				y0 = D_pty(xyc0,p0);
				D_map[w].flg_xy |= 2;
			}
		}
		else if(D_pty(xyc0,p1) == D_pty(xyc0,r1))		//Hor
		{
			if(D_ptc(xyc0,r1) & BON_FLAG)			//Line
			{
				y0 = D_pty(xyc0,p1);
				D_map[w].flg_xy |= 2;
			}
		}
		D_map[w].ipx = x0;
		D_map[w].ipy = y0;
	}
	
return atn;
}


void D_OrderMapByP0Prms(D_MAPANTI * map, short map_num)
// If map[i].p0 == map[j].p0 and i<j; we will make
// map[i].t0<map[j].t0 in this function.
{
	D_MAPANTI		tmp_map;
	short			end_cc;
	short			i,j;
	
	end_cc = 0;
	while(!end_cc)
	{
		end_cc = 1;
		for(i=0;i<map_num;i++)
		for(j=i+1;j<map_num;j++)
		if(map[i].p0==map[j].p0)
		if(D_GreaterLongFSH(map[i].c_fz0, map[i].c_fm0,
		                    map[i].n_fz0, map[i].n_fm0,
		                    map[j].c_fz0, map[j].c_fm0,
		                    map[j].n_fz0, map[j].n_fm0)==1) //prm(i)>prm(j)
		{
			end_cc  	= 0;
			tmp_map 	= map[i];
			map[i]		= map[j];
			map[j]		= tmp_map;
			i = map_num;
			j = map_num;
		}
	}

return;
}

//_______________________Complete Contours____________________________
short D_GetMapPNum(short 			be,		short nd,
                   D_MAPANTI *	map,	
                   char *		not_used,
                   short			map_num)
{
	short	i;
	
	for(i=0;i<map_num;i++)
	if(not_used[i])
	if(map[i].p0 >=be && map[i].p0<=nd)
	{
		return i;
	}

return -1;
}

short B1_GetMapPNum(short 			pp,
                   D_MAPANTI *	map,	
                   short			map_num)
{
	short	i;
	
	for(i=0;i<map_num;i++)
	if(map[i].p0 == pp)
	{
		return i;
	}
return -1;
}

short D_Save1Member( short * 		xyc0, 
			         short * 		xyc1,	short num,
                     short 				p0,
               		 unsigned char 		c_fz0,	
               		 unsigned char    	c_fm0,
               		 short				n_fz0,
               		 short				n_fm0,
			   
               		 unsigned char 		c_fz1,	
               		 unsigned char    	c_fm1,
               		 short				n_fz1,
               		 short				n_fm1,
               		 long 				max_num,
               		 short				x0,
               		 short				y0,
               		 short				x1,
               		 short				y1,
               		 char				fxy0,
               		 char				fxy1)
{
	D_BEZIER	bz;

	////ASSERT((D_ptc(xyc0,p0) & BON_FLAG));
	D_GetBezier(xyc0,p0,&bz);
	D_FJBezier(&bz,c_fz0,c_fm0,n_fz0,n_fm0,
	               c_fz1,c_fm1,n_fz1,n_fm1,x0,y0,x1,y1,fxy0,fxy1);
	if(num+3>=max_num)
	{
		return -1;
	}
	num = D_SaveBezier(bz,xyc1,num);
	
return num;
}

short D_Save1Segment(short * 		xyc0, 
			         short * 		xyc1,	short num,
                     short 				p0,
               		 unsigned char 		c_fz0,	
               		 unsigned char    	c_fm0,
               		 short				n_fz0,
               		 short				n_fm0,
			   
			   		 short				p1,
               		 unsigned char 		c_fz1,	
               		 unsigned char    	c_fm1,
               		 short				n_fz1,
               		 short				n_fm1,
               		 long 				max_num,
               		 short				x0,
               		 short				y0,
               		 short				x1,
               		 short				y1,
               		 char				fxy0,
               		 char				fxy1)
{
	short		rp = D_NextOn(xyc0,p0);
	short		a0,b0,a1,b1;
	
	////ASSERT((D_ptc(xyc0,p1) & BON_FLAG));
    a1 = D_ptx(xyc0,rp);
	b1 = D_pty(xyc0,rp);
	num = D_Save1Member(xyc0,xyc1,num,p0,c_fz0,c_fm0,n_fz0,n_fm0,
	                                     1,1,0,1,max_num,
	                                     x0,y0,
	                                     a1,b1,fxy0,0);
	if(num<0)
	{
		return -1;
	}
	p0 = D_NextOn(xyc0,p0);
	while(p0!=p1)
	{
		rp = D_NextOn(xyc0,p0);
    	a0 = D_ptx(xyc0,p0);
		b0 = D_pty(xyc0,p0);
    	a1 = D_ptx(xyc0,rp);
		b1 = D_pty(xyc0,rp);
		num = D_Save1Member(xyc0,xyc1,num,p0, 0,1,0,1,
		                                      1,1,0,1,max_num,
		                                      a0,b0,a1,b1,0,0);
		if(num<0) 
		{
			return -1;
		}
		p0 = D_NextOn(xyc0,p0);
	}
  	a0 = D_ptx(xyc0,p1);
	b0 = D_pty(xyc0,p1);
	num = D_Save1Member(xyc0,xyc1,num,p1,0,1,0,1,
	                                     c_fz1,c_fm1,n_fz1,n_fm1,max_num,
	                                     a0,b0,x1,y1,0,fxy1);
return num;
}
		
short D_Complete1Contour(short 				map_bep,
					     short * 		xyc0,		short 	pnum,
					     short *			xyc1,		short	num,
					     D_MAPANTI *		map,		
					     char * 			not_used,	short	map_num,
					     long				max_num)
{   
	short			p0,map_p,cp,p1;
	short			i;
	unsigned char 	c_fz0,c_fm0;
	short			n_fz0,n_fm0;
	short			ctrl_num0,ctrl_num1;
	short			x0,y0,x1,y1;
	char			fxy0,fxy1;
	
	map_p = map_bep;
	ctrl_num0 = 0;
	while(ctrl_num0<map_num+4)
	{
		ctrl_num0++;
		x0    = map[map_p].ipx;
		y0    = map[map_p].ipy;
		p0    = map[map_p].p1;
		c_fz0 = map[map_p].c_fz1;
		c_fm0 = map[map_p].c_fm1;
		n_fz0 = map[map_p].n_fz1;
		n_fm0 = map[map_p].n_fm1;
		fxy0  = map[map_p].flg_xy;
		cp = -1;		// Get antipode(p0) == another map[n].p1 which n!= map_bep,
						// and with smallest t (t>map[map_p].t; where 
						// t= c_fz/c_fm*n_fz/n_fm.
		for(i=0;i<map_num;i++)
		if(map[i].p0 == p0)
		if(D_GreaterLongFSH(c_fz0,
		                    c_fm0,
		                    n_fz0,
		                    n_fm0,
		                    map[i].c_fz0,
		                    map[i].c_fm0,
		                    map[i].n_fz0,
		                    map[i].n_fm0) == -1) //former < later.
		{
		 	cp = i;
		 	break;
		}
		if(cp==-1) // p0 no antipode
		{
			p1 = D_NextOn(xyc0,p0);
			ctrl_num1 = D_Nd(xyc0,p1) - D_Be(xyc0,p1)+4;
			while(ctrl_num1>0)
			{
				ctrl_num1--;
				map_p = B1_GetMapPNum(p1,map,map_num);
				if(map_p<0)
				{
					p1 = D_NextOn(xyc0,p1);
				}
				else
				break;
			}
			////ASSERT(ctrl_num1>1);
			////ASSERT(not_used[map_p]);
			x1 = map[map_p].ipx;
			y1 = map[map_p].ipy;
			fxy1  = map[map_p].flg_xy;
			num = D_Save1Segment(xyc0,xyc1,num,
			                     p0,c_fz0,c_fm0,n_fz0,n_fm0,
			                     p1,
			                     map[map_p].c_fz0,
			                     map[map_p].c_fm0,
			                     map[map_p].n_fz0,
			                     map[map_p].n_fm0,
			                     max_num,x0,y0,x1,y1,fxy0,fxy1);
			if(num<0)
		   	{
		   		return -1;
		   	}
			
		}
		if(cp>=0)
		{
			////ASSERT(not_used[cp]);
			map_p = cp;
			x1	  = map[map_p].ipx;
			y1    = map[map_p].ipy;
			fxy1  = map[map_p].flg_xy;
			num = D_Save1Member(xyc0,xyc1,num,
			                    p0,c_fz0,c_fm0,n_fz0,n_fm0,
			                    map[map_p].c_fz0,
			                    map[map_p].c_fm0,
			                    map[map_p].n_fz0,
			                    map[map_p].n_fm0,
			                    max_num,x0,y0,x1,y1,fxy0,fxy1);
			if(num<0)
			{
				return -1;
			}			                    
		}
		not_used[map_p] = 0;
		if(map_p == map_bep)
		{
			break;
		}
	}
	////ASSERT(ctrl_num0<map_num+4);
	not_used[map_p] = 0;
	if(num>0)
	D_ptc(xyc1,num-1) |= BND_FLAG;

return num;	
}					     
	
short D_CompleteContours(short * 	xyc0, 	short pnum,
	                     short * 	xyc1,
	                     D_MAPANTI * map, 	short map_num)
{
	long 			max_num = (MAX_MEMSIZE - 64 - map_num
	                           - D_memAddr)/3/sizeof(short);
	char *  		not_used = (char *)&D_pmem[MAX_MEMSIZE - 32 - map_num];
	short			num;
	short			w,i,be,nd,bep;
	
	for(w=0;w<map_num;w++)
	{
		not_used[w] = 1;
	}
	
	num = 0;
	for(w=0;w<pnum;)
	{
		be = w;
		nd = D_Nd(xyc0,w);
		if(D_ptc(xyc0,nd) & BNOINTER_FLAG)
		{
			for(i=be;i<=nd;i++)
			{
				if(num>=max_num)
				{
					return -1;
				}
				D_ptx(xyc1,num) = D_ptx(xyc0,i);
				D_pty(xyc1,num) = D_pty(xyc0,i);
				D_ptc(xyc1,num) = D_ptc(xyc0,i);
				num ++;
			}
			w = nd+1;
		}
		else
		{
			bep = D_GetMapPNum(be,nd,map,not_used,map_num);
			if(bep<0)
			{
				w = nd+1;
			}
			else
				{
					num = D_Complete1Contour(bep,
					                         xyc0,pnum,
					                         xyc1,num,
					                         map,
					                         not_used,map_num,
					                         max_num);
					if(num<0)
					{
						return -1;
					}
				}
		}
	}

return num;	
}

/**********
void D_Test0(D_INTERPNT * ip, short ipn);
void D_Test1(D_ANTIPODE * 	at,
             short				atn,
             D_INTERPNT *	ip,
             short				ipn,
             short *			xyc);
void D_Test2(D_ANTIPODE * 	at,
             short				atn,
             D_INTERPNT *	ip,
             short				ipn,
             short *			xyc);
short D_Test3(D_MAPANTI * map,  short map_num);
*******/
//________________________The Main Function_________________________
short DM_Dom(char * mem,short pnum, short nCurveDegree)
{
	short * 		xyc;
	short *		nxyc;
	short			nptn;		// nxyc_ptn.
	short 			m_tx,m_ty;	// times.
	short			m_dx,m_dy;
	D_RECT			m_bbox0;
	D_RECT			m_bbox1;
	short			w,i;
	long			xyc_ad,nxyc_ad,itpt_ad,scan_ad;
	short			D_itptn;	// Count of All interpoints.
	long			max_anti_num;
	short			anti_num,map_num;
	D_MAPANTI *	tmp_map;
	D_MAPANTI 		tmp_mp;
	
	nStaticCurveDegree = nCurveDegree;
	
	// PreDisposing.
	if(pnum<0)
	{
		return 0;
	}
	
	
	D_pmem  		=  	mem;
	xyc_ad    		= 	0;
	xyc 			=	(short *) &D_pmem[0];
	D_ptc(xyc,pnum-1)  |= BND_FLAG;					// Prevect infinite circulation.
	D_memAddr = pnum * (long)sizeof(short) * 3 + 4;
	if( D_memAddr >= MAX_MEMSIZE/2 )
	{
		return 0;
	}


	// Fit Outline into m_bbox1.
	m_bbox1.m_x0 = 0;
	m_bbox1.m_y0 = 0;
	m_bbox1.m_x1 = MAX_XXXX;
	m_bbox1.m_y1 = MAX_YYYY;
	D_GetBBox(xyc,pnum,&m_bbox0);
	m_dx = D_Min(m_bbox0.m_x1 - m_bbox0.m_x0,MAX_XXXX);// Used by D_GetAllInterPnts().
	m_dy = D_Min(m_bbox0.m_y1 - m_bbox0.m_y0,MAX_YYYY);
	
	m_tx = m_bbox0.m_x1 - m_bbox0.m_x0;
	if(m_tx == 0)
	{
		m_tx = 1;
	}
	m_ty = m_bbox0.m_y1 - m_bbox0.m_y0;
	if(m_ty == 0)
	{
		m_ty = 1;
	}
	
	m_tx = 1 + m_tx/(m_bbox1.m_x1 - m_bbox1.m_x0);
	m_ty = 1 + m_ty/(m_bbox1.m_y1 - m_bbox1.m_y0);

	for(w=0;w<pnum;w++)
	{
		D_ptx(xyc,w) = m_bbox1.m_x0 + (D_ptx(xyc,w) - m_bbox0.m_x0)/m_tx;
		D_pty(xyc,w) = m_bbox1.m_y0 + (D_pty(xyc,w) - m_bbox0.m_y0)/m_ty;
	}
	
	// Trnasform Bezier to LineSections and Set a map from new data array
	// to xyc.
	nxyc = (short *)&D_pmem[D_memAddr];
	nptn = D_TrnsBzToLn(xyc,pnum,nxyc);
	if(!nptn)
	{
		return 0;
	}
	//____________From Now on,the addresses of xyc,nxyc must be_________
	//____________be preserved until Have decided xyc's select flags____
	//____________nxyc can be deleted___________________________________
	
	//____________Elimilate Repeative Points on nxyc___________________
	nxyc_ad     = D_memAddr;
	
	D_memAddr  += (long)sizeof(short)*4*nptn;
	nptn = D_Elimi(nxyc,nptn);
	if(!nptn)								// Memory not enough.
	{
		return 0;
	}
	D_memAddr   = nxyc_ad + (long)sizeof(short)*4*nptn;
	//_________________Get ALL InterPoints for nxyc_____________________

	itpt_ad    = D_memAddr;
	D_itpt     = (D_INTERPNT *)&mem[D_memAddr];
	D_itptn    = D_GetAllInterPnts(nxyc,nptn,m_dx,m_dy);

	if(D_itptn<0)
	{
		return 0;
	}

	if(0)
	if(D_itptn == 0)
	{
		return pnum;
	}
	
	D_memAddr  += (long)(sizeof(D_INTERPNT))*D_itptn;
	scan_ad     = D_memAddr;
	
	//__________________Scanning to Valuate D_itpt[].flg__________________
	// Comment On Scanning:
	// At this moment, mem saves data( and in the order)xyc,nxyc,D_itpt[].
	// Select_Flags will be generated by Scanning will also be save to D_itpt[].
	// So,from scan_ad,mem can be used freely until the moment to dispose 
	// xyc[] by D_itpt[].
	// Following function D_ScanAllInterPnts will valuate D_itpt[].flg By the
	// format which can refered to D_SetLeftFlag() and D_GetLeftFlag(),and Rght.
	// If m_itpt[p].flg == 0, this flag had not touched,to ignor it.
	
	if(!D_ScanAllInterPnts(nxyc,	nptn,
	                       D_itpt,	D_itptn))
	{
		return 0;
	}
	
	//_______________Get Antipodes for Selected m_itpt[].pn______________
	// To get antipode,also use m_itpt and nxyc,and data state is same as 
	// before time.Antipode is the point number,at where,the contour will
	// change direction.

	D_anti  = (D_ANTIPODE *)&D_pmem[D_memAddr];
	max_anti_num = (MAX_MEMSIZE-64)/sizeof(D_ANTIPODE);
	anti_num = D_GetAllAntipodes(nxyc, 
	                             D_itpt, D_itptn,
	                             max_anti_num);
	if(anti_num<0)
	{
		return 0;
	}

	//________________Map The Antipode from nxyc to xyc_____________________
	//	On this time,D_anti is for nxyc,By nxyc->c_ptr(),we can map the
	//  the antipodes to xyc.This is the destination of our program.
	
	D_BeforeMapping(xyc,pnum,				// Denote D_ptc() with BNOINTER_FLAG
	                nxyc,nptn,				// Which means,this contour has no
	                D_itpt, D_itptn);		// interpoints.

	D_memAddr	+=	(long)(sizeof(D_ANTIPODE)) * anti_num;
	D_map        =  (D_MAPANTI *)&D_pmem[D_memAddr];
	map_num = D_MapAntipode(xyc,
	                        nxyc,
	          			    D_itpt,D_itptn,
	          				D_anti,anti_num);
	if(map_num < 0)							// if mem_size is too small,this case
	{										// will occur.
		return 0;
	}
	
	////D_Test1(D_anti,anti_num,D_itpt,D_itptn,nxyc);
	
	// Shift D_map to be just after xyc. After this,nxyc,D_itpt,D_anti
	// will be destroied.
	tmp_map = D_map;
	D_memAddr = (long)(sizeof(short)) * 3 * pnum;
	D_map     = (D_MAPANTI *)&D_pmem[D_memAddr];
	for(w=0;w<map_num;w++)
	{
		tmp_mp = tmp_map[w];
		D_map[w] = tmp_mp;
	}
	D_memAddr += (long)(sizeof(D_MAPANTI)) * map_num;
	
	D_OrderMapByP0Prms(D_map,map_num);
	
	////if(!D_Test3(D_map,map_num))
	////return 0;
	
	//__________________Complete Contours_________________________________
	// Now,the data state as following: only xyc and D_map is useful. By
	// them,we make xyc to be domains.
	
	nxyc = (short *)&D_pmem[D_memAddr];
	nptn = D_CompleteContours(xyc,pnum,
	                          nxyc,
	                          D_map,map_num);
	if(nptn<0)
	{
		return 0;
	}
	
	//__________________Retrieve xyc______________________________________
	
	for(w=0;w<nptn;w++)
	{
		D_ptx(xyc,w) = D_ptx(nxyc,w);
		D_pty(xyc,w) = D_pty(nxyc,w);
		D_ptc(xyc,w) = D_ptc(nxyc,w);
	}
	pnum = nptn;
	for(i=0;i<pnum;i++)
	{
	 	D_ptx(xyc,i) = m_bbox0.m_x0 + (D_ptx(xyc,i) - m_bbox1.m_x0)/m_tx;
	 	D_pty(xyc,i) = m_bbox0.m_y0 + (D_pty(xyc,i) - m_bbox1.m_y0)/m_ty;
	}

return pnum;
}

/*******
void D_Test0(D_INTERPNT * ip, short ipn)
{
	short	w;
	
	for(w=0;w<ipn;w++)
	G_Cr(m__pDC,ip[w].x_in,ip[w].y_in,8,1);

return;	
}

#define		ip_pn(p,f)		(ip[p].pn0*(1-(f)) + ip[p].pn1*(f))
void D_Test1(D_ANTIPODE * 	at,
             short				atn,
             D_INTERPNT *	ip,
             short				ipn,
             short *			xyc)
{
    if(!test_abcd)
    {
    	return;
    }
		
	double	t0,t1;
	short	w,p0,p1,q0,q1,rp;
	short	cx,cy,x0,y0,x1,y1,dx0,dy0,dx1,dy1;
	CPen	pen0(PS_SOLID,3,RGB(0,255,0));
	CPen	pen1(PS_SOLID,2,RGB(255,255,255));
	CPen*	oldPen = m__pDC->SelectObject(&pen0);
	char	f0,f1;


	
	for(w=0;w<atn;w++)
	{
		p0  = at[w].pn;
		p1  = at[w].ap;
		f0  = (at[w].flg & 1);
		f1  = ((at[w].flg & 2)>>1);
		q0  = ip_pn(p0,f0);
		q1  = ip_pn(p1,f1);
		rp  = C_Next(xyc,q0);
		cx  = ip[p0].x_in;
		cy  = ip[p0].y_in;
		
		dx0 = c_ptx(xyc,rp) - c_ptx(xyc,q0);
		dy0 = c_pty(xyc,rp) - c_pty(xyc,q0);
		dx0 = -dx0;
		dy0 = -dy0;
		rp  = C_Next(xyc,q1);
		dx1 = c_ptx(xyc,rp) - c_ptx(xyc,q1);
		dy1 = c_pty(xyc,rp) - c_pty(xyc,q1);
		
if(dx0==0 && dy0==0)
{
	G_Cr(m__pDC,c_ptx(xyc,q0),c_pty(xyc,q0),8);
	m__pDC->TextOut(100,100,"AAAAAAAA");
	return;
}
if(dx1==0 && dy1==0)
{
	G_Cr(m__pDC,c_ptx(xyc,q1),c_pty(xyc,q1),8,1);
	m__pDC->TextOut(100,120,"BBBBBBBBBB");
return;
}

		t0  = (double)8/D_Max(D_Abs(dx0),D_Abs(dy0));
		t1  = (double)8/D_Max(D_Abs(dx1),D_Abs(dy1));
		
		x0  = (short)(cx + t0*dx0 + 0.5);
		y0  = (short)(cy + t0*dy0 + 0.5);
		x1  = (short)(cx + t1*dx1 + 0.5);
		y1  = (short)(cy + t1*dy1 + 0.5);
		
		m__pDC->SelectObject(&pen0);
		fmx.Ln(m__pDC,cx,cy,x0,y0);
		m__pDC->SelectObject(&pen1);
		fmx.Ln(m__pDC,cx,cy,x1,y1);
	}
	m__pDC->SelectObject(oldPen);

return;
}

short D_Test3(D_MAPANTI * map,  short map_num)
// The destinetion of this testing is to assure that:
// For all left_selected_flag point (p-),there must
// be an unique (p+) with right_selected_flag;and the
// the reverse also hold.
{
	short u,v;

	for(u=0;u<map_num;u++)
	for(v=u+1;v<map_num;v++)
	if(map[u].p0 == map[v].p0)
	if(D_GreaterLongFSH(map[u].c_fz0,map[u].c_fm0,
	                    map[u].n_fz0,map[u].n_fm0,
	                    map[v].c_fz0,map[v].c_fm0,
	                    map[v].n_fz0,map[v].n_fm0)==0)
	{
		G_Cr(m__pDC,map[u].ipx,map[u].ipy,20,1);
		G_Cr(m__pDC,map[u].ipx,map[u].ipy,10);
		return 0;
	}
			
	for(u=0;u<map_num;u++)
	for(v=u+1;v<map_num;v++)
	if(map[u].p1 == map[v].p1)
	if(D_GreaterLongFSH(map[u].c_fz1,map[u].c_fm1,
	                    map[u].n_fz1,map[u].n_fm1,
	                    map[v].c_fz1,map[v].c_fm1,
	                    map[v].n_fz1,map[v].n_fm1)==0)
	{
		G_Cr(m__pDC,map[u].ipx,map[u].ipy,20,1);
		G_Cr(m__pDC,map[u].ipx,map[u].ipy,10);
		return 0;
	}
	
	for(u=0;u<map_num;u++)
	if(D_GreaterLongFSH(map[u].c_fz0, map[u].c_fm0,
	                    map[u].n_fz0, map[u].n_fm0,
	                    0           , map[u].c_fm0,
	                    0           , map[u].n_fm0)==0)	//p0 cann't with t=0.
	{
		G_Cr(m__pDC,map[u].ipx,map[u].ipy,20,1);
		G_Cr(m__pDC,map[u].ipx,map[u].ipy,10);
		return 0;
	}
	for(u=0;u<map_num;u++)
	if(D_GreaterLongFSH(map[u].c_fz1, map[u].c_fm1,
	                    map[u].n_fz1, map[u].n_fm1,
	                    map[u].c_fm1, map[u].c_fm1,
	                    0           , map[u].n_fm1)==0)	//p0 cann't with t=1.
	{
		G_Cr(m__pDC,map[u].ipx,map[u].ipy,20,1);
		G_Cr(m__pDC,map[u].ipx,map[u].ipy,10);
		return 0;
	}
return 1;
}

**********/