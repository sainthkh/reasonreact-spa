open Express;

let app = express();

App.use(app, Middleware.from((next, _req, res) => {
    res
    |> Response.setHeader("Access-Control-Allow-Origin", "http://localhost:8000")
    |> Response.setHeader("Access-Control-Allow-Methods", "GET")
    |> next(Next.middleware)
}))

App.get(app, ~path="/notifications", Middleware.from((_next, _req, res) => {
    let messages: Message_bs.messages = [
      { icon: "test", title: "test", date: "Dec, 20", messageType: `YouTubeVideo, link: "/test", read: false },
    ]
    
    res
    |> Response.sendJson(Message_bs.write_messages(messages))
}))

App.get(app, ~path="/exports", Middleware.from((_next, _req, res) => {
    let messages: Message_bs.messages = [
    ]

    res
    |> Response.sendJson(Message_bs.write_messages(messages))
}))


let onListen = e =>
  switch (e) {
  | exception (Js.Exn.Error(e)) =>
    Js.log(e);
    Node.Process.exit(1);
  | _ => Js.log @@ "Listening at http://127.0.0.1:3000"
  };

let server = App.listen(app, ~port=3000, ~onListen, ());