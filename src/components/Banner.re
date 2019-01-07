module Styles = {
    open Css;
    
    let wrap = style([
        display(flexBox),
        justifyContent(center),
        alignItems(center),
        background(hex("2e3c56")),
        minHeight(px(221)),
        overflow(hidden),
        position(relative),
    ]);

    let closeButton = style([
        position(absolute),
        background(url("https://cdn.ahrefs.com/images/cross-white.svg")),
        backgroundPosition(pct(50.0), pct(50.0)),
        backgroundRepeat(noRepeat),
        backgroundSize(size(px(11), px(11))),
        height(px(20)),
        width(px(20)),
        top(px(16)),
        right(px(16)),
        cursor(`pointer),
        zIndex(6),
        opacity(0.6),
    ])

    let imgLeft = style([
        background(url("https://cdn.ahrefs.com/images/dashboard/sa-banner-left.png")),
        backgroundSize(size(px(524), px(221))),
        height(px(221)),
        width(px(524)),
        marginRight(px(50)),
        flexShrink(0),
    ])

    let imgRight = style([
        background(url("https://cdn.ahrefs.com/images/dashboard/sa-banner-right.png")),
        backgroundSize(size(px(406), px(221))),
        height(px(221)),
        width(px(406)),
        marginLeft(px(35)),
    ])

    let textBox = style([
        color(hex("fff")),
        flexShrink(0),
    ])

    let tagline = style([
        fontSize(px(26)),
        fontWeight(bold),
        lineHeight(px(30)),
        marginTop(px(0)),
        marginBottom(px(6)),
    ])

    let subhead = style([
        fontSize(px(16)),
        lineHeight(px(18)),
        marginTop(zero),
        marginBottom(px(14)),
    ])

    let buttonBase = style([
        display(inlineBlock),
        color(hex("fff")),
        textAlign(center),
        padding2(~v=px(6), ~h=px(14)),
        fontSize(px(14)),
        marginRight(px(8)),
        lineHeight(px(18)),
        borderRadius(px(3)),
    ])

    let learnMore = merge([
        buttonBase,
        style([
            background(hex("5ebf5e")),
            hover([
                background(hex("54ab54")),
            ])
        ])
    ])

    let tryitnow = merge([
        buttonBase,
        style([
            border(px(1), solid, rgba(255, 255, 255, 0.2)),
            hover([
                border(px(1), solid, rgba(255, 255, 255, 0.7)),
            ])
        ])
    ])
}
let component = ReasonReact.statelessComponent("Banner")

let make = (_children) => {
    ...component,

    render: _self => {
        <div className=Styles.wrap>
            <div className=Styles.closeButton />
            <div className=Styles.imgLeft />
            <div className=Styles.textBox>
                <h2 className=Styles.tagline>{ ReasonReact.string("The new Site Audit") }</h2>
                <p className=Styles.subhead>{ ReasonReact.string("Analyze your website for 100+ SEO issues.") }</p>
                <div>
                    <a className=Styles.learnMore href="https://ahrefs.com/blog/new-site-audit-tool/">{ ReasonReact.string("Learn more") }</a>
                    <a className=Styles.tryitnow href="#">{ ReasonReact.string("Try it now") }</a>
                </div>
            </div>
            <div className=Styles.imgRight />
        </div>
    }
}
