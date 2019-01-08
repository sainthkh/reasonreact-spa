module Styles = {
    open Css;

    let wrap = style([
        background(hex("f2f2f5")),
        padding2(~v=px(18), ~h=px(16)),
        borderTop(px(1), `solid, hex("e5e5e8")),
        position(absolute),
        bottom(zero),
        width(vw(100.0)),
        boxSizing(borderBox),
    ]);

    let menus = style([
        display(flexBox),
        paddingBottom(px(16)),
    ])

    let navLink = style([
        color(hex("333")),
        hover([
            color(hex("f70")),
        ])
    ])

    let rightMenu = style([
        marginLeft(`auto),
    ])

    let disclaimers = style([
        borderTop(px(1), `solid, hex("e5e5e8")),
        paddingTop(px(12)),
        paddingBottom(px(12)),
    ])

    let companyLocation = style([
        fontSize(px(12)),
        color(hex("aaa")),
        marginRight(px(5)),
    ])

    let disclaimerLink = style([
        fontSize(px(12)),
        color(hex("999")),
    ])
}

let component = ReasonReact.statelessComponent("Footer")

let make = (_children) => {
    ...component,

    render: _self => {
        <footer className=Styles.wrap>
            <div className=Styles.menus>
                <NavBar>
                    <NavLink className=Styles.navLink href="#">{ ReasonReact.string("About") }</NavLink>
                    <NavLink className=Styles.navLink href="#">{ ReasonReact.string("Team") }</NavLink>
                    <NavLink className=Styles.navLink href="#">{ ReasonReact.string("Jobs") }</NavLink>
                    <NavLink className=Styles.navLink href="#">{ ReasonReact.string("Our data") }</NavLink>
                    <NavLink className=Styles.navLink href="#">{ ReasonReact.string("Robot") }</NavLink>
                    <NavLink className=Styles.navLink href="#">{ ReasonReact.string("Affiliate") }</NavLink>
                    <NavLink className=Styles.navLink href="#">{ ReasonReact.string("Pricing") }</NavLink>
                    <NavLink className=Styles.navLink href="#">{ ReasonReact.string("API") }</NavLink>
                    <NavLink className=Styles.navLink href="#">{ ReasonReact.string("Help") }</NavLink>
                    <NavLink className=Styles.navLink href="#">{ ReasonReact.string("Contact us") }</NavLink>
                </NavBar>
                <div className=Styles.rightMenu>
                    <NavBar>
                        <NavLink className=Styles.navLink href="#">{ ReasonReact.string("Blog") }</NavLink>
                        <NavLink className=Styles.navLink href="#">{ ReasonReact.string("Tech blog") }</NavLink>
                        <NavLink className=Styles.navLink href="#">{ ReasonReact.string("Twitter") }</NavLink>
                        <NavLink className=Styles.navLink href="#">{ ReasonReact.string("Facebook") }</NavLink>
                        <NavLink className=Styles.navLink href="#">{ ReasonReact.string("Youtube") }</NavLink>
                    </NavBar>
                </div>
            </div>
            <div className=Styles.disclaimers>
                <span className=Styles.companyLocation>{ ReasonReact.string({j|© 2019 Ahrefs Pte. Ltd. (201227417H) 16 Raffles Quay, #33-03 Hong Leong Building, Singapore 048581|j}) }</span>
                <NavLink href="#" className=Styles.disclaimerLink>{ ReasonReact.string("Terms & conditions") }</NavLink>
                <span className=Styles.disclaimerLink>{ ReasonReact.string(" | ") }</span>
                <NavLink href="#" className=Styles.disclaimerLink>{ ReasonReact.string("Privacy policy") }</NavLink>
            </div>
        </footer>
    }
}
