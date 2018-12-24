[@bs.module "./ListenerManager"] external addEventListener: (string, ReactEvent.Mouse.t => unit) => int = "add"
[@bs.module "./ListenerManager"] external removeEventListener: int => unit = "remove"

module Styles = {
    open Css;

    let dropdownWrap = style([
        position(relative),
    ])

    let button = style([
        color(rgba(255, 255, 255, 0.7)),
        textDecoration(none),
        cursor(`pointer),
        paddingTop(px(14)),
        paddingRight(px(16)),
        hover([
            color(hex("fff")),
        ]),
    ])

    let dropdownMenu = style([
        position(absolute),
        top(pct(100.0)),
        left(px(0)),
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

    let menuLink = style([
        display(block),
        fontWeight(normal),
        color(hex("333")),
        lineHeight(px(18)),
        padding4(~top=px(4), ~right=px(16), ~bottom=px(4), ~left=px(10)),
        hover([
            backgroundColor(hex("f2f2f5")),
        ])
    ])
}

type menuItem = {
    name: string, 
    url: string,
}

type state = {
    show: bool,
    eventId: ref(int),
};

type action = OpenMenu | CloseMenu;

let component = ReasonReact.reducerComponent("DropdownMenu");

let make = (~menuName, ~menuItems: list(menuItem), _children) => {
    ...component,
    initialState: () => {
        show: false,
        eventId: ref(-1),
    },

    reducer: (action: action, state: state) => {
        switch(action) {
        | OpenMenu => ReasonReact.UpdateWithSideEffects({ ...state, show: true }, self => {
            let _ = Js.Global.setTimeout(() => {
                state.eventId := addEventListener("click", (_e) => {
                    self.send(CloseMenu);
                });
            }, 0);
        })
        | CloseMenu => ReasonReact.UpdateWithSideEffects({ ...state, show: false }, _self => {
            removeEventListener(state.eventId^);
        })
        }
    },

    render: self => {
        let onClick = event => {
            if(self.state.show) {
                self.send(CloseMenu)
            } else {
                self.send(OpenMenu)
            }

            event->ReactEvent.Synthetic.preventDefault;
        };

        <div className=Styles.dropdownWrap>
            <a className=Cn.make([Styles.button, Icons.triangle]) onClick>{
                ReasonReact.string(menuName)
            }</a>
            { self.state.show ? 
                <div className=Styles.dropdownMenu>
                    {ReasonReact.array(
                        Array.mapi((i, {name, url}) => {
                            <a href=url key=string_of_int(i) className=Styles.menuLink>{ReasonReact.string(name)}</a>
                        }, Array.of_list(menuItems))
                    )}
                </div>
                :
                {ReasonReact.string("")}
            }
        </div>
    }
}
