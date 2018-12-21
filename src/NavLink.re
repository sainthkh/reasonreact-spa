let component = ReasonReact.statelessComponent("NavLink");

let make = (~href, ~className="", children) => {
    ...component,
    render: _self => {
        let onClick = (link) => 
            (event) => {
                ReasonReact.Router.push(link)
                event->ReactEvent.Synthetic.preventDefault
            }
        ;
        <a href className onClick=onClick(href)>...children</a>
    }
}