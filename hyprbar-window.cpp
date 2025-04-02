#include "hyprbar-window.h"

#include <gtk4-layer-shell.h>

#include <iostream>

namespace hyprbar {

static constexpr auto LAYER_SHELL_NAME{"hyprbar"};

ExampleWindow::ExampleWindow()
    : m_button_1("button 1"), m_button_2("button 2"), m_button_quit("Quit") {
  set_title("Gtk::Grid");

  set_child(m_centerBox);

  m_centerBox.set_start_widget(m_boxLeft);
  m_centerBox.set_center_widget(m_boxCenter);
  m_centerBox.set_end_widget(m_boxRight);

  m_boxLeft.append(m_button_1);
  m_boxCenter.append(m_button_2);
  m_boxRight.append(m_button_quit);

  m_button_1.signal_clicked().connect(sigc::bind(
      sigc::mem_fun(*this, &ExampleWindow::on_button_numbered), "button 1"));
  m_button_2.signal_clicked().connect(sigc::bind(
      sigc::mem_fun(*this, &ExampleWindow::on_button_numbered), "button 2"));

  m_button_quit.signal_clicked().connect(
      sigc::mem_fun(*this, &ExampleWindow::on_button_quit));
}

ExampleWindow::~ExampleWindow() {}

void ExampleWindow::setup_gtk_layer() {

  auto *window{gobj()};

  gtk_layer_init_for_window(window);

  gtk_layer_set_anchor(window, GTK_LAYER_SHELL_EDGE_TOP, true);
  gtk_layer_set_anchor(window, GTK_LAYER_SHELL_EDGE_LEFT, true);
  gtk_layer_set_anchor(window, GTK_LAYER_SHELL_EDGE_RIGHT, true);
  gtk_layer_set_layer(window, GTK_LAYER_SHELL_LAYER_TOP);
  gtk_layer_set_keyboard_mode(window, GTK_LAYER_SHELL_KEYBOARD_MODE_NONE);
  gtk_layer_set_namespace(window, LAYER_SHELL_NAME);

  gtk_layer_auto_exclusive_zone_enable(gobj());
}

void ExampleWindow::on_button_quit() { set_visible(false); }

void ExampleWindow::on_button_numbered(const Glib::ustring &data) {
  std::cout << data << " was pressed" << std::endl;
}

} // namespace hyprbar
