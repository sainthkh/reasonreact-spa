type page = 
    | Index 
    | SiteExplorer 
    | KeywordExplorer 
    | Error404 ;

let page = (page) =>
    switch(page) {
    | Index => "/dashboard/metrics"
    | SiteExplorer => "/site-explorer"
    | KeywordExplorer => "/keyword-explorer"
    | Error404 => "/404"
    }