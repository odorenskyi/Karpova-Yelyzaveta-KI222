#ifndef MODULESKARPOVA_H_INCLUDED
#define MODULESKARPOVA_H_INCLUDED

class ClassLab12_Karpova {
    private:
        float height;
        float radius;
    public:
        ClassLab12_Karpova(float, float);
        float getHeight();
        float getRadius();
        float getVolume();
        bool setHeight(float);
        bool setRadius(float);
};

#endif // MODULESKARPOVA_H_INCLUDED
