module Styles = {
    open Css;
    
    let menuWrapBase = style([
        position(absolute),
        top(pct(100.0)),
        zIndex(1000),
        margin3(~top=px(2), ~h=px(0), ~bottom=px(0)),
        padding2(~v=px(4), ~h=px(0)),
        maxHeight(px(400)),
        minWidth(px(230)),
        
        color(hex("373a3c")),
        backgroundColor(hex("fff")),
        backgroundClip(paddingBox),
        border(px(1), solid, rgba(0, 0, 0, 0.1)),
        borderRadius(px(3)),
        boxShadow(~x=px(0), ~y=px(3), ~blur=px(20), ~spread=px(-4), rgba(0, 0, 0, 0.2)),
    ]);

    let menuWrapOnLeft = merge([
        menuWrapBase,
        style([
            left(px(0)),
        ]),
    ]);

    let menuWrapOnRight = merge([
        menuWrapBase,
        style([
            right(px(0)),
        ]),
    ]);

    let messageBoxWrap = merge([
        menuWrapBase,
        style([
            minWidth(px(430)),
            right(px(0)),
        ])
    ])

    let menuLink = style([
        display(flexBox),
        fontWeight(normal),
        color(hex("333")),
        lineHeight(px(18)),
        padding4(~top=px(4), ~right=px(10), ~bottom=px(4), ~left=px(10)),
        hover([
            backgroundColor(hex("f2f2f5")),
        ])
    ]);

    let separator = style([
        borderTop(px(1), solid, hex("ebebee")),
        margin2(~v=px(3), ~h=px(0)),
    ]);
}

let menuWrap = (menuOnLeft) => {
    menuOnLeft ? Styles.menuWrapOnLeft : Styles.menuWrapOnRight;
}

let messageBoxWrap = Styles.messageBoxWrap;

let menuLink = Styles.menuLink
let separator = Styles.separator

module MessageBox {
    open Css;
    
    let titleWrap = style([
        display(flexBox),
        padding2(~v=px(9), ~h=px(16)),
        borderBottom(px(1), `solid, hex("ebebee")),
    ]);

    let title = style([
        fontWeight(`bold),
    ])

    let button = style([
        marginLeft(`auto),
    ])

    let messageAreaWrap = style([
        display(flexBox),
        justifyContent(`center),
    ])

    let loading = style([
        width(px(24)),
        height(px(24)),
    ])

    let empty = style([
        padding2(~v=px(16), ~h=`zero),
    ])
}
