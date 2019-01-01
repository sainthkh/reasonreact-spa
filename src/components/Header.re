module Styles = {
    open Css;
    
    let container = style([
        display(flexBox),
        backgroundColor(hex("005a9e")),
        padding3(~top=px(0), ~h=px(16), ~bottom=px(7)),
    ]);

    let left = style([
        display(flexBox),
        marginRight(auto),
        paddingTop(px(14)),
    ])

    let right = style([
        display(flexBox),
        paddingTop(px(7)),
    ])

    let logo = style([
        display(block),
        height(px(28)),
        width(px(74)),
        marginTop(px(13)),
        marginRight(px(20)),

        backgroundImage(url("\"data:image/svg+xml,%3Csvg xmlns='http://www.w3.org/2000/svg' id='Layer_1' data-name='Layer 1' viewBox='0 0 148 36'%3E%3Cdefs%3E%3Cstyle%3E.cls-1%7Bfill:%23fff;%7D.cls-2%7Bfill:%23f80;%7D%3C/style%3E%3C/defs%3E%3Ctitle%3EArtboard 1%3C/title%3E%3Cpath id='Rectangle_20_copy_5' data-name='Rectangle 20 copy 5' class='cls-1' d='M44,36V12H36V36H28V0h8V8H48v4h4V36ZM64,16V36H56V8h8v4h4V8h8v8Zm40,12v4h-4V28ZM84,36V32H80V12h4V8h16v4h4V24H88v8h12v4ZM96,20V12H88v8ZM120,4V8h4v4h-4V36h-8V12h-4V8h4V4h4V0h12V4Zm20,12v4h4v4h4v8h-4v4H132V32h8V28h-4V24h-4V20h-4V12h4V8h12v4h-8v4ZM128,28h4v4h-4Zm20-12h-4V12h4Z'/%3E%3Cpath id='Rectangle_20_copy_7' data-name='Rectangle 20 copy 7' class='cls-2' d='M4,36V32H0V24H4V20H16V12H4V8H20v4h4V36ZM8,24v8h8V24ZM0,16V12H4v4Z'/%3E%3C/svg%3E\"")),
        backgroundRepeat(noRepeat),
        backgroundSize(size(px(74), px(18))),
        textIndent(px(-5000)),
        overflow(hidden),
    ])

    let link = style([
        display(block),
        color(rgba(255, 255, 255, 0.7)),
        hover([
            color(hex("fff")),
        ]),
    ])
}

let component = ReasonReact.statelessComponent("Header");

let make = (_children) => {
    ...component,

    render: _self => {
        <div className=Styles.container>
            <NavLink href=Url.page(Index) className=Styles.logo>{ReasonReact.string("Ahrefs")}</NavLink>
            <div className=Styles.left>
                <NavBar>
                    <NavLink href=Url.page(Index) className=Styles.link>{ReasonReact.string("Dashboard")}</NavLink>
                    <NavLink href="#" className=Styles.link>{ReasonReact.string("Alerts")}</NavLink>
                    <NavLink href=Url.page(SiteExplorer) className=Styles.link>{ReasonReact.string("Site explorer")}</NavLink>
                    <NavLink href="#" className=Styles.link>{ReasonReact.string("Content explorer")}</NavLink>
                    <NavLink href=Url.page(KeywordExplorer) className=Styles.link>{ReasonReact.string("Keywords explorer")}</NavLink>
                    <NavLink href="#" className=Styles.link>{ReasonReact.string("Rank tracker")}</NavLink>
                    <NavLink href="#" className=Styles.link newFeature=true>{ReasonReact.string("Site audit")}</NavLink>
                    <Dropdown button=Text("More") menu=<SimpleMenu menuItems=[
                            Link({ name: "Ahrefs rank", url: "#"}),
                            Link({ name: "Domain comparison", url: "#"}),
                            Link({ name: "Batch analysis", url: "#"}),
                            Link({ name: "Link intersect", url: "#"}),
                            Link({ name: "SEO toolbar", url: "#"}),
                            Link({ name: "Ahrefs API", url: "#"}),
                            Link({ name: "Apps", url: "#"}),
                        ] />
                    />
                </NavBar>
            </div>
            <div className=Styles.right>
                <NavBar>
                    <Dropdown button=Icon(Icons.question) menu=<SimpleMenu menuOnLeft=false menuItems=[] /> />
                    <Dropdown button=Icon(Icons.bell) menu=<SimpleMenu menuOnLeft=false menuItems=[] /> />
                    <Dropdown button=Icon(Icons.exportBox) menu=<SimpleMenu menuOnLeft=false menuItems=[] /> />
                    <Dropdown button=Icon(Icons.profile)
                        menu=<SimpleMenu menuOnLeft=false menuItems=[
                            Text({ title: "Kukhyeon Heo", explanation: "sssshkh@gmail.com" }),
                            Separator,
                            Link({ name: "Subscription plan", url: "#" }),
                            Link({ name: "Orders", url: "#" }),
                            Link({ name: "Account settings", url: "#" }),
                            Link({ name: "Email subscriptions", url: "#" }),
                            Link({ name: "Applications", url: "#" }),
                            Submenu("Language", [
                                Link({ name: "Deutsch", url: "#"}),
                                Link({ name: "English", url: "#"}),
                                Link({ name: {js|Español|js}, url: "#"}),
                                Link({ name: {js|Français|js}, url: "#"}),
                                Link({ name: "Italiano", url: "#"}),
                                Link({ name: {js|日本語|js}, url: "#"}),
                                Link({ name: "Nederlands", url: "#"}),
                                Link({ name: "Polski", url: "#"}),
                                Link({ name: {js|Português|js}, url: "#"}),
                                Link({ name: {js|Русский|js}, url: "#"}),
                                Link({ name: "Svenska", url: "#"}),
                                Link({ name: {js|Türkçe|js}, url: "#"}),
                                Link({ name: {js|中文|js}, url: "#"}),
                            ]),
                            Separator,
                            Link({ name: "Sign out", url: "#" }),
                        ] />
                    />
                </NavBar>
            </div>
        </div>
    }
}
