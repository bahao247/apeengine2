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

#ifndef __PU_BOX_SET_H__
#define __PU_BOX_SET_H__

#include "ParticleUniversePrerequisites.h"
#include "ParticleRenderers/ParticleUniversePrimitiveShapeSet.h"

namespace ParticleUniverse
{
	class Box;

	/** The BoxSet and Box classes are comparable with the BillboardSet and Billboard classes in Ogre, instead
		Boxes are rendered.
	@remarks
		The uv mapping is done like this:
<pre>
|---|---|
| 1 | 4 |
|---|---|
| 2 | 5 |
|---|---|
| 3 | 6 |
|---|---|
</pre>
    */
	class _ParticleUniverseExport BoxSet : public PrimitiveShapeSet
	{
		protected:
			/** Default width of each box
			*/
			Ogre::Real mDefaultWidth;

			/** Default height of each box
			*/
			Ogre::Real mDefaultHeight;

			/** Default depth of each box
			*/
			Ogre::Real mDefaultDepth;

			/** Half values
			*/
			Ogre::Real mDefaultHalfWidth;
			Ogre::Real mDefaultHalfHeight;
			Ogre::Real mDefaultHalfDepth;

			/** Texture coordinates.
			*/
			Ogre::Vector2 mTextCoord[16];

			/** Flag indicating whether to autoextend pool
			*/
			bool mAutoExtendPool;

			/** Contains the local positions of the box corners, repeated because of texture mapping.
			*/
			Ogre::Vector3 mDefaultCorners[16];

			typedef std::list<Box*> ActiveBoxList;
			typedef std::list<Box*> FreeBoxList;
			typedef std::vector<Box*> BoxPool;

			/** Active box list.
			@remarks
				This is a linked list of pointers to boxes in the box pool.
			*/
			ActiveBoxList mActiveBoxes;

			/** Free box queue.
			*/
			FreeBoxList mFreeBoxes;

			/** Pool of box instances for use and reuse in the active box list.
			*/
			BoxPool mBoxPool;

			/** The vertex position data for all boxes in this set.
			*/
			Ogre::VertexData* mVertexData;

			/** Shortcut to main buffer
			*/
			Ogre::HardwareVertexBufferSharedPtr mMainBuf;

			/** Locked pointer to buffer
			*/
			float* mLockPtr;

			/** The vertex index data for all boxes in this set (1 set only)
			*/
			Ogre::IndexData* mIndexData;

			typedef std::vector<Ogre::FloatRect> TextureCoordSets;
			TextureCoordSets mTextureCoords;

			/** Internal method for culling individual boxes
			*/
			inline bool boxVisible(Ogre::Camera* cam, const Box& box);

			/** Number of visible boxes
			*/
			unsigned short mNumVisibleBoxes;

			/** Internal method for increasing pool size
			*/
			virtual void increasePool(size_t size);

			/** 
			*/
			void _genDefaultCorners(void);

			/** Internal method for generating vertex data
			*/
			void _genVertices(Box& box);

			/** Internal method for generating texture coordinates
			*/
			void _initTextCoord(void);

		private:
			/** Flag indicating whether the HW buffers have been created.
			*/
			bool mBuffersCreated;

			/** The number of boxes in the pool.
			*/
			size_t mPoolSize;
        
			/** Is external box data in use?
			*/
			bool mExternalData;

			/** Internal method creates vertex and index buffers.
			*/
			void _createBuffers(void);
        
			/** Internal method destroys vertex and index buffers.
			*/
			void _destroyBuffers(void);

		public:
			/** Default constructor.
			*/
			BoxSet(const Ogre::String& name, unsigned int poolSize = 20, bool externalData = false);

			/** Default constructor.
			*/
			BoxSet(void);

			/** Default destructor.
			*/
	        virtual ~BoxSet(void);

			/** Creates a new box and adds it to this set.
			*/
			Box* createBox(const Ogre::Vector3& position);

			/** Creates a new box and adds it to this set.
			*/
			Box* createBox(Ogre::Real x, Ogre::Real y, Ogre::Real z);

			/** Returns the number of active boxes which currently make up this set.
			*/
			virtual int getNumBoxes(void) const;
			
			/** Tells the set whether to allow automatic extension of the pool of boxes.
			*/
			virtual void setAutoextend(bool autoextend);
			
			/** Returns true if the box pool automatically extends.
			*/
			virtual bool isAutoextend(void) const;

			/** Adjusts the size of the pool of boxes available in this set.
			*/
			virtual void setPoolSize(size_t size);

			/** Returns the current size of the box pool.
			*/
			virtual unsigned int getPoolSize(void) const;

			/** Empties this set of all boxes.
			*/
			virtual void clear();

			/** Returns a pointer to the box at the supplied index.
			*/
			virtual Box* getBox(unsigned int index) const;

			/** Removes the box at the supplied index.
			*/
			virtual void removeBox(unsigned int index);

			/** Removes a box from the set.
			*/
			virtual void removeBox(Box* box);

			/** Sets the default dimensions of the boxes in this set.
			*/
			virtual void setDefaultDimensions(Ogre::Real width, Ogre::Real height, Ogre::Real depth);

			/** See setDefaultDimensions - this sets 1 component individually.
			*/
			virtual void setDefaultWidth(Ogre::Real width);

			/** See setDefaultDimensions - this gets 1 component individually.
			*/
			virtual Ogre::Real getDefaultWidth(void) const;

			/** See setDefaultDimensions - this sets 1 component individually.
			*/
        	virtual void setDefaultHeight(Ogre::Real height);

			/** See setDefaultDimensions - this gets 1 component individually.
			*/
			virtual Ogre::Real getDefaultHeight(void) const;

			/**  See setDefaultDimensions - this gets 1 component individually.
			*/
        	virtual void setDefaultDepth(Ogre::Real depth);

			/** See setDefaultDimensions - this gets 1 component individually.
			*/
			virtual Ogre::Real getDefaultDepth(void) const;

			/** Begin injection of box data; applicable when constructing the BoxSet for external data use.
			*/
			void beginBoxes(size_t numBoxes = 0);

			/** Define a box.
			*/
			void injectBox(Box& bb);
        
			/** Finish defining boxes. */
			void endBoxes(void);

			/** Set the bounds of the BoxSet.
			*/
			void setBounds(const Ogre::AxisAlignedBox& box, Ogre::Real radius);

			/** Overridden from MovableObject
			@see
				MovableObject
			*/
			virtual void _updateRenderQueue(Ogre::RenderQueue* queue);

			/** Overridden from MovableObject
			@see
				MovableObject
			*/
			virtual void getRenderOperation(Ogre::RenderOperation& op);

			/** Overridden from MovableObject 
			*/
			virtual const Ogre::String& getMovableType(void) const;

			/** Update the bounds of the box set
			*/
			virtual void _updateBounds(void);

			/** Sets whether boxes should be treated as being in world space. 
			*/
			virtual void setBoxesInWorldSpace(bool ws) { mWorldSpace = ws; }
	};

	/** Factory object for creating BoxSet instances */
	class _ParticleUniverseExport BoxSetFactory : public Ogre::MovableObjectFactory
	{
	
		protected:
			Ogre::MovableObject* createInstanceImpl( const Ogre::String& name, const Ogre::NameValuePairList* params);

		public:
			BoxSetFactory() {}
			~BoxSetFactory() {}

			static Ogre::String PU_FACTORY_TYPE_NAME;

			const Ogre::String& getType(void) const;
			void destroyInstance( Ogre::MovableObject* obj);  
	};

}

#endif
