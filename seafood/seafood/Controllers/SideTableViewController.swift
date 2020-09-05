//
//  SideTableViewController.swift
//  seafood
//
//  Created by 김수완 on 2020/09/03.
//  Copyright © 2020 김수완. All rights reserved.
//

import UIKit

class SideTableViewController: UITableViewController {
    
    var menus = [menu(name: "마이페이지", identifier: "myPageVC", cellSize: 90),
                 menu(name: "장바구니", identifier: "myCartVC", cellSize: 60)]
    
    override func viewDidLoad() {
        super.viewDidLoad()
    }
    
    override func tableView(_ tableView: UITableView, numberOfRowsInSection section: Int) -> Int {
        return menus.count
    }
    
    override func tableView(_ tableView: UITableView, cellForRowAt indexPath: IndexPath) -> UITableViewCell{
        let cell = tableView.dequeueReusableCell(withIdentifier: "cell", for: indexPath)
        cell.textLabel?.text = menus[indexPath.row].name
        cell.textLabel?.font = UIFont(name: "Helvetica-Bold", size: CGFloat((menus[indexPath.row].cellSize)/3))

        return cell
    }

    override func tableView(_ tableView: UITableView, heightForRowAt indexPath: IndexPath) -> CGFloat {
        return CGFloat(menus[indexPath.row].cellSize)
    }
    
    override func tableView(_ tableView: UITableView, didSelectRowAt indexPath: IndexPath) {
        tableView.deselectRow(at: indexPath, animated: true)
        let vcName = self.storyboard?.instantiateViewController(withIdentifier: menus[indexPath.row].identifier)
        vcName?.modalPresentationStyle = .fullScreen
        vcName?.modalTransitionStyle = .coverVertical
        self.present(vcName!, animated: true, completion: nil)
    }
    @IBAction func goInfo(_ sender: Any) {
    }
    @IBAction func goServiceCenter(_ sender: Any) {
    }
    
}


struct menu {
    let name: String
    let identifier: String
    let cellSize: Int
}
