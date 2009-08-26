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

#ifndef __PU_ONPOSITION_OBSERVER_FACTORY_H__
#define __PU_ONPOSITION_OBSERVER_FACTORY_H__

#include "ParticleUniversePrerequisites.h"
#include "ParticleUniverseObserverFactory.h"
#include "ParticleUniverseOnPositionObserverTokens.h"
#include "ParticleUniverseOnPositionObserver.h"

namespace ParticleUniverse
{
	/** Factory class responsible for creating the OnPositionObserver.
    */
	class _ParticleUniverseExport OnPositionObserverFactory : public ParticleObserverFactory
	{
		public:
			OnPositionObserverFactory(void) {};
	        virtual ~OnPositionObserverFactory(void) {};

			/** See ParticleObserverFactory */
			virtual Ogre::String getObserverType(void) const
			{
				return "OnPosition";
			}

			/** See ParticleObserverFactory */
			virtual ParticleObserver* createObserver(void)
			{
				return _createObserver<OnPositionObserver>();
			}

			/** See ParticleObserverFactory
			@remarks
				This observer doesn't have attributes */
			virtual void setupTokenDefinitions(ITokenRegister* tokenRegister)
			{
				// Delegate to mOnPositionObserverTokens
				mOnPositionObserverTokens.setupTokenDefinitions(tokenRegister);
			}

		protected:
			OnPositionObserverTokens mOnPositionObserverTokens;
	};

}
#endif
