#include <cmath>
#include "ModulesKarpova.h"

ClassLab12_Karpova::ClassLab12_Karpova(float heightToSet, float radiusToSet) {
    height = heightToSet;
    radius = radiusToSet;
}

float ClassLab12_Karpova::getHeight() {
    return height;
}

float ClassLab12_Karpova::getRadius() {
    return radius;
}

float ClassLab12_Karpova::getVolume() {
    return M_PI*pow(radius, 2)*height;
}

bool ClassLab12_Karpova::setHeight(float heightToSet) {
    if (heightToSet > 0) {
        height = heightToSet;
        return true;
    } else {
        return false;
    }
}

bool ClassLab12_Karpova::setRadius(float radiusToSet) {
    if (radiusToSet > 0) {
        radius = radiusToSet;
        return true;
    } else {
        return false;
    }
}
