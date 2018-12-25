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

    let menuLink = style([
        display(block),
        fontWeight(normal),
        color(hex("333")),
        lineHeight(px(18)),
        padding4(~top=px(4), ~right=px(16), ~bottom=px(4), ~left=px(10)),
        hover([
            backgroundColor(hex("f2f2f5")),
        ])
    ])
}

type menuLink = {
    name: string,
    url: string,
}

let component = ReasonReact.statelessComponent("SimpleMenu")

let make = (~menuItems: list(menuLink), ~menuOnLeft=true, _children) => {
    ...component,

    render: _self => {
        let menuWrap = menuOnLeft ? Styles.menuWrapOnLeft : Styles.menuWrapOnRight;

        <div className=menuWrap>
            {ReasonReact.array(
                Array.mapi((i, {name, url}) => {
                    <a href=url key=string_of_int(i) className=Styles.menuLink>{ReasonReact.string(name)}</a>
                }, Array.of_list(menuItems))
            )}
        </div>
    }
}
