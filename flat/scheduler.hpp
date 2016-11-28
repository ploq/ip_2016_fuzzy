class Scheduler {
    int _V0_gen, _V1_gen, _V2_gen;
public:
    int _V0, _V1, _V2;
    Scheduler();
    void updateIO(const int V0, const int V1, const int V2);
    void APP_Execute();
    void APP_Initialize();
};