let component = ReasonReact.statelessComponent("Banner")

let make = (_children) => {
    ...component,

    render: _self => {
        <div>
            { ReasonReact.string("Banner") }
        </div>
    }
}
