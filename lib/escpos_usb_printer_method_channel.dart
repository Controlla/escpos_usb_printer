import 'package:flutter/foundation.dart';
import 'package:flutter/services.dart';

import 'escpos_usb_printer_platform_interface.dart';

/// An implementation of [EscposUsbPrinterPlatform] that uses method channels.
class MethodChannelEscposUsbPrinter extends EscposUsbPrinterPlatform {
  /// The method channel used to interact with the native platform.
  @visibleForTesting
  final methodChannel = const MethodChannel('escpos_usb_printer');

  @override
  Future<bool?> initService() async {
    final bool? isInitialized =
        await methodChannel.invokeMethod<bool>('initService');
    return isInitialized;
  }

  @override
  Future<String?> getPrinterStatus() async {
    final String? printerStatus =
        await methodChannel.invokeMethod<String>('getPrinterStatus');
    return printerStatus;
  }
}
