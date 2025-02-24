// Export entire struct.
struct __declspec(dllexport) Add {
    int lh;
    static int rh;

    Add(int l, int r) {
        lh = l;
        rh = r;
    }
    int operator()(){
        return lh + rh;
    }
};

int Add::rh = 0;

// Export members.
// struct Add {
//     int lh;
//     __declspec(dllexport) static int rh;

//     __declspec(dllexport) Add(int l, int r) {
//         lh = l;
//         rh = r;
//     }
//     __declspec(dllexport) int operator()(){
//         return lh + rh;
//     }
// };

// int Add::rh = 0;

// ERROR
// struct Add {
//     int lh;
//     static int rh;

//     __declspec(dllexport) Add(int l, int r) {
//         lh = l;
//         rh = r;
//     }
//     __declspec(dllexport) int operator()(){
//         return lh + rh;
//     }
// };

//__declspec(dllexport) int Add::rh = 0;