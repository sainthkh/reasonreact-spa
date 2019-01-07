let component = ReasonReact.statelessComponent("Layout")

let make = (children) => {
    ...component,

    render: _self => {
        <div>
            <Header />
            <div> ...children </div>
            <Footer />
        </div>
    }
}
