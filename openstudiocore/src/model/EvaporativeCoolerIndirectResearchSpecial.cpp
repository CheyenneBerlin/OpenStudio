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

#include "EvaporativeCoolerIndirectResearchSpecial.hpp"
#include "EvaporativeCoolerIndirectResearchSpecial_Impl.hpp"
#include "Schedule.hpp"
#include "Schedule_Impl.hpp"
#include "Node.hpp"
#include "Node_Impl.hpp"
#include "Curve.hpp"
#include "Curve_Impl.hpp"
#include "ScheduleTypeLimits.hpp"
#include "ScheduleTypeRegistry.hpp"
#include <utilities/idd/OS_EvaporativeCooler_Indirect_ResearchSpecial_FieldEnums.hxx>
#include <utilities/idd/IddEnums.hxx>
#include "../utilities/units/Unit.hpp"
#include "../utilities/core/Assert.hpp"

namespace openstudio {
namespace model {

namespace detail {

  EvaporativeCoolerIndirectResearchSpecial_Impl::EvaporativeCoolerIndirectResearchSpecial_Impl(const IdfObject& idfObject,
                                                                                               Model_Impl* model,
                                                                                               bool keepHandle)
    : StraightComponent_Impl(idfObject,model,keepHandle)
  {
    OS_ASSERT(idfObject.iddObject().type() == EvaporativeCoolerIndirectResearchSpecial::iddObjectType());
  }

  EvaporativeCoolerIndirectResearchSpecial_Impl::EvaporativeCoolerIndirectResearchSpecial_Impl(const openstudio::detail::WorkspaceObject_Impl& other,
                                                                                               Model_Impl* model,
                                                                                               bool keepHandle)
    : StraightComponent_Impl(other,model,keepHandle)
  {
    OS_ASSERT(other.iddObject().type() == EvaporativeCoolerIndirectResearchSpecial::iddObjectType());
  }

  EvaporativeCoolerIndirectResearchSpecial_Impl::EvaporativeCoolerIndirectResearchSpecial_Impl(const EvaporativeCoolerIndirectResearchSpecial_Impl& other,
                                                                                               Model_Impl* model,
                                                                                               bool keepHandle)
    : StraightComponent_Impl(other,model,keepHandle)
  {}

  const std::vector<std::string>& EvaporativeCoolerIndirectResearchSpecial_Impl::outputVariableNames() const
  {
    static std::vector<std::string> result;
    if (result.empty()){
    }
    return result;
  }

  IddObjectType EvaporativeCoolerIndirectResearchSpecial_Impl::iddObjectType() const {
    return EvaporativeCoolerIndirectResearchSpecial::iddObjectType();
  }

  std::vector<ScheduleTypeKey> EvaporativeCoolerIndirectResearchSpecial_Impl::getScheduleTypeKeys(const Schedule& schedule) const
  {
    std::vector<ScheduleTypeKey> result;
    UnsignedVector fieldIndices = getSourceIndices(schedule.handle());
    UnsignedVector::const_iterator b(fieldIndices.begin()), e(fieldIndices.end());
    if (std::find(b,e,OS_EvaporativeCooler_Indirect_ResearchSpecialFields::AvailabilityScheduleName) != e)
    {
      result.push_back(ScheduleTypeKey("EvaporativeCoolerIndirectResearchSpecial","Availability"));
    }
    return result;
  }

  boost::optional<Schedule> EvaporativeCoolerIndirectResearchSpecial_Impl::availabilitySchedule() const {
    return getObject<ModelObject>().getModelObjectTarget<Schedule>(OS_EvaporativeCooler_Indirect_ResearchSpecialFields::AvailabilityScheduleName);
  }

  double EvaporativeCoolerIndirectResearchSpecial_Impl::coolerMaximumEffectiveness() const {
    boost::optional<double> value = getDouble(OS_EvaporativeCooler_Indirect_ResearchSpecialFields::CoolerMaximumEffectiveness,true);
    OS_ASSERT(value);
    return value.get();
  }

  boost::optional<double> EvaporativeCoolerIndirectResearchSpecial_Impl::recirculatingWaterPumpPowerConsumption() const {
    return getDouble(OS_EvaporativeCooler_Indirect_ResearchSpecialFields::RecirculatingWaterPumpPowerConsumption,true);
  }

  bool EvaporativeCoolerIndirectResearchSpecial_Impl::isRecirculatingWaterPumpPowerConsumptionAutosized() const {
    bool result = false;
    boost::optional<std::string> value = getString(OS_EvaporativeCooler_Indirect_ResearchSpecialFields::RecirculatingWaterPumpPowerConsumption, true);
    if (value) {
      result = openstudio::istringEqual(value.get(), "autosize");
    }
    return result;
  }

  boost::optional<double> EvaporativeCoolerIndirectResearchSpecial_Impl::secondaryFanFlowRate() const {
    return getDouble(OS_EvaporativeCooler_Indirect_ResearchSpecialFields::SecondaryFanFlowRate,true);
  }

  bool EvaporativeCoolerIndirectResearchSpecial_Impl::isSecondaryFanFlowRateAutosized() const {
    bool result = false;
    boost::optional<std::string> value = getString(OS_EvaporativeCooler_Indirect_ResearchSpecialFields::SecondaryFanFlowRate, true);
    if (value) {
      result = openstudio::istringEqual(value.get(), "autosize");
    }
    return result;
  }

  double EvaporativeCoolerIndirectResearchSpecial_Impl::secondaryFanTotalEfficiency() const {
    boost::optional<double> value = getDouble(OS_EvaporativeCooler_Indirect_ResearchSpecialFields::SecondaryFanTotalEfficiency,true);
    OS_ASSERT(value);
    return value.get();
  }

  double EvaporativeCoolerIndirectResearchSpecial_Impl::secondaryFanDeltaPressure() const {
    boost::optional<double> value = getDouble(OS_EvaporativeCooler_Indirect_ResearchSpecialFields::SecondaryFanDeltaPressure,true);
    OS_ASSERT(value);
    return value.get();
  }

  double EvaporativeCoolerIndirectResearchSpecial_Impl::dewpointEffectivenessFactor() const {
    boost::optional<double> value = getDouble(OS_EvaporativeCooler_Indirect_ResearchSpecialFields::DewpointEffectivenessFactor,true);
    OS_ASSERT(value);
    return value.get();
  }

  boost::optional<double> EvaporativeCoolerIndirectResearchSpecial_Impl::driftLossFraction() const {
    return getDouble(OS_EvaporativeCooler_Indirect_ResearchSpecialFields::DriftLossFraction,true);
  }

  boost::optional<double> EvaporativeCoolerIndirectResearchSpecial_Impl::blowdownConcentrationRatio() const {
    return getDouble(OS_EvaporativeCooler_Indirect_ResearchSpecialFields::BlowdownConcentrationRatio,true);
  }

  bool EvaporativeCoolerIndirectResearchSpecial_Impl::setAvailabilitySchedule(Schedule& schedule) {
    bool result = setSchedule(OS_EvaporativeCooler_Indirect_ResearchSpecialFields::AvailabilityScheduleName,
                              "EvaporativeCoolerIndirectResearchSpecial",
                              "Availability",
                              schedule);
    return result;
  }

  void EvaporativeCoolerIndirectResearchSpecial_Impl::resetAvailabilitySchedule() {
    bool result = setString(OS_EvaporativeCooler_Indirect_ResearchSpecialFields::AvailabilityScheduleName, "");
    OS_ASSERT(result);
  }

  bool EvaporativeCoolerIndirectResearchSpecial_Impl::setCoolerMaximumEffectiveness(double coolerMaximumEffectiveness) {
    bool result = setDouble(OS_EvaporativeCooler_Indirect_ResearchSpecialFields::CoolerMaximumEffectiveness, coolerMaximumEffectiveness);
    return result;
  }

  void EvaporativeCoolerIndirectResearchSpecial_Impl::setRecirculatingWaterPumpPowerConsumption(double recirculatingWaterPumpPowerConsumption) {
    bool result = setDouble(OS_EvaporativeCooler_Indirect_ResearchSpecialFields::RecirculatingWaterPumpPowerConsumption, recirculatingWaterPumpPowerConsumption);
    OS_ASSERT(result);
  }

  void EvaporativeCoolerIndirectResearchSpecial_Impl::autosizeRecirculatingWaterPumpPowerConsumption() {
    bool result = setString(OS_EvaporativeCooler_Indirect_ResearchSpecialFields::RecirculatingWaterPumpPowerConsumption, "autosize");
    OS_ASSERT(result);
  }

  bool EvaporativeCoolerIndirectResearchSpecial_Impl::setSecondaryFanFlowRate(boost::optional<double> secondaryFanFlowRate) {
    bool result(false);
    if (secondaryFanFlowRate) {
      result = setDouble(OS_EvaporativeCooler_Indirect_ResearchSpecialFields::SecondaryFanFlowRate, secondaryFanFlowRate.get());
    }
    else {
      resetSecondaryFanFlowRate();
      result = true;
    }
    return result;
  }

  void EvaporativeCoolerIndirectResearchSpecial_Impl::resetSecondaryFanFlowRate() {
    bool result = setString(OS_EvaporativeCooler_Indirect_ResearchSpecialFields::SecondaryFanFlowRate, "");
    OS_ASSERT(result);
  }

  void EvaporativeCoolerIndirectResearchSpecial_Impl::autosizeSecondaryFanFlowRate() {
    bool result = setString(OS_EvaporativeCooler_Indirect_ResearchSpecialFields::SecondaryFanFlowRate, "autosize");
    OS_ASSERT(result);
  }

  bool EvaporativeCoolerIndirectResearchSpecial_Impl::setSecondaryFanTotalEfficiency(double secondaryFanTotalEfficiency) {
    bool result = setDouble(OS_EvaporativeCooler_Indirect_ResearchSpecialFields::SecondaryFanTotalEfficiency, secondaryFanTotalEfficiency);
    return result;
  }

  bool EvaporativeCoolerIndirectResearchSpecial_Impl::setSecondaryFanDeltaPressure(double secondaryFanDeltaPressure) {
    bool result = setDouble(OS_EvaporativeCooler_Indirect_ResearchSpecialFields::SecondaryFanDeltaPressure, secondaryFanDeltaPressure);
    return result;
  }

  void EvaporativeCoolerIndirectResearchSpecial_Impl::setDewpointEffectivenessFactor(double dewpointEffectivenessFactor) {
    bool result = setDouble(OS_EvaporativeCooler_Indirect_ResearchSpecialFields::DewpointEffectivenessFactor, dewpointEffectivenessFactor);
    OS_ASSERT(result);
  }

  bool EvaporativeCoolerIndirectResearchSpecial_Impl::setDriftLossFraction(boost::optional<double> driftLossFraction) {
    bool result(false);
    if (driftLossFraction) {
      result = setDouble(OS_EvaporativeCooler_Indirect_ResearchSpecialFields::DriftLossFraction, driftLossFraction.get());
    }
    else {
      resetDriftLossFraction();
      result = true;
    }
    return result;
  }

  void EvaporativeCoolerIndirectResearchSpecial_Impl::resetDriftLossFraction() {
    bool result = setString(OS_EvaporativeCooler_Indirect_ResearchSpecialFields::DriftLossFraction, "");
    OS_ASSERT(result);
  }

  bool EvaporativeCoolerIndirectResearchSpecial_Impl::setBlowdownConcentrationRatio(boost::optional<double> blowdownConcentrationRatio) {
    bool result(false);
    if (blowdownConcentrationRatio) {
      result = setDouble(OS_EvaporativeCooler_Indirect_ResearchSpecialFields::BlowdownConcentrationRatio, blowdownConcentrationRatio.get());
    }
    else {
      resetBlowdownConcentrationRatio();
      result = true;
    }
    return result;
  }

  void EvaporativeCoolerIndirectResearchSpecial_Impl::resetBlowdownConcentrationRatio() {
    bool result = setString(OS_EvaporativeCooler_Indirect_ResearchSpecialFields::BlowdownConcentrationRatio, "");
    OS_ASSERT(result);
  }

  unsigned EvaporativeCoolerIndirectResearchSpecial_Impl::inletPort()
  {
    return OS_EvaporativeCooler_Indirect_ResearchSpecialFields::PrimaryAirInletNode;
  }

  unsigned EvaporativeCoolerIndirectResearchSpecial_Impl::outletPort()
  {
    return OS_EvaporativeCooler_Indirect_ResearchSpecialFields::PrimaryAirOutletNode;
  }


  bool EvaporativeCoolerIndirectResearchSpecial_Impl::addToNode(Node & node)
  {
    if( boost::optional<AirLoopHVAC> airLoop = node.airLoopHVAC() )
    {
      if( ! airLoop->demandComponent(node.handle()) )
      {
        if( StraightComponent_Impl::addToNode( node ) )
        {
          return true;
        }
      }
    }

    return false;
  }

  bool EvaporativeCoolerIndirectResearchSpecial_Impl::setReliefAirInletNode(const Node & node)
  {
    return setPointer(OS_EvaporativeCooler_Indirect_ResearchSpecialFields::ReliefAirInletNode, node.handle());
  }

  boost::optional<Node> EvaporativeCoolerIndirectResearchSpecial_Impl::reliefAirInletNode() const
  {
    return getObject<ModelObject>().getModelObjectTarget<Node>(OS_EvaporativeCooler_Indirect_ResearchSpecialFields::ReliefAirInletNode);
  }

  boost::optional<Curve> EvaporativeCoolerIndirectResearchSpecial_Impl::wetbulbEffectivenessFlowRatioModifierCurve() const {
    return getObject<ModelObject>().getModelObjectTarget<Curve>(OS_EvaporativeCooler_Indirect_ResearchSpecialFields::WetbulbEffectivenessFlowRatioModifierCurveName);
  }

  boost::optional<double> EvaporativeCoolerIndirectResearchSpecial_Impl::coolerDrybulbDesignEffectiveness() const {
    return getDouble(OS_EvaporativeCooler_Indirect_ResearchSpecialFields::CoolerDrybulbDesignEffectiveness,true);
  }

  boost::optional<Curve> EvaporativeCoolerIndirectResearchSpecial_Impl::drybulbEffectivenessFlowRatioModifierCurve() const {
    return getObject<ModelObject>().getModelObjectTarget<Curve>(OS_EvaporativeCooler_Indirect_ResearchSpecialFields::DrybulbEffectivenessFlowRatioModifierCurveName);
  }

  double EvaporativeCoolerIndirectResearchSpecial_Impl::waterPumpPowerSizingFactor() const {
    boost::optional<double> value = getDouble(OS_EvaporativeCooler_Indirect_ResearchSpecialFields::WaterPumpPowerSizingFactor,true);
    OS_ASSERT(value);
    return value.get();
  }

  boost::optional<Curve> EvaporativeCoolerIndirectResearchSpecial_Impl::waterPumpPowerModifierCurve() const {
    return getObject<ModelObject>().getModelObjectTarget<Curve>(OS_EvaporativeCooler_Indirect_ResearchSpecialFields::WaterPumpPowerModifierCurveName);
  }

  double EvaporativeCoolerIndirectResearchSpecial_Impl::secondaryAirFlowScalingFactor() const {
    boost::optional<double> value = getDouble(OS_EvaporativeCooler_Indirect_ResearchSpecialFields::SecondaryAirFlowScalingFactor,true);
    OS_ASSERT(value);
    return value.get();
  }

  boost::optional<double> EvaporativeCoolerIndirectResearchSpecial_Impl::secondaryAirFanDesignPower() const {
    return getDouble(OS_EvaporativeCooler_Indirect_ResearchSpecialFields::SecondaryAirFanDesignPower,true);
  }

  bool EvaporativeCoolerIndirectResearchSpecial_Impl::isSecondaryAirFanDesignPowerAutosized() const {
    bool result = false;
    boost::optional<std::string> value = getString(OS_EvaporativeCooler_Indirect_ResearchSpecialFields::SecondaryAirFanDesignPower, true);
    if (value) {
      result = openstudio::istringEqual(value.get(), "autosize");
    }
    return result;
  }

  boost::optional<Curve> EvaporativeCoolerIndirectResearchSpecial_Impl::secondaryAirFanPowerModifierCurve() const {
    return getObject<ModelObject>().getModelObjectTarget<Curve>(OS_EvaporativeCooler_Indirect_ResearchSpecialFields::SecondaryAirFanPowerModifierCurveName);
  }

  boost::optional<double> EvaporativeCoolerIndirectResearchSpecial_Impl::primaryDesignAirFlowRate() const {
    return getDouble(OS_EvaporativeCooler_Indirect_ResearchSpecialFields::PrimaryDesignAirFlowRate,true);
  }

  bool EvaporativeCoolerIndirectResearchSpecial_Impl::isPrimaryDesignAirFlowRateAutosized() const {
    bool result = false;
    boost::optional<std::string> value = getString(OS_EvaporativeCooler_Indirect_ResearchSpecialFields::PrimaryDesignAirFlowRate, true);
    if (value) {
      result = openstudio::istringEqual(value.get(), "autosize");
    }
    return result;
  }

  bool EvaporativeCoolerIndirectResearchSpecial_Impl::setWetbulbEffectivenessFlowRatioModifierCurve(const boost::optional<Curve>& curve) {
    bool result(false);
    if (curve) {
      result = setPointer(OS_EvaporativeCooler_Indirect_ResearchSpecialFields::WetbulbEffectivenessFlowRatioModifierCurveName, curve.get().handle());
    }
    else {
      resetWetbulbEffectivenessFlowRatioModifierCurve();
      result = true;
    }
    return result;
  }

  void EvaporativeCoolerIndirectResearchSpecial_Impl::resetWetbulbEffectivenessFlowRatioModifierCurve() {
    bool result = setString(OS_EvaporativeCooler_Indirect_ResearchSpecialFields::WetbulbEffectivenessFlowRatioModifierCurveName, "");
    OS_ASSERT(result);
  }

  bool EvaporativeCoolerIndirectResearchSpecial_Impl::setCoolerDrybulbDesignEffectiveness(boost::optional<double> coolerDrybulbDesignEffectiveness) {
    bool result(false);
    if (coolerDrybulbDesignEffectiveness) {
      result = setDouble(OS_EvaporativeCooler_Indirect_ResearchSpecialFields::CoolerDrybulbDesignEffectiveness, coolerDrybulbDesignEffectiveness.get());
    }
    else {
      resetCoolerDrybulbDesignEffectiveness();
      result = true;
    }
    return result;
  }

  void EvaporativeCoolerIndirectResearchSpecial_Impl::resetCoolerDrybulbDesignEffectiveness() {
    bool result = setString(OS_EvaporativeCooler_Indirect_ResearchSpecialFields::CoolerDrybulbDesignEffectiveness, "");
    OS_ASSERT(result);
  }

  bool EvaporativeCoolerIndirectResearchSpecial_Impl::setDrybulbEffectivenessFlowRatioModifierCurve(const boost::optional<Curve>& curve) {
    bool result(false);
    if (curve) {
      result = setPointer(OS_EvaporativeCooler_Indirect_ResearchSpecialFields::DrybulbEffectivenessFlowRatioModifierCurveName, curve.get().handle());
    }
    else {
      resetDrybulbEffectivenessFlowRatioModifierCurve();
      result = true;
    }
    return result;
  }

  void EvaporativeCoolerIndirectResearchSpecial_Impl::resetDrybulbEffectivenessFlowRatioModifierCurve() {
    bool result = setString(OS_EvaporativeCooler_Indirect_ResearchSpecialFields::DrybulbEffectivenessFlowRatioModifierCurveName, "");
    OS_ASSERT(result);
  }

  void EvaporativeCoolerIndirectResearchSpecial_Impl::setWaterPumpPowerSizingFactor(double waterPumpPowerSizingFactor) {
    bool result = setDouble(OS_EvaporativeCooler_Indirect_ResearchSpecialFields::WaterPumpPowerSizingFactor, waterPumpPowerSizingFactor);
    OS_ASSERT(result);
  }

  bool EvaporativeCoolerIndirectResearchSpecial_Impl::setWaterPumpPowerModifierCurve(const boost::optional<Curve>& curve) {
    bool result(false);
    if (curve) {
      result = setPointer(OS_EvaporativeCooler_Indirect_ResearchSpecialFields::WaterPumpPowerModifierCurveName, curve.get().handle());
    }
    else {
      resetWaterPumpPowerModifierCurve();
      result = true;
    }
    return result;
  }

  void EvaporativeCoolerIndirectResearchSpecial_Impl::resetWaterPumpPowerModifierCurve() {
    bool result = setString(OS_EvaporativeCooler_Indirect_ResearchSpecialFields::WaterPumpPowerModifierCurveName, "");
    OS_ASSERT(result);
  }

  void EvaporativeCoolerIndirectResearchSpecial_Impl::setSecondaryAirFlowScalingFactor(double secondaryAirFlowScalingFactor) {
    bool result = setDouble(OS_EvaporativeCooler_Indirect_ResearchSpecialFields::SecondaryAirFlowScalingFactor, secondaryAirFlowScalingFactor);
    OS_ASSERT(result);
  }

  void EvaporativeCoolerIndirectResearchSpecial_Impl::setSecondaryAirFanDesignPower(boost::optional<double> secondaryAirFanDesignPower) {
    bool result(false);
    if (secondaryAirFanDesignPower) {
      result = setDouble(OS_EvaporativeCooler_Indirect_ResearchSpecialFields::SecondaryAirFanDesignPower, secondaryAirFanDesignPower.get());
    }
    OS_ASSERT(result);
  }

  void EvaporativeCoolerIndirectResearchSpecial_Impl::autosizeSecondaryAirFanDesignPower() {
    bool result = setString(OS_EvaporativeCooler_Indirect_ResearchSpecialFields::SecondaryAirFanDesignPower, "autosize");
    OS_ASSERT(result);
  }

  bool EvaporativeCoolerIndirectResearchSpecial_Impl::setSecondaryAirFanPowerModifierCurve(const boost::optional<Curve>& curve) {
    bool result(false);
    if (curve) {
      result = setPointer(OS_EvaporativeCooler_Indirect_ResearchSpecialFields::SecondaryAirFanPowerModifierCurveName, curve.get().handle());
    }
    else {
      resetSecondaryAirFanPowerModifierCurve();
      result = true;
    }
    return result;
  }

  void EvaporativeCoolerIndirectResearchSpecial_Impl::resetSecondaryAirFanPowerModifierCurve() {
    bool result = setString(OS_EvaporativeCooler_Indirect_ResearchSpecialFields::SecondaryAirFanPowerModifierCurveName, "");
    OS_ASSERT(result);
  }

  bool EvaporativeCoolerIndirectResearchSpecial_Impl::setPrimaryDesignAirFlowRate(boost::optional<double> primaryDesignAirFlowRate) {
    bool result(false);
    if (primaryDesignAirFlowRate) {
      result = setDouble(OS_EvaporativeCooler_Indirect_ResearchSpecialFields::PrimaryDesignAirFlowRate, primaryDesignAirFlowRate.get());
    }
    else {
      resetPrimaryDesignAirFlowRate();
      result = true;
    }
    return result;
  }

  void EvaporativeCoolerIndirectResearchSpecial_Impl::resetPrimaryDesignAirFlowRate() {
    bool result = setString(OS_EvaporativeCooler_Indirect_ResearchSpecialFields::PrimaryDesignAirFlowRate, "");
    OS_ASSERT(result);
  }

  void EvaporativeCoolerIndirectResearchSpecial_Impl::autosizePrimaryDesignAirFlowRate() {
    bool result = setString(OS_EvaporativeCooler_Indirect_ResearchSpecialFields::PrimaryDesignAirFlowRate, "autosize");
    OS_ASSERT(result);
  }

} // detail

EvaporativeCoolerIndirectResearchSpecial::EvaporativeCoolerIndirectResearchSpecial(const Model& model)
  : StraightComponent(EvaporativeCoolerIndirectResearchSpecial::iddObjectType(),model)
{
  OS_ASSERT(getImpl<detail::EvaporativeCoolerIndirectResearchSpecial_Impl>());

  setCoolerMaximumEffectiveness(0.75);
  setRecirculatingWaterPumpPowerConsumption(30.0);
  setSecondaryFanTotalEfficiency(0.6);
  setSecondaryFanDeltaPressure(124.6);
  setDewpointEffectivenessFactor(0.9);
  setDriftLossFraction(0.0);
  setWaterPumpPowerSizingFactor(0.1);
  setSecondaryAirFlowScalingFactor(1.0);
  resetBlowdownConcentrationRatio();
}

IddObjectType EvaporativeCoolerIndirectResearchSpecial::iddObjectType() {
  return IddObjectType(IddObjectType::OS_EvaporativeCooler_Indirect_ResearchSpecial);
}

boost::optional<Schedule> EvaporativeCoolerIndirectResearchSpecial::availabilitySchedule() const {
  return getImpl<detail::EvaporativeCoolerIndirectResearchSpecial_Impl>()->availabilitySchedule();
}

double EvaporativeCoolerIndirectResearchSpecial::coolerMaximumEffectiveness() const {
  return getImpl<detail::EvaporativeCoolerIndirectResearchSpecial_Impl>()->coolerMaximumEffectiveness();
}

boost::optional<double> EvaporativeCoolerIndirectResearchSpecial::recirculatingWaterPumpPowerConsumption() const {
  return getImpl<detail::EvaporativeCoolerIndirectResearchSpecial_Impl>()->recirculatingWaterPumpPowerConsumption();
}

bool EvaporativeCoolerIndirectResearchSpecial::isRecirculatingWaterPumpPowerConsumptionAutosized() const {
  return getImpl<detail::EvaporativeCoolerIndirectResearchSpecial_Impl>()->isRecirculatingWaterPumpPowerConsumptionAutosized();
}

boost::optional<double> EvaporativeCoolerIndirectResearchSpecial::secondaryFanFlowRate() const {
  return getImpl<detail::EvaporativeCoolerIndirectResearchSpecial_Impl>()->secondaryFanFlowRate();
}

bool EvaporativeCoolerIndirectResearchSpecial::isSecondaryFanFlowRateAutosized() const {
  return getImpl<detail::EvaporativeCoolerIndirectResearchSpecial_Impl>()->isSecondaryFanFlowRateAutosized();
}

double EvaporativeCoolerIndirectResearchSpecial::secondaryFanTotalEfficiency() const {
  return getImpl<detail::EvaporativeCoolerIndirectResearchSpecial_Impl>()->secondaryFanTotalEfficiency();
}

double EvaporativeCoolerIndirectResearchSpecial::secondaryFanDeltaPressure() const {
  return getImpl<detail::EvaporativeCoolerIndirectResearchSpecial_Impl>()->secondaryFanDeltaPressure();
}

double EvaporativeCoolerIndirectResearchSpecial::dewpointEffectivenessFactor() const {
  return getImpl<detail::EvaporativeCoolerIndirectResearchSpecial_Impl>()->dewpointEffectivenessFactor();
}

boost::optional<double> EvaporativeCoolerIndirectResearchSpecial::driftLossFraction() const {
  return getImpl<detail::EvaporativeCoolerIndirectResearchSpecial_Impl>()->driftLossFraction();
}

boost::optional<double> EvaporativeCoolerIndirectResearchSpecial::blowdownConcentrationRatio() const {
  return getImpl<detail::EvaporativeCoolerIndirectResearchSpecial_Impl>()->blowdownConcentrationRatio();
}

boost::optional<Curve> EvaporativeCoolerIndirectResearchSpecial::wetbulbEffectivenessFlowRatioModifierCurve() const {
  return getImpl<detail::EvaporativeCoolerIndirectResearchSpecial_Impl>()->wetbulbEffectivenessFlowRatioModifierCurve();
}

boost::optional<double> EvaporativeCoolerIndirectResearchSpecial::coolerDrybulbDesignEffectiveness() const {
  return getImpl<detail::EvaporativeCoolerIndirectResearchSpecial_Impl>()->coolerDrybulbDesignEffectiveness();
}

boost::optional<Curve> EvaporativeCoolerIndirectResearchSpecial::drybulbEffectivenessFlowRatioModifierCurve() const {
  return getImpl<detail::EvaporativeCoolerIndirectResearchSpecial_Impl>()->drybulbEffectivenessFlowRatioModifierCurve();
}

double EvaporativeCoolerIndirectResearchSpecial::waterPumpPowerSizingFactor() const {
  return getImpl<detail::EvaporativeCoolerIndirectResearchSpecial_Impl>()->waterPumpPowerSizingFactor();
}

boost::optional<Curve> EvaporativeCoolerIndirectResearchSpecial::waterPumpPowerModifierCurve() const {
  return getImpl<detail::EvaporativeCoolerIndirectResearchSpecial_Impl>()->waterPumpPowerModifierCurve();
}

double EvaporativeCoolerIndirectResearchSpecial::secondaryAirFlowScalingFactor() const {
  return getImpl<detail::EvaporativeCoolerIndirectResearchSpecial_Impl>()->secondaryAirFlowScalingFactor();
}

boost::optional<double> EvaporativeCoolerIndirectResearchSpecial::secondaryAirFanDesignPower() const {
  return getImpl<detail::EvaporativeCoolerIndirectResearchSpecial_Impl>()->secondaryAirFanDesignPower();
}

bool EvaporativeCoolerIndirectResearchSpecial::isSecondaryAirFanDesignPowerAutosized() const {
  return getImpl<detail::EvaporativeCoolerIndirectResearchSpecial_Impl>()->isSecondaryAirFanDesignPowerAutosized();
}

boost::optional<Curve> EvaporativeCoolerIndirectResearchSpecial::secondaryAirFanPowerModifierCurve() const {
  return getImpl<detail::EvaporativeCoolerIndirectResearchSpecial_Impl>()->secondaryAirFanPowerModifierCurve();
}

boost::optional<double> EvaporativeCoolerIndirectResearchSpecial::primaryDesignAirFlowRate() const {
  return getImpl<detail::EvaporativeCoolerIndirectResearchSpecial_Impl>()->primaryDesignAirFlowRate();
}

bool EvaporativeCoolerIndirectResearchSpecial::isPrimaryDesignAirFlowRateAutosized() const {
  return getImpl<detail::EvaporativeCoolerIndirectResearchSpecial_Impl>()->isPrimaryDesignAirFlowRateAutosized();
}

bool EvaporativeCoolerIndirectResearchSpecial::setAvailabilitySchedule(Schedule& schedule) {
  return getImpl<detail::EvaporativeCoolerIndirectResearchSpecial_Impl>()->setAvailabilitySchedule(schedule);
}

void EvaporativeCoolerIndirectResearchSpecial::resetAvailabilitySchedule() {
  getImpl<detail::EvaporativeCoolerIndirectResearchSpecial_Impl>()->resetAvailabilitySchedule();
}

bool EvaporativeCoolerIndirectResearchSpecial::setCoolerMaximumEffectiveness(double coolerMaximumEffectiveness) {
  return getImpl<detail::EvaporativeCoolerIndirectResearchSpecial_Impl>()->setCoolerMaximumEffectiveness(coolerMaximumEffectiveness);
}

void EvaporativeCoolerIndirectResearchSpecial::setRecirculatingWaterPumpPowerConsumption(double recirculatingWaterPumpPowerConsumption) {
  getImpl<detail::EvaporativeCoolerIndirectResearchSpecial_Impl>()->setRecirculatingWaterPumpPowerConsumption(recirculatingWaterPumpPowerConsumption);
}

void EvaporativeCoolerIndirectResearchSpecial::autosizeRecirculatingWaterPumpPowerConsumption() {
  getImpl<detail::EvaporativeCoolerIndirectResearchSpecial_Impl>()->autosizeRecirculatingWaterPumpPowerConsumption();
}

bool EvaporativeCoolerIndirectResearchSpecial::setSecondaryFanFlowRate(double secondaryFanFlowRate) {
  return getImpl<detail::EvaporativeCoolerIndirectResearchSpecial_Impl>()->setSecondaryFanFlowRate(secondaryFanFlowRate);
}

void EvaporativeCoolerIndirectResearchSpecial::resetSecondaryFanFlowRate() {
  getImpl<detail::EvaporativeCoolerIndirectResearchSpecial_Impl>()->resetSecondaryFanFlowRate();
}

void EvaporativeCoolerIndirectResearchSpecial::autosizeSecondaryFanFlowRate() {
  getImpl<detail::EvaporativeCoolerIndirectResearchSpecial_Impl>()->autosizeSecondaryFanFlowRate();
}

bool EvaporativeCoolerIndirectResearchSpecial::setSecondaryFanTotalEfficiency(double secondaryFanTotalEfficiency) {
  return getImpl<detail::EvaporativeCoolerIndirectResearchSpecial_Impl>()->setSecondaryFanTotalEfficiency(secondaryFanTotalEfficiency);
}

bool EvaporativeCoolerIndirectResearchSpecial::setSecondaryFanDeltaPressure(double secondaryFanDeltaPressure) {
  return getImpl<detail::EvaporativeCoolerIndirectResearchSpecial_Impl>()->setSecondaryFanDeltaPressure(secondaryFanDeltaPressure);
}

void EvaporativeCoolerIndirectResearchSpecial::setDewpointEffectivenessFactor(double dewpointEffectivenessFactor) {
  getImpl<detail::EvaporativeCoolerIndirectResearchSpecial_Impl>()->setDewpointEffectivenessFactor(dewpointEffectivenessFactor);
}

bool EvaporativeCoolerIndirectResearchSpecial::setDriftLossFraction(double driftLossFraction) {
  return getImpl<detail::EvaporativeCoolerIndirectResearchSpecial_Impl>()->setDriftLossFraction(driftLossFraction);
}

void EvaporativeCoolerIndirectResearchSpecial::resetDriftLossFraction() {
  getImpl<detail::EvaporativeCoolerIndirectResearchSpecial_Impl>()->resetDriftLossFraction();
}

bool EvaporativeCoolerIndirectResearchSpecial::setBlowdownConcentrationRatio(double blowdownConcentrationRatio) {
  return getImpl<detail::EvaporativeCoolerIndirectResearchSpecial_Impl>()->setBlowdownConcentrationRatio(blowdownConcentrationRatio);
}

void EvaporativeCoolerIndirectResearchSpecial::resetBlowdownConcentrationRatio() {
  getImpl<detail::EvaporativeCoolerIndirectResearchSpecial_Impl>()->resetBlowdownConcentrationRatio();
}

bool EvaporativeCoolerIndirectResearchSpecial::setWetbulbEffectivenessFlowRatioModifierCurve(const Curve& curve) {
  return getImpl<detail::EvaporativeCoolerIndirectResearchSpecial_Impl>()->setWetbulbEffectivenessFlowRatioModifierCurve(curve);
}

void EvaporativeCoolerIndirectResearchSpecial::resetWetbulbEffectivenessFlowRatioModifierCurve() {
  getImpl<detail::EvaporativeCoolerIndirectResearchSpecial_Impl>()->resetWetbulbEffectivenessFlowRatioModifierCurve();
}

bool EvaporativeCoolerIndirectResearchSpecial::setCoolerDrybulbDesignEffectiveness(double coolerDrybulbDesignEffectiveness) {
  return getImpl<detail::EvaporativeCoolerIndirectResearchSpecial_Impl>()->setCoolerDrybulbDesignEffectiveness(coolerDrybulbDesignEffectiveness);
}

void EvaporativeCoolerIndirectResearchSpecial::resetCoolerDrybulbDesignEffectiveness() {
  getImpl<detail::EvaporativeCoolerIndirectResearchSpecial_Impl>()->resetCoolerDrybulbDesignEffectiveness();
}

bool EvaporativeCoolerIndirectResearchSpecial::setDrybulbEffectivenessFlowRatioModifierCurve(const Curve& curve) {
  return getImpl<detail::EvaporativeCoolerIndirectResearchSpecial_Impl>()->setDrybulbEffectivenessFlowRatioModifierCurve(curve);
}

void EvaporativeCoolerIndirectResearchSpecial::resetDrybulbEffectivenessFlowRatioModifierCurve() {
  getImpl<detail::EvaporativeCoolerIndirectResearchSpecial_Impl>()->resetDrybulbEffectivenessFlowRatioModifierCurve();
}

void EvaporativeCoolerIndirectResearchSpecial::setWaterPumpPowerSizingFactor(double waterPumpPowerSizingFactor) {
  getImpl<detail::EvaporativeCoolerIndirectResearchSpecial_Impl>()->setWaterPumpPowerSizingFactor(waterPumpPowerSizingFactor);
}

bool EvaporativeCoolerIndirectResearchSpecial::setWaterPumpPowerModifierCurve(const Curve& curve) {
  return getImpl<detail::EvaporativeCoolerIndirectResearchSpecial_Impl>()->setWaterPumpPowerModifierCurve(curve);
}

void EvaporativeCoolerIndirectResearchSpecial::resetWaterPumpPowerModifierCurve() {
  getImpl<detail::EvaporativeCoolerIndirectResearchSpecial_Impl>()->resetWaterPumpPowerModifierCurve();
}

void EvaporativeCoolerIndirectResearchSpecial::setSecondaryAirFlowScalingFactor(double secondaryAirFlowScalingFactor) {
  getImpl<detail::EvaporativeCoolerIndirectResearchSpecial_Impl>()->setSecondaryAirFlowScalingFactor(secondaryAirFlowScalingFactor);
}

void EvaporativeCoolerIndirectResearchSpecial::setSecondaryAirFanDesignPower(double secondaryAirFanDesignPower) {
  getImpl<detail::EvaporativeCoolerIndirectResearchSpecial_Impl>()->setSecondaryAirFanDesignPower(secondaryAirFanDesignPower);
}

void EvaporativeCoolerIndirectResearchSpecial::autosizeSecondaryAirFanDesignPower() {
  getImpl<detail::EvaporativeCoolerIndirectResearchSpecial_Impl>()->autosizeSecondaryAirFanDesignPower();
}

bool EvaporativeCoolerIndirectResearchSpecial::setSecondaryAirFanPowerModifierCurve(const Curve& curve) {
  return getImpl<detail::EvaporativeCoolerIndirectResearchSpecial_Impl>()->setSecondaryAirFanPowerModifierCurve(curve);
}

void EvaporativeCoolerIndirectResearchSpecial::resetSecondaryAirFanPowerModifierCurve() {
  getImpl<detail::EvaporativeCoolerIndirectResearchSpecial_Impl>()->resetSecondaryAirFanPowerModifierCurve();
}

bool EvaporativeCoolerIndirectResearchSpecial::setPrimaryDesignAirFlowRate(double primaryDesignAirFlowRate) {
  return getImpl<detail::EvaporativeCoolerIndirectResearchSpecial_Impl>()->setPrimaryDesignAirFlowRate(primaryDesignAirFlowRate);
}

void EvaporativeCoolerIndirectResearchSpecial::resetPrimaryDesignAirFlowRate() {
  getImpl<detail::EvaporativeCoolerIndirectResearchSpecial_Impl>()->resetPrimaryDesignAirFlowRate();
}

void EvaporativeCoolerIndirectResearchSpecial::autosizePrimaryDesignAirFlowRate() {
  getImpl<detail::EvaporativeCoolerIndirectResearchSpecial_Impl>()->autosizePrimaryDesignAirFlowRate();
}

/// @cond
EvaporativeCoolerIndirectResearchSpecial::EvaporativeCoolerIndirectResearchSpecial(std::shared_ptr<detail::EvaporativeCoolerIndirectResearchSpecial_Impl> impl)
  : StraightComponent(impl)
{}
/// @endcond

} // model
} // openstudio

