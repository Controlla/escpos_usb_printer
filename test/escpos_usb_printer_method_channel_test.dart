import 'package:flutter/services.dart';
import 'package:flutter_test/flutter_test.dart';
import 'package:escpos_usb_printer/escpos_usb_printer_method_channel.dart';

void main() {
  MethodChannelEscposUsbPrinter platform = MethodChannelEscposUsbPrinter();
  const MethodChannel channel = MethodChannel('escpos_usb_printer');

  TestWidgetsFlutterBinding.ensureInitialized();

  setUp(() {
    channel.setMockMethodCallHandler((MethodCall methodCall) async {
      return '42';
    });
  });

  tearDown(() {
    channel.setMockMethodCallHandler(null);
  });

  test('getPlatformVersion', () async {
    expect(await platform.getPlatformVersion(), '42');
  });
}
