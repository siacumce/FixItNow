#include "Appliance.h"

class TV: public Appliance{
    private:
        int diagonal;
    public:
        TV(string&, string&, int, double, int);

        int getDiag() const;
        string getType() const override;
        void disp() const override;

        ~TV() = default;
        
};