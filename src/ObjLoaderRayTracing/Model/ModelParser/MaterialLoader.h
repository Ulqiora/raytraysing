#include "IMaterialLoader.h"
#include <fstream>
namespace   s21{
class MaterialLoader:public IMaterialLoader{
public:
    virtual std::vector<MaterialData>* start(const std::string& materialFileName)override;
};
}