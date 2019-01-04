type state = 
    | Loading
    | Loaded(Message_bs.messages)
    | LoadedEmpty
    | Error

type action = 
    | FetchMessages
    | FetchSucceeded(Message_bs.messages)
    | FetchFailed

let component = ReasonReact.reducerComponent("NotificationBoxMenu");

let make = (_children) => {
    ...component,
    initialState: () => Loading,
    didMount: self => self.send(FetchMessages),

    reducer: (action: action, _state: state) => {
        switch(action) {
        | FetchMessages => ReasonReact.UpdateWithSideEffects(Loading, self => {
            Js.Promise.(
                Fetch.fetch("http://localhost:3000/notifications")
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
                <div className=MenuStyles.MessageBox.title>{ ReasonReact.string("Notifications") }</div>
                { switch(self.state) {
                | Loaded(_messages) => <div className=MenuStyles.MessageBox.button><a href="#">{ ReasonReact.string("Mark all as read") }</a></div>
                | _ => { ReasonReact.string("") }
                }}
            </div>
            <div className=MenuStyles.MessageBox.messageAreaWrap>
                {switch(self.state) {
                | Loading => <img className=Cn.make([MenuStyles.MessageBox.loading, MenuStyles.MessageBox.empty])  src="https://cdn.ahrefs.com/images/loader.gif" />
                | LoadedEmpty => <div className=MenuStyles.MessageBox.empty>{ ReasonReact.string("No notification") }</div>
                | Loaded(messages) => { 
                    <div>{
                    ReasonReact.array(
                        Array.mapi((i, message:Message_bs.message) => {
                            switch(message.messageType) {
                            | `BlogPost => 
                                <a href=message.link key=string_of_int(i)> 
                                    <div></div>
                                    <div>
                                        <div>{ ReasonReact.string(message.title) }</div>
                                        <div>{ ReasonReact.string("BlogPost") }</div>
                                    </div>
                                    <div>{ ReasonReact.string(message.date) }</div>
                                </a>
                            | `YouTubeVideo => 
                                <a href=message.link key=string_of_int(i)> 
                                    <div></div>
                                    <div>
                                        <div>{ ReasonReact.string(message.title) }</div>
                                        <div>{ ReasonReact.string("YouTube Video") }</div>
                                    </div>
                                    <div>{ ReasonReact.string(message.date) }</div>
                                </a>
                            | `Export => <div>{ ReasonReact.string("Export") } </div>
                            }
                        }, Array.of_list(messages))
                    )
                    }</div>
                }
                | Error => { ReasonReact.string("Error") }
                }}
            </div>
        </div>
    }
}