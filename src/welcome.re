module Welcome = {
  external style : string = "" [@@bs.module "./assets"] [@@bs.scope "styles"];
  external logo : string = "" [@@bs.module "./assets"];
  let createElement ::name ::children () =>
    <div className=style>
      <img src=logo />
      <h1> (ReactRe.stringToElement ("Hello, " ^ name)) </h1>
    </div>;
};
