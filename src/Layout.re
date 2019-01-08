module Styles = {
    open Css;
    
    let wrap = style([
        minHeight(vh(100.0)),
        position(relative),
    ]);
}
let component = ReasonReact.statelessComponent("Layout")

let make = (~currentPage, children) => {
    ...component,

    render: _self => {
        <div className=Styles.wrap>
            <Header currentPage />
            <div>...children</div>
            <Footer />
        </div>
    }
}
