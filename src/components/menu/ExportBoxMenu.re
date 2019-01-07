let component = ReasonReact.statelessComponent("ExportBoxMenu")

let make = (_children) => {
    ...component,

    render: _self => {
        <MessageBox 
            source="/exports" 
            title="Exported files" 
            buttonText="Remove all"
            buttonAction={ (self, _messages) => {
                let emptyMessages: MessageBox.action = UpdateMessages([]);
                self.send(emptyMessages)
            }}
            emptyMessage="You have no exported files"
            marginRight={-33}
        />
    }
}
