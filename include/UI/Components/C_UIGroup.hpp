/*
 * ------------------------
 *  Module    : Components
 *  Submodule : Group
 * ------------------------
 *  Author : Koushtav Chakrabarty < theillusionistmirage@gmail.com >
 *  Date   : 01-01-2018
 * 
 *  This file is a part of the software that resides here:
 *  https://github.com/TheIllusionistMirage/rts-feat
 * ------------------------------------------------------------------
 * 
 *  This module defines the Group component for the UI widgets. UI
 *  widgets containing the Group component can act as parent
 *  containers for other UI widgets.
 * 
 */

#ifndef C_UI_GROUP_HPP
#define C_UI_GROUP_HPP

#include <string>
#include <memory>
#include <vector>

#include "UI/Components/C_ComponentBase.hpp"

namespace rts
{
    namespace CManager
    {
        namespace UIComponent
        {
            struct C_UIGroup : public C_ComponentBase
            {
                typedef std::shared_ptr<C_UIGroup> Ptr;
                
                C_UIGroup();
                
                C_UIGroup( std::vector<std::string> members );
                
                void draw( sf::RenderTarget& target, sf::RenderStates states ) const;
                
                // The list of widgets that are members of this group
                std::vector<std::string> m_members;
                
                // The currently selected member
                std::string m_selected;
            };
        }
    }
}

#endif // C_UI_GROUP_HPP
