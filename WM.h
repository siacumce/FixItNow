#include "Appliance.h"


//washing machine
class WM: public Appliance{
    private: 
        int capacity;
    public:
        WM(const string&,const string&, int, double, int);

        int getCapacity() const;
        string getType() const override;
        void disp() const override;

        ~WM() = default;
};