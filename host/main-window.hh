﻿#pragma once

#include <QMainWindow>
#include <QKeyEvent>

class Application;
class SettingsDialog;
class PluginParametersWidget;
class PluginQuickControlsWidget;

class MainWindow : public QMainWindow {
   using super = QMainWindow;

   Q_OBJECT

public:
   explicit MainWindow(Application &app);
   ~MainWindow();

   WId getEmbedWindowId();

public:
   void loadNativePluginPreset();
   void showSettingsDialog();
   void showPluginParametersWindow();
   void showPluginQuickControlsWindow();
   void resizePluginView(int width, int height);

   void showPluginWindow() { _pluginViewWidget->show(); }

   void hidePluginWindow() { _pluginViewWidget->hide(); }

protected:
   void closeEvent(QCloseEvent *event) override;
   void keyPressEvent(QKeyEvent *event) override;
   void keyReleaseEvent(QKeyEvent *event) override;

private:
   void createMenu();

   void togglePluginWindowVisibility();
   void recreatePluginWindow();
   void showAboutDialog();
   void updatePluginMenuItems(bool pluginLoaded = false);

   Application &_application;
   QWindow *_pluginViewWindow = nullptr;
   QWidget *_pluginViewWidget = nullptr;

   QAction *_loadPluginPresetAction = nullptr;
   QAction *_showPluginParametersAction = nullptr;
   QAction *_showPluginQuickControlsAction = nullptr;
   QAction *_togglePluginWindowVisibilityAction = nullptr;
   QAction *_recreatePluginWindowAction = nullptr;

   PluginParametersWidget *_pluginParametersWidget = nullptr;
   PluginQuickControlsWidget *_pluginRemoteControlsWidget = nullptr;
};
