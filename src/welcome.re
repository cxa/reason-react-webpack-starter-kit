external style : string = "" [@@bs.module "./assets"] [@@bs.scope "styles"];

external logo : string = "" [@@bs.module "./assets"];

let comp = ReasonReact.statelessComponent "Welcome";

let make _ => {
  ...comp,
  render: fun _ =>
    <div className=style>
      <img src=logo />
      <h1> ("Hello ReasonML" |> ReasonReact.stringToElement) </h1>
    </div>
};
