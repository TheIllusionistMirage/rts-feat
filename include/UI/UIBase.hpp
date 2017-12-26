// #ifndef UI_BASE_HPP
// #define UI_BASE_HPP
// 
// #include <memory>
// 
// #include <SFML/Graphics/Drawable.hpp>
// #include <SFML/Graphics/Transformable.hpp>
// #include <SFML/System/NonCopyable.hpp>
// #include <SFML/Graphics/RenderWindow.hpp>
// #include <SFML/Graphics/Text.hpp>
// 
// namespace rts
// {
//     namespace UI
//     {
//         class UIBase : public sf::Drawable,
//                        public sf::Transform
//         {
//             public:
//             
//                 typedef std::shared_ptr<UIBase> Ptr;
//             
//                 UIBase() :
//                 m_bounds{ 0.f, 0.f, 0.f, 0.f } ,
//                 m_enabled{ true } ,
//                 m_visible{ true } ,
//                 m_selected{ false } ,
//                 m_selectable{ false }
//                 {}
//                 
//                 virtual ~UIBase();
//                 
//                 virtual void handleInput(const sf::Time dt) = 0;
//                 virtual void update(const sf::Time dt) = 0;
//                 virtual void draw() = 0;
//             
//             private:
//             
//                 /* The rectangular bounds of the UI widget */
//                 sf::FloatRect m_bounds;
//                 
//                 /* Indicates whether or not the widget reacts to user input & is updated */
//                 bool m_enabled;
//                 
//                 /* Indicates whether the widget is visible or not */
//                 bool m_visible;
//                 
//                 /* Indicates whether the widget is currently reacting to mouse/keyboard input */
//                 bool m_selected;
//                 
//                 /* Indicates whether the widget can be selected or not */
//                 bool m_selectable;
//         };
//     }
// }
// 
// #endif // UI_BASE_HPP
