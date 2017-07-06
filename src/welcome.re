external style : string = "" [@@bs.module "./assets"] [@@bs.scope "styles"];

external logo : string = "" [@@bs.module "./assets"];

let comp = ReasonReact.statelessComponent "Welcome";

let make ::name _ => {
  ...comp,
  render: fun _ =>
    <div className=style>
      <img src=logo />
      <h1> ("Hello " ^ name |> ReasonReact.stringToElement) </h1>
    </div>
};
