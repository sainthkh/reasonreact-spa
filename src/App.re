type page = Index | SiteExplorer | KeywordExplorer;

let url_of_page = (page) =>
    switch(page) {
    | Index => "/dashboard/metrics"
    | SiteExplorer => "/site-explorer"
    | KeywordExplorer => "/keyword-explorer"
    }

type state = {
    page: page,
};

type action = ClickLink(page);

let component = ReasonReact.reducerComponent("App");

let make = (_children) => {
    ...component,
    initialState: () => {
        page: Index,
    },

    reducer: (action: action, _state: state) => {
        switch(action) {
        | ClickLink(page) => {
            ReasonReact.Router.push(url_of_page(page));
            ReasonReact.Update({page: page})
        }
        }
    },

    render: self => {
        let onClick = (page) => 
            (event) => {
                self.send(page)
                event->ReactEvent.Synthetic.preventDefault
            };
        
        <div>
            <h1>{ReasonReact.string("App")}</h1>
            <a href="#" onClick={onClick(ClickLink(Index))}>{ReasonReact.string("Ahrefs")}</a>
            <a href="#" onClick={onClick(ClickLink(SiteExplorer))}>{ReasonReact.string("Site Explorer")}</a>
            {switch(self.state.page){
            | Index => <IndexPage />
            | SiteExplorer => <SiteExplorerPage />
            | KeywordExplorer => <KeywordExplorerPage />
            }}
        </div>
    }
}