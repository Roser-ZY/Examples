struct __declspec(dllexport) Add {
    int lh;
    static int rh;
    
    Add(int l, int r);
    int operator()();
};