let component = ReasonReact.statelessComponent("DropdownMenu")

let make = (~text, ~menuItems, _children) => {
    ...component,

    render: _self => {
        <Dropdown content={ReasonReact.string(text)} triangle=true 
            menu=<SimpleMenu menuItems />
        />
    }
}
