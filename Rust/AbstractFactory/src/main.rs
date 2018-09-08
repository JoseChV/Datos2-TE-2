trait Button {
    fn Bmake(&self);
}

trait Menu {
    fn Mmake(&self);
}

trait Factory<B: Button, M: Menu> {
    fn newButton(&self) -> B;
    fn newMenu(&self) -> M;
}

struct WindowsButton;

impl Button for WindowsButton {
    fn Bmake(&self) {
        println!("Boton de windows");
    }
}

struct WindowsMenu;

impl Menu for WindowsMenu {
    fn Mmake(&self) {
        println!("Menu de windows");
    }
}

struct WindowsFactory;

impl Factory<WindowsButton, WindowsMenu> for WindowsFactory {
    fn newButton(&self) -> WindowsButton {
        return WindowsButton;
    }

    fn newMenu(&self) -> WindowsMenu {
        return WindowsMenu;
    }
}

struct LinuxButton;

impl Button for LinuxButton {
    fn Bmake(&self) {
        println!("Boton de linux");
    }
}

struct LinuxMenu;

impl Menu for LinuxMenu {
    fn Mmake(&self) {
        println!("Menu de linux");
    }
}

struct LinuxFactory;

impl Factory<LinuxButton, LinuxMenu> for LinuxFactory {
    fn newButton(&self) -> LinuxButton {
        return LinuxButton;
    }

    fn newMenu(&self) -> LinuxMenu {
        return LinuxMenu;
    }
}


fn main() {
    let windows = WindowsFactory;
    let linux = LinuxFactory;

    let button = windows.newButton();
    button.Bmake();

    let button = linux.newButton();
    button.Bmake();

    let menu = windows.newMenu();
    menu.Mmake();

    let menu = linux.newMenu();
    menu.Mmake();
}
