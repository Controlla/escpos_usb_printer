import 'package:flutter/foundation.dart';
import 'package:flutter/services.dart';

import 'escpos_usb_printer_platform_interface.dart';

/// An implementation of [EscposUsbPrinterPlatform] that uses method channels.
class MethodChannelEscposUsbPrinter extends EscposUsbPrinterPlatform {
  /// The method channel used to interact with the native platform.
  @visibleForTesting
  final methodChannel = const MethodChannel('escpos_usb_printer');

  @override
  Future<String?> getPlatformVersion() async {
    final version = await methodChannel.invokeMethod<String>('getPlatformVersion');
    return version;
  }
}
