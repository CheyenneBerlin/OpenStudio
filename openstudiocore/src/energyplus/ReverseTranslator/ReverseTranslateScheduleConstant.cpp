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

#include <boost/none.hpp>
#include <boost/optional/optional.hpp>
#include <utilities/idd/IddEnums.hxx>
#include <utilities/idd/OS_Schedule_Constant_FieldEnums.hxx>
#include <utilities/idd/Schedule_Constant_FieldEnums.hxx>

#include "../../model/ScheduleConstant.hpp"
#include "../../utilities/idd/IddEnums.hpp"
#include "../ReverseTranslator.hpp"
#include "energyplus/ReverseTranslator/../../model/../utilities/idd/../core/EnumBase.hpp"
#include "energyplus/ReverseTranslator/../../model/../utilities/idd/../core/LogMessage.hpp"
#include "energyplus/ReverseTranslator/../../model/../utilities/idd/../core/Logger.hpp"
#include "energyplus/ReverseTranslator/../../model/../utilities/idd/../core/Optional.hpp"
#include "energyplus/ReverseTranslator/../../model/../utilities/idd/IddObject.hpp"
#include "energyplus/ReverseTranslator/../../model/../utilities/idf/WorkspaceObject.hpp"
#include "energyplus/ReverseTranslator/../../model/ModelObject.hpp"

using namespace openstudio::model;

namespace openstudio {

namespace energyplus {

OptionalModelObject ReverseTranslator::translateScheduleConstant( const WorkspaceObject & workspaceObject )
{
  if( workspaceObject.iddObject().type() != IddObjectType::Schedule_Constant )
  {
    LOG(Error, "WorkspaceObject is not IddObjectType: Schedule:Constant");
    return boost::none;
  }

  ScheduleConstant scheduleConstant(m_model);

  boost::optional<WorkspaceObject> target = workspaceObject.getTarget(Schedule_ConstantFields::ScheduleTypeLimitsName);
  if (target){
    OptionalModelObject scheduleTypeLimits = translateAndMapWorkspaceObject(*target);
    if (scheduleTypeLimits) {
      scheduleConstant.setPointer(OS_Schedule_ConstantFields::ScheduleTypeLimitsName, scheduleTypeLimits->handle());
    }
  }
  if (OptionalDouble val = workspaceObject.getDouble(Schedule_ConstantFields::HourlyValue)) {
    scheduleConstant.setValue(*val);
  }

  return scheduleConstant;
}

} // energyplus

} // openstudio

