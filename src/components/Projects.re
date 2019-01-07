let component = ReasonReact.statelessComponent("Projects")

let make = (_children) => {
    ...component,

    render: _self => {
        <div>
            { ReasonReact.string("Projects") }
        </div>
    }
}
