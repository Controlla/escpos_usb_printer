// ignore: depend_on_referenced_packages
import 'package:escpos_usb_printer_example/products_model.dart';
import 'package:json_annotation/json_annotation.dart';

import 'branch_info_model.dart';

part 'ticket_model.g.dart';

@JsonSerializable(explicitToJson: true)
class TicketModel {
  @override
  @JsonKey(name: "branch")
  final BranchInfoModel branchInfoModel;

  @override
  @JsonKey(name: "products")
  final List<ProductsModel> productsModel;

  @override
  @JsonKey(name: "total")
  final double total;
  @override
  @JsonKey(name: "order")
  final int order;

  const TicketModel(
      {required this.branchInfoModel,
      required this.order,
      required this.productsModel,
      required this.total});

  factory TicketModel.fromJson(Map<String, dynamic> json) =>
      _$TicketModelFromJson(json);

  Map<String, dynamic> toJson() => _$TicketModelToJson(this);

  static Future<TicketModel> fromJsonModel(Map<String, dynamic> json) async =>
      TicketModel.fromJson(json);
}
