class Complex
{
public:
    Complex(double real, double imag):real_(real), imag_(imag){}
    friend bool operator ==(const Complex& c1, const Complex& c2)
    {
        return c1.real_== c2.real_ && c1.imag_ == c2.imag_;
    }
private:
    double real_, imag_;
};