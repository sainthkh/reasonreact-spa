module Styles = {
    open Css;
    
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

type state = {
    active: bool,
};

type action = Click;

let component = ReasonReact.reducerComponent("IconDropdownMenu");

let make = (~icon, ~menu, _children) => {
    ...component,
    initialState: () => {
        active: false,
    },

    reducer: (action: action, state: state) => {
        switch(action) {
        | Click => ReasonReact.Update({ active: !state.active })
        }
    },

    render: self => {
        <Dropdown 
            content=<span 
                className=Cn.make([
                    icon, 
                    Styles.icon, 
                    Styles.active->Cn.ifTrue(self.state.active),
                ]) 
                onClick={ _e => self.send(Click) } 
            />
            menu 
        />
    }
}
