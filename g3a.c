/* generate close triangular grid on plane */

#include <stdio.h>
#include <stdlib.h>

char * HELP = "Generator of Petri net models of triangular grid with plugs on edges\n"
              "Product of Tatiana Shmeleva: tishtri@rambler.ru\n\n"
              "USAGE: g3a k [p] [b] > pn_model.ndr\n"
              "  k - size of triangular grid,\n"
              "  p - number of packets in each section of the internal buffer,\n"
              "  b - available buffer size,\n"
              "  output format - .ndr file of Tina www.laas.fr/tina\n\n";

#define DI 560.0
#define DJ 280.0

int main( int argc, char * argv[] )
{
 int k,i,j,l,off,p=0,b=0;
 
 if( argc < 2 )
 {
   fprintf(stderr, "%s", HELP);
   fprintf(stderr, "*** actually: %d arguments\n", argc);
   return 2;
 }
 k = atoi( argv[1] );
 if(argc>2) p = atoi( argv[2] );
 if(argc>3) b = atoi( argv[3] );
 
 for(i=1; i<=k; i++)
 {
 	off=DJ*(k-i);
    for(j=1; j<=2*i-1; j++)
   {
   	   	
   	if (j%2==1)  // Even triangle
   	{
      printf("p %.1f %.1f {pbl^%d.%d} %d n\n",off+j*DJ+280.0, i*DI+280.0, i,j, b);
   	  printf("p %.1f %.1f {pb1^%d.%d} %d n\n",off+j*DJ+220.0, i*DI+248.0, i,j, p);
	  printf("p %.1f %.1f {pb2^%d.%d} %d n\n",off+j*DJ+340.0, i*DI+248.0, i,j, p);	
	  printf("p %.1f %.1f {pb3^%d.%d} %d n\n",off+j*DJ+280.0, i*DI+368.0, i,j, p);
	  
	  printf("p %.1f %.1f {pi1^%d.%d} 0 n\n",off+j*DJ+220.0, i*DI+108.0, i,j);
	  printf("p %.1f %.1f {pil1^%d.%d} 1 n\n",off+j*DJ+176.0, i*DI+176.0, i,j);
	  printf("p %.1f %.1f {po1^%d.%d} 0 n\n",off+j*DJ+100.0, i*DI+320.0, i,j);
	  printf("p %.1f %.1f {pol1^%d.%d} 1 n\n",off+j*DJ+64.0, i*DI+388.0, i,j);
	  
	  printf("p %.1f %.1f {pol2^%d.%d} 1 n\n",off+j*DJ+336.0, i*DI+108.0, i,j);
	  printf("p %.1f %.1f {po2^%d.%d} 0 n\n",off+j*DJ+376.0, i*DI+176.0, i,j);
	  printf("p %.1f %.1f {pil2^%d.%d} 1 n\n",off+j*DJ+460.0, i*DI+320.0, i,j);
	  printf("p %.1f %.1f {pi2^%d.%d} 0 n\n",off+j*DJ+500.0, i*DI+388.0, i,j);
	  
	  printf("p %.1f %.1f {pi3^%d.%d} 0 n\n",off+j*DJ+124.0, i*DI+492.0, i,j);
	  printf("p %.1f %.1f {pil3^%d.%d} 1 n\n",off+j*DJ+204.0, i*DI+492.0, i,j);
	  printf("p %.1f %.1f {po3^%d.%d} 0 n\n",off+j*DJ+364.0, i*DI+492.0, i,j);
	  printf("p %.1f %.1f {pol3^%d.%d} 1 n\n",off+j*DJ+480.0, i*DI+492.0, i,j);
	  
	  printf("t %.1f %.1f {to1^%d.%d} 0 w n\n", off+j*DJ+136.0, i*DI+376.0, i, j);
	  printf("e {pb1^%d.%d} {to1^%d.%d} 1 n\n", i, j, i, j);
	  printf("e {to1^%d.%d} {po1^%d.%d} 1 n\n", i, j, i, j);
	  printf("e {pol1^%d.%d} {to1^%d.%d} 1 n\n", i, j, i, j);
	  printf("e {to1^%d.%d} {pbl^%d.%d} 1 n\n", i, j, i, j);
	  
	  printf("t %.1f %.1f {to2^%d.%d} 0 w n\n", off+j*DJ+320.0, i*DI+160.0, i, j);
	  printf("e {pb2^%d.%d} {to2^%d.%d} 1 n\n", i, j, i, j);
	  printf("e {to2^%d.%d} {po2^%d.%d} 1 n\n", i, j, i, j);
	  printf("e {pol2^%d.%d} {to2^%d.%d} 1 n\n", i, j, i, j);
	  printf("e {to2^%d.%d} {pbl^%d.%d} 1 n\n", i, j, i, j);
	  
	  printf("t %.1f %.1f {to3^%d.%d} 0 w n\n", off+j*DJ+420.0, i*DI+420.0, i, j);
	  printf("e {pb3^%d.%d} {to3^%d.%d} 1 n\n", i, j, i, j);
	  printf("e {to3^%d.%d} {po3^%d.%d} 1 n\n", i, j, i, j);
	  printf("e {pol3^%d.%d} {to3^%d.%d} 1 n\n", i, j, i, j);
	  printf("e {to3^%d.%d} {pbl^%d.%d} 1 n\n", i, j, i, j);
	  
	  printf("t %.1f %.1f {ti1,2^%d.%d} 0 w n\n", off+j*DJ+280.0, i*DI+100.0, i, j);
	  printf("e {pbl^%d.%d} {ti1,2^%d.%d} 1 n\n", i, j, i, j);
	  printf("e {ti1,2^%d.%d} {pil1^%d.%d} 1 n\n", i, j, i, j);
	  printf("e {pi1^%d.%d} {ti1,2^%d.%d} 1 n\n", i, j, i, j);
	  printf("e {ti1,2^%d.%d} {pb2^%d.%d} 1 n\n", i, j, i, j);
	  
	  printf("t %.1f %.1f {ti1,3^%d.%d} 0 w n\n", off+j*DJ+240.0, i*DI+180.0, i, j);
	  printf("e {pbl^%d.%d} {ti1,3^%d.%d} 1 n\n", i, j, i, j);
	  printf("e {ti1,3^%d.%d} {pil1^%d.%d} 1 n\n", i, j, i, j);
	  printf("e {pi1^%d.%d} {ti1,3^%d.%d} 1 n\n", i, j, i, j);
	  printf("e {ti1,3^%d.%d} {pb3^%d.%d} 1 n\n", i, j, i, j);
	  
	  printf("t %.1f %.1f {ti2,1^%d.%d} 0 w n\n", off+j*DJ+400.0, i*DI+300.0, i, j);
	  printf("e {pbl^%d.%d} {ti2,1^%d.%d} 1 n\n", i, j, i, j);
	  printf("e {ti2,1^%d.%d} {pil2^%d.%d} 1 n\n", i, j, i, j);
	  printf("e {pi2^%d.%d} {ti2,1^%d.%d} 1 n\n", i, j, i, j);
	  printf("e {ti2,1^%d.%d} {pb1^%d.%d} 1 n\n", i, j, i, j);
	  
	  printf("t %.1f %.1f {ti2,3^%d.%d} 0 w n\n", off+j*DJ+440.0, i*DI+368.0, i, j);
	  printf("e {pbl^%d.%d} {ti2,3^%d.%d} 1 n\n", i, j, i, j);
	  printf("e {ti2,3^%d.%d} {pil2^%d.%d} 1 n\n", i, j, i, j);
	  printf("e {pi2^%d.%d} {ti2,3^%d.%d} 1 n\n", i, j, i, j);
	  printf("e {ti2,3^%d.%d} {pb3^%d.%d} 1 n\n", i, j, i, j);
	  
	  printf("t %.1f %.1f {ti3,1^%d.%d} 0 w n\n", off+j*DJ+200.0, i*DI+420.0, i, j);
	  printf("e {pbl^%d.%d} {ti3,1^%d.%d} 1 n\n", i, j, i, j);
	  printf("e {ti3,1^%d.%d} {pil3^%d.%d} 1 n\n", i, j, i, j);
	  printf("e {pi3^%d.%d} {ti3,1^%d.%d} 1 n\n", i, j, i, j);
	  printf("e {ti3,1^%d.%d} {pb1^%d.%d} 1 n\n", i, j, i, j);
	  
	  printf("t %.1f %.1f {ti3,2^%d.%d} 0 w n\n", off+j*DJ+300.0, i*DI+420.0, i, j);
	  printf("e {pbl^%d.%d} {ti3,2^%d.%d} 1 n\n", i, j, i, j);
	  printf("e {ti3,2^%d.%d} {pil3^%d.%d} 1 n\n", i, j, i, j);
	  printf("e {pi3^%d.%d} {ti3,2^%d.%d} 1 n\n", i, j, i, j);
	  printf("e {ti3,2^%d.%d} {pb2^%d.%d} 1 n\n", i, j, i, j);
	   
	}
	else // Odd triangle
	{
      printf("p %.1f %.1f {pbl^%d.%d} %d n\n",off+j*DJ+280.0, i*DI+208.0, i,j,b);
	  printf("p %.1f %.1f {pb1^%d.%d} %d n\n",off+j*DJ+332.0, i*DI+240.0, i,j,p);
	  printf("p %.1f %.1f {pb2^%d.%d} %d n\n",off+j*DJ+212.0, i*DI+248.0, i,j,p);	
	  printf("p %.1f %.1f {pb3^%d.%d} %d n\n",off+j*DJ+280.0, i*DI+120.0, i,j,p);	
	  
	  printf("t %.1f %.1f {to1^%d.%d} 0 w n\n", off+j*DJ+400.0, i*DI+120.0, i, j);
	  printf("t %.1f %.1f {to2^%d.%d} 0 w n\n", off+j*DJ+220.0, i*DI+320.0, i, j);
	  printf("t %.1f %.1f {to3^%d.%d} 0 w n\n", off+j*DJ+140.0, i*DI+60.0, i, j);
	  
	  printf("t %.1f %.1f {ti1,2^%d.%d} 0 w n\n", off+j*DJ+280.0, i*DI+400.0, i, j);
	  printf("t %.1f %.1f {ti1,3^%d.%d} 0 w n\n", off+j*DJ+320.0, i*DI+320.0, i, j);
	  	  
	  printf("t %.1f %.1f {ti2,1^%d.%d} 0 w n\n", off+j*DJ+160.0, i*DI+212.0, i, j);
	  printf("t %.1f %.1f {ti2,3^%d.%d} 0 w n\n", off+j*DJ+120.0, i*DI+140.0, i, j);
	  	  
	  printf("t %.1f %.1f {ti3,1^%d.%d} 0 w n\n", off+j*DJ+240.0, i*DI+48.0, i, j);
	  printf("t %.1f %.1f {ti3,2^%d.%d} 0 w n\n", off+j*DJ+340.0, i*DI+48.0, i, j);
	  
	  printf("e {pb1^%d.%d} {to1^%d.%d} 1 n\n", i, j, i, j);
	  printf("e {to1^%d.%d} {pbl^%d.%d} 1 n\n", i, j, i, j);
	  
	  printf("e {pb2^%d.%d} {to2^%d.%d} 1 n\n", i, j, i, j);
	  printf("e {to2^%d.%d} {pi2^%d.%d} 1 n\n", i, j, i, j-1);
	  printf("e {pil2^%d.%d} {to2^%d.%d} 1 n\n", i, j-1, i, j);
	  printf("e {to2^%d.%d} {pbl^%d.%d} 1 n\n", i, j, i, j);
	  	  
	  printf("e {pb3^%d.%d} {to3^%d.%d} 1 n\n", i, j, i, j);
	  printf("e {to3^%d.%d} {pi3^%d.%d} 1 n\n", i, j, i-1, j-1);
	  printf("e {pil3^%d.%d} {to3^%d.%d} 1 n\n", i-1, j-1, i, j);
	  printf("e {to3^%d.%d} {pbl^%d.%d} 1 n\n", i, j, i, j);
	  
	  printf("e {pbl^%d.%d} {ti1,2^%d.%d} 1 n\n", i, j, i, j);
	  printf("e {ti1,2^%d.%d} {pb2^%d.%d} 1 n\n", i, j, i, j);
	  
	  printf("e {pbl^%d.%d} {ti1,3^%d.%d} 1 n\n", i, j, i, j);
	  printf("e {ti1,3^%d.%d} {pb3^%d.%d} 1 n\n", i, j, i, j);
	  
	  printf("e {pbl^%d.%d} {ti2,1^%d.%d} 1 n\n", i, j, i, j);
	  printf("e {ti2,1^%d.%d} {pb1^%d.%d} 1 n\n", i, j, i, j);
	  printf("e {po2^%d.%d} {ti2,1^%d.%d} 1 n\n", i, j-1, i, j);
	  printf("e {ti2,1^%d.%d} {pol2^%d.%d} 1 n\n", i, j, i, j-1);
	  
	  printf("e {pbl^%d.%d} {ti2,3^%d.%d} 1 n\n", i, j, i, j);
	  printf("e {ti2,3^%d.%d} {pb3^%d.%d} 1 n\n", i, j, i, j);
	  printf("e {po2^%d.%d} {ti2,3^%d.%d} 1 n\n", i, j-1, i, j);
	  printf("e {ti2,3^%d.%d} {pol2^%d.%d} 1 n\n", i, j, i, j-1);
	  
	  printf("e {pbl^%d.%d} {ti3,1^%d.%d} 1 n\n", i, j, i, j);
	  printf("e {ti3,1^%d.%d} {pb1^%d.%d} 1 n\n", i, j, i, j);
	  printf("e {po3^%d.%d} {ti3,1^%d.%d} 1 n\n", i-1, j-1, i, j);
	  printf("e {ti3,1^%d.%d} {pol3^%d.%d} 1 n\n", i, j, i-1, j-1);
	  
	  printf("e {pbl^%d.%d} {ti3,2^%d.%d} 1 n\n", i, j, i, j);
	  printf("e {ti3,2^%d.%d} {pb2^%d.%d} 1 n\n", i, j, i, j);
	  printf("e {po3^%d.%d} {ti3,2^%d.%d} 1 n\n", i-1, j-1, i, j);
	  printf("e {ti3,2^%d.%d} {pol3^%d.%d} 1 n\n", i, j, i-1, j-1);
	    
	}
  }
}

for(i=1; i<=k; i++)  // Union even and odd triangles
 {
 	off=DI*(k-i);
    for(j=1; j<=2*i-1; j++)
   {
   	
   	if (j%2==0) 
	{
   	  printf("e {to1^%d.%d} {pi1^%d.%d} 1 n\n", i, j, i, j+1);
	  printf("e {pil1^%d.%d} {to1^%d.%d} 1 n\n", i, j+1, i, j);
		 
	  printf("e {po1^%d.%d} {ti1,2^%d.%d} 1 n\n", i, j+1, i, j);
	  printf("e {ti1,2^%d.%d} {pol1^%d.%d} 1 n\n", i, j, i, j+1);
	  
	  printf("e {po1^%d.%d} {ti1,3^%d.%d} 1 n\n", i, j+1, i, j);
	  printf("e {ti1,3^%d.%d} {pol1^%d.%d} 1 n\n", i, j, i, j+1);
	}
}}

 for(i=1; i<=k; i++)  // Add plugs on edges
 {
 	off=DJ*(k-i);
 	
 	printf("t %.1f %.1f {t^%d.%d} 0 w n\n", off+1*DJ+80.0, (i)*DI+172.0, i, 0);
	printf("t %.1f %.1f {t^%d.%d} 0 w n\n", off+(2*i-1)*DJ+484.0, (i)*DI+172.0, i, k+1);
	printf("t %.1f %.1f {t^%d.%d} 0 w n\n", (2*i-1)*DJ+280.0, k*DI+576.0, k+1, (i-1)*2+1);
	
	printf("e {t^%d.%d} {pi1^%d.%d} 1 n\n", i, 0, i, 1);
	printf("e {t^%d.%d} {pol1^%d.%d} 1 n\n", i, 0, i, 1);
	printf("e {po1^%d.%d} {t^%d.%d} 1 n\n", i, 1, i, 0);
	printf("e {pil1^%d.%d} {t^%d.%d} 1 n\n", i, 1, i, 0);
	
	printf("e {t^%d.%d} {pi2^%d.%d} 1 n\n", i, k+1, i, 2*i-1);
	printf("e {t^%d.%d} {pol2^%d.%d} 1 n\n", i, k+1, i, 2*i-1);
	printf("e {po2^%d.%d} {t^%d.%d} 1 n\n", i, 2*i-1, i, k+1);
	printf("e {pil2^%d.%d} {t^%d.%d} 1 n\n", i, 2*i-1, i, k+1);
	
	printf("e {t^%d.%d} {pi3^%d.%d} 1 n\n", k+1, (i-1)*2+1, k, (i-1)*2+1);
	printf("e {t^%d.%d} {pol3^%d.%d} 1 n\n", k+1, (i-1)*2+1, k, (i-1)*2+1);
	printf("e {po3^%d.%d} {t^%d.%d} 1 n\n", k, (i-1)*2+1, k+1, (i-1)*2+1);
	printf("e {pil3^%d.%d} {t^%d.%d} 1 n\n", k, (i-1)*2+1, k+1, (i-1)*2+1);
	}
 

 printf("h {g3a-ndr%d}\n", k); 

} /* main */

/*
The MIT License (MIT)

Copyright (c) 2018 Tatiana Shmeleva

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in
all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
THE SOFTWARE.
*/

