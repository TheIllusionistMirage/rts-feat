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
 *  Contains implementation of the methods & classes declared
 *  in Group submodule.
 * 
 */

#include "Utility/Constants.hpp"
#include "UI/Components/C_UIGroup.hpp"

namespace rts
{
    namespace CManager
    {
        namespace UIComponent
        {
            C_UIGroup::C_UIGroup() :
             m_members{} ,
             m_selected{ UI_INVALID_WIDGET_ID }
            {
            }
            
            C_UIGroup::C_UIGroup( std::vector<std::string> members ) :
             m_members{ members } ,
             m_selected{ UI_INVALID_WIDGET_ID }
            {                
            }
            
            void C_UIGroup::draw(sf::RenderTarget& target, sf::RenderStates states) const
            {
                //states.transform *= getTransform();
                //target.draw( m_text, states );
            }
        }
    }
}
