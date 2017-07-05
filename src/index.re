ReactDOMRe.renderToElementWithId <Welcome name="ReasonML" /> "root";

[%bs.raw
  {|
    (() => {
      if (!module.hot) return;
      module.hot.accept("./welcome.re", () => {
        const next = require("./welcome.re");
        // tips: you can copy from lib/js/index.js
        ReactDOMRe.renderToElementWithId(
          ReasonReact.element(0, 0, next.make("ReasonML", [])),
          "root"
        );
      });
    })()
|}
];
