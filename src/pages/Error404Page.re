let component = ReasonReact.statelessComponent("Error404Page")

let make = (_children) => {
    ...component,
    render: _self => {
        <h2>{ReasonReact.string("Error 404")}</h2>
    }
}