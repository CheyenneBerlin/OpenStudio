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

#ifndef RUNMANAGER_LIB_CONFIGOPTIONS_HPP
#define RUNMANAGER_LIB_CONFIGOPTIONS_HPP

#include <boost/preprocessor/arithmetic/dec.hpp>
#include <boost/preprocessor/arithmetic/inc.hpp>
#include <boost/preprocessor/comparison/not_equal.hpp>
#include <boost/preprocessor/control/expr_iif.hpp>
#include <boost/preprocessor/control/iif.hpp>
#include <boost/preprocessor/detail/auto_rec.hpp>
#include <boost/preprocessor/logical/bool.hpp>
#include <boost/preprocessor/logical/compl.hpp>
#include <boost/preprocessor/repetition/detail/for.hpp>
#include <boost/preprocessor/repetition/for.hpp>
#include <boost/preprocessor/seq/elem.hpp>
#include <boost/preprocessor/seq/size.hpp>
#include <boost/preprocessor/tuple/elem.hpp>
#include <ostream>
#include <set>
#include <string>
#include <utility>
#include <vector>

#include "../../utilities/core/Enum.hpp"
#include "../../utilities/core/Path.hpp"
#include "RunManagerAPI.hpp"
#include "ToolInfo.hpp"
#include "runmanager/lib/../../utilities/core/LogMessage.hpp"
#include "runmanager/lib/../../utilities/core/Logger.hpp"

namespace openstudio {
namespace runmanager {

  /** \class ToolType
   *
   *  \relates ToolLocationInfo */
  OPENSTUDIO_ENUM(ToolType,
      ((EnergyPlus))
      ((Radiance))
      ((Ruby))
      ((XMLPreprocessor)(XML Pre-processor))
      ((Dakota))
    );

  /// Contains information about a tool installation
  class RUNMANAGER_API ToolLocationInfo
  {
    public:
      ToolLocationInfo() {} 

      /** 
       *  \param[in] t_type Enumeration value specifying a tool/application
       *  \param[in] t_bindir Path to the binary for local execution */
      ToolLocationInfo(const ToolType &t_type, 
                       const openstudio::path &t_bindir);

      bool operator<(const ToolLocationInfo &rhs) const;
      bool operator==(const ToolLocationInfo &rhs) const;

      /// Type of tool at this location
      ToolType toolType;

      /// Location of binary for local execution
      openstudio::path binaryDir;
  };

  /// Operator overload for streaming ToolLocationInfo to ostream
  RUNMANAGER_API std::ostream &operator<<(std::ostream &os, const ToolLocationInfo &epi);


  //! Stores configuration options for the runmanager project
  //! \sa openstudio::runmanager::Configuration
  class RUNMANAGER_API ConfigOptions
  {
    public:
      //! Constructor to set intelligent defaults for the current system
      //! Defaults to max parallel local jobs as number of hardware threads - 1
      explicit ConfigOptions(bool t_loadQSettings = false);

      //! Automatically find tools and add them to the ConfigOptions
      bool findTools(bool t_showProgressDialog, bool t_onlyIfZeroTools=false, bool t_promptUser=false, bool t_checkQSettings=false);

      //! Automatically find EnergyPlus if it is in a well defined, known place, then add to ConfigOptions
      void fastFindEnergyPlus();

      //! Automatically find Radiance if it is in a well defined, known place, then add to ConfigOptions
      void fastFindRadiance();

      //! Saves the tools to the appropriate QSettings location.
      void saveQSettings() const;

      //! Add a tool to the list of known versions
      void setToolLocation(const ToolVersion &t_epv, const ToolLocationInfo &t_info);

      //! get all known version / path pairs
      std::vector<std::pair<ToolVersion, ToolLocationInfo> > getToolLocations() const;

      //! get all known tools for passing to jobs
      openstudio::runmanager::Tools getTools() const;

      //! Convert a pair returned from getToolLocation to a ToolInfo object
      //! appropriate for creating an EnergyPlusJob
      //! \param[in] eplus results from getToolLocations create ToolInfo from
      static openstudio::runmanager::ToolInfo toEPlusToolInfo(const std::pair<ToolVersion, ToolLocationInfo> &eplus);

      //! Convert a pair returned from getToolLocation to a ToolInfo object
      //! appropriate for creating an ExpandObjects job
      //! \param[in] eplus results from getToolLocations create ToolInfo from
      static openstudio::runmanager::ToolInfo toExpandObjectsToolInfo(const std::pair<ToolVersion, ToolLocationInfo> &eplus);

      //! Convert a pair returned from getToolLocation to a ToolInfo object
      //! appropriate for creating a Basement job
      //! \param[in] eplus results from getToolLocations create ToolInfo from
      static openstudio::runmanager::ToolInfo toBasementToolInfo(const std::pair<ToolVersion, ToolLocationInfo> &eplus);
      
      //! Convert a pair returned from getToolLocation to a ToolInfo object
      //! appropriate for creating a Slab job
      //! \param[in] eplus results from getToolLocations create ToolInfo from
      static openstudio::runmanager::ToolInfo toSlabToolInfo(const std::pair<ToolVersion, ToolLocationInfo> &eplus);
      
      //! Convert a pair returned from getToolLocation to a ToolInfo object
      //! appropriate for creating an xmlpreprocessor job
      //! \param[in] preproc results from getToolLocations create ToolInfo from
      static openstudio::runmanager::ToolInfo 
        toXMLPreprocessorToolInfo(const std::pair<ToolVersion, ToolLocationInfo> &preproc);


      //! Convert a pair returned from getToolLocation to a ToolInfo object
      //! appropriate for creating an ies2rad job
      //! \param[in] rad results from getToolLocations create ToolInfo from
      static openstudio::runmanager::ToolInfo toIES2RadToolInfo(const std::pair<ToolVersion, ToolLocationInfo> &rad);

      //! Convert a pair returned from getToolLocation to a ToolInfo object
      //! appropriate for creating an ra_image job
      //! \param[in] rad results from getToolLocations create ToolInfo from
      static openstudio::runmanager::ToolInfo toRaImageToolInfo(const std::pair<ToolVersion, ToolLocationInfo> &rad);

      //! Convert a pair returned from getToolLocation to a ToolInfo object
      //! appropriate for creating a rad job
      //! \param[in] rad results from getToolLocations create ToolInfo from
      static openstudio::runmanager::ToolInfo toRadToolInfo(const std::pair<ToolVersion, ToolLocationInfo> &rad);

      //! Convert a pair returned from getToolLocation to a ToolInfo object
      //! appropriate for creating a rtrace job
      //! \param[in] rtrace results from getToolLocations create ToolInfo from
      static openstudio::runmanager::ToolInfo toRTraceToolInfo(const std::pair<ToolVersion, ToolLocationInfo> &rtrace);

      //! Convert a pair returned from getToolLocation to a ToolInfo object
      //! appropriate for creating a epw job
      //! \param[in] eplus results from getToolLocations create ToolInfo from
      static openstudio::runmanager::ToolInfo toEpw2Wea(const std::pair<ToolVersion, ToolLocationInfo> &eplus);

      //! Convert a pair returned from getToolLocation to a ToolInfo object
      //! appropriate for creating a ruby RubyJob
      //! \param[in] ruby results from getToolLocations create ToolInfo from
      static openstudio::runmanager::ToolInfo toRubyToolInfo(const std::pair<ToolVersion, ToolLocationInfo> &ruby);

      //! Convert a pair returned from getToolLocation to a ToolInfo object
      //! appropriate for creating a DakotaJob
      //! \param[in] dakota result from getToolLocations create ToolInfo from
      static openstudio::runmanager::ToolInfo toDakotaToolInfo(const std::pair<ToolVersion, ToolLocationInfo>& dakota);

      //! Convert a pair returned from getToolLocation to a ToolInfo object
      //! \param[in] t_type Type of tool to create
      //! \param[in] t_tool results from getToolLocations create ToolInfo from
      static openstudio::runmanager::Tools makeTools(
          const ToolType &t_type,
          const std::pair<ToolVersion, ToolLocationInfo> &t_tool);

      //! Convert some paths into standard understood ToolInfo objects. The created
      //! ToolInfos have version numbers determined by ToolFinder::parseToolVersion.
      //! \param[in] t_energyplus Path to energy plus binaries
      //! \param[in] t_xmlpreproc Path to xmlpreproc binary
      //! \param[in] t_radiance Path to radiance binaries
      //! \param[in] t_ruby Path to ruby binary
      //! \param[in] t_dakota Path to dakota binary
      static openstudio::runmanager::Tools makeTools(const openstudio::path &t_energyplus, 
                                                     const openstudio::path &t_xmlpreproc, 
                                                     const openstudio::path &t_radiance,
                                                     const openstudio::path &t_ruby,
                                                     const openstudio::path &t_dakota);

      //! Construct a ToolInfo object from the set of information
      //! used as a convenience function
      //! \param[in] t_type Type of tool to create
      //! \param[in] t_local Path to local binaries for tool
      //! \param[in] t_version Version info to attach to created Tools
      static openstudio::runmanager::Tools makeTools(
          const ToolType &t_type,
          const openstudio::path &t_local,
          const ToolVersion &t_version);

      //! Remove all known versions of E+. All other configuration data stays the same.
      void reset();

      //! \returns default location to open UI dialogs to when opening an IDF
      openstudio::path getDefaultIDFLocation() const;

      //! Sets the default location to open UI dialogs to when opening an IDF
      //! \param[in] t_loc The new location
      void setDefaultIDFLocation(const openstudio::path &t_loc);

      //! \returns default location to open UI dialogs to when opening an EPW
      openstudio::path getDefaultEPWLocation() const;

      //! Sets the default location to open UI dialogs to when opening an EPW
      //! \param[in] t_loc The new location
      void setDefaultEPWLocation(const openstudio::path &t_loc);

      //! \returns configured output location to use for jobs
      openstudio::path getOutputLocation() const;

      //! Sets the configured output location
      //! \param[in] t_loc The new location
      void setOutputLocation(const openstudio::path &t_loc);

      //! \returns the maximum number of simultaneous jobs to run locally
      int getMaxLocalJobs() const;

      //! Set the maximum number of simultaneous jobs to run locally
      //! \param[in] t_numjobs the new max
      void setMaxLocalJobs(int t_numjobs);

      //! \returns True if jobs created by the RunManager UI should have simple folder names
      //!          these folder names are more likely to conflict with other jobs
      bool getSimpleName() const;

      //! Set the SimpleName state
      //! \param[in] t_simplename Whether or not the folder names used by the RunManager UI should be more simple
      //! \sa setSimpleName
      void setSimpleName(bool t_simplename);
    
    private:
      REGISTER_LOGGER("RunManager.ConfigOptions");
      //! Returns a vector of paths that may contain EnergyPlus
      std::vector<openstudio::path> potentialEnergyPlusLocations() const;

      //! Returns a vector of paths that may contain Radiance
      std::vector<openstudio::path> potentialRadianceLocations() const;

      void saveQSettings(const std::vector<std::pair<openstudio::runmanager::ToolVersion, openstudio::runmanager::ToolLocationInfo> > &t_tools) const;
      std::vector<std::pair<openstudio::runmanager::ToolVersion, openstudio::runmanager::ToolLocationInfo> > loadQSettingsTools() const;
      void loadQSettingsData();

      void saveQSettingsData() const;

      //! Set up default paths for idf and epw dirs
      void setIDFEPWDefaults();

      //! Location for energyplus executables
      std::set<std::pair<ToolVersion, ToolLocationInfo> > m_toolLocations;

      //! Location the UI will default to for the IDF open dialog
      openstudio::path m_defaultIDFLocation;

      //! Location the UI will default to for the EPW open dialog
      openstudio::path m_defaultEPWLocation;

      //! Location the UI will use for the base dir for output files
      openstudio::path m_outputLocation;

      //! Number of jobs that can be run locally simultaneously
      int m_maxLocalJobs;

      //! Whether the UI should use simplified folder names which are more likely to conflict with each other
      bool m_simpleName;

  };

}
}

#endif // RUNMANAGER_LIB_CONFIGOPTIONS_HPP
