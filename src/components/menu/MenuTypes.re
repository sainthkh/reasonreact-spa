type menuLink = {
    name: string,
    url: string,
}

type menuText = {
    title: string,
    explanation: string,
}

type menuItem = 
    | Link(menuLink) 
    | Separator 
    | Submenu(string, list(menuItem)) 
    | Text(menuText);