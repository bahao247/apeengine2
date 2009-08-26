/*
-----------------------------------------------------------------------------
This source file is part of the Particle Universe product.

Copyright (c) 2006-2008 Henry van Merode

Usage of this program is free for non-commercial use and licensed under the
the terms of the GNU Lesser General Public License.

You should have received a copy of the GNU Lesser General Public License along with
this program; if not, write to the Free Software Foundation, Inc., 59 Temple
Place - Suite 330, Boston, MA 02111-1307, USA, or go to
http://www.gnu.org/copyleft/lesser.txt.
-----------------------------------------------------------------------------
*/

#ifndef __PU_DO_FREEZE_EVENT_HANDLER_FACTORY_H__
#define __PU_DO_FREEZE_EVENT_HANDLER_FACTORY_H__

#include "ParticleUniversePrerequisites.h"
#include "ParticleUniverseEventHandlerFactory.h"
#include "ParticleUniverseDoFreezeEventHandler.h"

namespace ParticleUniverse
{
	/** This factory class is responsible for creation of a DoFreezeEventHandler.
    */
	class _ParticleUniverseExport DoFreezeEventHandlerFactory : public ParticleEventHandlerFactory
	{
		public:
			DoFreezeEventHandlerFactory(void) {};
	        virtual ~DoFreezeEventHandlerFactory(void) {};

			/** See ParticleEventHandlerFactory*/
			virtual Ogre::String getEventHandlerType(void) const
			{
				return "DoFreeze";
			}

			/** See ParticleEventHandlerFactory*/
			virtual ParticleEventHandler* createEventHandler(void)
			{
				return _createEventHandler<DoFreezeEventHandler>();
			}

			/** See ParticleEventHandlerFactory
			@remarks
				This event handler doesn't have attributes */
			virtual void setupTokenDefinitions(ITokenRegister* tokenRegister){};

		protected:
	};

}
#endif
