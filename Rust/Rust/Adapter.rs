struct rectangle {
    xx1 :  u8,
    xx2 :u8,
    yy1 :u8,
    yy2 : u8,
}

impl rectangle  {
    fn new (xx1 : u8, xx2 : u8, yy1 : u8, yy2 :u8) -> rectangle {
        rectangle{
            xx1,
            xx2,
            yy1,
            yy2,

        }
        println!("Nuevo rectangulo creado, sus puntos son: ("xx1","yy1") y ("xx2","yy2")");
    }
}

trait rectangleAdapter{
    fn adapter(&self, r: &rectangle);
}

impl rectangleAdapter for rectangle{
    fn adapter(&self, r: &rectangle){
        println!("Adaptando el rectangulo de puntos de cordenadas a dimensiones  ({x1},{y1}) y su
        anchura es de: {ancho} y altura de {altura}",
        x1 = r.xx1,
        y1 = r.yy1,
        ancho = r.xx2 - r.xx1,
        altura = r.yy2 - r.yy1);
    }
}
fn main(){
    let r = rectangle{xx1 : 120, xx2 : 200, yy1 : 180, yy2 : 240};
    let r2 = rectangle{xx1 : 120, xx2 : 200, yy1 : 180, yy2 : 240};
    r2.adapter(&r);
}
