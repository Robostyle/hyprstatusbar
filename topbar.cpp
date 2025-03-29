#include "CLI/CLI.hpp"
#include <gtk/gtk.h>
#include <gtk4-layer-shell.h>


#include <CLI/CLI.hpp>


// #include <chrono>
// #include <format>
// #include <memory>
// #include <string>
//
// class TopBar
// {
// private:
//     GtkApplication* app;
//     GtkWindow* window;
//     GtkBox* box;
//     GtkButton* button;
//     GtkLabel* time_label;
//
//     guint timeout_id;
//
//     // Button click handler
//     static void on_button_clicked(GtkButton* button, gpointer user_data)
//     {
//         auto* self = static_cast<TopBar*>(user_data);
//         g_print("Button clicked!\n");
//     }
//
//     // Time update function
//     static gboolean update_time(gpointer user_data)
//     {
//         auto* self = static_cast<TopBar*>(user_data);
//         auto now = std::chrono::system_clock::now();
//         auto time = std::chrono::system_clock::to_time_t(now);
//
//         std::string time_str = std::format("{:%H:%M:%S}", *std::localtime(&time));
//         gtk_label_set_text(self->time_label, time_str.c_str());
//
//         return G_SOURCE_CONTINUE;
//     }
//
//     // Application activation handler
//     static void on_activate(GtkApplication* app, gpointer user_data)
//     {
//         auto* self = static_cast<TopBar*>(user_data);
//         self->setup_window();
//     }
//
//     // Initialize the window and widgets
//     void setup_window()
//     {
//         // Create the window
//         window = GTK_WINDOW(gtk_application_window_new(app));
//
//         // Setup layer shell
//         gtk4_layer_shell_init_for_window(window);
//         gtk4_layer_shell_set_layer(window, GTK4_LAYER_SHELL_LAYER_TOP);
//         gtk4_layer_shell_set_anchor(window, GTK4_LAYER_SHELL_EDGE_TOP, TRUE);
//         gtk4_layer_shell_set_anchor(window, GTK4_LAYER_SHELL_EDGE_LEFT, TRUE);
//         gtk4_layer_shell_set_anchor(window, GTK4_LAYER_SHELL_EDGE_RIGHT, TRUE);
//
//         // Create a horizontal box for content
//         box = GTK_BOX(gtk_box_new(GTK_ORIENTATION_HORIZONTAL, 6));
//         gtk_widget_set_margin_start(GTK_WIDGET(box), 12);
//         gtk_widget_set_margin_end(GTK_WIDGET(box), 12);
//         gtk_widget_set_margin_top(GTK_WIDGET(box), 6);
//         gtk_widget_set_margin_bottom(GTK_WIDGET(box), 6);
//
//         // Add the box to the window
//         gtk_window_set_child(window, GTK_WIDGET(box));
//
//         // Create a button
//         button = GTK_BUTTON(gtk_button_new_with_label("Menu"));
//         g_signal_connect(button, "clicked", G_CALLBACK(on_button_clicked), this);
//         gtk_box_append(box, GTK_WIDGET(button));
//
//         // Create a time label
//         time_label = GTK_LABEL(gtk_label_new(""));
//         gtk_widget_set_margin_start(GTK_WIDGET(time_label), 10);
//         gtk_box_append(box, GTK_WIDGET(time_label));
//
//         // Update time immediately and set up a timer to update every second
//         update_time(this);
//         timeout_id = g_timeout_add_seconds(1, update_time, this);
//
//         // Show the window
//         gtk_widget_show(GTK_WIDGET(window));
//     }
//
// public:
//     TopBar()
//         : app(nullptr)
//         , window(nullptr)
//         , box(nullptr)
//         , button(nullptr)
//         , time_label(nullptr)
//         , timeout_id(0)
//     {
//         app = gtk_application_new("org.example.topbar", G_APPLICATION_DEFAULT_FLAGS);
//         g_signal_connect(app, "activate", G_CALLBACK(on_activate), this);
//     }
//
//     ~TopBar()
//     {
//         if (timeout_id > 0)
//         {
//             g_source_remove(timeout_id);
//         }
//         g_object_unref(app);
//     }
//
//     int run(int argc, char** argv) { return g_application_run(G_APPLICATION(app), argc, argv); }
// };
//


namespace
{

static constexpr auto prog_name{ "gtk4-layer-demo" };

}

int main(int argc, char** argv)
{
    CLI::App app;
    CLI11_PARSE(app, argc, argv);


    g_set_prgname(prog_name);


    return 0;
    // TopBar top_bar;
    // return top_bar.run(argc, argv);
}
