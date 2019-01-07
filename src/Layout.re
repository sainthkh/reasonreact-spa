module Styles = {
    open Css;
    
    let wrap = style([
        minHeight(vh(100.0)),
        position(relative),
    ]);
}
let component = ReasonReact.statelessComponent("Layout")

let make = (children) => {
    ...component,

    render: _self => {
        <div className=Styles.wrap>
            <Header />
            <div>...children</div>
            <Footer />
        </div>
    }
}
