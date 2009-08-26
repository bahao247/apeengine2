/*!
	@file
	@author		Pablo Nu�ez
	@date		13/2009
	@module
*//*
	This file is part of the Nebula Engine.
	
	Nebula Engine is free software: you can redistribute it and/or modify
	it under the terms of the GNU Lesser General Public License as published by
	the Free Software Foundation, either version 3 of the License, or
	(at your option) any later version.
	
	Nebula Engine is distributed in the hope that it will be useful,
	but WITHOUT ANY WARRANTY; without even the implied warranty of
	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
	GNU Lesser General Public License for more details.
	
	You should have received a copy of the GNU Lesser General Public License
	along with Nebula Engine.  If not, see <http://www.gnu.org/licenses/>.
*/

#ifndef _CSMALLCREATURE_H_
#define _CSMALLCREATURE_H_

#include "EnginePrerequisites.h"

#include "ItemBoxWindow.h"
#include "Tooltip.h"

namespace Nebula {

	using namespace Ogre;
	class IGameComponent;

	class ToolTip;
	class ItemBoxWindow;
	
	//class GuiManager;
	//enum WindowPosition;

	struct NebulaDllPrivate CSmallCreatureDesc
	{
		CSmallCreatureDesc()
		{

		}

		std::string name;
		
	};
	
	class NebulaDllPrivate CSmallCreature : public IGameComponent,
									 public IPickableItem
	{
	public:
		CSmallCreature();
		CSmallCreature(const CSmallCreatureDesc&);
		~CSmallCreature();

		void update();
		void setup();
		
		void notifyStartDrop(wraps::BaseLayout * _sender, wraps::DDItemInfo _info, bool & _result);
		void notifyRequestDrop(wraps::BaseLayout * _sender, wraps::DDItemInfo _info, bool & _result);
		void notifyEndDrop(wraps::BaseLayout * _sender, wraps::DDItemInfo _info, bool _result);
		void notifyNotifyItem(wraps::BaseLayout * _sender, const MyGUI::IBNotifyItemData & _info);
		void notifyDropState(wraps::BaseLayout * _sender, MyGUI::DDItemState _state);
		void notifyToolTip(wraps::BaseLayout * _sender, const MyGUI::ToolTipInfo & _info, ItemData * _data);

		void notifyMouseButtonClick(MyGUI::WidgetPtr _sender, int _left, int _top, MyGUI::MouseButton _id);
		void notifyMouseSetFocus(MyGUI::WidgetPtr _sender, MyGUI::WidgetPtr _old);
		void notifyMouseLostFocus(MyGUI::WidgetPtr _sender, MyGUI::WidgetPtr _new);

		void hideCreaturePaper();
		void showCreaturePaper();
		void createCreaturePaper(Vector2 imageSize,std::string resourceName); //, WindowPosition align
		void destroyCreaturePaper();
		void create();

		CSmallCreatureDesc& getDescription() {
			return mDesc;
		}

		void callLuaFunction(const std::string func );

		virtual const std::string& componentID() const { 
			return mComponentID; 
		}
	private:
		std::string mComponentID;
		
		ItemBoxWindow * mCreatureBox;
		ToolTip * mToolTip;

		MyGUI::StaticImagePtr mCreatureImage;

		CSmallCreatureDesc mDesc;
	};

} //end namespace

#endif
