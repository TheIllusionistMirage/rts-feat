// /*
//  * Include this UI component in the widget if the widget should
//  * be able to act as a container for other UI widgets (e.g., a panel).
//  */
// 
// #ifndef C_UI_GROUP_HPP
// #define C_UI_GROUP_HPP
// 
// #include <vector>
// #include <memory>
// 
// #include "UI/UIBase.hpp"
// 
// namespace rts
// {
//     namespace Group
//     {
//         //////////////////////////
//         // Component attributes //
//         //////////////////////////
//         
//         struct C_UIGroup
//         {
//             typedef std::shared_ptr<C_UIGroup> Ptr;
//             
//             //static int m_groupCount;
//             
//             C_UIGroup();
//             
//             /* The widgets currently in the group */
//             std::vector<UIBase::Ptr> m_group;
//             
//             /* ID of the currently selected widget in the group */
//             std::string m_selectedID;
//         };
//         
//         /////////////////////////
//         // Component functions //
//         /////////////////////////
//         
//         /* Create a new group component with given ID */
//         bool create( const std::string& gID );
//         
//         /* Delete the group component with given ID */
//         void destroy( const std::string& gID );
//         
//         /* Add a widget to the group */
//         bool add( const std::string& gID, const std::string& ID );
//         
//         /* Remove a widget from the group */
//         void remove( const std::string& gID, const std::string& ID );
//         
//         /* Return the count of the widgets in the group */
//         const unsigned count( const std::string& gID );
//         
//         /* Checks the existence of a widget in the group */
//         bool contains( const std::string& gID, const std::string& ID );
//         
//         /* Returns the ID of the currently selected widget, else an invalid ID is returned */
//         const std::string& selectedID( const std::string& gID );
//         
//         /* Select the widget wuth given ID if it exists in the group */
//         void select( const std::string& gID, const std::string& ID );
//         
//         /* Select the next selectable widget in the groupo (if possible) */
//         void selectNext( const std::string& gID );
//         
//         /* Select the previous selectable widget in the groupo (if possible) */
//         void selectPrevious( const std::string& gID );
//     }
// }
// 
// #endif // C_UI_GROUP_HPP
