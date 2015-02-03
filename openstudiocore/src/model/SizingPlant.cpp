/**********************************************************************
 *  Copyright (c) 2008-2015, Alliance for Sustainable Energy.
 *  All rights reserved.
 *
 *  This library is free software; you can redistribute it and/or
 *  modify it under the terms of the GNU Lesser General Public
 *  License as published by the Free Software Foundation; either
 *  version 2.1 of the License, or (at your option) any later version.
 *
 *  This library is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 *  Lesser General Public License for more details.
 *
 *  You should have received a copy of the GNU Lesser General Public
 *  License along with this library; if not, write to the Free Software
 *  Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301  USA
 **********************************************************************/

#include <utilities/idd/IddEnums.hxx>
#include <utilities/idd/IddFactory.hxx>
#include <utilities/idd/OS_Sizing_Plant_FieldEnums.hxx>
#include <ostream>

#include "../utilities/core/Assert.hpp"
#include "PlantLoop.hpp"
#include "SizingPlant.hpp"
#include "SizingPlant_Impl.hpp"
#include "model/../utilities/idd/../core/EnumBase.hpp"
#include "model/../utilities/idd/../core/Optional.hpp"
#include "model/../utilities/idd/../core/Singleton.hpp"
#include "model/../utilities/idd/IddObject.hpp"
#include "model/../utilities/idf/IdfObject.hpp"
#include "model/../utilities/idf/WorkspaceObject_Impl.hpp"
#include "model/../utilities/units/OSOptionalQuantity.hpp"
#include "model/../utilities/units/Quantity.hpp"
#include "model/ModelObject.hpp"
#include "model/ModelObject_Impl.hpp"

namespace openstudio {
namespace model {
class Model;
}  // namespace model
}  // namespace openstudio

namespace openstudio {
namespace model {

namespace detail {

class Model_Impl;

  SizingPlant_Impl::SizingPlant_Impl(const IdfObject& idfObject,
                                     Model_Impl* model,
                                     bool keepHandle)
    : ModelObject_Impl(idfObject,model,keepHandle)
  {
    OS_ASSERT(idfObject.iddObject().type() == SizingPlant::iddObjectType());
  }

  SizingPlant_Impl::SizingPlant_Impl(const openstudio::detail::WorkspaceObject_Impl& other,
                                     Model_Impl* model,
                                     bool keepHandle)
    : ModelObject_Impl(other,model,keepHandle)
  {
    OS_ASSERT(other.iddObject().type() == SizingPlant::iddObjectType());
  }

  SizingPlant_Impl::SizingPlant_Impl(const SizingPlant_Impl& other,
                                     Model_Impl* model,
                                     bool keepHandle)
    : ModelObject_Impl(other,model,keepHandle)
  {}

  const std::vector<std::string>& SizingPlant_Impl::outputVariableNames() const
  {
    static std::vector<std::string> result;
    if (result.empty()){
    }
    return result;
  }

  IddObjectType SizingPlant_Impl::iddObjectType() const {
    return SizingPlant::iddObjectType();
  }

  PlantLoop SizingPlant_Impl::plantLoop() const {
    boost::optional<PlantLoop> value = optionalPlantLoop();
    if (!value) {
      LOG_AND_THROW(briefDescription() << " does not have a Plant Loop attached.");
    }
    return value.get();
  }

  std::string SizingPlant_Impl::loopType() const {
    boost::optional<std::string> value = getString(OS_Sizing_PlantFields::LoopType,true);
    OS_ASSERT(value);
    return value.get();
  }

  double SizingPlant_Impl::designLoopExitTemperature() const {
    boost::optional<double> value = getDouble(OS_Sizing_PlantFields::DesignLoopExitTemperature,true);
    OS_ASSERT(value);
    return value.get();
  }

  Quantity SizingPlant_Impl::getDesignLoopExitTemperature(bool returnIP) const {
    OptionalDouble value = designLoopExitTemperature();
    OSOptionalQuantity result = getQuantityFromDouble(OS_Sizing_PlantFields::DesignLoopExitTemperature, value, returnIP);
    OS_ASSERT(result.isSet());
    return result.get();
  }

  double SizingPlant_Impl::loopDesignTemperatureDifference() const {
    boost::optional<double> value = getDouble(OS_Sizing_PlantFields::LoopDesignTemperatureDifference,true);
    OS_ASSERT(value);
    return value.get();
  }

  Quantity SizingPlant_Impl::getLoopDesignTemperatureDifference(bool returnIP) const {
    OptionalDouble value = loopDesignTemperatureDifference();
    OSOptionalQuantity result = getQuantityFromDouble(OS_Sizing_PlantFields::LoopDesignTemperatureDifference, value, returnIP);
    OS_ASSERT(result.isSet());
    return result.get();
  }

  bool SizingPlant_Impl::setPlantLoop(const PlantLoop& plantLoop) {
    bool result = setPointer(OS_Sizing_PlantFields::PlantorCondenserLoopName, plantLoop.handle());
    return result;
  }

  bool SizingPlant_Impl::setLoopType(std::string loopType) {
    bool result = setString(OS_Sizing_PlantFields::LoopType, loopType);
    return result;
  }

  void SizingPlant_Impl::setDesignLoopExitTemperature(double designLoopExitTemperature) {
    bool result = setDouble(OS_Sizing_PlantFields::DesignLoopExitTemperature, designLoopExitTemperature);
    OS_ASSERT(result);
  }

  bool SizingPlant_Impl::setDesignLoopExitTemperature(const Quantity& designLoopExitTemperature) {
    OptionalDouble value = getDoubleFromQuantity(OS_Sizing_PlantFields::DesignLoopExitTemperature,designLoopExitTemperature);
    if (!value) {
      return false;
    }
    setDesignLoopExitTemperature(value.get());
    return true;
  }

  bool SizingPlant_Impl::setLoopDesignTemperatureDifference(double loopDesignTemperatureDifference) {
    bool result = setDouble(OS_Sizing_PlantFields::LoopDesignTemperatureDifference, loopDesignTemperatureDifference);
    return result;
  }

  bool SizingPlant_Impl::setLoopDesignTemperatureDifference(const Quantity& loopDesignTemperatureDifference) {
    OptionalDouble value = getDoubleFromQuantity(OS_Sizing_PlantFields::LoopDesignTemperatureDifference,loopDesignTemperatureDifference);
    if (!value) {
      return false;
    }
    return setLoopDesignTemperatureDifference(value.get());
  }

  boost::optional<PlantLoop> SizingPlant_Impl::optionalPlantLoop() const {
    return getObject<ModelObject>().getModelObjectTarget<PlantLoop>(OS_Sizing_PlantFields::PlantorCondenserLoopName);
  }

  std::vector<std::string> SizingPlant_Impl::loopTypeValues() const {
    return SizingPlant::loopTypeValues();
  }

  openstudio::Quantity SizingPlant_Impl::designLoopExitTemperature_SI() const {
    return getDesignLoopExitTemperature(false);
  }

  openstudio::Quantity SizingPlant_Impl::designLoopExitTemperature_IP() const {
    return getDesignLoopExitTemperature(true);
  }

  openstudio::Quantity SizingPlant_Impl::loopDesignTemperatureDifference_SI() const {
    return getLoopDesignTemperatureDifference(false);
  }

  openstudio::Quantity SizingPlant_Impl::loopDesignTemperatureDifference_IP() const {
    return getLoopDesignTemperatureDifference(true);
  }

  boost::optional<ModelObject> SizingPlant_Impl::plantLoopAsModelObject() const {
    OptionalModelObject result = plantLoop();
    return result;
  }

  bool SizingPlant_Impl::setPlantLoopAsModelObject(const boost::optional<ModelObject>& modelObject) {
    if (modelObject) {
      OptionalPlantLoop intermediate = modelObject->optionalCast<PlantLoop>();
      if (intermediate) {
        PlantLoop plantLoop(*intermediate);
        return setPlantLoop(plantLoop);
      }
    }
    return false;
  }

} // detail

SizingPlant::SizingPlant(const Model& model, const PlantLoop & plantLoop)
  : ModelObject(SizingPlant::iddObjectType(),model)
{
  OS_ASSERT(getImpl<detail::SizingPlant_Impl>());

  setPlantLoop(plantLoop);

  setLoopType("Heating");
  setDesignLoopExitTemperature(82.0);
  setLoopDesignTemperatureDifference(11.0);
}

IddObjectType SizingPlant::iddObjectType() {
  return IddObjectType(IddObjectType::OS_Sizing_Plant);
}

std::vector<std::string> SizingPlant::loopTypeValues() {
  return getIddKeyNames(IddFactory::instance().getObject(iddObjectType()).get(),
                        OS_Sizing_PlantFields::LoopType);
}

PlantLoop SizingPlant::plantLoop() const {
  return getImpl<detail::SizingPlant_Impl>()->plantLoop();
}

std::string SizingPlant::loopType() const {
  return getImpl<detail::SizingPlant_Impl>()->loopType();
}

double SizingPlant::designLoopExitTemperature() const {
  return getImpl<detail::SizingPlant_Impl>()->designLoopExitTemperature();
}

Quantity SizingPlant::getDesignLoopExitTemperature(bool returnIP) const {
  return getImpl<detail::SizingPlant_Impl>()->getDesignLoopExitTemperature(returnIP);
}

double SizingPlant::loopDesignTemperatureDifference() const {
  return getImpl<detail::SizingPlant_Impl>()->loopDesignTemperatureDifference();
}

Quantity SizingPlant::getLoopDesignTemperatureDifference(bool returnIP) const {
  return getImpl<detail::SizingPlant_Impl>()->getLoopDesignTemperatureDifference(returnIP);
}

bool SizingPlant::setPlantLoop(const PlantLoop& plantLoop) {
  return getImpl<detail::SizingPlant_Impl>()->setPlantLoop(plantLoop);
}

bool SizingPlant::setLoopType(std::string loopType) {
  return getImpl<detail::SizingPlant_Impl>()->setLoopType(loopType);
}

void SizingPlant::setDesignLoopExitTemperature(double designLoopExitTemperature) {
  getImpl<detail::SizingPlant_Impl>()->setDesignLoopExitTemperature(designLoopExitTemperature);
}

bool SizingPlant::setDesignLoopExitTemperature(const Quantity& designLoopExitTemperature) {
  return getImpl<detail::SizingPlant_Impl>()->setDesignLoopExitTemperature(designLoopExitTemperature);
}

bool SizingPlant::setLoopDesignTemperatureDifference(double loopDesignTemperatureDifference) {
  return getImpl<detail::SizingPlant_Impl>()->setLoopDesignTemperatureDifference(loopDesignTemperatureDifference);
}

bool SizingPlant::setLoopDesignTemperatureDifference(const Quantity& loopDesignTemperatureDifference) {
  return getImpl<detail::SizingPlant_Impl>()->setLoopDesignTemperatureDifference(loopDesignTemperatureDifference);
}

/// @cond
SizingPlant::SizingPlant(std::shared_ptr<detail::SizingPlant_Impl> impl)
  : ModelObject(impl)
{}
/// @endcond

} // model
} // openstudio

