module Styles = {
    open Css;
    
    let menuLink = style([
        display(flexBox),
        fontWeight(normal),
        color(hex("333")),
        lineHeight(px(18)),
        padding4(~top=px(4), ~right=px(16), ~bottom=px(4), ~left=px(10)),
        hover([
            backgroundColor(hex("f2f2f5")),
        ])
    ]);

    let separator = style([
        borderTop(px(1), solid, hex("ebebee")),
        margin2(~v=px(3), ~h=px(0)),
    ]);

    let menuTextWrap = style([
        padding3(~top=px(4), ~h=px(10), ~bottom=px(3)),
    ]);

    let menuTextTitle = style([
        fontWeight(bold),
        fontSize(px(14)),
        lineHeight(px(18)),
        color(hex("333")),
        margin(zero),
        padding(zero),
        maxWidth(pct(90.0)),
    ]);

    let menuTextExplanation = style([
        margin(zero),
        color(hex("7a7a7a")),
        fontSize(px(13)),
    ])

    let arrow = merge([
        Icons.nextArrow,
        style([
            marginLeft(auto),
            opacity(0.3),
        ])
    ]);

    global({j|.$menuLink:hover .$arrow|j}, [
        opacity(1.0),
    ])
}

open MenuTypes;

let component = ReasonReact.statelessComponent("MenuItems");

let make = (~menuItems, ~onSubmenu, _children) => {
    ...component,

    render: _self => {
        let onClick = (title, menuItems) => 
            event => {
                onSubmenu(title, menuItems);
                
                event->ReactEvent.Synthetic.stopPropagation;
                event->ReactEvent.Synthetic.preventDefault;
            };

        {ReasonReact.array(
            Array.mapi((i, menuItem) => {
                let key = string_of_int(i)

                switch(menuItem) {
                | Link({name, url}) => 
                    <a href=url 
                        key 
                        className=Styles.menuLink>
                        {ReasonReact.string(name)}
                    </a>
                | Separator => <div className=Styles.separator key />
                | Submenu(name, menu) => 
                    <a href="#" 
                        key 
                        className=Styles.menuLink
                        onClick=onClick(name, menu)>
                        {ReasonReact.string(name)}
                        <span className=Styles.arrow />
                    </a>
                | Text({title, explanation}) => 
                    <div className=Styles.menuTextWrap key>
                        <h5 className=Styles.menuTextTitle>{ReasonReact.string(title)}</h5>
                        <p className=Styles.menuTextExplanation>{ReasonReact.string(explanation)}</p>
                    </div>
                }
            }, Array.of_list(menuItems))
        )}
    }
}
