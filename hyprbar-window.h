#pragma once

#include <gtkmm.h>
#include <gtkmm/box.h>
#include <gtkmm/centerbox.h>

namespace hyprbar {

class ExampleWindow : public Gtk::Window {
public:
  ExampleWindow();
  virtual ~ExampleWindow();

private:
  void setup_gtk_layer();

  // Signal handlers:
  void on_button_quit();
  void on_button_numbered(const Glib::ustring &data);

  // Child widgets:
  Gtk::CenterBox m_centerBox;
  Gtk::Box m_boxLeft;
  Gtk::Box m_boxCenter;
  Gtk::Box m_boxRight;
  Gtk::Button m_button_1, m_button_2, m_button_quit;
};

} // namespace hyprbar
