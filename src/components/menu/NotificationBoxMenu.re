let component = ReasonReact.statelessComponent("NotificationBoxMenu")

let make = (_children) => {
    ...component,

    render: _self => {
        <MessageBox
            source="/notifications"
            title="Notifications"
            buttonText="Mark all as read"
            buttonAction={ (self, messages) => {
                let allRead: MessageBox.action = 
                    UpdateMessages(List.map
                        (message => { ...message, read: true} : Message_bs.message => Message_bs.message)
                        (messages : Message_bs.messages)
                    )
                self.send(allRead)
            }}
            emptyMessage="No notifications"
            marginRight={-65}
        />
    }
}
