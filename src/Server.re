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
      { icon: "test", title: "Marketing Funnels for Beginners: A Comprehensive Guide", date: "Dec 20", messageType: `BlogPost, link: "https://ahrefs.com/blog/marketing-funnels/", read: true },
      { icon: "test", title: "Copy My Link Building System: How to Get Backlinks \"At Scale\"", date: "Dec 19", messageType: `YouTubeVideo, link: "https://www.youtube.com/watch?v=Ovu2ZYWgOJQ&index=1&list=PLvJ_dXFSpd2tjUTuAHpHidz5e2hAedP_m", read: false },
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