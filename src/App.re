type state = {
    page: Url.page,
};

type action = ChangePage(Url.page);

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
            <Header />
            {switch(self.state.page){
            | Index => <IndexPage />
            | SiteExplorer => <SiteExplorerPage />
            | KeywordExplorer => <KeywordExplorerPage />
            | Error404 => <Error404Page />
            }}
        </div>
    }
}