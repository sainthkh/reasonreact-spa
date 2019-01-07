module Styles = {
    open Css;
    
    let wrap = style([
        padding3(~top=px(0), ~h=px(16), ~bottom=px(13)),
        background(hex("005a9e")),
    ]);

    let formWrap = style([
        display(flexBox),
        maxWidth(pct(50.0)),
        minWidth(px(650)),
    ])

    let input = style([
        padding4(~top=px(4), ~right=px(35), ~bottom=px(3), ~left=px(10)),
        width(px(595)),
        lineHeight(px(21)),
        border(px(1), `solid, hex("fff")),
        borderRightWidth(px(0)),
        placeholder([
            fontSize(px(14)),
            color(hex("a7a7a7")),
        ])
    ])

    let button = style([
        width(px(55)),
        color(hex("fff")),
        borderRadius(px(3)),
        borderTopLeftRadius(zero),
        borderBottomLeftRadius(zero),
        border(px(1), `solid, hex("f80")),
        backgroundColor(hex("f80")),
        padding3(~top=px(2), ~h=px(16), ~bottom=px(4)),
        height(px(30)),
    ])
}

let component = ReasonReact.statelessComponent("SearchBar")

let make = (_children) => {
    ...component,

    render: _self => {
        <nav className=Styles.wrap>
            <form className=Styles.formWrap>
                <input type_="text" className=Styles.input placeholder="Enter domain, URL or topic" />
                <button type_="submit" className=Styles.button><span className=Icons.explorer /></button>
            </form>
        </nav>
    }
}
