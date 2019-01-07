module Styles = {
    open Css;
    
    let wrap = style([
        paddingTop(px(21)),
    ]);

    let message = style([
        padding2(~v=px(12), ~h=px(15)),
        fontSize(px(16)),
        textAlign(center),
    ])

    let addNew = style([
        marginTop(px(42)),
    ])

    let title = style([
        textAlign(center),
    ])

    let form = style([
        display(flexBox),
        width(px(370)),
        margin2(~v=zero, ~h=auto),
    ])

    let input = style([
        width(px(247)),
        height(px(43)),
        padding3(~top=px(4), ~h=px(8), ~bottom=px(3)),
        border(px(1), solid, hex("d7d7d7")),
        borderRightWidth(zero),
        boxSizing(borderBox),
    ])

    let button = style([
        color(hex("fff")),
        background(hex("f80")),
        width(px(120)),
        height(px(43)),
        borderWidth(`zero),
        borderTopRightRadius(px(3)),
        borderBottomRightRadius(px(3)),
        cursor(`pointer),
        hover([
            background(hex("f70")),
        ])
    ])
}
let component = ReasonReact.statelessComponent("Projects")

let make = (_children) => {
    ...component,

    render: _self => {
        <div className=Styles.wrap>
            <div className=Styles.message>
                { ReasonReact.string("Your Dashboard is empty. Please use the form below to add your first site here.") }
            </div>
            <div className=Styles.addNew>
                <h2 className=Styles.title>{ ReasonReact.string("Add new project") }</h2>
                <form className=Styles.form>
                    <input type_="text" className=Styles.input placeholder="Domain, subfolder or URL"/>
                    <button type_="submit" className=Styles.button>{ ReasonReact.string("Add project") }</button>
                </form>
            </div>
        </div>
    }
}
