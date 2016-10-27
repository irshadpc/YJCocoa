//
//  YJUICollectionViewCell.m
//  YJUICollectionView
//
//  HomePage:https://github.com/937447974/YJCocoa
//  YJ技术支持群:557445088
//
//  Created by 阳君 on 16/5/21.
//  Copyright © 2016年 YJCocoa. All rights reserved.
//

#import "YJUICollectionViewCell.h"
#import "YJUICollectionViewManager.h"

@implementation UICollectionViewCell (YJUICollectionView)

+ (CGSize)collectionViewManager:(YJUICollectionViewManager *)collectionViewManager sizeForCellObject:(YJUICollectionCellObject *)cellObject {
    if (cellObject.createCell == YJUICollectionCellCreateDefault) { // 默认使用xib创建cell
        NSArray<UIView *> *array = [[NSBundle mainBundle] loadNibNamed:cellObject.cellName owner:nil options:nil];
        return array.firstObject.frame.size;
    }
    return collectionViewManager.delegateFlowLayoutManager.flowLayout.itemSize; // 默认设置
}

@end

@implementation YJUICollectionViewCell

- (void)reloadDataSyncWithCellObject:(YJUICollectionCellObject *)cellObject collectionViewManager:(nonnull YJUICollectionViewManager *)collectionViewManager {
    _cellObject = cellObject;
    _collectionViewManager = collectionViewManager;
}

@end