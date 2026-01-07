#include "Appliance.h"

class Fridge: public Appliance{
    private:
        bool hasFreezer;   
    public:
        Fridge(string&, string&, int, double, bool);

        bool hasITFreezer() const;
        string getType() const override;
        void disp() const override;

        ~Fridge() = default;

};