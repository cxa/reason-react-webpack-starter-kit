const webpack = require("webpack");
const resolve = require("path").resolve;
const merge = require("webpack-merge");
const CopyWebpackPlugin = require("copy-webpack-plugin");

const common = env => {
  return {
    context: resolve(__dirname, "src"),

    resolve: {
      extensions: [".re", ".ml", ".js", ".scss"]
    },

    output: {
      filename: "bundle.js",
      path: resolve(__dirname, "dist"),
      publicPath: "/"
    },

    devtool: "inline-source-map",

    module: {
      rules: [
        {
          test: /\.jsx?$/,
          use: ["babel-loader"],
          exclude: /node_modules/
        },
        {
          test: /\.scss$/,
          use: ["style-loader", "css-loader?modules", "sass-loader"]
        },
        {
          test: /\.(png|svg|jpg|gif)$/,
          use: ["file-loader"]
        },
        {
          test: /\.(re|ml)$/,
          use: "bs-loader"
        }
      ]
    }
  };
};

const devSrvPort = 3000;

module.exports = function(env) {
  return merge(
    common(env),
    env === "dev"
      ? {
          entry: [
            "react-hot-loader/patch",
            "webpack-dev-server/client?http://localhost:" + devSrvPort,
            "webpack/hot/only-dev-server",
            "./index.re"
          ],

          devServer: {
            hot: true,
            port: devSrvPort,
            contentBase: resolve(__dirname, "public"),
            publicPath: "/"
          },

          plugins: [
            new webpack.HotModuleReplacementPlugin(),
            new webpack.NamedModulesPlugin()
          ]
        }
      : {
          entry: ["./index.re"],

          plugins: [
            new CopyWebpackPlugin([
              {
                from: "../public"
              }
            ]),
            new webpack.LoaderOptionsPlugin({
              minimize: true,
              debug: false
            }),
            new webpack.DefinePlugin({
              "process.env": {
                NODE_ENV: JSON.stringify("production")
              }
            }),
            new webpack.optimize.UglifyJsPlugin({
              beautify: false,
              comments: false
            })
          ]
        }
  );
};
