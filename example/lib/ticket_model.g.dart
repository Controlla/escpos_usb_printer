// GENERATED CODE - DO NOT MODIFY BY HAND

part of 'ticket_model.dart';

// **************************************************************************
// JsonSerializableGenerator
// **************************************************************************

TicketModel _$TicketModelFromJson(Map<String, dynamic> json) => TicketModel(
      branchInfoModel:
          BranchInfoModel.fromJson(json['branch'] as Map<String, dynamic>),
      order: json['order'] as int,
      productsModel: (json['products'] as List<dynamic>)
          .map((e) => ProductsModel.fromJson(e as Map<String, dynamic>))
          .toList(),
      total: (json['total'] as num).toDouble(),
    );

Map<String, dynamic> _$TicketModelToJson(TicketModel instance) =>
    <String, dynamic>{
      'branch': instance.branchInfoModel.toJson(),
      'products': instance.productsModel.map((e) => e.toJson()).toList(),
      'total': instance.total,
      'order': instance.order,
    };
