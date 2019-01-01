[@bs.module "../ListenerManager"] external addEventListener: (string, ReactEvent.Mouse.t => unit) => int = "add"
[@bs.module "../ListenerManager"] external removeEventListener: int => unit = "remove"

module Styles = {
    open Css;

    let dropdownWrap = style([
        position(relative),
    ])

    let button = style([
        display(inlineBlock),
        color(rgba(255, 255, 255, 0.7)),
        textDecoration(none),
        cursor(`pointer),
        hover([
            color(hex("fff")),
        ]),
    ])

    let icon = style([
        opacity(0.3),
        marginTop(px(9)),
        hover([
            opacity(1.0),
        ])
    ]);

    let active = style([
        opacity(1.0),
    ]);
}

type menuItem = {
    name: string, 
    url: string,
}

type button = Text(string) | Icon(string)

type state = {
    show: bool,
    eventId: ref(int),
};

type action = OpenMenu | CloseMenu;

let component = ReasonReact.reducerComponent("Dropdown");

let make = (~button: button, ~menu, _children) => {
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
            <a className=Cn.make([
                Styles.button, 
                Cn.mapSome(
                    Some(button),
                    fun
                    | Text(_text) => Icons.triangle
                    | Icon(_icon) => ""
                )]) 
                onClick>
                { switch(button) {
                | Text(button) => { ReasonReact.string(button) }
                | Icon(icon) => <span 
                        className=Cn.make([
                            icon, 
                            Styles.icon, 
                            Styles.active->Cn.ifTrue(self.state.show),
                        ]) 
                    />
                }}
            </a>
            {self.state.show ? menu : {ReasonReact.string("")}}
        </div>
    }
}
