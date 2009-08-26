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

#ifndef __PU_FLOCK_CENTER_AFFECTOR_H__
#define __PU_FLOCK_CENTER_AFFECTOR_H__

#include "ParticleUniversePrerequisites.h"
#include "ParticleUniverseAffector.h"

namespace ParticleUniverse
{
	/** Todo.
    */
	class _ParticleUniverseExport FlockCenteringAffector : public ParticleAffector
	{
		protected:
			Ogre::Vector3 mSum;
			Ogre::Vector3 mAverage;
			Ogre::Real mCount;

		public:
			FlockCenteringAffector(void) : 
				ParticleAffector(),
				mSum(Ogre::Vector3::ZERO),
				mAverage(Ogre::Vector3::ZERO),
				mCount(0.0f)
			{
				mAffectorType = "FlockCentering";
			};
	        virtual ~FlockCenteringAffector(void) {};

			/** @copydoc ParticleAffector::_preProcessParticles */
			virtual void _preProcessParticles(ParticleTechnique* particleTechnique, Ogre::Real timeElapsed);

			/** @copydoc ParticleAffector::copyAttributesTo */
			virtual void copyAttributesTo (ParticleAffector* affector);

			/** @copydoc ParticleAffector::_affect */
			virtual void _affect(ParticleTechnique* particleTechnique, Particle* particle, Ogre::Real timeElapsed);
	};

}
#endif
