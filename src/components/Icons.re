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

let createIcon = data => 
    merge([
        iconBase,
        style([
            backgroundImage(url(data))
        ])
    ])

let profile = createIcon("\"data:image/svg+xml,%3Csvg xmlns='http://www.w3.org/2000/svg' xmlns:xlink='http://www.w3.org/1999/xlink' width='16' height='64'%3E%3Cdefs%3E%3Cpath id='a' fill='%23fff' fill-rule='evenodd' d='M10.1500244,8.2670695 C9.51110055,8.80194911 8.6285254,9 7.99987433,9 C7.37122326,9 6.4887088,8.8017895 5.84997559,8.2670695 C5.21124238,7.7323495 4.33531303,6.92256076 4.02454589,4.20000076 C3.7351099,1.66431804 5.53099866,-2.2576842e-15 7.99987433,1.77635684e-15 C10.46875,5.32904129e-15 12.2652126,1.66440076 11.9754993,4.20000076 C11.6644245,6.92255916 10.7887576,7.7323495 10.1500244,8.2670695 Z M8,11 C10.67,11 16,12.0400008 16,14.7000008 L16,16 L0,16 L0,14.7000008 C0,12.0400008 5.33,11 8,11 Z'/%3E%3C/defs%3E%3Cuse x='0' y='0' xlink:href='%23a' /%3E%3C/svg%3E%0A\"")
let backArrow = createIcon("\"data:image/svg+xml,%3Csvg xmlns='http://www.w3.org/2000/svg' width='14' height='14' viewBox='0 0 14 14'%3E%3Cg fill='none'%3E%3Cpath d='M0 0h14v14h-14z'/%3E%3Cpath fill='%23333' fill-rule='nonzero' d='M5.417 7l4.583-4.583-1.417-1.417-6 6 6 6 1.417-1.417z'/%3E%3C/g%3E%3C/svg%3E\"")
let nextArrow = merge([
    backArrow,
    style([
        after([
            transform(rotate(deg(180))),
        ])
    ])
])
let exportBox = createIcon("\"data:image/svg+xml,%3Csvg xmlns='http://www.w3.org/2000/svg' width='16' height='16' viewBox='0 0 16 16'%3E%3Cg fill='none'%3E%3Cpath d='M0 0h16v16h-16z'/%3E%3Cpath fill='%23FFF' d='M1.658 0h12.675c.917 0 1.667.75 1.667 1.667v12.667c0 .917-.75 1.667-1.667 1.667h-12.675c-.925 0-1.658-.75-1.658-1.667l.008-12.667c0-.917.725-1.667 1.65-1.667zm8.342 11h4v-9h-12v9h4c0 1.105.895 2 2 2s2-.895 2-2z'/%3E%3C/g%3E%3C/svg%3E\"");
let bell = createIcon("\"data:image/svg+xml,%3Csvg xmlns='http://www.w3.org/2000/svg' width='16' height='16' viewBox='0 0 16 16'%3E%3Cpath fill='%23FFF' fill-rule='evenodd' d='M5.5,14 C5.5,15.1045695 6.61928813,16 8,16 C9.38071187,16 10.5,15.1045695 10.5,14 L5.5,14 Z M9,1.07541676 C11.8377133,1.50821503 14,3.75182156 14,6.45454545 C14,6.46973458 13.9999317,6.4848861 13.9997954,6.5 L14,11 C15.1045695,11 16,11.8954305 16,13 L0,13 C0,11.8954305 0.8954305,11 2,11 L2,6.5 C2.00006829,6.4848861 2,6.46973458 2,6.45454545 C2,3.75182156 4.16228666,1.50821503 7,1.07541676 L7,0.5 C7,0.223857625 7.22385763,0 7.5,0 L8.5,0 C8.77614237,0 9,0.223857625 9,0.5 L9,1.07541676 Z'/%3E%3C/svg%3E%0A\"")
let question = createIcon("\"data:image/svg+xml,%3Csvg xmlns='http://www.w3.org/2000/svg' xmlns:xlink='http://www.w3.org/1999/xlink' width='16' height='16'%3E%3Cdefs%3E%3Cpath id='a' fill='%23fff' d='M8 16c-4.418 0-8-3.582-8-8s3.582-8 8-8 8 3.582 8 8-3.582 8-8 8zm0-2.9c.608 0 1.1-.492 1.1-1.1 0-.608-.492-1.1-1.1-1.1-.608 0-1.1.492-1.1 1.1 0 .608.492 1.1 1.1 1.1zm-.836-3.1h1.705l.027-.383c.049-.447.242-.836.579-1.169.6-.643 1.024-1.2 1.272-1.671.178-.338.253-.71.253-1.097 0-.852-.26-1.512-.779-1.979-.519-.467-1.25-.701-2.191-.701-.932 0-1.668.246-2.208.738-.539.492-.814 1.173-.822 2.044h1.931c.009-.365.112-.651.31-.858.198-.207.461-.311.789-.311.693 0 1.039.385 1.039 1.155 0 .724-.447 1.257-.849 1.624-.402.367-.678.739-.829 1.118-.151.378-.226.852-.226 1.49z'/%3E%3C/defs%3E%3Cuse xlink:href='%23a'/%3E%3C/svg%3E\"")