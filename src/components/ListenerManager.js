let listeners = { }

let id = 0;

export function add(eventName, listener, target) {
    if (!target) {
        target = window;
    }
    target.addEventListener(eventName, listener)
    listeners[id] = {
        listener,
        eventName,
        target,
    };
    
    return id++;
}

export function remove(id) {
    let { target, listener, eventName } = listeners[id]

    target.removeEventListener(eventName, listener);

    delete listeners[id];
}
