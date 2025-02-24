class Calculate {
public:
    Calculate() = delete;
    virtual ~Calculate() = 0 {};

    virtual int cal(int op1, int op2) = 0;
};