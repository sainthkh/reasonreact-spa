let component = ReasonReact.statelessComponent("IndexPage")

let make = (_children) => {
    ...component,
    render: _self => {
        <h2>{ReasonReact.string("IndexPage")}</h2>
    }
}