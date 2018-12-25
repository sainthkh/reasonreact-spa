module Styles = {
    open Css;

    let newFeature = style([
        display(inlineBlock),
        color(hex("f80")),
        fontSize(px(9)),
        fontWeight(bold),
        marginTop(px(-2)),
        marginLeft(px(5)),
        padding(px(0)),
        textTransform(uppercase),
        verticalAlign(textTop),
    ]);
}

let component = ReasonReact.statelessComponent("NavLink");

let make = (~href, ~className="", ~newFeature=false, children) => {
    ...component,
    render: _self => {
        let onClick = (link) => 
            (event) => {
                ReasonReact.Router.push(link)
                event->ReactEvent.Synthetic.preventDefault
            }
        ;
        
        <a href className onClick=onClick(href)>
            {ReasonReact.array(Array.concat([
                children,
                [| newFeature ? (<span className=Styles.newFeature key="new-tag">{ReasonReact.string("NEW")}</span>) : {ReasonReact.string("")} |],
            ]))}
        </a>
    }
}