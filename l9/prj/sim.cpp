#include <cmath>
#include <cstdlib>
#include <iostream>
#include "sim.hh"

using namespace std;

/*!
 * \file
 * \brief Metody klasy sim
 *
 */


typedef double MAT[25][25];

MAT  A;
int  IPOSV[25], IZROV[25];
int  i,j,ICASE,N,M,M1,M2,M3;
double R;


  void simp1(MAT,int,int *,int,int,int *,double *);
  void simp2(MAT,int,int,int *,int,int *,int,double *);
  void simp3(MAT,int,int,int,int);


void simplx(MAT a,int m,int n,int m1,int m2,int m3,int *icase,int *izrov, int *iposv)  
{ 

  int i,ip,ir,is,k,kh,kp,m12,nl1,nl2,l1[25],l2[25],l3[25]; 
  double bmax,q1,EPS=1e-6; 
  nl1=n; 
  for (k=1; k<=n; k++) 
  { 
    l1[k]=k;    
    izrov[k]=k;  
  } 
  nl2=m;
  for (i=1; i<=m; i++) 
  { 
    l2[i]=i;
    iposv[i]=n+i; 
  }
  for (i=1; i<=m2; i++) l3[i]=1;
  ir=0;
  if(m2+m3 == 0) goto e30; 
  ir=1;
  for (k=1; k<=n+1; k++) { 
    q1=0.0; 
    for (i=m1+1; i<=m; i++) q1 += a[i+1][k]; 
    a[m+2][k]=-q1; 
  } 
e10: simp1(a,m+1,l1,nl1,0,&kp,&bmax);   
  if(bmax <= EPS && a[m+2][1] < -EPS) 
  { 
    *icase=-1;    
    return;      
  }	
  else if (bmax <= EPS && a[m+2][1] <= EPS) 
  { 

    m12=m1+m2+1;
    if (m12 <= m)
      for (ip=m12; ip<=m; ip++) 
		  if(iposv[ip] == ip+n) {   
            simp1(a,ip,l1,nl1,1,&kp,&bmax); 
            if(bmax > EPS) goto e1; 
          }                        
    ir=0;
    m12=m12-1;
    if (m1+1 > m12) goto e30; 
    for (i=m1+1; i<=m1+m2; i++)    
      if(l3[i-m1] == 1)          
        for (k=1; k<=n+1; k++) 
          a[i+1][k] *= -1.0; 
    goto e30;                      
  } 

  simp2(a,m,n,l2,nl2,&ip,kp,&q1); 
                                         
  if(ip == 0) {                        
    *icase=-1;                        
    return; 
  } 
e1: simp3(a,m+1,n,ip,kp); 

  if(iposv[ip] >= n+m1+m2+1) 
  { 
                              
    for (k=1; k<=nl1; k++) 
      if(l1[k] == kp) goto e2; 
e2: nl1=nl1-1; 
    for (is=k; is<=nl1; is++)  l1[is]=l1[is+1]; 
  }	
  else {
    if(iposv[ip] < n+m1+1) goto e20;
    kh=iposv[ip]-m1-n; 
    if(l3[kh] == 0) goto e20;  
    l3[kh]=0;                  
                               
  }   
  a[m+2][kp+1] += 1.0; 
  for (i=1; i<=m+2; i++)  a[i][kp+1] *= -1.0; 
e20: is=izrov[kp];          
  izrov[kp]=iposv[ip]; 
  iposv[ip]=is; 
  if (ir != 0) goto e10;      

e30: simp1(a,0,l1,nl1,0,&kp,&bmax); 
  if(bmax <= EPS) 
  {         
    *icase=0; 
    return; 
  }
  simp2(a,m,n,l2,nl2,&ip,kp,&q1);  
  if(ip == 0) {            
    *icase=1; 
    return; 
  } 
  simp3(a,m,n,ip,kp);      
  goto e20;                 
}                         

 

void simp1(MAT a,int mm,int *ll,int nll,int iabf,int *kp,double *bmax) 
{

  int k; 
  double test; 
  *kp=ll[1]; 
  *bmax=a[mm+1][*kp+1];
  if (nll < 2) return; 
  for (k=2; k<=nll; k++) { 
    if(iabf == 0) 
      test=a[mm+1][ll[k]+1]-(*bmax); 
    else
      test=fabs(a[mm+1][ll[k]+1])-fabs(*bmax); 
    if(test > 0.0) { 
      *bmax=a[mm+1][ll[k]+1]; 
      *kp=ll[k]; 
    } 
  } 
  return; 
} 

void simp2(MAT a, int m,int n,int *l2,int nl2,int *ip,int kp,double *q1) 
{ 
  double EPS=1e-6; 

  int i,ii,k; 
  double q,q0,qp; 
  *ip=0; 
  if(nl2 < 1) return;
  for (i=1; i<=nl2; i++) 
    if (a[i+1][kp+1] < -EPS) goto e2; 
  return; 
e2: *q1=-a[l2[i]+1][1]/a[l2[i]+1][kp+1]; 
  *ip=l2[i];
  if (i+1 > nl2) return; 
  for (i=i+1; i<=nl2; i++) 
  { 
    ii=l2[i];
	if(a[ii+1][kp+1] < -EPS) 
  { 
      q=-a[ii+1][1]/a[ii+1][kp+1]; 
      if (q <  *q1) 
      { 
        *ip=ii; 
        *q1=q; 
      }
      else if (q == *q1) 
      {  
		for (k=1; k<=n; k++) 
    { 
          qp=-a[*ip+1][k+1]/a[*ip+1][kp+1]; 
          q0=-a[ii+1][k+1]/a[ii+1][kp+1]; 
          if (q0 != qp) goto e6; 
        } 
e6:     if (q0 < qp) *ip=ii; 
      } 
    } 
  } 
  return; 
} 

void simp3(MAT a,int i1,int k1,int ip,int kp) 
{ 

  int ii,kk; 
  double piv; 
  piv=1.0/a[ip+1][kp+1];
  if (i1 >= 0) 
    for (ii=1; ii<=i1+1; ii++) 
	  if (ii-1 != ip) { 
        a[ii][kp+1] *= piv; 
        for (kk=1; kk<=k1+1; kk++) 
          if (kk-1 != kp) 
            a[ii][kk] -= a[ip+1][kk]*a[ii][kp+1]; 
      } 
  for (kk=1; kk<=k1+1; kk++) 
    if(kk-1 !=  kp) a[ip+1][kk] =-a[ip+1][kk]*piv; 
  a[ip+1][kp+1]=piv; 
  return; 
} 

/*! \brief Funkcja pozwala rozpocząć algorytm, wywołuje funkcje pomocnicze
 * 
 */
void sim::simplex(double *tab,double *wyniki, int NV, int m1, int m2) 
{

  N=NV;
  M1=m1;
  M2=m2;
  M3=0;

  M=M1+M2+M3;  

  for (i=1; i<=M+2; i++)
    for (j=1; j<=N+1; j++)
		A[i][j]=0.0;

 
  for (i=2; i<=N+1; i++) 
  {
 
	  A[1][i]=tab[i-2];
	
  }

  A[1][1]=0;

  for (i=1; i<=M; i++) {
   
    for (j=2; j<=N+1; j++) 
    {
  
	  R=tab[i*(NV+1)+j-2];
	 
	  A[i+1][j] = -R;
	}
  
	A[i+1][1]=tab[i*(NV+1)+NV];
	
  }


  simplx(A,M,N,M1,M2,M3,&ICASE,IZROV,IPOSV);

  if (ICASE==0) 
  {
  
	wyniki[0]=A[1][1];
    for (i=1; i<=N; i++) 
    {
      for (j=1; j<=M; j++)
	    if (IPOSV[j] == i) 
      {
        
		  wyniki[i]=A[j+1][1];
	      goto e3;
		}
      
e3:;
}
  }
  else
  {
    
	wyniki[0]=-1;
  }
}
