#include "include/escpos_usb_printer/escpos_usb_printer_plugin_c_api.h"

#include <flutter/plugin_registrar_windows.h>

#include "escpos_usb_printer_plugin.h"

void EscposUsbPrinterPluginCApiRegisterWithRegistrar(
    FlutterDesktopPluginRegistrarRef registrar) {
  escpos_usb_printer::EscposUsbPrinterPlugin::RegisterWithRegistrar(
      flutter::PluginRegistrarManager::GetInstance()
          ->GetRegistrar<flutter::PluginRegistrarWindows>(registrar));
}
