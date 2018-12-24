module Styles {
    open Css;

    let container = style([
        display(flexBox),
    ])

    let navItem = style([
        paddingTop(px(14)),
        paddingRight(px(16)),
    ])
}

let component = ReasonReact.statelessComponent("NavBar");

let make = (children) => {
    ...component,

    render: _self => {
        <div className=Styles.container>
            {ReasonReact.array(
                Array.mapi((i, child) => 
                    <div className=Styles.navItem key=string_of_int(i)>child</div>,
                    children
                )
            )}
        </div>
    }
}
