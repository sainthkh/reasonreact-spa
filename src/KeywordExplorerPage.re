let component = ReasonReact.statelessComponent("KeywordExplorerPage")

let make = (_children) => {
    ...component,
    render: self => {
        <h2>{ReasonReact.string("Keyword Explorer Page")}</h2>
    }
}