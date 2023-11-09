import 'package:flutter_test/flutter_test.dart';
import 'package:escpos_usb_printer/escpos_usb_printer.dart';
import 'package:escpos_usb_printer/escpos_usb_printer_platform_interface.dart';
import 'package:escpos_usb_printer/escpos_usb_printer_method_channel.dart';
import 'package:plugin_platform_interface/plugin_platform_interface.dart';

class MockEscposUsbPrinterPlatform
    with MockPlatformInterfaceMixin
    implements EscposUsbPrinterPlatform {

  @override
  Future<String?> getPlatformVersion() => Future.value('42');
}

void main() {
  final EscposUsbPrinterPlatform initialPlatform = EscposUsbPrinterPlatform.instance;

  test('$MethodChannelEscposUsbPrinter is the default instance', () {
    expect(initialPlatform, isInstanceOf<MethodChannelEscposUsbPrinter>());
  });

  test('getPlatformVersion', () async {
    EscposUsbPrinter escposUsbPrinterPlugin = EscposUsbPrinter();
    MockEscposUsbPrinterPlatform fakePlatform = MockEscposUsbPrinterPlatform();
    EscposUsbPrinterPlatform.instance = fakePlatform;

    expect(await escposUsbPrinterPlugin.getPlatformVersion(), '42');
  });
}
