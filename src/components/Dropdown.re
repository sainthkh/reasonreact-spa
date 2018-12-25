[@bs.module "./ListenerManager"] external addEventListener: (string, ReactEvent.Mouse.t => unit) => int = "add"
[@bs.module "./ListenerManager"] external removeEventListener: int => unit = "remove"

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

let component = ReasonReact.reducerComponent("Dropdown");

let make = (~content, ~menu, ~triangle=false, _children) => {
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
            <a className=Cn.make([Styles.button, Icons.triangle->Cn.ifTrue(triangle)]) onClick>
                content
            </a>
            {self.state.show ? 
                menu
            :
            {ReasonReact.string("")}}
        </div>
    }
}
