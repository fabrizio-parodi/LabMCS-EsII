#ifndef _ODESOLVER
#define _ODESOLVER

#include <vector>
#include "Vector.h"
#include "MatPoint.h"

using namespace std;

class OdeSolver{
 public:
  OdeSolver(string method="Eulero", vector<MatPoint> p=vector<MatPoint>(0)):m_method(method),m_p(p),m_t(0),m_h(0.1){}
  void                   Punto(MatPoint tmp);
  MatPoint         Punto(unsigned int i);
  vector<MatPoint> Punti();
  unsigned int   N();
  void           T(double t0);
  double         T();
  void           Passo(double h);
  double         Passo();
  void           Cinematica();
  std::function < Vector(unsigned int i,unsigned int j, double t, vector<MatPoint> p) > fInterna;
  std::function < Vector(unsigned int i,double t, vector<MatPoint> p) >        fEsterna;
 private:
  string   m_method;
  vector<MatPoint> m_p;
  double   m_t,m_h; 
  Vector  m_eqDiff(unsigned int i, double t, vector<MatPoint>);
};


#endif
