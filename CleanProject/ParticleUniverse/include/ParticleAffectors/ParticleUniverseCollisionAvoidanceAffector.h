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

#ifndef __PU_COLLISION_AVOIDANCE_AFFECTOR_H__
#define __PU_COLLISION_AVOIDANCE_AFFECTOR_H__

#include "ParticleUniversePrerequisites.h"
#include "ParticleUniverseAffector.h"

namespace ParticleUniverse
{
	/** The CollisionAvoidanceAffector is used to prevent particles from colliding with each other.
	@remarks
		The current implementation doesn�t take avoidance of colliders (box, sphere, plane) into account (yet).
    */
	class _ParticleUniverseExport CollisionAvoidanceAffector : public ParticleAffector
	{
		public:
			CollisionAvoidanceAffector(void) : 
				ParticleAffector(),
				mRadius(100.0f)
			{
				mAffectorType = "CollisionAvoidance";
			};
	        virtual ~CollisionAvoidanceAffector(void){};

			/** Todo
			*/
			Ogre::Real getRadius(void) const;

			/** Todo
			*/
			void setRadius(Ogre::Real radius);

			/** @copydoc ParticleAffector::_prepare */
			virtual void _prepare(ParticleTechnique* particleTechnique);

			/** @copydoc ParticleAffector::_affect */
			virtual void _affect(ParticleTechnique* particleTechnique, Particle* particle, Ogre::Real timeElapsed);

			/** @copydoc ParticleAffector::copyAttributesTo */
			virtual void copyAttributesTo (ParticleAffector* affector);
		
		protected:
			Ogre::Real mRadius;
	};

}
#endif
