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

#ifndef __PU_SECTION_H__
#define __PU_SECTION_H__

#include "ParticleUniversePrerequisites.h"
#include "ParticleUniverseIElement.h"

namespace ParticleUniverse
{
	/** The Section class is used for parsing. A section is a piece of data between brackets {}.
	*/
	class _ParticleUniverseExport Section
	{
		public:
			IElement* element;
			Ogre::String elementName;
			Ogre::String sectionName;

			Section(void) : elementName(Ogre::StringUtil::BLANK), sectionName(Ogre::StringUtil::BLANK) {};
			virtual ~Section(void) {};
	};

}
#endif
