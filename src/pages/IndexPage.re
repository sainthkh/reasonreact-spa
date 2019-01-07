module Styles = {
    open Css;
    
    let wrap = style([
        height(pct(100.0)),
    ]);
}

let component = ReasonReact.statelessComponent("IndexPage")

let make = (_children) => {
    ...component,
    render: _self => {
        <div className=Styles.wrap>  
            <SearchBar />
            <Banner />
            <Projects />
        </div>
    }
}