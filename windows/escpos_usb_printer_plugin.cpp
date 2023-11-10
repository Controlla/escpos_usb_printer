#include "escpos_usb_printer_plugin.h"

// This must be included before many other Windows headers.
#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>
#include <cstdint>
#include <sstream>
#include <SDKDDKVer.h>
#include <Windows.h>

#include <flutter/method_channel.h>
#include <flutter/plugin_registrar_windows.h>
#include <flutter/standard_method_codec.h>

#include <memory>
#include <limits>
#include <iomanip>
#include <string>
#include "utilities.h"
#include "PosPrinterEx.h"

PpUsbPtr m_ppStream = nullptr;  

//Mandar comandos a la impresora
void write_to_printer(const std::vector<uint8_t>& data) {
    if (m_ppStream) {
        m_ppStream->write(reinterpret_cast<const char*>(data.data()), static_cast<int>(data.size()));
    }
}

//Convertir string a uint8 y mandar comando
void write_text_to_printer(const std::string& text) {
    std::vector<uint8_t> data(text.begin(), text.end());
    write_to_printer(data);
}

bool InitializeUsbService() {
    if (m_ppStream) {
        PpClose(m_ppStream);  // Esta funcion debe estar definida en alguna parte de tu codigo.
        m_ppStream = NULL;
    }
    m_ppStream = PpOpenUsb();  // Suponemos que esta funcion devuelve un puntero.

    if (m_ppStream) {
        std::cout << "Conexion establecida.\n";
        // Selecciona el conjunto de caracteres de Espana
        const char ESC = 27;
        const unsigned char spain_char_set = 13; // Caracteres internacionales de Espana

        std::string set_international_char_command = { ESC, 'R', spain_char_set };
        write_text_to_printer(set_international_char_command);
        return true;
    }
    else {
        return false;
    }
}

namespace escpos_usb_printer {

// static
void EscposUsbPrinterPlugin::RegisterWithRegistrar(
    flutter::PluginRegistrarWindows *registrar) {
  auto channel =
      std::make_unique<flutter::MethodChannel<flutter::EncodableValue>>(
          registrar->messenger(), "escpos_usb_printer",
          &flutter::StandardMethodCodec::GetInstance());

  auto plugin = std::make_unique<EscposUsbPrinterPlugin>();

  channel->SetMethodCallHandler(
      [plugin_pointer = plugin.get()](const auto &call, auto result) {
        plugin_pointer->HandleMethodCall(call, std::move(result));
      });

  registrar->AddPlugin(std::move(plugin));
}

EscposUsbPrinterPlugin::EscposUsbPrinterPlugin() {}

EscposUsbPrinterPlugin::~EscposUsbPrinterPlugin() {}

void EscposUsbPrinterPlugin::HandleMethodCall(
    const flutter::MethodCall<flutter::EncodableValue> &method_call,
    std::unique_ptr<flutter::MethodResult<flutter::EncodableValue>> result) {
    /*
  if (method_call.method_name().compare("getPlatformVersion") == 0) {
    std::ostringstream version_stream;
    version_stream << "Windows ";
    if (IsWindows10OrGreater()) {
      version_stream << "10+";
    } else if (IsWindows8OrGreater()) {
      version_stream << "8";
    } else if (IsWindows7OrGreater()) {
      version_stream << "7";
    }
    result->Success(flutter::EncodableValue(version_stream.str()));
  } else {
    result->NotImplemented();
  }*/
}

}  // namespace escpos_usb_printer
