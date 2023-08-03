#[allow(dead_code)]
mod insert_data;

fn main(){
    let var:String = insert_data::insert_username();
    print!("{}", var);
}
