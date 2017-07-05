external style : string = "" [@@bs.module "./assets"] [@@bs.scope "styles"];

external logo : string = "" [@@bs.module "./assets"];

let make ::name _ => {
  ...ReasonReact.statelessComponent "Welcome",
  render: fun () _ =>
    <div className=style>
      <img src=logo />
      <h1> ("Hello " ^ name |> ReactRe.stringToElement) </h1>
    </div>
};
