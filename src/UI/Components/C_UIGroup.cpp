// #include "Utility/Constants.hpp"
// #include "Utility/Log.hpp"
// #include "UI/Components/C_UIGroup.hpp"
// //#include "UI/UIContainer.hpp"
// 
// namespace rts
// {
//     namespace Group
//     {
//         C_UIGroup::C_UIGroup() :
//         m_group{} ,
//         m_selectedID{ UI_INVALID_WIDGET_ID }
//         {
//         }
//         
//         bool create( const std::string& gID )
//         {
//             //UIContainer::m_groupComponents;
//         }
//         
//         void destroy( const std::string& gID )
//         {
//             
//         }
//         
//         bool add( const std::string& gID, const std::string& ID )    
//         {
//             if ( gID == UI_INVALID_COMPONENT_ID )
//             {
//                 LOG(Logger::Level::ERROR) << "Invalid group ID used." << std::endl;
//                 return false;
//             }
//             
//             if ( ID == UI_INVALID_COMPONENT_ID )
//             {
//                 LOG(Logger::Level::ERROR) << "Invalid widget ID used." << std::endl;
//                 return false;
//             }
//             
//             return true;
//         }
//         
//         void remove( const std::string& gID, const std::string& ID )
//         {
//             
//         }
//         
//         const unsigned count( const std::string& gID )    
//         {
//             
//         }
//         
//         bool contains( const std::string& gID, const std::string& ID )
//         {
//             
//         }
//         
//         const std::string& selectedID( const std::string& gID )
//         {
//             
//         }
//         
//         void select( const std::string& gID, const std::string& ID )
//         {
//             
//         }
//         
//         void selectNext( const std::string& gID )
//         {
//             
//         }
//         
//         void selectPrevious( const std::string& gID )
//         {
//             
//         }
//     }
// }
