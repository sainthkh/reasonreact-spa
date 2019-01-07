module Styles = {
    open Css;
    
    let textWrap = style([
        flexGrow(0.0),
        flexShrink(1),
        flexBasis(pct(100.0)),
    ])

    let icon = style([
        width(px(14)),
        height(px(14)),
        marginTop(px(2)),
        marginRight(px(8)),
        flexShrink(0),
        backgroundPosition(`zero, pct(33.33)),
    ])

    let explanation = style([
        fontSize(px(13)),
        lineHeight(px(16)),
        color(hex("7a7a7a"))
    ])
}

type detailedMenuItem = {
    icon: string,
    title: string, 
    explanation: string,
    link: string,
}

let component = ReasonReact.statelessComponent("DetailedMenu")

let make = (~menuItems: list(detailedMenuItem), ~menuOnLeft, ~marginRight, _children) => {
    ...component,

    render: _self => {
        <div className=Cn.make([
            MenuStyles.menuWrap(menuOnLeft), 
            MenuStyles.marginRight(marginRight), 
            MenuStyles.triangle(-marginRight)
            ])>
            {ReasonReact.array(
                Array.mapi((i, menuItem) => {
                    let key = string_of_int(i);

                    <div key>
                        <a className=MenuStyles.menuLink href=menuItem.link>
                            <div className=Cn.make([menuItem.icon, Styles.icon]) />
                            <div className=Styles.textWrap>
                                <div>{ReasonReact.string(menuItem.title)}</div>
                                <div className=Styles.explanation>{ReasonReact.string(menuItem.explanation)}</div>
                            </div>
                        </a>
                        { i < List.length(menuItems) - 1 ?
                            <div className=MenuStyles.separator /> :
                            {ReasonReact.string("")}
                        }
                    </div>

                }, Array.of_list(menuItems))
            )}
        </div>
    }
}
