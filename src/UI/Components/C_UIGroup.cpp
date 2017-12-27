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
