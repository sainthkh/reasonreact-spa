let component = ReasonReact.statelessComponent("IndexPage")

let make = (_children) => {
    ...component,
    render: _self => {
        <div>  
            <SearchBar />
            <Banner />
            <Projects />
        </div>
    }
}