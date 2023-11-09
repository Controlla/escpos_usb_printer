
import 'escpos_usb_printer_platform_interface.dart';

class EscposUsbPrinter {
  Future<String?> getPlatformVersion() {
    return EscposUsbPrinterPlatform.instance.getPlatformVersion();
  }
}
