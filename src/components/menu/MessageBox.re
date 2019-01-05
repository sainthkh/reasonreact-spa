type state = 
    | Loading
    | Loaded(Message_bs.messages)
    | LoadedEmpty
    | Error

type action = 
    | FetchMessages
    | UpdateMessages(Message_bs.messages)
    | FetchFailed

let component = ReasonReact.reducerComponent("NotificationBoxMenu");

let make = (~source, ~title, ~buttonText, ~buttonAction, ~emptyMessage, _children) => {
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
                        self.send(UpdateMessages(messages))
                    })
                    |> resolve
                })
                |> catch(_error => 
                    resolve(self.send(FetchFailed)))
                |> ignore
            );
        })
        | UpdateMessages(messages) => {
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
                <div className=MenuStyles.MessageBox.title>{ ReasonReact.string(title) }</div>
                { switch(self.state) {
                | Loaded(messages) => 
                    <div className=MenuStyles.MessageBox.button>
                        <a href="#" 
                            onClick={ event => {
                                buttonAction(self, messages)
                                event->ReactEvent.Synthetic.preventDefault;
                                event->ReactEvent.Synthetic.stopPropagation;
                            }}>
                            { ReasonReact.string(buttonText) }
                        </a>
                    </div>
                | _ => { ReasonReact.string("") }
                }}
            </div>
            <div className=MenuStyles.MessageBox.messageAreaWrap>
                {switch(self.state) {
                | Loading => <img className=Cn.make([MenuStyles.MessageBox.loading, MenuStyles.MessageBox.empty])  src="https://cdn.ahrefs.com/images/loader.gif" />
                | LoadedEmpty => <div className=MenuStyles.MessageBox.empty>{ ReasonReact.string(emptyMessage) }</div>
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