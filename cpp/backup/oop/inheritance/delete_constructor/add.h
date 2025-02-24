#include "calculate.h"

class Add : public Calculate {
public:
    Add() {};   // Error: Try to use a deleted function.
    ~Add() override {};

    int cal(int op1, int op2) override;
};