//
//  YJTTableCellObject.h
//  YJTTableViewFactory
//
//  HomePage:https://github.com/937447974/YJCocoa
//  YJ技术支持群:557445088
//
//  Created by 阳君 on 16/5/13.
//  Copyright © 2016年 YJCocoa. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

/** cell模型协议*/
@protocol YJTTableCellModelProtocol <NSObject>

@end


/** 创建cell的方式*/
typedef NS_ENUM(NSInteger, YJTTableViewCellCreate) {
    YJTTableViewCellCreateDefault,   ///< 默认使用xib创建cell，推荐此方式
    YJTTableViewCellCreateSoryboard, ///< 使用soryboard创建cell时，请使用类名作为标识符
    YJTTableViewCellCreateClass      ///< 使用Class创建cell,即使用[[UITableViewCell alloc] initWithStyle:UITableViewCellStyleDefault reuseIdentifier:className]创建cell    
};

/** TableCell对象*/
@interface YJTTableCellObject : NSObject

@property (nonatomic) id<YJTTableCellModelProtocol> cellModel; ///< cell对应的VM
@property (nonatomic) YJTTableViewCellCreate createCell;  ///< 创建cell的方式
@property (nonatomic, strong, nullable) id userInfo;     ///< 携带的自定义数据

@property (nonatomic) BOOL suspension; ///< 是否悬浮

@property (nonatomic, strong, nullable) NSIndexPath *indexPath; ///< cell所处位置，无须添加，自动填充

@property (nonatomic, readonly) Class cellClass;            ///< UITableViewCell对应的类
@property (nonatomic, copy, readonly) NSString *cellName;   ///< UITableViewCell对应的类名

/**
 *  初始化YJTTableCellObject，当不想创建子类时，可使用此方法创建对象
 *
 *  @param cellClass YJTTableViewCell对应的类
 *
 *  @return void
 */
- (instancetype)initWithTableViewCellClass:(Class)cellClass;

@end

NS_ASSUME_NONNULL_END