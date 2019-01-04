module Styles = {
    open Css;
    
    let titleWrap = style([
        display(flexBox),
        padding2(~v=px(9), ~h=px(16)),
        borderBottom(px(1), `solid, hex("ebebee")),
    ]);

    let title = style([
        fontWeight(`bold),
    ])

    let button = style([
        marginLeft(`auto),
    ])

    let messageAreaWrap = style([
        display(flexBox),
        justifyContent(`center),
    ])

    let loading = style([
        width(px(24)),
        height(px(24)),
        padding2(~v=px(16), ~h=`zero),
    ])

    let empty = style([
        padding2(~v=px(16), ~h=`zero),
    ])
}

type state = 
    | Loading
    | Loaded(Message_bs.messages)
    | LoadedEmpty
    | Error

type action = 
    | FetchMessages
    | FetchSucceeded(Message_bs.messages)
    | FetchFailed

let component = ReasonReact.reducerComponent("MessageBoxMenu");

let make = (~title, ~source, ~buttonText, _children) => {
    ...component,
    initialState: () => Loading,
    didMount: self => self.send(FetchMessages),

    reducer: (action: action, _state: state) => {
        switch(action) {
        | FetchMessages => ReasonReact.UpdateWithSideEffects(Loading, self => {
            Js.Promise.(
                Fetch.fetch("http://localhost:3000" ++ source)
                |> then_(Fetch.Response.json)
                |> then_(json => {
                    json
                    |> Atdgen_codec_runtime.Decode.decode(Message_bs.read_messages)
                    |> (messages => {
                        self.send(FetchSucceeded(messages))
                    })
                    |> resolve
                })
                |> catch(_error => 
                    resolve(self.send(FetchFailed)))
                |> ignore
            );
        })
        | FetchSucceeded(messages) => {
            switch(List.length(messages)) {
            | 0 => ReasonReact.Update(LoadedEmpty)
            | _ => ReasonReact.Update(Loaded(messages))
            }
        } 
        | FetchFailed => ReasonReact.Update(Error)
        }
    },

    render: self => {
        <div className=MenuStyles.messageBoxWrap>
            <div className=Styles.titleWrap>
                <div className=Styles.title>{ ReasonReact.string(title) }</div>
                { switch(self.state) {
                | Loaded(_messages) => <div className=Styles.button><a href="#">{ ReasonReact.string(buttonText) }</a></div>
                | _ => { ReasonReact.string("") }
                }}
            </div>
            <div className=Styles.messageAreaWrap>
                {switch(self.state) {
                | Loading => <img className=Styles.loading src="https://cdn.ahrefs.com/images/loader.gif" />
                | LoadedEmpty => <div className=Styles.empty>{ ReasonReact.string("You have no exported files.") }</div>
                | Loaded(messages) => { ReasonReact.string("Loaded") }
                | Error => { ReasonReact.string("Error") }
                }}
            </div>
        </div>
    }
}