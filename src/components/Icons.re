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

let iconBase = style([
    display(inlineBlock),
    width(px(16)),
    height(px(16)),
    after([
        display(block),
        height(pct(100.0)),
        width(pct(100.0)),

        backgroundPosition(px(0), pct(-0.333)),
        backgroundSize(cover),
        backgroundRepeat(noRepeat),
        contentRule(""),
    ]),
]);

let profile = merge([
    iconBase,
    style([
        after([
            backgroundImage(url("\"data:image/svg+xml,%3Csvg xmlns='http://www.w3.org/2000/svg' xmlns:xlink='http://www.w3.org/1999/xlink' width='16' height='64'%3E%3Cdefs%3E%3Cpath id='a' fill='%23fff' fill-rule='evenodd' d='M10.1500244,8.2670695 C9.51110055,8.80194911 8.6285254,9 7.99987433,9 C7.37122326,9 6.4887088,8.8017895 5.84997559,8.2670695 C5.21124238,7.7323495 4.33531303,6.92256076 4.02454589,4.20000076 C3.7351099,1.66431804 5.53099866,-2.2576842e-15 7.99987433,1.77635684e-15 C10.46875,5.32904129e-15 12.2652126,1.66440076 11.9754993,4.20000076 C11.6644245,6.92255916 10.7887576,7.7323495 10.1500244,8.2670695 Z M8,11 C10.67,11 16,12.0400008 16,14.7000008 L16,16 L0,16 L0,14.7000008 C0,12.0400008 5.33,11 8,11 Z'/%3E%3C/defs%3E%3Cuse x='0' y='0' xlink:href='%23a' /%3E%3C/svg%3E%0A\"")),
        ])
    ]),
])

let backArrow = merge([
    iconBase,
    style([
        after([
            backgroundImage(url("\"data:image/svg+xml,%3Csvg xmlns='http://www.w3.org/2000/svg' width='14' height='14' viewBox='0 0 14 14'%3E%3Cg fill='none'%3E%3Cpath d='M0 0h14v14h-14z'/%3E%3Cpath fill='%23333' fill-rule='nonzero' d='M5.417 7l4.583-4.583-1.417-1.417-6 6 6 6 1.417-1.417z'/%3E%3C/g%3E%3C/svg%3E\""))
        ])
    ])
])

let nextArrow = merge([
    backArrow,
    style([
        after([
            transform(rotate(deg(180))),
        ])
    ])
])