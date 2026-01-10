#include "Appliance.h"

class Fridge: public Appliance{
    private:
        bool hasFreezer;   
    public:
        Fridge(const string&, const string&, int, double, bool);

        bool hasITFreezer() const;
        string getType() const override;
        void disp() const override;

        ~Fridge() = default;

};