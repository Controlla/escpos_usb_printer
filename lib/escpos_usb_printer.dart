import 'escpos_usb_printer_platform_interface.dart';

class EscposUsbPrinter {
  Future<bool?> initService() {
    return EscposUsbPrinterPlatform.instance.initService();
  }

  Future<String?> getPrinterStatus() {
    return EscposUsbPrinterPlatform.instance.getPrinterStatus();
  }
}
