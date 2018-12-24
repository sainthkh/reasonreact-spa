open Css;

let triangle = style([
    after([
        display(inlineBlock),
        width(px(0)),
        height(px(0)),
        verticalAlign(middle),
        borderTop(px(6), solid, currentColor),
        borderRight(px(4), solid, transparent),
        borderLeft(px(4), solid, transparent),
        marginRight(px(0)),
        marginLeft(rem(0.4)),
        marginTop(px(-1)),
        contentRule(""),
    ]),
]);
