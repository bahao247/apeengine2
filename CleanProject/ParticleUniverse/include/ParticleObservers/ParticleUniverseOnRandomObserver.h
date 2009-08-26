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

#ifndef __PU_ONRANDOM_OBSERVER_H__
#define __PU_ONRANDOM_OBSERVER_H__

#include "ParticleUniversePrerequisites.h"
#include "ParticleUniverseCommon.h"
#include "ParticleUniverseObserver.h"

namespace ParticleUniverse
{
	/** This class is used to observe whether a random generated number is within a specified interval.
    */
	class _ParticleUniverseExport OnRandomObserver : public ParticleObserver
	{
		protected:
			Ogre::Real mThreshold; // Value between 0..1

		public:
			OnRandomObserver(void) : ParticleObserver(),
				mThreshold(0.5f)
			{
				mObserverType = "OnRandom";
			};
	        virtual ~OnRandomObserver(void) {};

			/** See ParticleObserver::_preProcessParticles()
	        */
			virtual void _preProcessParticles(ParticleTechnique* technique, Ogre::Real timeElapsed);

			/** 
	        */
			virtual bool _observe (ParticleTechnique* particleTechnique, Particle* particle, Ogre::Real timeElapsed);

			/** 
	        */
			Ogre::Real getThreshold(){return mThreshold;};
			void setThreshold(Ogre::Real threshold){mThreshold = threshold;};

			/** Copy attributes to another observer.
	        */
			virtual void copyAttributesTo (ParticleObserver* observer);
	};

}
#endif
