type page = 
    | Index 
    | SiteExplorer 
    | KeywordExplorer 
    | Error404 ;

let url_of_page = (page) =>
    switch(page) {
    | Index => "/dashboard/metrics"
    | SiteExplorer => "/site-explorer"
    | KeywordExplorer => "/keyword-explorer"
    | Error404 => "/404"
    }

type state = {
    page: page,
};

type action = ChangePage(page);

let component = ReasonReact.reducerComponent("App");

let make = (_children) => {
    ...component,
    initialState: () => {
        page: Index,
    },

    reducer: (action: action, _state: state) => {
        switch(action) {
        | ChangePage(page) => ReasonReact.Update({page: page})
        }
    },

    didMount: self => {
        let watcherID = ReasonReact.Router.watchUrl(url => {
            switch(url.path) {
            | ["dashboard", "metrics"] => self.send(ChangePage(Index))
            | ["site-explorer"] => self.send(ChangePage(SiteExplorer))
            | ["keyword-explorer"] => self.send(ChangePage(KeywordExplorer))
            | _ => self.send(ChangePage(Error404))
            }
        })
        self.onUnmount(() => ReasonReact.Router.unwatchUrl(watcherID))
    },

    render: self => {        
        <div>
            <h1>{ReasonReact.string("App")}</h1>
            <NavLink href=url_of_page(Index)>{ReasonReact.string("Ahrefs")}</NavLink>
            <NavLink href=url_of_page(SiteExplorer)>{ReasonReact.string("Site Explorer")}</NavLink>
            {switch(self.state.page){
            | Index => <IndexPage />
            | SiteExplorer => <SiteExplorerPage />
            | KeywordExplorer => <KeywordExplorerPage />
            | Error404 => <Error404Page />
            }}
        </div>
    }
}