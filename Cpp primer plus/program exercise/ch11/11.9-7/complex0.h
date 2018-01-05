#ifndef COMPLEX0_H_
#define COMPLEX0_H_
class complex{
private:
double m_real;
double m_imaginary;
public:
complex();
complex(double a,double b);
~complex(){}
complex operator+(const complex&t) const;
complex operator-(const complex&t) const;
complex operator*(const complex&t) const;
complex operator~();
friend complex operator*(const complex&t,double n);
friend complex operator*(double n,const complex&t);
friend std::ostream& operator<<(std::ostream&os,const complex&t);
friend std::istream& operator>>(std::istream&is,complex&t);
};
#endif
