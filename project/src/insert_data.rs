use std::io;
use std::io::Write;

pub fn insert_website() -> String{
    let mut website = String::new();
    let boolean: bool;
    
    print!("Website: ");
    let _ = io::stdout().flush();
    match io::stdin().read_line(&mut website){
        Ok(_) => boolean = true,
        Err(_error) => boolean = false,
    }

    if boolean == true {
        return website;
    }else{
        return "".to_string();
    }
}

pub fn insert_username() -> String{
    let mut username = String::new();
    let boolean: bool;

    print!("Username: ");
    let _ = io::stdout().flush();
    match io::stdin().read_line(&mut username){
        Ok(_) => boolean = true,
        Err(_error) => boolean = false,
    }

    if boolean == true {
        return username;
    }else{
        return "".to_string();
    }
}

pub fn insert_password() -> String{
    let mut password = String::new();
    let boolean: bool;

    print!("Passord: ");
    let _ = io::stdout().flush();
    match io::stdin().read_line(&mut password){
        Ok(_) => boolean = true,
        Err(_error) => boolean = false,
    }

    if boolean == true {
        return password;
    }else{
        return "".to_string();
    }
}
