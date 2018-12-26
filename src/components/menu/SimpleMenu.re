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

    let backButton = merge([
        MenuItems.Styles.menuLink,
        style([
            borderBottom(px(1), solid, hex("ebebee")),
            fontWeight(bold),
            cursor(`pointer),
        ])
    ]);

    let backIcon = merge([
        Icons.backArrow,
        style([
            marginRight(px(8)),
        ])
    ])
}

open MenuTypes;

type menu = {
    title: option(string),
    menuItems: list(menuItem)
}

type state = {
    menuStack: Stack.t(menu),
};

type action = 
    | ShowSubmenu(string, list(menuItem)) 
    | GoBack
    | StackChanged;

let component = ReasonReact.reducerComponent("SimpleMenu");

let make = (~menuItems: list(menuItem), ~menuOnLeft=true, _children) => {
    ...component,
    initialState: () => {
        let stack = Stack.create();
        
        Stack.push({
            title: None,
            menuItems,
        }, stack);

        {
            menuStack: stack,
        }
    },

    reducer: (action: action, state: state) => {
        switch(action) {
        | ShowSubmenu(title, menuItems) => 
            ReasonReact.SideEffects(self => {
                Stack.push({
                    title: Some(title),
                    menuItems,
                }, self.state.menuStack)
                
                self.send(StackChanged)
            })
        | GoBack => 
            ReasonReact.SideEffects(self => {
                let _ = Stack.pop(self.state.menuStack)

                self.send(StackChanged)
            })
        | StackChanged => ReasonReact.Update(state)
        }
    },

    render: self => {
        let menuWrap = menuOnLeft ? Styles.menuWrapOnLeft : Styles.menuWrapOnRight;
        let menu = Stack.top(self.state.menuStack);

        let onSubmenu = (title, menuItems) => 
            self.send(ShowSubmenu(title, menuItems))
        ;

        let onBackButtonClick = event => {
            self.send(GoBack);
            event->ReactEvent.Synthetic.stopPropagation;
        };

        <div className=menuWrap>
            {switch(menu.title){
            | None => {ReasonReact.string("")}
            | Some(title) => 
                <div className=Styles.backButton
                    onClick = onBackButtonClick
                    >
                    <span className=Styles.backIcon />
                    {ReasonReact.string(title)}
                </div>
            }}
            <MenuItems menuItems=menu.menuItems onSubmenu />
        </div>
    }
}
