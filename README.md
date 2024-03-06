# escpos_usb_printer

ESC/POS Protocol integration in Flutter for desktop (only Windows). For a detailed explanation, please look at the comments in the code.

## Getting Started

This flutter plugin for Windows uses the ESC/POS Protocol to print data on a monochromatic thermal printer.
Features:

- Print monochromatic images in .bmp format and 400px x 120px resolution.
- Converts UTF-8 characters to CP437, some characters are not available at all in the CP437 protocol, and some irregular characters are replaced with available characters for compatibility and before legibility.
- Use of paper cutter
- Receives a JSON with required fields and then prints the data
- Initialize the printer service
- Get the printer status

## Easy implementation in Flutter
```
//We make an instance of the plugin
final _escposUsbPrinterPlugin = EscposUsbPrinter();
//Wrap the function in a try-catch to prevent app crashes
try {
  isTicketPrinted = await _escposUsbPrinterPlugin.printTicket(
          imageBytes, ticket.toJson()) ??
      false;
} on PlatformException {
  isTicketPrinted = false;
}
```
### Considerations
The printTicket function is typed as "printTicket(Uint8List imageBytes, Map<String, dynamic> json)" so we need to have in mind the following points:
- We have to convert the 400px x 120px monochromatic image to a Uint8List, the image has to be in this format in a perfect 24-bit greyscale because the binary data will be corrupted and the printer will print or understand another type of commands/data.
- The size of the image doesn't have to be 400px x 120px exactly, but I found it properly due to hardcoded positioning and the image that I have to implement (Look at the "How to adjust image spacing")
- The JSON structure has to be precisely like this:
```
{
    "branch": {
       "name": "Downtown",
       "address": "Av. Johnson Tyson #1889" 
    },
    "products": [
        {
            "product_name": "Pringles",
            "quantity": 1,
            "price": 30
        },
        {
            "product_name": "Coke 1LT",
            "quantity": 2,
            "price": 70
        }
    ],
    "total": 100.00,
    "order": 1,
    "isOffline": true
}
```
- isOffline is a required field that could be true if you want to display a label that says "folio" otherwise the label will say "orden".

## How to adjust image spacing
You have to look at escpos_usb_printer_plugin.cpp in the windows folder and then go to the 332 line at the print_image function and modify the manualSpaces variable. It looks like this:
```
void print_image(const std::vector<std::vector<uint32_t>>& pixels) {
    write_to_printer(INIT_PRINTER);
    write_to_printer(SET_LINE_SPACE_24);

    int manualSpaces = 6; // Aqui ajustamos la cantidad de espacios en blanco manualmente.
    std::vector<uint8_t> spaces(manualSpaces, 0x20); // Crear un vector con 10 espacios.
```
Also, you can adjust some global variables to adjust the printer to your needs.

## Error handling
Code 1000: This Means that the printer service is not initialized, it could be cause the printer is not correctly connected.

## Future implementations
This plugin is a kind of hardcoded initial state due to the fast release and implementation in our project, there are a lot of things that we can do to make the plugin more flexible like the auto center image, convert any image format, and size to the byte data that the printer needs, print any JSON format that we need, etc.
