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

#ifndef __PU_GEOMETRY_ROTATOR_FACTORY_H__
#define __PU_GEOMETRY_ROTATOR_FACTORY_H__

#include "ParticleUniversePrerequisites.h"
#include "ParticleUniverseGeometryRotatorTokens.h"
#include "ParticleUniverseGeometryRotator.h"
#include "ParticleUniverseAffectorFactory.h"

namespace ParticleUniverse
{
	/** Factory class responsible for creating the GeometryRotator.
    */
	class _ParticleUniverseExport GeometryRotatorFactory : public ParticleAffectorFactory
	{
		public:
			GeometryRotatorFactory(void){};
	        virtual ~GeometryRotatorFactory(void){};

			/** See ParticleAffectorFactory */
			Ogre::String getAffectorType() const
			{
				return "GeometryRotator";
			}

			/** See ParticleAffectorFactory  */
			ParticleAffector* createAffector(void)
			{
				return _createAffector<GeometryRotator>();
			}

			/** See ParticleAffectorFactory */
			virtual void setupTokenDefinitions(ITokenRegister* tokenRegister)
			{
				// Delegate to mGeometryRotatorTokens
				mGeometryRotatorTokens.setupTokenDefinitions(tokenRegister);
			}

	protected:
		GeometryRotatorTokens mGeometryRotatorTokens;
	};

}
#endif
