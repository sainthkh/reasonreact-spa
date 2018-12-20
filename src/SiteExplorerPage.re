let component = ReasonReact.statelessComponent("SiteExplorerPage")

let make = (_children) => {
    ...component,
    render: self => {
        <h2>{ReasonReact.string("SiteExplorerPage")}</h2>
    }
}