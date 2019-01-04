type state = 
    | Loading
    | Loaded(Message_bs.messages)
    | LoadedEmpty
    | Error

type action = 
    | FetchMessages
    | FetchSucceeded(Message_bs.messages)
    | FetchFailed

let component = ReasonReact.reducerComponent("ExportBoxMenu");

let make = (_children) => {
    ...component,
    initialState: () => Loading,
    didMount: self => self.send(FetchMessages),

    reducer: (action: action, _state: state) => {
        switch(action) {
        | FetchMessages => ReasonReact.UpdateWithSideEffects(Loading, self => {
            Js.Promise.(
                Fetch.fetch("http://localhost:3000/exports")
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
            <div className=MenuStyles.MessageBox.titleWrap>
                <div className=MenuStyles.MessageBox.title>{ ReasonReact.string("Exported files") }</div>
                { switch(self.state) {
                | Loaded(_messages) => <div className=MenuStyles.MessageBox.button><a href="#">{ ReasonReact.string("Remove all") }</a></div>
                | _ => { ReasonReact.string("") }
                }}
            </div>
            <div className=MenuStyles.MessageBox.messageAreaWrap>
                {switch(self.state) {
                | Loading => <img className=Cn.make([MenuStyles.MessageBox.loading, MenuStyles.MessageBox.empty])  src="https://cdn.ahrefs.com/images/loader.gif" />
                | LoadedEmpty => <div className=MenuStyles.MessageBox.empty>{ ReasonReact.string("You have no exported files.") }</div>
                | Loaded(_messages) => { ReasonReact.string("I don't have access.") }
                | Error => { ReasonReact.string("Error") }
                }}
            </div>
        </div>
    }
}