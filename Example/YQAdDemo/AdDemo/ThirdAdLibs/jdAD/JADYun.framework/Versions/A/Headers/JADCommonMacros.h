//
//  JADCommonMacros.h
//  JADYun
//
//  Created by wangshuai331 on 2020/9/8.
//  Copyright © 2020 JD.COM. All rights reserved.
//

#ifndef JADCommonMacros_h
#define JADCommonMacros_h

/*********************************************************************************************************/
//强弱引用转换，用于解决代码块（block）与强引用对象之间的循环引用问题
#ifndef jad_weakify
#if __has_feature(objc_arc)
#define jad_weakify(object) __weak __typeof__(object) weak##object = object;
#else
#define jad_weakify(object) __block __typeof__(object) block##object = object;
#endif
#endif
#ifndef jad_strongify
#if __has_feature(objc_arc)
#define jad_strongify(object) __typeof__(object) object = weak##object;
#else
#define jad_strongify(object) __typeof__(object) object = block##object;
#endif
#endif

/*********************************************************************************************************/

#define JADScreenWidth      ([UIScreen mainScreen].bounds.size.width)
#define JADScreenHeight     ([UIScreen mainScreen].bounds.size.height)

#ifndef JADMAXScreenSide
#define JADMAXScreenSide    MAX([UIScreen mainScreen].bounds.size.width, [UIScreen mainScreen].bounds.size.height)
#endif

#define JADIsNotchScreen                jad_is_notch_screen()
#define JADiPhoneX                      JADIsNotchScreen
#define kJADDefaultNavigationBarHeight  (JADiPhoneX?88:64)      // 导航条高度
#define kJADSafeTopMargin               (JADiPhoneX?24:0)
#define kJADDefaultStautsBarHeight      (JADiPhoneX?44:20)      // 状态栏高度

FOUNDATION_EXPORT BOOL jad_is_notch_screen(void);

#endif /* JADCommonMacros_h */
