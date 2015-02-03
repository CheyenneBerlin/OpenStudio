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
#include <utilities/idd/OS_Timestep_FieldEnums.hxx>
#include <utilities/idd/Timestep_FieldEnums.hxx>
#include <memory>

#include "../../model/Timestep.hpp"
#include "../../utilities/idd/IddEnums.hpp"
#include "../ReverseTranslator.hpp"
#include "energyplus/ReverseTranslator/../../model/../utilities/idd/../core/EnumBase.hpp"
#include "energyplus/ReverseTranslator/../../model/../utilities/idd/../core/LogMessage.hpp"
#include "energyplus/ReverseTranslator/../../model/../utilities/idd/../core/Logger.hpp"
#include "energyplus/ReverseTranslator/../../model/../utilities/idd/IddObject.hpp"
#include "energyplus/ReverseTranslator/../../model/../utilities/idf/WorkspaceObject.hpp"
#include "energyplus/ReverseTranslator/../../model/Model.hpp"
#include "energyplus/ReverseTranslator/../../model/ModelObject.hpp"

using namespace openstudio::model;

namespace openstudio {

namespace energyplus {

OptionalModelObject ReverseTranslator::translateTimestep( const WorkspaceObject & workspaceObject )
{
  if( workspaceObject.iddObject().type() != IddObjectType::Timestep )
  {
     LOG(Error, "WorkspaceObject is not IddObjectType: Timestep");
     return boost::none;
  }

  Timestep mo = m_model.getUniqueModelObject<Timestep>();

  boost::optional<int> i = workspaceObject.getInt(TimestepFields::NumberofTimestepsperHour);
  if( i )
  {
    mo.setInt(OS_TimestepFields::NumberofTimestepsperHour,i.get());
  } 

  return mo;
}

} // energyplus

} // openstudio

