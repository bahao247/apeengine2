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

#ifndef __PU_COLLISION_AVOIDANCE_AFFECTOR_FACTORY_H__
#define __PU_COLLISION_AVOIDANCE_AFFECTOR_FACTORY_H__

#include "ParticleUniversePrerequisites.h"
#include "ParticleUniverseAffectorFactory.h"
#include "ParticleUniverseCollisionAvoidanceAffector.h"
#include "ParticleUniverseCollisionAvoidanceAffectorTokens.h"

namespace ParticleUniverse
{
	/** Factory class responsible for creating the CollisionAvoidanceAffector.
    */
	class _ParticleUniverseExport CollisionAvoidanceAffectorFactory : public ParticleAffectorFactory
	{
		public:
			CollisionAvoidanceAffectorFactory(void) {};
	        virtual ~CollisionAvoidanceAffectorFactory(void) {};

			/** See ParticleAffectorFactory */
			Ogre::String getAffectorType() const
			{
				return "CollisionAvoidance";
			}

			/** See ParticleAffectorFactory  */
			ParticleAffector* createAffector(void)
			{
				return _createAffector<CollisionAvoidanceAffector>();
			}

			/** See ParticleAffectorFactory */
			virtual void setupTokenDefinitions(ITokenRegister* tokenRegister)
			{
				// Delegate to mCollisionAvoidanceAffectorTokens
				mCollisionAvoidanceAffectorTokens.setupTokenDefinitions(tokenRegister);
			};

		protected:
			CollisionAvoidanceAffectorTokens mCollisionAvoidanceAffectorTokens;
	};

}
#endif
