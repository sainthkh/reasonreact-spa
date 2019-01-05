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
    ])

    let empty = style([
        padding2(~v=px(16), ~h=`zero),
    ])

    let link = style([
        padding3(~top=px(9), ~h=px(16), ~bottom=px(8)),
        display(flexBox),
        background(rgba(55,157,228,0.08)),
        borderBottom(px(1), `solid, hex("ddd")),
        hover([
            background(rgba(55,157,228,0.12)),
        ])
    ])

    let linkIsRead = style([
        background(hex("fff")),
        hover([
            background(hex("f2f2f5")),
        ])
    ])

    let circle = style([
        borderRadius(pct(50.0)),
        height(px(24)),
        width(px(24)),
        padding(px(2)),
        display(flexBox),
        justifyContent(center),
        alignItems(center),
        marginRight(px(16)),
        flexGrow(1.0),
        flexShrink(0),
    ]);

    let blueCircle = merge([
        circle,
        style([
            backgroundColor(hex("379de4")),
        ])
    ]);

    let icon = style([
        height(px(20)),
        width(px(20)),
        backgroundSize(cover),
    ])

    let messageTitleWrap = style([
        flexGrow(0.0),
        flexShrink(1),
        flexBasis(pct(100.0)),
    ])

    let messageTitle = style([
        color(hex("333")),
        fontWeight(bold),
    ])

    let messageTitleIsRead = style([
        fontWeight(normal),
    ])

    let messageType = style([
        color(hex("7a7a7a")),
        fontSize(px(13)),
    ])

    let dateWrap = style([
        width(px(90)),
        textAlign(`right),
        color(hex("7a7a7a")),
    ])
}

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
            <div className=Styles.titleWrap>
                <div className=Styles.title>{ ReasonReact.string(title) }</div>
                { switch(self.state) {
                | Loaded(messages) => 
                    <div className=Styles.button>
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
            <div className=Styles.messageAreaWrap>
                {switch(self.state) {
                | Loading => <img className=Cn.make([Styles.loading, Styles.empty])  src="https://cdn.ahrefs.com/images/loader.gif" />
                | LoadedEmpty => <div className=Styles.empty>{ ReasonReact.string(emptyMessage) }</div>
                | Loaded(messages) => { 
                    let messageIcon = messageType => 
                        switch(messageType) {
                        | `BlogPost => <div className=Styles.blueCircle><span className=Cn.make([Icons.blogPost, Styles.icon]) /></div>
                        | `YouTubeVideo => <div className=Styles.circle><span className=Cn.make([Icons.youtube, Styles.icon]) /></div>
                        | `Export => <div className=Styles.blueCircle><span className=Cn.make([Icons.blogPost, Styles.icon]) /></div>
                        }
                    ;

                    let messageTypeName = messageType => 
                        switch(messageType) {
                        | `BlogPost => { ReasonReact.string("BlogPost") }
                        | `YouTubeVideo => { ReasonReact.string("YouTube Video") }
                        | `Export => { ReasonReact.string("Export") }
                        }
                    ;

                    <div>{
                    ReasonReact.array(
                        Array.mapi((i, message:Message_bs.message) => {
                            <a 
                                className=Cn.make([
                                    Styles.link, 
                                    Styles.linkIsRead->Cn.ifTrue(message.read)
                                ])
                                href=message.link 
                                key=string_of_int(i)> 
                                { messageIcon(message.messageType) }
                                <div className=Styles.messageTitleWrap>
                                    <div className=Cn.make([
                                        Styles.messageTitle,
                                        Styles.messageTitleIsRead->Cn.ifTrue(message.read)
                                    ])>
                                        { ReasonReact.string(message.title) }
                                    </div>
                                    <div className=Styles.messageType>{ messageTypeName(message.messageType) }</div>
                                </div>
                                <div className=Styles.dateWrap>{ ReasonReact.string(message.date) }</div>
                            </a>
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