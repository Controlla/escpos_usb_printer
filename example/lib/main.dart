import 'package:flutter/material.dart';
import 'dart:async';

import 'package:flutter/services.dart';
import 'package:escpos_usb_printer/escpos_usb_printer.dart';

void main() {
  runApp(const MyApp());
}

class MyApp extends StatefulWidget {
  const MyApp({super.key});

  @override
  State<MyApp> createState() => _MyAppState();
}

class _MyAppState extends State<MyApp> {
  bool _initializedService = false;
  final _escposUsbPrinterPlugin = EscposUsbPrinter();
  String _printerStatus = "Not Initialized";

  @override
  void initState() {
    super.initState();
  }

  // Platform messages are asynchronous, so we initialize in an async method.
  Future<void> initService() async {
    bool initService;
    // Platform messages may fail, so we use a try/catch PlatformException.
    // We also handle the message potentially returning null.
    try {
      initService = await _escposUsbPrinterPlugin.initService() ?? false;
    } on PlatformException {
      initService = false;
    }

    // If the widget was removed from the tree while the asynchronous platform
    // message was in flight, we want to discard the reply rather than calling
    // setState to update our non-existent appearance.
    if (!mounted) return;

    setState(() {
      _initializedService = initService;
    });
  }

  Future<void> getPrinterStatus() async {
    String printerStatus;
    try {
      printerStatus = await _escposUsbPrinterPlugin.getPrinterStatus() ??
          "Printer not Initialized";
    } on PlatformException {
      printerStatus = "Printer not initialized";
    }
    if (!mounted) return;
    setState(() {
      _printerStatus = printerStatus;
    });
  }

  @override
  Widget build(BuildContext context) {
    return MaterialApp(
      home: Scaffold(
        appBar: AppBar(
          title: const Text('Plugin example app'),
        ),
        body: Column(
          children: [
            Center(
              child: Text('Service initialized: $_initializedService\n'),
            ),
            ElevatedButton(
                onPressed: () {
                  initService();
                },
                child: const Text("Initialize Service")),
            Center(
              child: Text('Printer Status: $_printerStatus\n'),
            ),
            ElevatedButton(
                onPressed: () {
                  getPrinterStatus();
                },
                child: const Text("Get Printer Status"))
          ],
        ),
      ),
    );
  }
}
