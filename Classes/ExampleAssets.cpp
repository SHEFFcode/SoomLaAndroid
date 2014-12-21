//
//  ExampleAssets.cpp
//  HelloWorld2
//
//  Created by Yuriy Shefer on 12/10/14.
//
//

#include "ExampleAssets.h"
#include "CCVirtualCurrency.h"
#include "CCVirtualGood.h"
#include "CCLifetimeVG.h"
#include "CCPurchaseWithMarket.h"
#include "Cocos2dxStore.h"


USING_NS_CC;
using namespace soomla;

ExampleAssets *ExampleAssets::create() {
    ExampleAssets *ret = new ExampleAssets();
    ret->autorelease();
    ret->init();
    
    return ret;
}

bool ExampleAssets::init() {
    
    
    /** Google MANAGED Items **/
    CCVirtualGood *noAds = CCLifetimeVG::create(
    CCString::create("NoAds"),// name
    CCString::create("Removes Ads"), // description
    CCString::create("android.test.purchased"),// item id
    CCPurchaseWithMarket::createWithMarketItem(CCMarketItem::create(CCString::create("android.test.purchased"),
    CCInteger::create(CCMarketItem::NONCONSUMABLE),
    CCDouble::create(0.00))) // the way this virtual good is purchased
    );

    
    mGoods = CCArray::create(noAds, NULL);
    mGoods->retain();
    
    return true;
}

ExampleAssets::~ExampleAssets() {
    CC_SAFE_RELEASE(mCurrencies);
    CC_SAFE_RELEASE(mGoods);
    CC_SAFE_RELEASE(mCurrencyPacks);
    CC_SAFE_RELEASE(mCategories);
}

int ExampleAssets::getVersion() {
    return 0;
}

cocos2d::CCArray *ExampleAssets::getCurrencies() {
    return mCurrencies;
}

cocos2d::CCArray *ExampleAssets::getGoods() {
    return mGoods;
}

cocos2d::CCArray *ExampleAssets::getCurrencyPacks() {
    return mCurrencyPacks;
}

cocos2d::CCArray *ExampleAssets::getCategories() {
    return mCategories;
}
