module Styles = {
    open Css;

    let container = style([
        display(flexBox),
        padding2(~v=px(0), ~h=px(16)),
        paddingBottom(px(7)),
        backgroundColor(hex("005a9e")),
    ])

    let logo = style([
        backgroundImage(url("\"data:image/svg+xml,%3Csvg xmlns='http://www.w3.org/2000/svg' id='Layer_1' data-name='Layer 1' viewBox='0 0 148 36'%3E%3Cdefs%3E%3Cstyle%3E.cls-1%7Bfill:%23fff;%7D.cls-2%7Bfill:%23f80;%7D%3C/style%3E%3C/defs%3E%3Ctitle%3EArtboard 1%3C/title%3E%3Cpath id='Rectangle_20_copy_5' data-name='Rectangle 20 copy 5' class='cls-1' d='M44,36V12H36V36H28V0h8V8H48v4h4V36ZM64,16V36H56V8h8v4h4V8h8v8Zm40,12v4h-4V28ZM84,36V32H80V12h4V8h16v4h4V24H88v8h12v4ZM96,20V12H88v8ZM120,4V8h4v4h-4V36h-8V12h-4V8h4V4h4V0h12V4Zm20,12v4h4v4h4v8h-4v4H132V32h8V28h-4V24h-4V20h-4V12h4V8h12v4h-8v4ZM128,28h4v4h-4Zm20-12h-4V12h4Z'/%3E%3Cpath id='Rectangle_20_copy_7' data-name='Rectangle 20 copy 7' class='cls-2' d='M4,36V32H0V24H4V20H16V12H4V8H20v4h4V36ZM8,24v8h8V24ZM0,16V12H4v4Z'/%3E%3C/svg%3E\"")),
        backgroundRepeat(noRepeat),
        backgroundSize(size(px(74), px(18))),
        height(px(28)),
        width(px(74)),
        marginTop(px(13)),
        marginRight(px(20)),
        textIndent(px(-5000)),
        overflow(hidden),
    ])

    let link = style([
        color(rgba(255, 255, 255, 0.7)),
        textDecoration(none),
        paddingTop(px(14)),
        paddingRight(px(16)),
        hover([
            color(hex("fff")),
        ]),
    ])
}

let component = ReasonReact.statelessComponent("NavBar")

let make = (_children) => {
    ...component,

    render: _self => {
        <div className=Styles.container>
            <NavLink href=Url.page(Index) className=Styles.logo>{ReasonReact.string("Ahrefs")}</NavLink>
            <NavLink href=Url.page(Index) className=Styles.link>{ReasonReact.string("Dashboard")}</NavLink>
            <NavLink href="#" className=Styles.link>{ReasonReact.string("Alerts")}</NavLink>
            <NavLink href=Url.page(SiteExplorer) className=Styles.link>{ReasonReact.string("Site explorer")}</NavLink>
            <NavLink href="#" className=Styles.link>{ReasonReact.string("Content explorer")}</NavLink>
            <NavLink href=Url.page(KeywordExplorer) className=Styles.link>{ReasonReact.string("Keyword explorer")}</NavLink>
            <NavLink href="#" className=Styles.link>{ReasonReact.string("Rank tracker")}</NavLink>
            <NavLink href="#" className=Styles.link newFeature=true>{ReasonReact.string("Site audit")}</NavLink>
            <DropdownMenu className=Styles.link menuName="More" menuItems=[
                { name: "Ahrefs rank", url: "#"},
                { name: "Domain comparison", url: "#"},
                { name: "Batch analysis", url: "#"},
                { name: "Link intersect", url: "#"},
                { name: "SEO toolbar", url: "#"},
                { name: "Ahrefs API", url: "#"},
                { name: "Apps", url: "#"},
            ] />
        </div>
    }
}
